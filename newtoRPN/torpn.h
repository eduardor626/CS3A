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
    public:
        //member functions - only working within yourself, is a part of
        //of only this class
        toRPN();
        toRPN(const string  &infix);
        toRPN(const toRPN &other);
        ~toRPN();
        //list = x = y = z;
        toRPN& operator=(const toRPN &other);
        toRPN& operator<<(const string &item);
        toRPN& operator>>(string &item);
        toRPN& operator>>(double &value);
        double evaluate() const;
        //convert>>x>>y>>z;
        //cin>>x>>y>>z
        //friends are where you want a third party to be involved
        friend
        ostream& operator<<(ostream &out, const toRPN &output);

        friend
        istream& operator>>(istream &in, toRPN &input);

    private:
        string inFix,postFix, operators;
        vector<string> tokens, rpnExpression;
        map<string, int> precedence;
        void copy(const toRPN &other);
        void tokenize();
        bool isOperator(const string &token) const;
        void loadMaps();
        void trim(string &item);
        void convert();
        string toString(double x) const; //C++11 has std::to_string()
        double stod(const string &x) const; //C++11 has stod() in <string>
};
#endif // TORPN_H
