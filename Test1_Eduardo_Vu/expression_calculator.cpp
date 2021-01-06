#include "expression_calculator.h"
expression_calculator::expression_calculator(int argc, char *argv[])
{
    commandList = {"LET", "EVAL", "PRINT", "LOAD","SAVE","\n"};
    numbers = "0123456789-.";
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVW";
    start(argc,argv);
}

void expression_calculator::processCLA (int argc, char *argv[], string &inputName, string &outputName, string &help)
{
    if (argc >= 0 && argc <= 4)
        detectInAndOut (argc, argv,  inputName,  outputName, help);
    else
        return;
}

void expression_calculator:: detectInAndOut (int argc, char  *argv[], string &inputName, string &outputName, string &help)
{
    for (int i = 0 ; i < argc ; ++i)
    {
        int j = 0;
         while (argv[i][j] != '\0')
         {
                if (argv[i][j] == '/' && argv[i][j+1] == 'R')
                     outputName = extractName(argv[i]);
                else if (argv[i][j] == '/' && argv[i][j+1] == 'E')
                     inputName = extractName(argv[i]);
                else if (argv[i][j] == '/' && (argv[i][j+1] == 'h' || argv[i][j+1] == '?'))
                     help = extractName (argv[i]);
                j++;
         }
    }
}

string expression_calculator::extractName (const string command)
{
    unsigned int size = command.length();
    unsigned int i = command.find("=");
    return command.substr(i+1, size - i);
}

void expression_calculator::start(int argc, char *argv[])
{
    ofstream out;
    string inputName, outputName, help;
    vector<string> lines;
    string line;
    processCLA (argc, argv, inputName, outputName, help);

    if (!help.empty())
        helpMe();

    if (!inputName.empty())
        openInput(inputName, lines);
    if (!lines.empty())
    {
            for (unsigned int i = 0 ; i < lines.size() ; ++i)
            {
                if (!lines[i].empty())
                {
                    cout << "Pre-command:  "<< lines[i] << endl;////
                    processEvent(lines[i]);
                }
            }
    }
    if (!outputName.empty())
    {
        string extension;
        if(outputName.find('.') < outputName.size())
        {
            extension = outputName.substr(outputName.find('.'));
            if(extension != ".spt")
                cout<<"Error.. can only open .spt files\n";
        }
        else
        {
            outputName+=".spt";
            string ans;
            if(fileExists(outputName))
            {
                cout << "RECORD file exists. Do you want to overwrite? ";
                do
                {
                    cin >> ans;
                    ans = toupper(ans[0]);
                    cin.ignore(256,'\n');
                }while(ans[0] != 'Y' && ans[0] != 'N');
                if(ans[0] != 'Y')
                    cout<<"No override!\n\n";
            }

            if (!fileExists(outputName) || ans[0] == 'Y')
            {
                out.open(outputName);
                if (out.is_open())
                    cout << "Open output successful!\n\n";
                else
                    cout << "Can't open output!\n\n";
            }
        }
    }
    while (1)
    {
        cout<<"COMMAND: ";
        getline(cin,line);
        if(out.is_open()) //saving each user input into our RECORD output.spt file
            out << line << endl;
        processEvent(line);//then processing the users input
    }
}

void expression_calculator::processEvent(string line)
{
    int whatToDo;
    string command;
    string standardizedLine = standardize(line);
    command = getCommand(standardizedLine);
    if(command == "no" && alphabet.find(standardizedLine[0]) < alphabet.size() && standardizedLine[1] == '=')
    {
            standardizedLine="LET"+standardizedLine;
            command = "LET";
    }
    whatToDo = processCommand(command);
    switch(whatToDo)
    {
        case 0:
            let(standardizedLine.substr(command.size()));
            break;
        case 1:
            eval(standardizedLine.substr(command.size()));
            break;
        case 2:
            print(standardizedLine.substr(command.size()));
            break;
        case 3:
            load(line.substr(command.size()));
            break;
        case 4:
            save(line.substr(command.size()));
            break;
        case 5:
            cout<<"Exiting program...\n";
            exit(0);
            break;
        default:
            cout<<"ERROR IN INPUT! PLEASE TRY AGAIN!\n";
            break;
    }
    cout << endl;
}

