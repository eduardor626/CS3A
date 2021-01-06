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
    if (b == 0)
        throw DENOMINATOR_EQUALS_TO_ZERO;
    whole = 0;
    numer = a;
    denom = b;
    reduce ();
}


fraction::fraction ( int a, int b, int c)
{
    if (c == 0)
        throw DENOMINATOR_EQUALS_TO_ZERO;
    whole = a;
    numer = abs(b);
    denom = abs(c);
    if (whole < 0)
        numer = (whole * denom) - numer;
    else
        numer = (whole*denom) + numer;
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
        throw DENOMINATOR_EQUALS_TO_ZERO;
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

void fraction::copy(const fraction &other)
{
    numer = other.numer;
    denom = other.denom;
}

//fraction friends.cpp ------

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
        throw DEVIDED_BY_ZERO;
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
    if(me.denom == 0)
        throw DENOMINATOR_EQUALS_TO_ZERO;
    out << me.numer;
    if(me.denom != 1 && me.denom !=0)
        out << '/' <<me.denom;
    return out;
}

//FRIEND LOGICAL OPERATORS:
bool operator==(const fraction &first, const fraction &second)
{
    return (first.numer*second.denom == first.denom*second.numer);
}

bool operator!=(const fraction &first, const fraction &second)
{
    return !(first == second);
}

bool operator>=(const fraction &first, const fraction &second)
{
    return (first.numer*second.denom >= first.denom*second.numer);
}

bool operator<=(const fraction &first, const fraction &second)
{
    return (first.numer*second.denom <= first.denom*second.numer);
}

bool operator>(const fraction &first, const fraction &second)
{
    return !(first.numer*second.denom <= first.denom*second.numer);
}

bool operator<(const fraction &first, const fraction &second)
{
    return !(first.numer*second.denom >= first.denom*second.numer);
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

//fractionoperators.cpp ------

fraction& fraction::operator +=(const fraction &other)
{
    this->numer = this->numer*other.denom + other.numer*this->denom;
    this->denom = this->denom * other.denom;
    this->reduce();
    return *this;
}

fraction& fraction::operator -= (const fraction &other)
{
    this->numer = this->numer*other.denom - other.numer*this->denom;
    this->denom = this->denom * other.denom;
    this->reduce();
    return *this;
}

fraction& fraction::operator *= (const fraction &other)
{
    this->numer *= other.numer;
    this->denom *= other.denom;
    this->reduce();
    return *this;
}

fraction& fraction::operator /= (const fraction &other)
{
    if(other.numer == 0 || this->numer == 0)
        throw DEVIDED_BY_ZERO;
    this->numer *= other.denom;
    this->denom *= other.numer;
    this->reduce();
    return *this;
}

fraction& fraction::operator=(const fraction &other)
{
    numer = other.numer;
    denom = other.denom;
    return *this;
}

fraction& fraction::operator=(int a)
{
    numer = a;
    denom = 1;
    return *this;
}

fraction& fraction::operator=(double a)
{
    int leftVal = (int)a;
    const int MAX_DIGITS = 9;
    int digits = 0;
    while (leftVal != 0)
    {
        leftVal /=10;
        digits++;
    }

    int digitAllows = MAX_DIGITS - digits;
    int pow = 1;
    for (int i = 0 ; i < digitAllows && (int)(a*pow)!= INT_MIN  ; i++)
        pow *=10;
    numer = a*pow;
    denom = pow;
    if (abs(numer)%10 == 9)
        numer += numer >= 0 ? 1 : -1;
    reduce();
    return *this;
}
