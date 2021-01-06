#include "fractions.h"

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int n) //The "one argument" constructor
{
    num = n;
    denom = 1;
}

fraction::fraction(int n, int d) //The "two argument" constructor
{
    num = n;
    denom = d;
    reduce();
}

fraction::~fraction() //Destructor
{
    num = denom = 0;
}

fraction::fraction(const fraction &other)//Copy constructor
{
    num = other.num;
    denom = other.denom;
    cout<<"Copy constructor firing with num = "<<num<<" and denom = "<<denom<<endl;
}

fraction& fraction::operator=(const fraction &other)//Assignment operator
{
    if(&other != this)
    {
        num = other.num;
        denom = other.denom;
    }
    return *this;
}


fraction& fraction::operator+=(const fraction &other)//add someone to me
{
    num = num*other.denom + other.num*denom;
    denom *= other.denom;
    reduce();
    return *this;
}


int fraction::getNum() const
{
    return num;
}

int fraction::getDenom() const
{
    return denom;
}
void fraction::setValue(int n, int d)
{
    num = n;
    denom = d;
    reduce();
}

void fraction::display()
{
    cout<<num<<"/"<<denom;
}

int fraction::gcd(int p, int q)
{
    return q==0 ? p : gcd(q,p%q);
}

void fraction::reduce()
{
    int div = gcd(num, denom);
    num /= div;
    denom /= div;
    if(denom < 0)
    {
        num = -num;
        denom = -denom;
    }
}

ostream& operator<<(ostream &out, const fraction &me)
{
    out<<me.num<<"/"<<me.denom;
    return out;
}
