#include "complex.h"

using namespace std;

complex::complex()
    : real(0),imag(0)
{

}

complex::complex(int x) : real(x), imag(0)
{
}

complex::complex(double x) : real(x), imag(0)
{
}

complex::complex(const fraction &a, const fraction &b)
    : real(a), imag(b)
{}

complex::complex(const complex &other)
{
    copy(other);
}

complex::~complex()
{
    real = 0;
    imag = 0;
}

complex& complex::operator=(const complex &other)
{
    if(this != &other)
        copy(other);
    return *this;
}

complex& complex::operator*=(const complex &other)
{
    *this = *this * other;
    return *this;
}

complex& complex::operator/=(const complex &other)
{
    *this = *this / other;
    return *this;
}

complex& complex::operator-=(const complex &other)
{
    *this = *this - other;
    return *this;
}

complex& complex::operator+=(const complex &other)
{
    *this = *this + other;
    return *this;
}

complex complex::normalized() //http://reference.wolfram.com/language/ref/Normalize.html
{

}


void complex::copy(const complex &other)
{
    this->real = other.real;
    this->imag = other.imag;
}


ostream& operator<<(ostream &out, const complex &value)
{
    out<<value.real;
    if(value.imag < 0)
        out<<" - "<<abs(value.imag)<<"i";
    else
        if(value.imag > 0)
            out<<" + "<<value.imag<<"i";
    return out;
}


istream& operator>>(istream &in, complex &value)
{
    fraction real, imag;
    //What if there is only a real number to be entered?
    in>>real; // assume that there is only a real number on the input
    //What if there is only an imaginary number to be entered?
    if(in.peek() == 'i')
    {
        char junk;
        in>>junk;
        imag = real;
        real = 0;
    }
    //What if there is a truly complex number to be entered?
    else
    {
        char sign,i;
        in>>sign;
        if(sign == '-' || sign == '+')
        {
            in>>imag;
            if(sign == '-')
                 imag *= -1;
            in>>i;
        }
        else
            in.putback(sign);
    }
    value.real = real;
    value.imag = imag;
    return in;
}


complex operator*(const complex &x, const complex &y)
{

    complex c;
    c.real = x.real*y.real - x.imag*y.imag;
    c.imag = x.real*y.imag + x.imag*y.real;
    return c;


}


complex operator/(const complex &x, const complex &y)
{
    complex realpart = x.real / x.real;
    complex imagpart = x.imag / y.imag;
    complex result = realpart + imagpart;
    return result;

}


complex operator+(const complex &x, const complex &y)
{
    complex c;
    c.real = x.real+y.real;
    c.imag = x.imag + y.imag;
    return c;
}


complex operator-(const complex &x, const complex &y)
{
    complex c;
    c.real = x.real-y.real;
    c.imag = x.imag-y.imag;
    return c;

}


complex operator^(const complex &x, const complex &y)
{

}


bool operator==(const complex &x, const complex &y)
{
    return x.real == y.real && x.imag == y.imag;
}


bool operator!=(const complex &x, const complex &y)
{
    return !(x==y);
}
