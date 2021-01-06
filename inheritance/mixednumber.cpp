#include "mixednumber.h"

mixedNumber::mixedNumber()
{
}

mixedNumber::~mixedNumber()
{
}

mixedNumber& mixedNumber::operator=(const fraction& other)
{
    this->num = other.getNum();
    this->denom = other.getDenom();
    return *this;
}

mixedNumber::mixedNumber(int w, int n, int d )
{
    setValue(w,n,d);
}

void mixedNumber::setValue(int w, int n, int d)
{
    fraction::setValue(w*d+n,d);
}

istream& operator>>(istream &in, mixedNumber &me)
{

}


ostream& operator<<(ostream &out, const mixedNumber &me)
{
    int whole = me.num/me.denom, newNum = abs(me.num)%me.denom;
    if(newNum == 0)
        out<<whole;
    else
    {
        if(whole != 0)
            out<<whole;
    }
   if(abs(me.num) != 0)
       out<<" "<<newNum<<"/"<<me.denom;
   return out;
}
