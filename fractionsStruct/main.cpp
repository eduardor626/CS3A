#include <iostream>
#include <cstdlib>

using namespace std;

/* Working with struct - similiar to a class, except
a struct is public to everyone, this can be bad
because we dont want just anybody being able to manipulate
our data or have access to (private)members of my struct */

//entity that has multiple fields to it

struct fraction
{
    int num, denom, whole;

    fraction()
    {
        num = 0;
        denom = 1;
        whole = 0;
    }

    fraction(int n, int d)
    {
        num = n;
        denom = d;
        reduce();
    }

    void reduce()
    {
        int div = gcd(num, denom);
        num /= div;
        denom /= div;
    }

    bool mixedNum()
    {
        if(num > denom)
            return true;
        else
            return false;

    }

    int gcd(int p, int q)
    {
        return q == 0 ? p : gcd(q, p%q);
    }

    void display()
    {
        if(mixedNum())
        {
            whole = num / denom;
            num = num % denom;
            cout<<whole<<" "<<num<<"/"<<denom<<"\n";
        }
        else
        {
            cout<<num<<"/"<<denom<<"\n";
        }
    }
};

int main()
{
    cout<<"\n============\n";

    fraction one(24,36);
    cout<<"1) "; one.display();
    fraction two(21,10);
    cout<<"2) ";two.display();
    fraction three(19,4);
    cout<<"3) ";three.display();
    fraction four(15,2);
    cout<<"4) ";four.display();
    fraction five(88,3);
    cout<<"5) ";five.display();

    cout<<"\n============\n";

    return 0;
}

