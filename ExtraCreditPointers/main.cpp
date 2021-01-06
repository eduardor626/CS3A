#include <iostream>
using namespace std;

//Write a simple program where you declare some pointers of various types (int, char, etc.)
//Point these pointers to various variables, arrays, and each other, increment and decrement
//these pointers, dereference and print them.


//Constants ---------------------
const int MAX = 10;

//Function Declarations -----------------
void printPointerValue(int* pointer);
//- print pointer values in function

void printArray(int array[]);
//- printing an array

int main(int argc, char *argv[])
{

    cout<<endl<<endl;

    //A POINTER is a special kind of variable that POINTS to a memory address
    //POINTER = contains a memory address as a value
    //Format: datType* pointerName;

    //only need to put the * (asterisk) once , when declaring the pointer
    //after that C++ will memorize it
    //& - is ampersand operator the address
    //& - the memory address of where the variable is
    //*pointerName - dereferencing to get the varaible from the address

    cout<<"==== ARRAYS AND POINTER INCREMENTING/DECREMENTING ====="<<endl<<endl;

    int array1[MAX];
    cout<<"ARRAY 1 IS: ";
    for (int i = 0; i<MAX; ++i)
    {
        array1[i] = 5;
        cout<<array1[i]<<" ";
    }
    cout<<endl;

    int* ptr1;
    ptr1 = array1;
    cout<<"ARRAY ADDRESS : "<<array1<<endl;
    cout<<"POINTER1 ADDRESS : "<<ptr1<<endl;
    cout<<"POINTER1 VALUE OF FIRST DIGIT : "<<*ptr1<<endl;
    *ptr1 = 30;
    cout<<"FIRST DIGIT CHANGED TO : "<<*ptr1<<endl;
    printArray(array1);
    ptr1++;
    *ptr1 = 40;
    cout<<"SECOND DIGIT CHANGED TO : "<<*ptr1<<endl;
    printArray(array1);
    ptr1++;
    *ptr1 = 50;
    cout<<"THIRD DIGIT CHANGED TO : "<<*ptr1<<endl;
    printArray(array1);
    ptr1+=3;
    *ptr1 = 80;
    cout<<"6TH DIGIT CHANGED TO : "<<*ptr1<<endl;
    printArray(array1);
    ptr1--;
    *ptr1 = 70;
    cout<<"5TH DIGIT CHANGED TO : "<<*ptr1<<endl;
    printArray(array1);
    *ptr1 += 5;
    cout<<"ADDING THE 5TH DIGIT BY 5 : ";
    printArray(array1);
    cout<<"SETTING ARRAY BACK TO 0's : ";
    for( int e = 0; e<MAX; ++e)
    {
        array1[e] = 0;

    }
    printArray(array1);
    cout<<endl<<endl;



    cout<<"==== DYNAMIC ARRAYS ===== "<<endl;

    int* newPointer;
    newPointer = new int[MAX];
    newPointer[0] = 6;
    newPointer[1] = 8;
    newPointer[2] = 11;
    newPointer[3] = 9;

    cout<<"NEW ARRAY : ";
    for(int j = 0; j< 4; j++)
    {
        cout<<newPointer[j]<<" ";
    }
    cout<<endl;
    delete []newPointer;

//    for ( int n =0; n<4; n++)
//    {
//        cout<<newPointer[n]<<" ";
//        delete []newPointer;
//    }
    cout<<"DELETED ARRAY : GIVES US ERROR BC MEMORY DEALLOCATED AFTER DELETE!"<<endl<<endl;


    cout<<"==== INTEGER ARITHMETIC ==== "<<endl;

    int num1 = 25, num2 = 100;
    int* ptr2;
    int* ptr3;
    ptr2 = &num1;
    ptr3 = &num2;

    cout<<"NUM1 : "<<num1<<endl;
    cout<<"NUM2 : "<<num2<<endl;

    cout<<"POINTER2 VALUE : "<<*ptr2<<endl;
    cout<<"POINTER3 VALUE : "<<*ptr3<<endl;

    *ptr2 = *ptr3;
    cout<<"POINTER2 VALUE EQUAL TO POINTER3 VALUE : "<<*ptr2<<" = "<<*ptr3<<endl;

    *ptr2 = 50;
    cout<<"CHANGING POINTER2 VALUE TO : "<<*ptr2<<endl;
    *ptr2 -= 5;
    cout<<"POINTER2 MINUS 5 : "<<*ptr2<<endl;

    cout<<"ADDRESS OF NUM1 : "<<&num1<<endl;
    cout<<"ADDRESS OF POINTER2 : "<<ptr2<<endl;
    cout<<"ADDRESS OF NUM2 : "<<&num2<<endl;
    cout<<"ADDRESS OF POINTER3 : "<<ptr3<<endl;

    cout<<endl<<endl;

    return 0;
}


//Function Definitions --------------------

void printPointerValue(int* pointer)
{
    cout<<*pointer<<endl;

}

void printArray(int array[])
{

    for (int i = 0; i<MAX; ++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

}

