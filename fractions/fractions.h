#ifndef FRACTIONS_H
#define FRACTIONS_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

class fraction
{
  public:
        fraction(); // The "DEFAULT" constructor
        fraction(int n); //The "one argument" constructor
        fraction(int n, int d); //The "two argument" constructor
        ~fraction(); //Destructor
        fraction(const fraction &other);//Copy constructor
        fraction& operator=(const fraction &other);//Assignment operator

        fraction& operator+=(const fraction &other);//add someone to me
        int getNum() const;
        int getDenom() const;
        void setValue(int n, int d);
        void display();

        friend
        ostream& operator<<(ostream &out, const fraction &me);

    private:
        int num, denom;
        int gcd(int p, int q);
        void reduce();
};

#endif // FRACTIONS_H
