#include <iostream>
#include <vector>
#include <string>


#include "expression.h"

using namespace std;

const vector<string> commandList = {"LET", "EVAL", "PRINT", "LOAD","SAVE","\n"};

string getInput();

//void loadVariables(vector<expression>expressions);

void processInput(string &input);

string getCommand(string input);

int processCommand(string input);



int main()
{
//    vector<expression> expressions[23];
    getInput();



    return 0;
}


string getInput()
{
    string line;
    int whatToDo;
    string command;
    string functionVariable;
    while(1)
    {

        cout<<"COMMAND: ";
        getline(cin,line);
        command = getCommand(line);
        whatToDo = processCommand(command);
        switch(whatToDo)
        {
        case 0:
            cout<<"LET--\n";
            break;
        case 1:
            cout<<"EVAL--\n";
            break;
        case 2:
            cout<<"PRINT--\n";
            break;
        case 3:
            cout<<"LOAD--\n";
            break;

        }



    }


}


void processInput(string &input)
{


}

int processCommand(string input)
{
    int whoIsIt = 0;
    for(int i = 0; i< commandList.size(); ++i)
        if(input.find(commandList[i]) == 0)
        {
            whoIsIt = i;
        }
    return whoIsIt;

}


string getCommand(string input)
{
    for( int i = 0; i<commandList.size(); ++i)
    {
        if(input.find(commandList[i]) < input.size())
            return commandList[i];
        else
            cout<<"ERROR in getCommand!\n";
    }
}
