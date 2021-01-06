#include <iostream>
#include "mixednumber.h"

using namespace std;

int main(int argc, char *argv[])
{


    mixedNumber number(3,3,4), another(2,2,3), yan;
    yan = number+another;
    cout <<number<<" + "<<another<<" = "<<yan << endl;
    return 0;
}