int expression_calculator::processCommand(string &input)
{
    if(input.empty())
        return commandList.size()-1;
    for(unsigned int i = 0; i< commandList.size(); ++i)
    {
        if(input.find(commandList[i]) == 0)
            return i;
    }
    return 10; //goes to default in switch
}

string expression_calculator::trim(const string &input)
{
    string temp;
    for (unsigned int i = 0 ; i < input.size(); ++i)
        if (input[i] != ' ')
            temp.push_back(input[i]);
    return temp;
}

string expression_calculator::getCommand(string input)
{
    if(input.empty())
        return "";
    for(unsigned int i = 0; i<commandList.size(); ++i)
        if(input.find(commandList[i]) < input.size())
            return commandList[i];
    return "no";
}

string expression_calculator::standardize(string input)
{
    string temp;
    for(size_t i = 0; i<input.size(); ++i)
        if(input[i] != ' '&& input[i] != '(' && input[i] != ')')
            temp.push_back(toupper(input[i]));
     return temp;
}

void expression_calculator::openInput(string &inputName, vector<string> &lines)
{
    string extension;
    if(inputName.find('.') < inputName.size())
    {
        extension = inputName.substr(inputName.find('.'));
        if(extension != ".spt")
        {
            cout<<"Error.. in opening file that is not .spt\n";
            return;
        }
    }else
        inputName+=".spt";

    ifstream in;
    string line;
    in.open(inputName);
    if (in.is_open())
    {
        cout << "Open input sucessful.\nLoading commands...... " << endl;
        while (getline (in,line))
             lines.push_back(line);
    }else
        cout << "Input doesn't exist!" << endl;
    in.close();
}

void expression_calculator::let(string line)
{
    int numOfChar = findChar(line);
    if (numOfChar == 1)
    {
        string exp = line.substr(line.find("=")+1);
        char index = (line.at(0));
        expression temp = expression(exp);
        if (line.find('~') > line.size())
        {
            myExpressions[index] = temp;
            cout << index << " = " << temp << endl; ////
            return;
        }else
        {
            string pow = line.substr(line.find('~')+1);
            int degree = stringToInt (pow);
            if (degree ==0)
            {
                temp = expression("1");
            }else if (degree > 0)
            {
                temp = temp^degree;
            }
            myExpressions[index] = temp;
            cout << index << " = " << temp << endl; ////
            return;
         }
    }
    else if (numOfChar == 2)
    {
        if (expExists(line[2]) && line.find('^') == string::npos )
        {
             evalDerivative(line);
             return;
        }
    }
    else if (numOfChar == 3)
    {
        if(expExists(line[2]) && expExists(line[4]))
        {
            switch (line[3])
            {
                case '+':   myExpressions[line[0]] = myExpressions[line[2]] + myExpressions[line[4]];
                    break;
                case '-':   myExpressions[line[0]] = myExpressions[line[2]] - myExpressions[line[4]];
                    break;
                case '*':   myExpressions[line[0]] = myExpressions[line[2]] * myExpressions[line[4]];
                    break;
                default:    cout << "Bad input!" << endl;return;
                    break;
            }

            cout << line[0] << " = "<<myExpressions[line[0]] << endl; ////
            return;
        }else if (expExists(line[2]) && expExists(line[3]))
        {
            myExpressions[line[0]] = myExpressions[line[0]].composition(myExpressions[line[2]], myExpressions[line[3]]);
            print(line);
            //cout << line[0] << " = " << myExpressions[line[0]] << endl;
            return;
        }else
        {
            cout << "One ore more expression doesn't exist!" << endl;////
            return;
        }
    }else
    {
        cout << "Invalid Input" << endl;////
        return;
    }
}

int expression_calculator::findChar(const string &line)
{
    int counter = 0;
    for (unsigned int i = 0 ; i < line.size(); ++i)
    {
        if (alphabet.find(line[i]) != string::npos)
          counter++;
    }
    return counter;
}

int expression_calculator::stringToInt(const string x)
{
    stringstream ss;
    int value;
    ss<<x;
    ss>>value;
    return value;
}

void expression_calculator::eval(string line)
{
        evalExpression(line);
}

