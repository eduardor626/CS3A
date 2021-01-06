#include "torpn.h"
//#define CHECK_THINGS_FIRST

toRPN::toRPN() : operators("()^*/+-~")
{
    loadMaps();
}

toRPN::toRPN(const string  &infix): operators("()^*/+-~")
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

ostream& operator<<(ostream &out, const toRPN &output)
{
    out<<"Infix Expression: " ;
    for(unsigned int i = 0; i < output.tokens.size(); ++i)
        out<<output.tokens[i]<<" ";
    out<<endl << "Postfix Expression: ";
    for(unsigned int i = 0; i < output.rpnExpression.size(); ++i)
        out<<output.rpnExpression[i]<<" ";
    out<< endl <<"which evaluates to: "<<output.evaluate()<<endl;
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

double toRPN::evaluate() const
{
    assert(404);
    double valueToReturn;
    try
    {
        stack operandStack(rpnExpression.size()-1);
        double value1, value2;
        for(unsigned int i = 0; i < rpnExpression.size(); ++i)
        {
            if(!isOperator(rpnExpression[i]))
            {
#ifdef CHECK_THINGS_FIRST
            {
                cout<<endl<<"At line "<<__LINE__<<" rpnExpression["<<i<<"] = "<<rpnExpression[i]<<endl;
#endif
                operandStack.push(rpnExpression[i]);
#ifdef CHECK_THINGS_FIRST
                if(operandStack.empty())
                    cout<<"Where did it go???"<<endl;
                else
                    cout<<"The value at the top of the stack is "<<operandStack.peek()<<endl;
            }
#endif
            }
            else
            {
                if(rpnExpression[i] == "~")
                {
                   value1 = stod(operandStack.pop());
                   operandStack.push(toString(-value1));
                }
                else
                {
#ifdef CHECK_THINGS_FIRST

                    cout << "This is the line number " << __LINE__;
                    cout << " of file " << __FILE__ << ".\n";
                    if(operandStack.empty())
                    {
                        cout<<"Operand stack is empty in evaluate"<<endl;
                        exit(1);
                    }
#endif
                    value1 = stod(operandStack.pop());
                    value2 = stod(operandStack.pop());
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
        }
        valueToReturn =  stod(operandStack.peek());
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
    return valueToReturn;
}

