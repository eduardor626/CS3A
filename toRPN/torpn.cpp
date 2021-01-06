#include "torpn.h"

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
{3
    precedence["+"] = precedence["-"] = 1;
    precedence["*"] = precedence["/"] = 2;
                      precedence["^"] = 3;
                      precedence["~"] = 4;
    operatorsMap["+"] = ADD;
    operatorsMap["-"] = SUBTRACT;
    operatorsMap["*"] = MULTIPLY;
    operatorsMap["/"] = DIVIDE;
    operatorsMap["^"] = POWER;
    operatorsMap["~"] = MAKE_NEG;
    cout<<operatorsMap["~"]<<endl;
}


toRPN& toRPN::operator>>(double &value)
{
    value = evaluate();
}


RPN_OPERATIONS toRPN::convertString(const string &op) const
{
    RPN_OPERATIONS ans = operatorsMap["+"];
    return ans;
}


double toRPN::evaluate() const
{
    stack operandStack(rpnExpression.size()),
          operatorStack(rpnExpression.size());
    double value1, value2;
    for(unsigned int i = 0; i < rpnExpression.size(); ++i)
    {
        if(!isOperator(rpnExpression[i]))
            operandStack.push(rpnExpression[i]);
        else
        {
            value1 = stod(operandStack.pop());
            value2 = stod(operandStack.pop());
            cout<<"value1 = "<<value1<<" value2 = "<<value2<<" = "<<operandStack.peek()<<endl;

            switch(convertString(rpnExpression[i]))
            {
                case  ADD   : operandStack.push(std::to_string(value1+value2));
                              break;

                case POWER  : operandStack.push(std::to_string(pow(value2,value1)));
                              break;

                case SUBTRACT: operandStack.push(std::to_string(value2-value1));
                               break;

                case MULTIPLY: operandStack.push(std::to_string(value1*value2));
                               break;

                case DIVIDE  : operandStack.push(std::to_string(value2/value1));
                               break;

                case MAKE_NEG: operandStack.push(std::to_string(value2));
                               operandStack.push(std::to_string(-value1));

            }
        }

    }
    return stod(operandStack.peek());
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
                        while(!operatorStack.empty() && operatorStack.peek() != "(")
                            rpnExpression.push_back(operatorStack.pop());
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
    }
    catch(STACK_ERRORS e)
    {
        const string errorMessage[3] = {"EMPTY", "FULL", "FULL,INVALID_SIZE"};
        cout<<errorMessage[e]<<" error from the stack occurred"<<endl;
    }
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
