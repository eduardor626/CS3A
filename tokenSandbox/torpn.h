#ifndef TORPN_H
#define TORPN_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <map>


using namespace std;

class toRPN
{
    public:
        toRPN();
        toRPN(const string  &infix);
        toRPN(const toRPN &other);
        ~toRPN();
        //list = x = y = z;
        toRPN& operator=(const toRPN &other);
        toRPN& operator<<(const string &item);
        toRPN& operator>>(string &item);
        //convert>>x>>y>>z;
        //cin>>x>>y>>z;

        friend
        ostream& operator<<(ostream &out, const toRPN &output);

        friend
        istream& operator>>(istream &in, toRPN &input);

    private:
        string inFix, postFix, operators;
        vector<string> tokens;
        map<string, int> precedence;

        void copy(const toRPN &other);
        void tokenize();
        bool isOperator(const string &token);
        void precedenceMap();
        void trim(string &item);
};

#endif // TORPN_H
