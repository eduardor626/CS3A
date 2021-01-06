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


fraction::fraction(double x)
{
    int tempNum = (int)x, temp = 0;
//    cout<<"X = "<<x<<endl;
//    cout<<"TEMP NUM = "<<tempNum<<endl;
    double frac = x - tempNum;
//    cout<<"FRAC = "<<frac<<endl;
    int power = 10;
//    while(frac != 0)
//    {
//        temp = temp*power + (int)(frac * power);  // 5.4
//        frac = frac*power - (int)(frac * power);  // 0.4
//        power = power*10;
//        cout << "temp = " << temp << " frac = " << frac << "power = " << power << endl;
//    }
    while((x*power - (int)(x*power)) != 0)
    {
        power = power*10;
//        cout << (int)x*power - x*power<< endl;

    }

    num = x * power;
    denom = power;
    reduce();
//    cout<<num<<" / "<<denom<<endl;

}

fraction::fraction(double x, double y)
{
    fraction one(x);
    fraction two(y);
    fraction three = one/two;
    three.reduce();
    num = three.getNum();
    denom = three.getDenom();


}



fraction::~fraction() //Destructor
{
    num = denom = 0;
}

fraction::fraction(const fraction &other)//Copy constructor
{
    num = other.num;
    denom = other.denom;
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

fraction& fraction::operator-=(const fraction &other)//subtracts someone to me
{
    *this = *this - other;
    return *this;
}

fraction& fraction::operator*=(const fraction &other)//multiplies someone to me
{
    *this = *this * other;
    return *this;

}

fraction& fraction::operator/=(const fraction &other)//divides someone to me
{
    *this = *this / other;
    return *this;
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
