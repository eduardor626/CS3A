#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>


using namespace std;

//PROTOTYPES

void swapInts(int *one, int *two);
//void swapInts - changes the value of both variables with the other using pointers
//@param int - first variable that will get the integer value of two
//@param int - second variable that will get the inter value of one

int *addInts(int *one, int *two);
//int *addInts - Adds two integer pointers, returns a pointer to an integer.
//int *one - first pointer to integer that gets added
//int *two - second pointer to integer that gets added

int *subInts(int *one, int *two);
//int *subInts - Subtracts two integer pointers, returns a pointer to an integer.
//int *one - first pointer
//int *two - second pointer

int *multInts(int *one, int *two);
//int *multInts - Multiplies two integer pointers, returns a pointer to an integer.
//int *one - first pointer
//int *two - second pointer

int *divInts(int *one, int *two);
//int *divInts - Divides two integer pointers, returns a pointer to an integer.
//int *one - first pointer
//int *two - second pointer

bool getInput(int n1, int n2);
//bool getInput - takes care of the input process until user wants to exit

void display(int num1, int num2);
//void display - prints all the operations


int main(int argc, char *argv[])
{
    cout<<endl<<endl;

    //Create a getInput function to allow user input

    display(12,30);
    display(20,500);
    display(1,100);
    display(45,50);
    display(55,40);
    display(5000,5000);
    display(44,1000);
    display(0,777);

    return 0;
}


//DEFINITIONS

void swapInts(int *one, int *two){
    int temp = *one;
    *one = *two;
    *two = temp;
}

//Static keeps the value on the stack during the delete process of the stack that
//usually happens once the function is deleted

//Static variable - is one that is not seen outside the function in which it is declared but which
//remains until the program terminates. It also means that the value of the variable persists
//between successive calls to a function.


int *addInts(int *one, int *two){
    int *total;
    static int temp;
    temp = *one + *two;
    total = &temp;
    return total;
}

int *subInts(int *one, int *two){
    int *total;
    static int temp; //static is only executed once, then the next time the
                     //the function is called, it skips the line where static is
    temp = *one - *two;
    total = &temp;
    return total;
}


int *multInts(int *one, int *two){
    int *total;
    static int temp;
    temp = (*one * *two);
    total = &temp;
    return total;

}

int *divInts(int *one, int *two){
    int *total;
    static int temp;
    temp = (*one / *two);
    total = &temp;
    return total;
}


void display(int num1, int num2){

    int *sum , *sub, *mult, *div;
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;
    cout<<"NUM1: "<<num1<<endl;
    cout<<"NUM2: "<<num2<<endl;
    cout<<"AFTER SWAP"<<endl;
    swap(ptr1,ptr2);
    cout<<"NUM1: "<<*ptr1<<endl;
    cout<<"NUM2: "<<*ptr2<<endl;

    sum = addInts(ptr1, ptr2);
    cout<<"ADD: "<<*sum<<endl;

    sub = subInts(ptr1, ptr2);
    cout<<"SUB: "<<*sub<<endl;

    mult = multInts(ptr1,ptr2);
    cout<<"MULT: "<<*mult<<endl;

    div = divInts(ptr1, ptr2);
    cout<<"DIVIDED: "<<*div<<endl;

    cout<<endl<<endl;

}



