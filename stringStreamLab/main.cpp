#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>


using namespace std;

bool getInput(string &line);
//bool getInput - gets user input, returns a boolean True or False
//depending if userInput is a True input or a False one
//@param string &line - string that is input and passed by reference
//because we are going to make changes to this value

void trimLine(string &line);
//void trimLine - take out unecessary spaces and getting what we want
//@param string &line - string that is passed by reference because we
//are going to change it and cut out the spaces

void processLine(string line, string &first, string &middle, string &last);
//void processLine - gets the string input, trims the string, gets name parts,
//and standardizes the first, middle and last names

void standardize(string &name, bool allUpper = true);
//void standardize - makes the name look how we want it to look
//if boolean is true, then we will make the name allUpper case (LAST NAME)
//will be upper case

void getNameParts(const string &line, string &first, string &middle, string &last);
//void getNameParts - getting a line and breaking it down into three parts

void assembleName(string &name, const string &first, const string &middle, const string &last);
//void assembleName - assembles the final name we want to display


int main()
{
    string line, name, first, middle,last;
    while(getInput(line))
    {
        processLine(line,first,middle,last);
        assembleName(name,first,middle,last);
        cout<<name<<endl;
        first = middle = last = "";
        //setting last values just to blank values so we can re-use
        //because we passed by reference so we have to set values
        //back to something we can change
    }

    return 0;
}

bool getInput(string &line)
{
    bool again;
    do
    {
    again = false;
    cout<<"Input: ";
    getline(cin,line);
    if(line.find_first_of("0123456789.,<>/?\\\"\';:][{}+=_-)(*&^%$#@!") < string::npos)
    {
        cout<<"Invalid input!!"<<endl;
        again = true;
    }
    }while(again);
    return !line.empty();
}

void trimLine(string &line)
{
    unsigned int size;
    while(line[0] == ' ')
        line.erase(0,1);
    while(line[size = line.size() - 1] == ' ')
        line.erase(size);
}

void getNameParts(const string &line, string &first, string &middle, string &last)
{
    stringstream ss;
    ss<<line;
    ss>>first>>middle>>last;
    if(last.empty())
    {

        last = middle;
        middle = "";
    }
}

void processLine(string line, string &first, string &middle, string &last)
{
    trimLine(line);
    getNameParts(line,first,middle,last);
    standardize(last);
    standardize(middle, false);
    standardize(first, false);
}

void standardize(string &name, bool allUpper)
{
    if(name.empty())
        return;
    name[0] = toupper(name[0]);
    for(unsigned int i = 1; i < name.size(); ++i)
        name[i] = allUpper ? toupper(name[i]) : tolower(name[i]);
    /*
     * The above is equivalent to, but faster, than:
     * if(allUpper)
     *   name[i] = toupper(name[i]);
     * else
     *   name[i] = tolower(name[i]);
     */
}

void assembleName(string &name, const string &first, const string &middle, const string &last)
{
    name = last + ", " + first + ' ' + middle;
}
