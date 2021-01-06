#include "torpn.h"

toRPN::toRPN() : operators("()^*/+-")
{
    precedenceMap();
}
toRPN::toRPN(const string  &infix): operators("()^*/+-")
{
    inFix = infix;
    precedenceMap();
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
    tokenize();
}

toRPN& toRPN::operator>>(string &item)
{
    item = postFix;
    return *this;
}

//convert>>x>>y>>z;
//cin>>x>>y>>z;

void toRPN::copy(const toRPN &other)
{
    inFix = other.inFix;
    postFix = other.postFix;
}

void toRPN::tokenize()
{
    int pos;
    tokens.clear();
    string toTokenize = inFix, token, fromChar("A");
    while(!toTokenize.empty())
    {
        trim(toTokenize);
        pos = toTokenize.find_first_of(operators);
        fromChar[0] = toTokenize[0];
        if(isOperator(fromChar))
        {
            tokens.push_back(fromChar);
            toTokenize.erase(0,1);
        }
        else
        {
            token = toTokenize.substr(0,pos);
            toTokenize = toTokenize.substr(pos+1);
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

bool toRPN::isOperator(const string &token)
{
    return token.find_first_of(operators) < token.size();
}

void toRPN::precedenceMap()
{
    precedence["+"] = precedence["-"] = 1;
    precedence["*"] = precedence["/"] = 2;
                      precedence["^"] = 3;
}

ostream& operator<<(ostream &out, const toRPN &output)
{
//  out<<output.inFix<<" converts to "<<output.postFix<<endl;
    out<<"The tokens you have are: "<<endl;
    for(int i = 0; i < output.tokens.size(); ++i)
        out<<output.tokens[i]<<endl;
    return out;
}

istream& operator>>(istream &in, toRPN &input)
{

}
