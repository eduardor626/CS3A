#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#define uint8_t unsigned int
using namespace std;

enum STACK_ERRORS {EMPTY, FULL,INVALID_SIZE};

class stack
{
    public:
        stack(uint8_t s = 5);
        stack(const stack &other);
        ~stack();
        stack& operator=(const stack &other);

        void push(const string &input);
        string pop();
        string peek();
        bool empty();
        bool full();
        int items();
        void resize(int s);
        stack& operator<<(const string &input); //Another way to push
        stack& operator>>(string &output); //Another way to pop

        friend
        ostream& operator<<(ostream& out, const stack &other);

        friend
        istream& operator>>(istream&in, stack &other);

    private:
        int tos, size;
        string *theStack;

        void copy(const stack& other);
        void removeAll();

};
#endif // STACK_H
