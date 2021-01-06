#include <iostream>
#include <cstring>
#include <string>

#include "addchararrays.h"


using namespace std;



int main(int argc, char *argv[])
{

    cout<<endl<<endl;

    //Initializing our char int arrays
    char firstNum[MAX] = "22225";
    char secondNum[MAX] = "224";
    char result[MAX];
    char n3[MAX] = "999999999";
    char n4[MAX] = "999999999";
    char n5[MAX] = "5559";
    char n6[MAX] = "6666";
    char n7[MAX] = "3459734";
    char n8[MAX] = "1000000";
    char n9[MAX] = "857397524";
    char n10[MAX] = "69";



    cout<<"CHAR ARRAY NUMBER 1: ";
    printArray(firstNum);
    cout<<"CHAR ARRAY NUMBER 2: ";
    printArray(secondNum);
    Add(firstNum,secondNum,result,MAX);
    cout<<"RESULT: ";
    printArray(result);
    cout<<endl;

    cout<<"CHAR ARRAY NUMBER 3: ";
    printArray(n3);
    cout<<"CHAR ARRAY NUMBER 4: ";
    printArray(n4);
    Add(n3,n4,result,MAX);
    cout<<"RESULT: ";
    printArray(result);
    cout<<endl;


    cout<<"CHAR ARRAY NUMBER 5: ";
    printArray(n5);
    cout<<"CHAR ARRAY NUMBER 6: ";
    printArray(n6);
    Add(n5,n6,result,MAX);
    cout<<"RESULT: ";
    printArray(result);
    cout<<endl;

    cout<<"CHAR ARRAY NUMBER 7: ";
    printArray(n7);
    cout<<"CHAR ARRAY NUMBER 8: ";
    printArray(n8);
    Add(n7,n8,result,MAX);
    cout<<"RESULT: ";
    printArray(result);
    cout<<endl;

    cout<<"CHAR ARRAY NUMBER 9: ";
    printArray(n9);
    cout<<"CHAR ARRAY NUMBER 10: ";
    printArray(n10);
    Add(n9,n10,result,MAX);
    cout<<"RESULT: ";
    printArray(result);
    cout<<endl;



    return 0;
}
