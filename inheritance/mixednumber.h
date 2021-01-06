#ifndef MIXEDNUMBER_H
#define MIXEDNUMBER_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <fstream>
#include "fraction.h"

using namespace std;

class mixedNumber : public fraction
{
    public:
        mixedNumber();
        mixedNumber(int w, int n=0, int d=1);
        ~mixedNumber();
    //Assignment operators that also...
        void setValue(int w, int n, int d);
        mixedNumber& operator=(const fraction& other);

        friend
        istream& operator>>(istream &in, mixedNumber &me);

        friend
        ostream& operator<<(ostream &out, const mixedNumber &me);

    private:

        void copy(const mixedNumber &other);
};

#endif // MIXEDNUMBER_H
