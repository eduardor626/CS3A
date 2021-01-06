#include <iostream>
#include <string>
#include "torpn.h"
#include "stack.h"
using namespace std;

bool getInput(char *title, toRPN &item);

//main function
int main()
{
    toRPN converter;
    while(getInput("Enter infix expression",converter))
        cout<<converter<<endl;
    return 0;
}

bool getInput(char *title, toRPN &item)
{
    try
    {
        cout<<title<<": ";
        cin >> item;
    }
    catch(RPN_ERROR e)
    {
        return false;
    }
    return true;
}