void expression_calculator::evalDerivative(string &line)
{
    unsigned int  derivativeDegree = 0;
    for (unsigned int i = 0; i < line.size() ; ++i)
        if (line[i] == '\'')
            derivativeDegree++;

    myExpressions[line[0]] = myExpressions[line[2]].derivative(derivativeDegree);
    print(line);
}

void expression_calculator::evalExpression(string &line)
{
    if (!expExists(line[0]))
    {
        cout << "Expression " << line[0] << " has not been defined!" << endl;
        return;
    }else
    {
        string s = "";
        fraction temp;
        if (line.find('/') != string::npos)   //input is fraction
        {
            string numer = line.substr(1,line.find('/')-1);
            string denom = line.substr(line.find('/')+1);
            temp = fraction (stod(numer), stod(denom));
        }else
        {
            for (unsigned int i = 0 ; i < line.size(); ++i)
            {
                if (numbers.find(line.at(i)) != string::npos)
                    s.push_back(line.at(i));
            }
            temp = fraction (stod(s));
        }
        fraction result = myExpressions[line[0]].evaluateAt(temp);
        if (result == INT_MIN || result == INT_MAX)
            cout << "OVERFLOW" << endl;
        else
        {
            int numer = result.getNumer();
            int denom = result.getDenom();
            if (abs(numer) >= denom && denom != 1)
            {
                int whole = numer/denom;
                int remainder = abs(numer%denom);
                cout << line[0] <<"(" << temp << ") " << "= " << whole << " " << remainder << "/" << denom <<endl;
                cout << "(" << (double)numer/denom << ")" << endl;
            }else
            {
                cout << line[0] <<"(" << temp << ") " << "= " << result << endl; ////
            }
        }
   }
}

void expression_calculator::print(string line)
{
    if(line == "ALL")
    {
        map<char,expression>::iterator it;
        for( it = myExpressions.begin(); it!=myExpressions.end(); ++it)
            cout << it->first << " = " << it->second <<endl;
        return;
    }

    if (myExpressions.count(line[0]) == true)
        cout << line[0] << " = "<<  myExpressions[line[0]]<<endl;
    else
        cout << "Expression " << line[0] << " has not been defined" << endl;
}

void expression_calculator::load(string line)
{
    string fileName = trim(line);
    string extension;
    if(fileName.find('.') < fileName.size())
    {
        extension = fileName.substr(fileName.find('.'));
        if(extension != ".exp") //requires user to only load .exp files!
            cout << "This program can only load .exp files" << endl;
        else
            openFile(fileName);
    }else
    {
        fileName+= ".exp";
        openFile(fileName);
    }
}


void expression_calculator::openFile (const string &fileName )
{
    ifstream in;
    in.open(fileName);
    if(in.is_open())
    {
        string line;
        cout << "open file successfully!" << endl;
        string alphabet;
        for (char c = 'A'; c <  'X' ; ++c)
            alphabet.push_back(c);

        while (getline(in,line))
        {
           if (line.find('=') != string::npos && alphabet.find(line[0]) != string::npos)
           {
                char key;
                key = line[0];
                line = standardize(line);
                string ex = line.substr(line.find('=')+1);;
                expression temp = expression (ex);
                myExpressions[key] = temp;
           }
        }
        in.close();
    }else
        cout << "file doesn't exist." << endl;
}

void expression_calculator::save(string line)
{
    string ans;
    ofstream fout;
    line = trim(line);
    string extension;
    if(line.find('.') < line.size())
    {
        extension = line.substr(line.find('.'));
        if(extension != ".exp") //requires user to only load .exp files!
        {
            cout << "This program can only save .exp files" << endl;
            return;
        }
    }else
        line+= ".exp";

    if(line == "..")
        cout << "Error: invalid file\n";

    if(fileExists(line))
    {
        cout << "This file exists. Do you want to overwrite? ";
        do
        {
            cin >> ans;
            ans = toupper(ans[0]);
            cin.ignore(256,'\n');
        }while(ans[0] != 'Y' && ans[0] != 'N');
        if(ans[0] == 'Y')
            fout.open(line);
        else
        {
            cout<<"No override!\n";
            return;
        }
    }
    else
        fout.open(line);

    if(fout.is_open())
    {
        map<char,expression>::iterator it;
        for( it = myExpressions.begin(); it!=myExpressions.end(); ++it)
            fout << it->first << " = " << it->second <<endl;
        cout << "file stored into " << line << endl;
        fout.close();
    }
    else
        cout << "Error file cannot be opened\n";
}

