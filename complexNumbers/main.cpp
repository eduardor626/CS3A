#include <iostream>
#include <sstream>

#include "complex.h"

using namespace std;


int main(int argc, char *argv[])
{
    cout<<endl<<endl;
    //creating fraction types
    fraction number1(2,1) , number2(3,1) ;
    fraction number3(1,1), number4(2,1);
    //taking in doubles as fractions
    fraction decimal1(1.5), decimal2(5.50,2.25);

    //complex types
    complex firstInput, secondInput;
    complex num1(decimal1);
    complex num2(decimal2, 2);
    complex num3(10,15);
    complex num4(7,33);

    // cout<<"You entered: "<<number2<<endl;
    cout<<"ADDING REAL AND COMPLEX NUMBERS\n";
    cout<<"===== NUM1 = "<<num1<<"   NUM2 = "<<num2<<" =====\n";
    cout<<num1<<" + "<<num2<<" = "<<num1+num2<<endl;
    cout<<num1<<" - "<<num2<<" = "<<num1 - num2<<endl;
    cout<<num1<<" * "<<num2<<" = "<<num1 * num2<<endl;
    cout<<num1<<" / "<<num2<<" = "<<num1 / num2<<endl;


    cout<<"ADDING TWO COMPLEX NUMBERS\n";
    cout<<"===== NUM3 = "<<num3<<"   NUM4 = "<<num4<<" =====\n";
    cout<<num3<<" + "<<num4<<" = "<<num3+num4<<endl;
    cout<<num3<<" - "<<num4<<" = "<<num3 - num4<<endl;
    cout<<num3<<" * "<<num4<<" = "<<num3 * num4<<endl;
    cout<<num3<<" / "<<num4<<" = "<<num3 / num4<<endl;

    cout<<"Please enter a complex number: ";
    cin>>firstInput;
    cout<<"Please enter a second complex number: ";
    cin>>secondInput;
    cout<<firstInput<<" + "<<secondInput<<" = "<<firstInput+secondInput<<endl;
    cout<<firstInput<<" - "<<secondInput<<" = "<<firstInput-secondInput<<endl;
    cout<<firstInput<<" * "<<secondInput<<" = "<<firstInput*secondInput<<endl;






    cout<<endl<<endl;

    return 0;
}




