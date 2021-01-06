#include <iostream>
#include <cstdlib>
#include <iomanip>

typedef int (*fptr)(int, int);

void output(const char *title, int x, int y, fptr whatToDo);
int add(int x, int y);
int sub(int x, int y);
int mult(int x, int y);
int divide(int x, int y);

using namespace std;

int main(int argc, char *argv[])
{
    output("The sum",3,2,add);
    output("The difference",3,2,sub);
    output("The product",3,2,mult);
    output("The quotient",3,2,divide);
    return 0;
}


void output(const char *title, int x, int y, fptr whatToDo)
{
    cout<<title<<" of "<<x<<" and "<<y<<" is "<<whatToDo(x,y)<<endl;
}

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mult(int x, int y)
{
    return x * y;
}

int divide(int x, int y)
{
    return x / y;
}