inline bool expression_calculator::fileExists(const string& name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

bool expression_calculator::expExists(char key)
{
    return myExpressions.count(key);
}

void expression_calculator::helpMe()
{
    cout << "        _--~~--_"          << "\t\t        _--~~--_" << endl;
    cout << "      /~/_|  |_\\~\\"      << "\t\t      /~/_|  |_\\~\\" << endl;
    cout << "     |____________|"       << "\t\t     |____________|" <<endl;
    cout << "     |[][][][][][]|"       << "\t\t     |[][][][][][]|" <<  endl;
    cout << "   __| __         |__"     << "\t\t   __| __         |__" <<  endl;
    cout << "  |  ||. |   ==   |  |"    << "\t\t  |  ||. |   ==   |  |" << endl;
    cout << " (|  ||__|   ==   |  |)"   << "\t\t (|  ||__|   ==   |  |)" <<endl;
    cout << "  |  |[] []  ==   |  |"    << "\t\t  |  |[] []  ==   |  |" <<endl;
    cout << "  |  |____________|  |"    << "\t\t  |  |____________|  |" <<endl;
    cout << "  /__\\            /__\\"  << "\t\t  /__\\            /__\\" <<endl<<endl;
    cout << "AVAILABLE  COMMANDS: LET - EVAL - PRINT - LOAD - SAVE - (EXIT)" << endl;
    cout << "AVAILABLE OPERATIONS: + , - , * , raise expression to a positive";
    cout << " power, composition, derivative" << endl;
    cout << "COMMAND LINE ARGUMENT: " << endl;
    cout << "\t /? /h to ask for help or instructions."<<endl;
    cout << "\t /EXECUTE=input.txt is used to load the commands from input.txt and execute line by line. " << endl;
    cout << "\t /RECORD=output.txt is used to record all the command that user type on the"<<endl;
    cout << " console while using this program" <<endl;
    cout << "***************************************************************************************"<<endl;
    cout << "INSTRUCTIONS AND EXAMPLES: "<< endl;
    cout << "*LET usage:(let command are optional) "<<endl;
    cout << "\t-To declare an expression." << endl;
    cout << "\t let f = 0.5X^4/3 + X + 4 (notice: input can be fraction, double, or integer)" << endl;
    cout << "\t-To find the expansion of an expression after raising to a positive integer." << endl;
    cout << "\t let f = (2x^2 + X + 1/2 )~3 (notice: you must use '~' instead of using '^') " << endl;
    cout << "\t-To assigning the result of an expression after being differentiated to a new expression. " <<endl;
    cout << "\t let f = g'' (notice: g must be defined )" << endl;
    cout << "*EVAL usage: " << endl;
    cout << "\t-To evaluate a defined expression with a fraction, a double, or an int. " << endl;
    cout << "\t eval f(4/2)  or f (2) or f(2.0)"<<endl;
    cout << "*PRINT usage: "<<endl;
    cout << "\t print A -> print epression A if A exists, you'll get a notice if A doesn't exist. "<<endl;
    cout << "\t print all -> print all the existence expression from A->W (we reserve X Y Z for variables.)" << endl;
    cout << "*LOAD usage:" << endl;
    cout << "\t-To load a predefined-valid expressions from a file (.txt is preferable)" << endl;
    cout << "\t load input.txt (you'll get a notice if input"
            " does not exist or input \n\texists, and loading file successfully.)"<<endl;
    cout << "*SAVE usage:" << endl;
    cout << "\t-To save current defined expressions you're working with to a file" << endl;
    cout << "\t SAVE output.txt (if output.txt already existed, you will ask you to confirm" <<endl;
    cout << "\t overwrite or cancel, otherwise you'll a notice when overwriting process finished"
            ")" << endl;
    cout << "*EXIT: enter an empty line or a space to exit the program." << endl;
    cout << "***************************************************************************************"<<endl;
    cout << "LET'S START IT!!!" << endl<<endl;;
}
