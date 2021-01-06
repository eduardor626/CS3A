#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include "fractions.h"

using namespace std;

class complex
{
    public:
        complex();
        complex(const fraction &a, const fraction &b = fraction(0,1));
        complex(int x);
        complex(double x);
        complex(const complex &other);
        ~complex();

        complex& operator=(const complex &other);
        complex& operator*=(const complex &other);
        complex& operator/=(const complex &other);
        complex& operator-=(const complex &other);
        complex& operator+=(const complex &other);

        complex normalized();

        friend
        ostream& operator<<(ostream &out, const complex &value);

        friend
        istream& operator>>(istream &in, complex &value);

        friend
        complex operator*(const complex &x, const complex &y);

        friend
        complex operator/(const complex &x, const complex &y);

        friend
        complex operator+(const complex &x, const complex &y);

        friend
        complex operator-(const complex &x, const complex &y);

        friend
        complex operator^(const complex &x, const complex &y);

        friend
        bool operator==(const complex &x, const complex &y);

        friend
        bool operator!=(const complex &x, const complex &y);

    private:
        fraction real, imag;
        void copy(const complex &other);
};

#endif // COMPLEX_H
