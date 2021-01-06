#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string getFileName(char *title);
string validateInput(string &name);
void processCommandLine(int argc, char *argv[], string &in, string &out, bool &over1, bool &app1);
void name(string &input, char *item);
void openInput(const string &name, ifstream &in);
void openOutput(const string &name, ofstream &out);
void process(ifstream &in, ofstream &out);

int main(int argc, char *argv[])
{
    cout<<endl;
    string inFileName, outFileName;
    ifstream in; //ifstream - Stream class to read from files
    ofstream out; //ofstream - Stream class to write on files
    bool over = false, append = false;

    cout<<"ARGC: "<<argc<<endl; //Checking number of items

    //Printing our items on the command line
    for (unsigned int i= 0; i<argc; ++i)
    {
        cout<<i+1<<": "<<argv[i]<<endl;
    }


    switch(argc)
    {
    case 1 : cout<<"Program use: myCopy inFile outFile"<<endl<<endl;
        exit(0);
    case 2 : inFileName = argv[1];
        outFileName = getFileName("Output File name: ");
        outFileName = validateInput(outFileName);
        break;
    case 3 : inFileName = argv[1];
        outFileName = argv[2];
        break;
    default: cout<<"Too many parameters!"<<endl<<endl;
        exit(0);
    }

    processCommandLine(argc,argv,inFileName,outFileName,over, append);
    cout<<"Input file: "<<inFileName<<endl
        <<"Output file: "<<outFileName<<endl
       <<"Overwrite: "<<boolalpha<<over<<endl
        <<"Append: "<<boolalpha<<append<<endl;
    openInput(inFileName,in);
    openOutput(outFileName,out);
    process(in,out);


    cout<<endl<<endl;
    return 0;
}

void processCommandLine(int argc, char *argv[], string &in, string &out, bool &over1, bool &app1)
{


    for(unsigned int i = 0; i < argc; ++i) //checks each item
      if(argv[i][0] == '/') //wherever there is a char '/' ( Ex: /i=input.txt)
        switch(tolower(argv[i][1])) //lower case the whole string so we condense the switch!
        {
            case 'a' : app1 = true; //append
                       break;
            case 'e' : over1 = true; //overwrite
                       break;
            case 'i' : name(in,argv[i]); //in file
                       break;
            case 'o' : name(out,argv[i]); //outfile
                        break;
        }
}



string validateInput(string &name){
    string extension;
    if(name.find(".") > name.size())
    {
        if(extension.empty())
        {
            extension = ".txt";
        }
        name = name + extension;
    }
    return name;
}

string getFileName(char *title)
{
    string name;
    cout<<title;
    cin>>name;
    return name;
}

void name(string &input, char *item)
{
    input = item;
    input = input.substr(3);
}

void openInput(const string &name, ifstream &in)
{
    bool again;
    string temp = name;
    do
    {
        again = false;
        in.open(temp.c_str());
        string line;
        if (in.fail())
        {
            in.close();
            in.clear();
            again = true;
            cout<<"That file does not exist for input"<<endl
                <<"Please enter another file name: ";
            cin>>temp;
        }
        } while(again);
}

void openOutput(const string &name, ofstream &out)
{
    string answer;
    string temp2 = name;
    ifstream in;
    in.open(temp2.c_str());
    if(in.is_open())
    {
        cout<<"The output file already exists"<<endl;
        cout<<"Do you want to (O)verwrite, (A)ppend or (Q)uit? ";
        getline(cin,answer);
        switch(toupper(answer[0]))
        {
        case 'O' : out.open(temp2.c_str(), ios::binary);
            break;
        case 'A' : out.open(temp2.c_str(), ios::app | ios::binary);
                   out<<endl;
            break;
        default  : cout<<"Unknown answer... quitting!"<<endl;
        case 'Q' : exit(0);
        }
    }
    else
    {
//        out.open(temp2.c_str());
        cout<<"Unable to open output file!";

    }
}

void process(ifstream &in, ofstream &out)
{
    char input;
    while(in.get(input))
        out.put(input);
    out.close();
    in.close();
}



