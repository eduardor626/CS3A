#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;


class fraction
{
private:
    long long whole,numer, denom;
public:
    //CONSTRUCTORS:
    fraction ( );
    fraction ( int a);
    fraction ( int a, int b);
    fraction ( int a, int b, int c);
    fraction ( double a);
    fraction (double a, double b);

    //TODO
//    fraction (int, fraction);
//    fraction (fraction, int);
    //****

    fraction (const fraction &other);

    //CLASS FUNCTIONS:
//    int getWhole () const;
    int getNumer () const;
    int getDenom () const;
    int gcd ( int a, int b );
//    void setWhole (int a);
    void setNumer (int b);
    void setDenom (int c);
    void getNewDenom(int numer, int &a);

    void getInput ( string title, int &a, int restriction);
    long long int getLog (double a, const long double epsi);
    void reduce();
    void display ();

    //BASIC CLASS OPERATORS:
    fraction& operator+= (const fraction other);
    fraction& operator-= (const fraction other);
    fraction& operator*= (const fraction other);
    fraction& operator/= (const fraction other);
    fraction& operator=  (const fraction other);
    fraction& operator=  (int a);
    fraction& operator =  (double a);

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
};

#endif // FRACTION_H


