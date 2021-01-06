#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

//RE-DEFINING UNSIGNED INT as uint8_t.
#define uint8_t unsigned int
using namespace std;

enum STACK_ERRORS {EMPTY, FULL,INVALID_SIZE};

class stack
{
    public:
        //DEFAULT SIZE OF STACK = 5.
        stack(uint8_t s = 5);
        stack(const stack &other);
        ~stack();
        stack& operator=(const stack &other);

        //CLASS PUBLIC FUNCTIONS:
        void push(const string &input);
        string pop();
        string peek();
        bool empty();
        bool full();
        int items();
        void resize(int s);

        //OPERATORS:
        stack& operator<<(const string &input); //Another way to push
        stack& operator>>(string &output);      //Another way to pop

        //FRIEND OPERATORS:
        friend
        ostream& operator <<(ostream& out, const stack &other);
        friend
        istream& operator >>(istream&in, stack &other);

    private:
        //CLASS VARIABLES:
        unsigned int tos, size;
        string *theStack;

        //CLASS PRIVATE FUNCTIONS:
        void copy(const stack& other);
        void removeAll();
};

#endif // STACK_H
