#include <iostream>
#include "fractions.h"

using namespace std;

fraction add(const fraction &a,const fraction &b);

int main()
{
    fraction one(3,4), two(6,9), three;
    three = one = two;
    three += one = two;
    cout<<"one = ";
    one.display();
    cout<<endl;
    cout<<"two = ";
    two.display();
    cout<<endl;
    cout<<"one = "<<one<<" and two = "<<two<<" and, of course, three = "<<three<<endl;
    three = add(one,two);
    cout<<"three = ";
    three.display();
    cout<<endl;
    return 0;
}


fraction add(const fraction &a, const fraction &b)
{
    int num = a.getNum()*b.getDenom() + b.getNum()*a.getDenom(),
        denom = a.getDenom()*b.getDenom();
    fraction result(num,denom);
    return result;
}
