#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "fraction.h"
#include "toRPN.h"
#include <vector>

using namespace std;

struct term
{
    fraction coef,power;
};

class expression
{
    public:
        expression();
        expression(const expression &other);
        ~expression();

        expression& operator=(const expression &other);
        expression& operator<<(const string &input);        
        expression& derivative(unsigned int x = 1);
        expression& operator>>(string &input);

        friend
        ostream& operator<<(ostream &out, const expression &exp);

        friend
        istream& operator>>(istream &in, expression &exp);

        //CLASS FUNCTIONS:
        fraction evaluateAt(const fraction &value);
        bool goodExpression();
        void readFromFile();
        void writeToFile();
        string standardize(string &input);

    private:
        string expressionToStore;
        toRPN expressionInRPN;
        vector<term> terms;
        void copy(const expression &other);
};

#endif // EXPRESSION_H
