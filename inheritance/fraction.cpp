#include "fraction.h"

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction::fraction(int n) //The "one argument" constructor
{
    cout<<"Int constructor for fraction just fired!!!"<<endl;
    num = n;
    denom = 1;
}

fraction::fraction(int n, int d) //The "two argument" constructor
{
    num = n;
    denom = d;
    reduce();
}


fraction::fraction(double x)
{
  fromDouble(x);
}

fraction::~fraction() //Destructor
{
    num = denom = 0;
}

fraction::fraction(const fraction &other)//Copy constructor
{
    copy(other);
    cout<<"Copy from base class constructor firing with num = "<<num<<" and denom = "<<denom<<endl;
}

fraction& fraction::operator=(const fraction &other)//Assignment operator
{
    if(&other != this)
        copy(other);
    return *this;
}

void fraction::copy(const fraction &other)
{
    num = other.num;
    denom = other.denom;
}

fraction& fraction::operator-=(const fraction &other)//subtracts someone to me
{

}

fraction& fraction::operator*=(const fraction &other)//multiplies someone to me
{

}

fraction& fraction::operator/=(const fraction &other)//divides someone to me
{

}

fraction& fraction::operator+=(const fraction &other)//add someone to me
{
    //a += 3;
    num = num*other.denom + other.num*denom;
    denom *= other.denom;
    reduce();
    return *this;
}

fraction fraction::operator-() const
{
    fraction c(-num,denom);
    return c;
}

fraction fraction::operator^(int x)
{

}

double fraction::toDouble()
{

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

void fraction::fromDouble (double x)
{

    int tempNum = (int)x, temp = 0;
    double frac = x - tempNum;
    int power = 1;
    while(frac != 0)
    {
        temp *= 10 + (int)(frac * 10);
        frac = frac*10 - (int)(frac * 10);
        power *= 10;
    }
    num = tempNum * power + temp;
    denom = power;
    reduce();
}

//fraction friends*********************************

ostream& operator<<(ostream &out, const fraction &me)
{
    out<<me.num;
    if(me.denom != 1)
        cout<<"/"<<me.denom;
    return out;
}

istream& operator>>(istream &in, fraction &me)
{
    char junk;
    double value;
    me.denom = 1;
    in>>me.num;
    if(in.peek() == '/')
        in>>junk>>me.denom;
    else
        if(in.peek() == '.')
        {
            in.putback(me.num);
            in>>value;
            me = value;
        }
    me.reduce();
    return in;
}

fraction operator*(const fraction &a, const fraction &b)
{
    int num, denom;
    fraction c;
    num = a.num * b.num;
    denom = a.denom * b.denom;
    c.setValue(num,denom);
    return c;
}

fraction operator/(const fraction &a, const fraction &b)
{
    int num, denom;
    fraction c;
    num = a.num * b.denom;
    denom = a.denom * b.num;
    c.setValue(num,denom);
    return c;
}

fraction operator+(const fraction &a, const fraction &b)
{
    int num, denom;
    fraction c;
    num = a.num * b.denom + a.denom * b.num;
    denom = a.denom * b.denom;
    c.setValue(num,denom);
    return c;
}

fraction operator-(const fraction &a, const fraction &b)
{
 /*
    int num, denom;
    fraction c;
    num = a.num * b.denom - a.denom * b.num;
    denom = a.denom * b.denom;
    c.setValue(num,denom);
    return c;
*/
    fraction c;
    c = a + -b;
    return c;
}

bool operator!=(const fraction &a, const fraction &b)
{
    return !(a == b);
}


bool operator==(const fraction &a, const fraction &b)
{
    return a.num * b.denom == a.denom * b.num;
}


bool operator>=(const fraction &a, const fraction &b)
{
    return a.num * b.denom >= a.denom * b.num;
}


bool operator<=(const fraction &a, const fraction &b)
{
    return a.num * b.denom <= a.denom * b.num;
}


bool operator>(const fraction &a, const fraction &b)
{
    return !(a <= b);
}


bool operator<(const fraction &a, const fraction &b)
{
    return !(a >= b);
}
