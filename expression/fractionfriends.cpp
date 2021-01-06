#include "fraction.h"

//FRIEND BASIC OPERATORS:
fraction operator+(const fraction &first, const fraction &second)
{
    int numer, denom;
    numer = first.numer * second.denom + first.denom * second.numer;
    denom = first.denom * second.denom;
    fraction third(numer,denom);
    return third;
}

fraction operator-(const fraction &first, const fraction &second)
{
    int numer, denom;
    numer = first.numer * second.denom - first.denom * second.numer;
    denom = first.denom * second.denom;
    fraction third(numer, denom);
    return third;
}

fraction operator*(const fraction &first, const fraction &second)
{
    int numer, denom;
    numer = first.numer * second.numer;
    denom = first.denom * second.denom;
    fraction third(numer, denom);
    return third;
}

fraction operator/(const fraction &first, const fraction &second)
{
    if (second != 0)
    {
    int numer, denom;
    numer = first.numer * second.denom;
    denom = first.denom * second.numer;
    fraction third(numer, denom);
    return third;
    }else{
        return fraction(INT_MAX,1);
    }
}

//FRIEND I/O OPERATORS:
istream& operator>>(istream &in, fraction &me)
{
    char crap;
    in>>me.numer >> crap >> me.denom;
    if(me.getDenom() == 0)
        me.setDenom(1);
    me.reduce();
    return in;
}

ostream& operator<<(ostream &out, const fraction &me)
{
    if (me.numer == INT_MAX)
    {
        out << "undefined";
        return out;
    }
    out << me.numer;
    if(me.denom != 1 && me.denom !=0)
        out << '/' <<me.denom;
    return out;
}

//FRIEND LOGICAL OPERATORS:
bool operator==(const fraction &first, const fraction &second)
{
    return (first.numer*second.denom == first.denom*second.denom);
}

bool operator!=(const fraction &first, const fraction &second)
{
    return !(first == second);
}

bool operator>=(const fraction &first, const fraction &second)
{
    return (first.numer*second.denom >= first.denom*second.denom);
}

bool operator<=(const fraction &first, const fraction &second)
{
    return (first.numer*second.denom <= first.denom*second.denom);
}

bool operator>(const fraction &first, const fraction &second)
{
    return !(first.numer*second.denom <= first.denom*second.denom);
}

bool operator<(const fraction &first, const fraction &second)
{
    return !(first.numer*second.denom >= first.denom*second.denom);
}

//FRIEND LOGICAL OVERLOAD OPERATORS:
bool operator==(const fraction &first, int a)
{
     return (first.getNumer() == (a*first.getDenom()));
}

bool operator!=(const fraction &first, int a)
{
    return !(first==a);
}

bool operator>=(const fraction &first, int a)
{
    return (first.getNumer() >= a*first.getDenom());
}

bool operator<=(const fraction &first, int a)
{
    return (first.getNumer() <= a*first.getDenom());
}

bool operator<(const fraction &first, int a)
{
    return !(first >= a);
}

bool operator>(const fraction &first, int a)
{
    return !(first <= a);
}
