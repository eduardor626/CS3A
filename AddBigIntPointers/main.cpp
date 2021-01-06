#include <iostream>

using namespace std;


const int MAX = 20;


void print(char*array);
//void print - prints an array of characters
//@param char* - the pointer which is pointing to an address
//@param - or the actual array which has the same address as the pointer
//BOTH WORK THE SAME! BOTH ARE THE SAME! EXCEPT WITH THE POINTER, WE CAN
//CHANGE THE MEMORY'S VALUE

char* reverseString(char* pString);
//char* reverseString - reverses the string using pointers
//@param char* pString - the address of the string array that is going to be reversed

void swap(char* firstIndex, char* lastIndex);
//void swap - swaps begining index with last until all are swapped
//@param char* - pointer pointing to address of index 0
//@param char* - pointer pointing to address of index last interesting element

void inputZeros(char* sourceArray);
//inputZeros - pads the whole array until the maximuim number of elements with zeros
//@param char sourceArray - the array that gets padded with 0's unti the end

char* Allocate(int size);
//char* Allocate - creating a dynamic array
//@param int size - the capacity of the dynamic array

char *Add(char* array1, char* array2, int base);
//void Add - adds two character arrays
//@param char* array1 - first char array to be added
//@param char* array2 - second char array to be added
//@param int base - base at which they are added


int main(int argc, char *argv[])
{
    cout <<endl<<endl;

    char ARRAY1[MAX] = "4";
    char ARRAY2[MAX] = "5";
    print(ARRAY1);
    print(ARRAY2);

    reverseString(ARRAY1);
    reverseString(ARRAY2);

    inputZeros(ARRAY1);
    inputZeros(ARRAY2);
    print(ARRAY1);
    print(ARRAY2);

    char* result = Add(ARRAY1,ARRAY2,MAX);
    print(result);


    delete [] result;

    cout<<endl<<endl;
    return 0;
}




void print(char* array)
{
    int total = strlen(array);
    for (int i = 0; i<MAX; ++i) //WAS TOTAL +1
    {
        cout<<*array<<" ";
        array++;
    }
    cout<<endl;
}

char* Allocate(int size)
{
    char* result = new char[size];
    return result;
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


void inputZeros(char* sourceArray)
{

    //strlen( ) - gives number of elements in string
    int total = strlen(sourceArray); //Getting the length of the array we want to store
    char* firstPt = sourceArray;
    for( int index = 0; index<MAX-1; index++){
        //START: [0] ----> ENDS: [MAX ARRAY SIZE-2]

        if(index >= total)
        {
            //Once we get out of that if statement
            *firstPt = '0'; //Sets the remaining characters to '0' after the integer characters
                                      //padding the array
        }
        firstPt++;
    }

}

char* Add(char* array1, char* array2, int base){
    int total = 0;//Initializing
    char* dArray = new char[base];
    char* pt1 = array1;
    cout<<"PT1 DEREFERENCED AT: "<<*pt1<<endl;
    char* pt2 = array2;
    cout<<"PT2 DEREFERENCED AT: "<<*pt2<<endl;
    for( int i = 0; i < base; i++){
         total += (*pt1 - '0') + (*pt2 - '0'); // - '0' to get the char as int
         if ( total >= 10){
             total = total - 10; //getting the single value we want less than 10
//             result[i] = total + '0'; // + '0' to convert int back to char
             *dArray = total + '0';
             total = 1; //carries the extra 1 back to the top to add to the next addition
         }
         else
         {
//             result[i] = total + '0'; //total less than 10 so we convert single int back to char
             *dArray = total + '0';
             total = 0; //reset total as it goes back to the top of the for loop
         }
         dArray++;
        }
    return dArray;
}
