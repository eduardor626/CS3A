#include "expression.h"

expression::expression()
{


}

expression& expression::derivative(unsigned int x)
{
    for(unsigned int i = 0; i < terms.size(); ++i)
        for(unsigned int j = 1; j <= x; ++j)
        {
            terms[i].coef = terms[i].coef * terms[i].power;
            terms[i].power = terms[i].power - 1;
        }
}

string expression::standardize(string &input)
{
    //making sure we make everything to uppercase so we can deal with
    //just uppercase
    string temp;
    for(size_t i = 0; i<input.size(); ++i)
         temp.push_back(toupper(input[i]));
     return temp;

}

istream& operator>>(istream &in, expression &exp)
{

}


