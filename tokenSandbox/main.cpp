#include <iostream>
#include <string>
#include "torpn.h"

using namespace std;

bool getInput(char *title, string &line);

int main()
{
    toRPN converter;
    string line;
    while(getInput("Enter infix expression",line))
    {
        cout<<"LINE"<<endl;
        converter<<line;
        cout<<"LINE2"<<endl;
        cout<<converter<<endl;
        cout<<"LINE3"<<endl;

    }
    return 0;
}


bool getInput(char *title, string &line)
{
    cout<<title<<": ";
    getline(cin,line);
    return !line.empty();
}
