#include <iostream>
#include <string>
#include <sstream>

//part3

using namespace std;

//Prototypes

bool getInput(string &line);
//bool getInput - getting the user input , returning True if correct
//input is given, returning False if incorrect input is given
//@param string &line - passed by referenced because we are going to change
//the value of the string

int convert(string &line);
//int convert - converts a string into an integer and returns the int
//@param string &line - passed by referenced string that changes into an int

int main()
{
    int value;
    string line;
    while(getInput(line))
    {
        value = convert(line);
        cout<<"The numeral contained is: "<<value<<endl;
    }
    return 0;
}

//Definitions

bool getInput(string &line)
{
    bool again;
    do
    {
    again = false;
    cout<<"Input: ";
    getline(cin,line);
    if(line.find_first_not_of("0123456789") < string::npos)
    {
        cout<<"Invalid number!"<<endl;
        again = true;
    }
    }while(again);
    return !line.empty();

}


int convert(string &line)
{

    //MAXIMUM VALUE FOR INT = 2,147,483,647
    //have to check this in input validation
    int value = 0;
    stringstream ss;
    ss<<line;
    ss>>value;
    return value;
}
