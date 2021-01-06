#ifndef TORPN_H
#define TORPN_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <assert.h>
#include "stack.h"

using namespace std;

enum RPN_ERROR {NO_INPUT};
enum RPN_OPERATIONS {ADD,SUBTRACT,MULTIPLY,DIVIDE,POWER,MAKE_NEG};

class toRPN
{
    //PRIVATE WILL BE IMPLEMENTED AT torpnPrivate FILE.
    private:
        //CLASS VARIABLES:
        string inFix,postFix, operators;
        vector<string> tokens, rpnExpression;
        map<string, int> precedence;

        //CLASS PRIVATE FUNCTIONS:
        void copy(const toRPN &other);
        void tokenize();
        void finalizeTokens();
        bool isOperator(const string &token) const;
        void loadMaps();
        void trim(string &item);
        void convert();
        string toString(double x) const; //C++11 has std::to_string()

    //PUBLIC WILL BE IMPLEMENTED AT torpnPublic FILE.
    public:
        //CONSTRUCTORS  & DESTRUCTOR:
        toRPN();
        toRPN(const string  &infix);
        toRPN(const toRPN &other);
        ~toRPN();

        //CLASS OPERATORS:
        toRPN& operator=(const toRPN &other);
        toRPN& operator<<(const string &item);
        toRPN& operator>>(string &item);   //convert>>x>>y>>z;
        toRPN& operator>>(double &value);  //cin>>x>>y>>z;

        //FRIEND OPERATORS:
        friend
        ostream& operator<<(ostream &out, const toRPN &output);
        friend
        istream& operator>>(istream &in, toRPN &input);

        //CLASS PUBLIC FUNCTION:
        double evaluate() const;
        double stod(const string &x) const; //C++11 has stod() in <string>
};
#endif // TORPN_H
