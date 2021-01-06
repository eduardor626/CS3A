/*
   This program converts infix expression to postfix expression.
   This program assume that there are Five operators: (*, /, +, -,^)
   in infix expression and operands can be of single-digit only.
   This program will not work for fractional numbers.
   Further this program does not check whether infix expression is
   valid or not in terms of number of operators and operands.
*/

#include<iostream>
#include<cstdlib>     //for exit()
#include<string>
#include <map>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <vector>


#define SIZE 100

using namespace std;

double pop(double stack[], int &tos, bool &safe);
void push(double value, double stack[], int &tos, bool &safe);
double convert(string value);
bool getLine(string &line);
void display(const string &line, string postfix);
void push(string item, string stack[], int &top, bool &safe);
string pop(string stack[], int &top, bool &safe);
bool isOperator(string symbol);
void loadPrecedenceMap(map<string,int> &theMap);
void trimString(string &input);
int precedence(string symbol, map<string, int> theMap, bool &safe);
string getToken(string &line);
bool infixToPostfix(string infixExp, string &postfixExp, map<string,int> precedenceMap);
string process(string infixExp, map<string, int> theMap);
double evaluate(string postfixExp, bool &safe);
bool unaryOperator(string &item);


typedef unsigned int u_int;

/* main function begins */
int main()
{

    string infixExp;                    // Declare infix expression string
    map<string,int> precedence;         // Table of operator precedence
    loadPrecedenceMap(precedence);
    while(getLine(infixExp))            // As long as there is  input
        process(infixExp,precedence);   // Process the input
    return 0;
}


// define push operation
void push(string item, string stack[], int &top, bool &safe)
{
    safe = true;
    if(++top > SIZE-1)
    {
        cout<<endl<<"Stack Overflow."<<endl;
        safe = false;
    }
    else
        stack[top] = item;
}

void push(double value, double stack[],int &tos, bool &safe)
{
    safe = true;
    if(++tos > SIZE-1)
    {
        cout<<"Infix stack overflow!"<<endl;
        safe = false;
    }
    else
        stack[tos] = value;
}


// define pop operation
// function that takes in 3 arguments,
// a string array, an integer variable at the top, boolean safe
string pop(string stack[], int &top, bool &safe)
{
    string item ;
    safe = true;
    if(top < 0)
    {
        cout<<"Stack under flow: invalid infix expression has been entered!"<<endl;
        /* underflow may occur for invalid expression */
        /* where ( and ) are not matched */
       safe = false;
    }
    else
       item = stack[top--];
    return item; //returning an item of type string, that is a character
}

double pop(double stack[], int &tos, bool &safe)
{
    double answer = 0;
    safe = true;
    if(tos < 0)
        safe = false;
    else
        answer = stack[tos--];
    return answer;
}

/*
  Define function that is used to determine whether any symbol is operator or not
  what has been entered is a symbol or an operand. This functions returns true if
  symbol is opreator else return false
*/

bool isOperator(string symbol)
{
    const string operators("<=->+&|*!~^@");
    return operators.find(symbol) < operators.size();
}


/*
    Define function that is used to assign precendence to operator.
*/

void loadPrecedenceMap(map<string,int> &theMap)
{
    theMap[")"] = 6;
    theMap["!"] = theMap["~"] = 5;
    theMap["*"] = theMap["&"] = 4;
    theMap["@"] = 4;
    theMap["+"] = theMap["|"] = 3;
    theMap["^"] = theMap["%"] = 3;
    theMap["->"] = theMap["<-"] = 2;
    theMap["<="] = theMap["=>"] = 2;
    theMap["<=>"] = theMap["<->"] = 1;
    theMap["("] = 0;

}

/*
    Define a function to check precedence
*/
int precedence(string symbol, map<string, int> theMap, bool &safe)
{
    if(theMap.count(symbol) == 0)
    {
        safe = true;
        cout<<"Unknown operator!"<<endl;
        safe = false;
    }
    return theMap[symbol];
}

// Define a function to make sure that there are no leading or trailing spaces
void trimString(string &input)
{
    while(input[0] == ' ') //trailing spaces
        input.erase(0,1); //deleting
    while(input[input.size()-1] == ' ') //leading spaces
        input.erase(input.size()-1); //deleting
//    cout<<"INPUT AFTER TRIMSTRING : "<<input<<endl;
}

// Define a function to get the next token in the input string
string getToken(string &line)
{
    const string seperators(" ()<=->+*!~");
    string result;
    u_int pos = 0;
    trimString(line);
    if(seperators.find(line[0]) < seperators.size())
    {
        int pos = line.find_first_not_of(seperators);//Finds index of first not of operators
        cout<<"POS = "<<pos<<endl;
        result = line.substr(0,1);//start index to position store in result
        line.erase(0,1); //taking part in line out from index 0 to position
    }
    else
        if((pos  = line.find_first_of(seperators)) < line.size())
        {
            cout<<"parantheses is trapped here!"<<endl;
            result = line.substr(0,pos);
            line.erase(0,pos);
        }
        else
            result = "";
    trimString(result);
    cout<<"REULT LEAVING GET TOKEN TO ITEM! = "<<result<<endl;
    return result;
}

