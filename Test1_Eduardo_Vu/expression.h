#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "fraction.h"
#include <vector>

struct term
{
    fraction coef,power;
};

class expression
{
    public:
//******************************************************************************
        //CONSTRUCTORS AND DESTRUCTOR:
        expression();
        expression(const expression &other);
        expression(string input);
        ~expression();

        //CLASS OPERATOR
        expression& operator=(const expression &other);
        expression& operator<<(const string &input);
        expression& operator+=(const expression &other);
        expression& operator-=(const expression &other);
        expression& operator*=(const expression &other);

        //CLASS PUBLIC FUNCTIONS:
        fraction evaluateAt(const fraction &value);
        expression derivative(unsigned int x);
        expression composition (const expression &one, const expression &two);
//******************************************************************************

        //FRIEND INPUT/OUTPUT OPERATORS
        friend
        ostream& operator<<(ostream &out, const expression &exp);
        friend
        istream& operator>>(istream &in, expression &exp);

        //FRIEND BASIC OPERATORS
        friend
        expression operator+(const expression &one, const expression &two);
        friend
        expression operator-(const expression &one, const expression &two);
        friend
        expression operator*(const expression &one, const expression &two);
        friend
        expression operator/(const expression &one, const expression &two);
        friend
        expression operator+(const expression &one, const fraction &num);
        friend
        expression operator-(const expression &one, const fraction &num);
        friend
        expression operator*(const expression &one, const fraction &num);
        friend
        expression operator/(const expression &one, const fraction &num);
        friend
        expression operator^(const expression &one, const int degree);

//******************************************************************************
    private:
        //PRIVATE VARIABLES:
        vector<term> terms;
        vector<string> tokens;
        string expressionToStore;
        string numbers = "0123456789.-";
        string variable = "X";

        //PRIVATE FUNCTIONS PART I:
        void copy(const expression &other);
        fraction makeFractionFrom(string input);
        string termToString (term input);
        string fractionToString (fraction input);
        double stod(const string &x) const;
        void printTerms();     //for testing
//******************************************************************************
        //PRIVATE FUNCTIONS PART II:
        void makeTerms(string input);
        void getTerms();
        void getTerms(string input);
        void addCommonTerms();
        void removeUselessTerm();
        void sortTerms ();
        void swapTerms(vector<term> &terms,const int &i,const int &j);
        void changeExpression();
        void destroy();
//******************************************************************************
};

#endif // EXPRESSION_H
