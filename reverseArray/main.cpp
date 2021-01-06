#include <iostream>
#include <string>

using namespace std;

char* reverseString(char* pString);
//char* reverseString - reverses the string using pointers
//@param char* pString - the address of the string array that is going to be reversed

void print(char*array);
//void print - prints an array of characters
//@param char* - the pointer which is pointing to an address
//@param - or the actual array which has the same address as the pointer
//BOTH WORK THE SAME! BOTH ARE THE SAME! EXCEPT WITH THE POINTER, WE CAN
//CHANGE THE MEMORY'S VALUE

void swap(char* firstIndex, char* lastIndex);
//void swap - swaps begining index with last until all are swapped
//@param char* - pointer pointing to address of index 0
//@param char* - pointer pointing to address of index last interesting element

char* copyString(char* pString);
//char* copyString - copies the string onto another string using pointers
//@param char* - string that will be copied

int main(int argc, char *argv[])
{

    cout<<endl;

    //Initializing our char array
    //char array is -- terminated by the NULL character, so
    //1 less than capacity to account for the NULL char

    char input[11] = "496572899";
    cout<<"NUM1: ";
    print(input);
    reverseString(input);
    cout<<"REVERSED NUM1: ";
    print(input);

    char array1[10] = "302424";
    cout<<"NUM2: ";
    print(array1);
    reverseString(array1);
    cout<<"REVERSED NUM2: ";
    print(array1);


    //MESSING WITH DYNAMIC ARRAY---
    char* dArray;
    dArray = new char[5];

    dArray[0] = '1';
    dArray[1] = '4';
    dArray[2] = '6';
    dArray[3] = '9';
    dArray[4] = '\0';

    cout<<"DYNAMIC ARRAY: ";
    print(dArray);
    reverseString(dArray);
    cout<<"DYNAMIC ARRAY REVERSED: ";
    print(dArray);

    delete [] dArray;
    dArray = NULL;

    cout<<endl<<endl;

    return 0;
}

void print(char* array)
{
    int total = strlen(array);
    for (int i = 0; i<total + 1; ++i)
    {
        cout<<*array<<" ";
        array++;
    }
    cout<<endl;
}


void swap(char* firstIndex, char* lastIndex)
{
    //swap values, but need to have a temp to hold
    //value of the first address in array after it
    //is over-rided, so we can store it at the end of
    //the array

    char temp = *firstIndex;
    *firstIndex = *lastIndex;
    *lastIndex = temp;

}

char* reverseString(char* pString)
{
    char* pStart = pString; //Initializing pointer to the address of the pString
    char* pEnd = pStart + strlen(pString) - 1; //Initializing pointer to last address of the pString

    while ( pEnd > pStart) //While the ending address is greater than the begining address
    {
        swap(pStart, pEnd);
        pStart++; //increment pointer address from begining
        pEnd--; //decrement pointer address from the end
    }
    //Once out of the loop all the contents of the char array have been swapped!
    return pString; //returns address of new pString
}



char* copyString(char* pString)
{


}

char* remove(char* pString)
{


}

