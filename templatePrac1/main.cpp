#include <iostream>
#include <string>

using namespace std;

int maximum(int x, int y);
int minimum(int x,int y);

template<typename T, typename F> //typename and class are interchangeable here
void perform(string title, T x, T y, F whatToDo);

int main()
{
   perform("maximum",3,2,maximum);
   perform("minimum",25,9,minimum);
   return 0;
}


int maximum(int x, int y)
{
    return x <= y ? y : x;
}

int minimum(int x, int y)
{
    return x >= y ? y : x;
}

template<typename T, typename F> //typename and class are interchangeable here
void perform(string title, T x, T y, F whatToDo)
{
    cout<<"The "<<title<<" of "<<x<<" and "<<y<<" is "<<whatToDo(x,y)<<endl;
}
