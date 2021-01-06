#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

class fraction
{
  public:
    //Constructors
        fraction(); // The "DEFAULT" constructor
        fraction(int n); //The "one argument" constructor
        fraction(int n, int d); //The "two argument" constructor
        fraction(double x);
    //Destructor
        ~fraction(); //Destructor
    //Copy constructor
        fraction(const fraction &other);//Copy constructor
    //Assignment Operators
        fraction& operator=(const fraction &other);//Assignment operator
    //Assignment operators that also...
        fraction& operator+=(const fraction &other);//add someone to me
        fraction& operator-=(const fraction &other);//subtracts someone to me
        fraction& operator*=(const fraction &other);//multiplies someone to me
        fraction& operator/=(const fraction &other);//divides someone to me
    //Class member operators
        fraction operator-() const; //Make the fraction negative
        fraction operator^(int x); //Return the inverse of the fraction
    //Coversion
        double toDouble();
    //Accessor functions
        int getNum() const;
        int getDenom() const;
    //Mutator function
        void setValue(int n, int d);
    //Display function
        void display();


        friend
        istream& operator>>(istream &in, fraction &me);

        friend
        ostream& operator<<(ostream &out, const fraction &me);

        friend
        fraction operator*(const fraction &a, const fraction &b);

        friend
        fraction operator/(const fraction &a, const fraction &b);

        friend
        fraction operator+(const fraction &a, const fraction &b);

        friend
        fraction operator-(const fraction &a, const fraction &b);

        friend
        bool operator!=(const fraction &a, const fraction &b);

        friend
        bool operator==(const fraction &a, const fraction &b);

        friend
        bool operator>=(const fraction &a, const fraction &b);

        friend
        bool operator<=(const fraction &a, const fraction &b);

        friend
        bool operator>(const fraction &a, const fraction &b);

        friend
        bool operator<(const fraction &a, const fraction &b);

    protected:
        int num, denom;
        void reduce();
        void fromDouble(double x);
        void copy(const fraction &other);

    private:
        int gcd(int p, int q);
};

#endif // FRACTION_H
