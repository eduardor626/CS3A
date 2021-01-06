#include "torpn.h"
#define CHECK_THINGS_FIRST
toRPN::toRPN() : operators("()^*/+-")
{
    loadMaps();
}

toRPN::toRPN(const string  &infix): operators("()^*/+-")
{
    inFix = infix;
    loadMaps();
}

toRPN::toRPN(const toRPN &other)
{
    copy(other);
}

toRPN::~toRPN()
{

}

//list = x = y = z;
toRPN& toRPN::operator=(const toRPN &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

toRPN& toRPN::operator<<(const string &item)
{
    inFix = item;
    postFix.clear();
    tokens.clear();
    rpnExpression.clear();
    tokenize();
    convert();
    return *this;
}

toRPN& toRPN::operator>>(string &item)
{
    item = postFix;
    return *this;
}

void toRPN::copy(const toRPN &other)
{
    inFix = other.inFix;
    postFix = other.postFix;
}

void toRPN::tokenize()
{
    unsigned int pos;
    tokens.clear();
    string toTokenize = inFix,
           token,
           fromChar("A");
    while(!toTokenize.empty())
    {
        trim(toTokenize);
        fromChar[0] = toTokenize[0];
        if(isOperator(fromChar))
        {
            trim(fromChar);
            tokens.push_back(fromChar);
            toTokenize.erase(0,1);
        }
        else
        {
            pos = toTokenize.find_first_of(operators);
            token = toTokenize.substr(0,pos);
            toTokenize =  pos > toTokenize.size() ? "" : toTokenize.substr(pos);
            trim(token);
            tokens.push_back(token);
        }
    }
}

void toRPN::trim(string &item)
{
    while(item[0] == ' ')
        item.erase(0,1);
    while(item[item.size()-1] == ' ')
        item.erase(item.size()-1);
}

bool toRPN::isOperator(const string &token) const
{
    return token.find_first_of(operators) < token.size();
}

void toRPN::loadMaps()
{
    precedence["+"] = precedence["-"] = 1;
    precedence["*"] = precedence["/"] = 2;
                      precedence["^"] = 3;
                      precedence["~"] = 4;
}


toRPN& toRPN::operator>>(double &value)
{
    value = evaluate();
    return *this;
}


double toRPN::evaluate() const
{
    assert(404);
    try
    {

        stack operandStack(rpnExpression.size());
//        cout<<"RPN EXPRESSION SIZE = "<<rpnExpression.size()<<endl;
        double value1, value2;
        for(unsigned int i = 0; i < rpnExpression.size(); ++i)
        {
            if(!isOperator(rpnExpression[i]))
#ifdef CHECK_THINGS_FIRST
            {
//                cout<<endl<<"At line "<<__LINE__<<" rpnExpression["<<i<<"] = "<<rpnExpression[i]<<endl;
#endif
                operandStack.push(rpnExpression[i]);
#ifdef CHECK_THINGS_FIRST
//                if(operandStack.empty())
//                    cout<<"Where did it go???"<<endl;
//                else
//                    cout<<"The value at the top of the stack is "<<operandStack.peek()<<endl;
            }
#endif
            else
                if(rpnExpression[i] == "~")
                {
                   value1 = stod(operandStack.pop());
                   operandStack.push(toString(-value1));
                }
                else
                {
#ifdef CHECK_THINGS_FIRST

//                    cout << "This is the line number " << __LINE__;
//                    cout << " of file " << __FILE__ << ".\n";
                    if(operandStack.empty())
                    {
                        cout<<"Operand stack is empty in evaluate"<<endl;
                        exit(1);
                    }
#endif
                    value1 = stod(operandStack.pop());
                    value2 = stod(operandStack.pop());
//                    cout<<"value1 = "<<value1<<" value2 = "<<value2<<" = "<<operandStack.peek()<<endl;

                    switch(rpnExpression[i][0])
                    {
                        case  '+' : operandStack.push(toString(value1+value2));
                                    break;

                        case '^'  : operandStack.push(toString(pow(value2,value1)));
                                    break;

                        case '-'  : operandStack.push(toString(value2-value1));
                                    break;

                        case '*'  : operandStack.push(toString(value1*value2));
                                    break;

                        case '/'  : operandStack.push(toString(value2/value1));
                                    break;

                   }
                }
        }
        return stod(operandStack.peek());
    }
    catch(STACK_ERRORS e)
    {
        switch(e)
        {
            case EMPTY        : cout<<"Stack became empty in evaluate!"<<endl;
                                break;
            case FULL         : cout<<"Stack became full in evaluate!"<<endl;
                                break;
            case INVALID_SIZE : cout<<"Stack has an invalid size in evaluate!"<<endl;
                                break;
        }
    }
//    return ;
}

void toRPN::convert()
{
    string temp;
    stack operatorStack(tokens.size());
    try
    {
        for(unsigned int i = 0; i < tokens.size(); ++i)
            if(!isOperator(tokens[i]))
                rpnExpression.push_back(tokens[i]);
            else
            {
                if(tokens[i] == "(")
                    operatorStack.push(tokens[i]);
                else
                    if(tokens[i] == ")" || tokens.empty())
                    {
                        while(!operatorStack.empty() && operatorStack.peek() != "(")
                            rpnExpression.push_back(operatorStack.pop());
                        operatorStack.pop();
                    }
                    else
                    {
                        while(!operatorStack.empty() && (precedence[tokens[i]] <= precedence[operatorStack.peek()]))
                            rpnExpression.push_back(operatorStack.pop());
                        operatorStack.push(tokens[i]);
                    }
            }
        while(!operatorStack.empty())
            rpnExpression.push_back(operatorStack.pop());
        for(unsigned int i = 0; i < rpnExpression.size(); ++i)
            postFix += rpnExpression[i] + " ";
        postFix.erase(postFix.size()-1);
//        cout<<"POST FIX EXP = "<<postFix<<endl;
    }
    catch(STACK_ERRORS e)
    {
        const string errorMessage[3] = {"EMPTY", "FULL", "FULL,INVALID_SIZE"};
        cout<<errorMessage[e]<<" error from the stack occurred"<<endl;
    }
}

string toRPN::toString(double x) const //C++11 has toString()
{
    stringstream ss;
    string value;
    ss<<x;
    ss>>value;
    return value;
}

double toRPN::stod(const string &x) const //C++11 has stod() in <string>
{
    stringstream ss;
    double value;
    ss<<x;
    ss>>value;
    return value;
}

ostream& operator<<(ostream &out, const toRPN &output)
{
//  out<<output.inFix<<" converts to "<<output.postFix<<endl;
    out<<"Infix: ";
    for(unsigned int i = 0; i < output.tokens.size(); ++i)
        out<<output.tokens[i]<<" ";
    out<<" <=> Postfix: ";
    for(unsigned int i = 0; i < output.rpnExpression.size(); ++i)
        out<<output.rpnExpression[i]<<" ";
    out<<"which evaluates to: "<<output.evaluate();
    return out;
}

istream& operator>>(istream &in, toRPN &input)
{
    string line;
    getline(in,line);
    if(line.empty())
        throw NO_INPUT;
    input << line;
    return in;
}
