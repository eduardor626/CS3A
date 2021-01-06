#include "fraction.h"

//CONSTRUCTORS:
fraction::fraction()
{
    whole  = 0;
    numer = 0;
    denom  = 1;
}

fraction::fraction( int a)
{
    whole = 0;
    numer = a;
    denom = 1;
}

fraction::fraction ( int a, int b)
{
    whole = 0;
    numer = a;
    if (b == 0)
    {
         getNewDenom(a,b);
    }
    denom = b;
    reduce ();
}


fraction::fraction ( int a, int b, int c)
{
    //By standard, the fraction part has to be positive.
    whole = a;
    numer = abs(b);
    if (c == 0)
    {
         getNewDenom(b, c);
    }
    denom = abs(c);
    if (whole < 0){
        numer = (whole * denom) - numer;
    }else{
        numer = (whole*denom) + numer;
    }
    reduce();
}

fraction::fraction (const fraction &other)
{
    numer = other.numer;
    denom = other.denom;
}

fraction::fraction (double a)
{
    fraction A;
    A = a ;
    numer  = A.numer;
    denom = A.denom;
    reduce();

}

fraction::fraction (double a, double b)
{
    fraction A(a);
    fraction B(b);
    fraction C = A / B;
    numer = C.getNumer();
    denom = C.getDenom();
    reduce();
}
//SETTERS and GETTERS:
void fraction::setNumer (int b)
{
    numer = b;
}

void fraction::setDenom (int c)
{
    if (c == 0)
    {
        getNewDenom(numer,c);
    }
    denom = c;
}

int fraction::getNumer  () const
{
    return numer;
}

int fraction::getDenom  () const
{
    return denom;
}

//CLASS FUNCTIONS:
void fraction::getNewDenom (int numer, int &a)
{
    stringstream sstream;
    string str;
    while (a == 0)
    {
        cout << numer << "/0 is an invalid fraction." << endl;
        cout << "Please enter new denom: ";
        cin >> str;
        sstream << str;
        sstream >> a;
        sstream.str(string());
        sstream.clear();
    }
}

void fraction::reduce()
{
    int c = gcd (numer, denom);
    numer /= c;
    denom /= c;
    if (double(numer)/denom < 0)
    {
        numer = -(abs(numer));
        denom = abs(denom);
    }else{
        numer = abs(numer);
        denom = abs(denom);
    }
}

int fraction::gcd (int a, int b)
{
    return ( a % b == 0) ? b : gcd(b, a % b);
}

void fraction::display()
{
    if (numer == 0)
    {
        cout << 0 << endl;
        return;
    }

    if (denom == 1)
    {
        cout << numer << endl;
    }else
    {
        cout << numer << "/" << denom << endl;
    }

}