// Define function to perform the conversion from infix to postfix notation
bool infixToPostfix(string infixExp, string &postfixExp,  map<string,int> precedenceMap)
{
    string stack[SIZE],     // Declare stack
           item;            // Current item to process
    int tos = -1;           // Set the stack to be empty
    bool safe;
    bool helpme;
    trimString(infixExp); //trimming our inFix so that there are no leading or trailing spaces
    cout<<"OUT OF FIRST TRIMSTRING!\n";
    cout<<"INFIX: "<<infixExp<<endl;

    push("(", stack, tos, safe); // Push '(' onto stack so that all expressions are automatically within parens
    infixExp += ")";       // Add ')' to infix expression

    cout<<"OUT OF FIRST PUSH AND FIRST INFIX AS: \n";
    cout<<infixExp<<endl;

    while(safe && ((item = getToken(infixExp)) != "") )        // run loop till end of infix expression
    {
        cout<<"ITEM ASSIGNED TO getToken(infixExp) IN WHILE LOOP: "<<item<<endl;
        cout<<"INFIX IN WHILE LOOP: "<<infixExp<<endl;
        if(item == "(")
        {
            cout<<"item in (item  == \"(\" ) = "<<item<<endl;
            push(item,stack,tos,safe);
            cout<<"STACK AFTER PUSH OF ( = "<<stack<<endl;
        }
        else
            if(item == ")")                    // if current symbol is ')' then
            {
                string temp = pop(stack,tos,safe);  // pop and keep popping until
                while( temp != "(")             // a  '(' encounterd
                {
                    postfixExp += " " + temp;
                    temp = pop(stack,tos,safe);
                    cout<<"-- POSTFIXEXP: "<<postfixExp<<endl;
                    cout<<"-- OPERATOR GETTING POPPED OUT = "<<temp<<endl;

                }

            } //TAKES CARE OF PARANTHESES PART
            else
                if( !isOperator(item) )
                    postfixExp += " " + item;          // add OPERAND symbol to postfix expression
                else
                    if(item == "!" || item == "~") //if item is the not operator
                        push(item,stack,tos,safe);// + item;
//                      postfixExp += " " + item;
                    else
                        if(isOperator(item))              // means item is operator
                        {
                            if(item == "!(")
                                cout<<"fired!!"<<endl;
                           string temp = pop(stack,tos,safe);
                           while(isOperator(temp) && ((precedence(temp,precedenceMap,safe) >= precedence(item,precedenceMap,safe)) && safe))
                           {       
                               postfixExp += " " + temp;         // so pop all higher precendence operator and
                               temp = pop(stack,tos,safe);            // add them to postfix expresion
                           }
                           if(safe)
                           {
                               push(temp,stack,tos,safe);
                               /*
                                 because just above while loop will terminate we have
                                 poppped one extra item for which condition fails and loop terminates, so that one
                                 needs to be pushed back onto the stack
                               */
                               push(item, stack,tos,safe); // push current oprerator symbol onto stack
                           }
                        }
                        else

                            return false; //if we cannot recognize the operators
    } // while loop ends here
    if(tos > -1 || !safe)
        return false;
    return true;
}

// Define function to get input of infix expression
bool getLine(string &line)
{
    cout<<"Expression: ";
    getline(cin,line);
    return !line.empty();
}

// Define display function
void display(const string &line, string postfix)
{
    bool safe;
   // double answer = evaluate(postfix,safe);
    cout<<line<<" in RPN is "<<postfix<<endl;
//    if(safe)
//       cout<<" and results into "<<answer;
//    else
//       cout<<" and is an invalid postix notation!";
//    cout<<endl;


}

// Define driver function
string process(string infixExp,map<string, int> theMap)
{
    string postfixExp;
    if(infixToPostfix(infixExp, postfixExp,theMap))
        display(infixExp,postfixExp);
    else
        cout<<"Invaild infix expression was entered!"<<endl;
    return postfixExp;
}


double evaluate(string postfixExp, bool &safe)
{
    string token;
    double operandStack[SIZE];
    int operandStackTos = -1;
    double value1, value2;
    safe = true;
    while(safe && !(token = getToken(postfixExp)).empty())
    {
        trimString(token);
        if(!isOperator(token))
            push(stod(token.c_str()),operandStack, operandStackTos, safe);

        else
        {
            value1 = pop(operandStack,operandStackTos,safe);
            cout<<"VALUE 1 = "<<value1<<endl;
            value2 = pop(operandStack,operandStackTos,safe);
            cout<<"VALUE 2 = "<<value2<<endl;

            switch(token[0])
            {
                case '+' : push(value1+value2, operandStack, operandStackTos,safe);
                           break;

                case '^' : push(pow(value2,value1), operandStack, operandStackTos,safe);
                           break;

                case '-' : push(value2-value1, operandStack, operandStackTos,safe);
                           break;

                case '*' : push(value1*value2, operandStack, operandStackTos,safe);
                           break;

                case '/' : push(value2/value1, operandStack, operandStackTos,safe);
                            break;
                case '~' : push('~', operandStack,operandStackTos,safe);
                            break;

            }
        }

    }
    return operandStack[0];
}



