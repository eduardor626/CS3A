#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>


using namespace std;

void processCommmandLine(int , char *[], string &, string &);
string getFileName(char *title);
void openInput(const string &name, ifstream &in);
void openOutput(const string &name, ofstream &out);
void process(ifstream &in, ofstream &out);

//                                  THE PARAMETERS (INT ARGC , CHAR *ARGV)


// argc - for main gives the number of items on the
// command line including how the program was started

// argv is an array of character pointers which in array
// position 0 contains the complete path of how the program
// was started,including the program name.

//      In C++ it is possible to accept command line arguments. Command-line arguments
// are given after the name of a program in command-line operating systems like DOS or Linux,
// and are passed in to the program from the operating system. To use command line arguments in
// your program, you must first understand the full declaration of the main function, which
// previously has accepted no arguments. In fact, main can actually accept
// two arguments: one argument is number of command line arguments, and the
// other argument is a full list of all of the command line arguments.

// The integer, argc is the ARGument Count (hence argc). It is the number of arguments/items
// passed into the program from the command line, including the name of the program.

// The array of character pointers is the listing of all the arguments. argv[0] is the name of the
// program, or an empty string if the name is not available. After that, every element number less
// than argc is a command line argument. You can use each argv element just like a string, or use
// argv as a two dimensional array. argv[argc] is a null pointer.

// How could this be used? Almost any program that wants its parameters to be set when it is executed would
// use this. One common use is to write a function that takes the name of a file and outputs the entire text
// of it onto the screen.

int main(int argc, char *argv[])
{
    string inFileName, outFileName;
    ifstream in;
    ofstream out;
    processCommmandLine(argc, argv,inFileName, outFileName);
    openInput(inFileName, in);
    openOutput(outFileName, out);
    process(in,out);
    return 0;
}


void processCommmandLine(int argc, char *argv[],string &inFile,string &outFile)
{
    cout<<"ARGC DEBUG: "<<argc<<endl;
    for ( unsigned int i = 0; i<argc; ++i)
    {
        cout<<argv[i]<<endl;
    }

    switch(argc)
    {
    case 1 : cout<<"Program use: myCopy inFile outFile"<<endl;
        exit(0);

    case 2 : inFile = argv[1];
        outFile = getFileName("Output file name: ");
        break;

    case 3 : inFile = argv[1];
        outFile = argv[2];
        break;

    default: cout<<"Too many parameters!"<<endl;
        exit(0);
    }
}

string getFileName(char *title)
{
    string name;
    cout<<title;
    cin>>name;
    return name;
}


void openInput(const string &name, ifstream &in)
{
    string extension,temp;
    bool again;
    if(name.find(".") > name.size())
    {
        cout<<"Please enter a file extension (press enter for .txt): ";
        getline(cin, extension);
        if(extension.empty())
        {
            extension = ".txt";
        }
    }
    do
    {
        temp = name + extension; //GETTING the name + extension! (Intro.txt)
        temp = temp.substr(3);
        again = false;
        in.open(temp.c_str());
        if(in.fail())
        {
            in.close();
            in.clear();
            again = true;
            cout<<"That file does not exist for input"<<endl
               <<"Please enter another file name: ";
            cin>>temp;
        }
    }while(again);
}

void openOutput(const string &name, ofstream &out)
{
    string extension, answer, temp;
    ifstream in;
//    if(name.find(".") > name.size())
//    {
//        cout<<"Please enter a file extension (press enter for .txt): "<<endl;
//        getline(cin,extension);
//        if(extension.empty())
//            extension = ".txt";
//        temp = name + extension;
//    }
    temp = name;
    temp = temp.substr(3);
    cout<<"DEBUG temp in openOutput = "<<temp<<endl;
    in.open(temp.c_str());
    if(in.is_open())
    {
        cout<<"That file already exists"<<endl;
        cout<<"Do you want to (O)verwrite, (A)ppend or (Q)uit? ";
        getline(cin,answer);
        switch(toupper(answer[0]))
        {
        case 'O' : out.open(temp.c_str(), ios::binary);
            break;

        case 'A' : out.open(temp.c_str(), ios::app | ios::binary);
                   out<<endl;
            break;

        default  : cout<<"Unknown answer... quitting!"<<endl;
        case 'Q' : exit(0);
        }
    }
    else
    {
        out.open(temp.c_str());

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
