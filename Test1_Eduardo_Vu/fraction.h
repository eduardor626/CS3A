#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>

enum FRACTION_ERRORS  {DEVIDED_BY_ZERO, DENOMINATOR_EQUALS_TO_ZERO};

using namespace std;
class fraction
{
public:
    //CONSTRUCTORS:
    fraction ( );
    fraction ( int a);
    fraction ( int a, int b);
    fraction ( int a, int b, int c);
    fraction (const fraction &other);
    fraction ( double a);
    fraction (double a, double b);


    //SETTERS and GETTERS:
    void setNumer (int b);
    void setDenom (int c);
    int getNumer () const;
    int getDenom () const;



    //CLASS FUNCTIONS:
    void reduce();
    int gcd ( int a, int b );
    void display ();
    void copy(const fraction &other);


    //BASIC CLASS OPERATORS:
    fraction& operator+= (const fraction &other);
    fraction& operator-= (const fraction &other);
    fraction& operator*= (const fraction &other);
    fraction& operator/= (const fraction &other);
    fraction& operator=  (const fraction &other);
    fraction& operator=  (int a);
    fraction& operator=  (double a);

    //BASIC FRIEND OPERATORS;
    friend
    fraction operator+(const fraction &first, const fraction &second);
    friend
    fraction operator-(const fraction &first, const fraction &second);
    friend
    fraction operator*(const fraction &first, const fraction &second);
    friend
    fraction operator/(const fraction &first, const fraction &second);

    //FRIEND I/O OPERATORS:
    friend
    istream& operator>>(istream &in, fraction &me);
    friend
    ostream& operator<<(ostream &out, const fraction &me);

    //FRIEND LOGICAL OPERATORS:
    friend
    bool operator!=(const fraction &first, const fraction &second);
    friend
    bool operator==(const fraction &first, const fraction &second);
    friend
    bool operator>=(const fraction &first, const fraction &second);
    friend
    bool operator<=(const fraction &first, const fraction &second);
    friend
    bool operator>(const fraction &first, const fraction &second);
    friend
    bool operator<(const fraction &first, const fraction &second);

    //FRIEND LOGICAL OVERLOAD OPERATORS:
    friend
    bool operator==(const fraction &first, int a);
    friend
    bool operator!=(const fraction &first, int a);
    friend
    bool operator>=(const fraction &first, int a);
    friend
    bool operator<=(const fraction &first, int a);
    friend
    bool operator<(const fraction &first, int a);
    friend
    bool operator>(const fraction &first, int a);

private:
    int whole,numer, denom;
};

#endif // FRACTION_H
