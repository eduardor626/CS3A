#include <iostream>
#include <cstring>
#include <string>
#include "addchararrays.h"

using namespace std;

//Function Definitions----------------------------------

void printArray(const char array[])
{
    cout<<array<<endl;
}


void reverseArray(char sourceArray[])
{
    //Setting up a temporary array that we will make
    //the reverse of the source array
    char tempArray[MAX];
    int total = strlen(sourceArray); //getting num of (real) elements in char array
    //excluding the NULL char
    for (int i = 0; i<total; ++i)
    {
        tempArray[i] = sourceArray[total-1-i];
    }
    tempArray[total] = '\0'; //setting the last index to NULL
    strcpy(sourceArray,tempArray);//copying the temp array back onto the source so that it
                                  //is now reversed
}


void inputZeros(char sourceArray[]){

    //strlen( ) - gives number of elements in string
    int total = strlen(sourceArray); //Getting the length of the array we want to store
    for( int index = 0; index<MAX-1; index++){
        //START: [0] ----> ENDS: [MAX ARRAY SIZE-2]
        if(index >= total)
        {
            //Once we get out of that if statement
            sourceArray[index] = '0'; //Sets the remaining characters to '0' after the integer characters
                                      //padding the array
        }

    }
    sourceArray[MAX - 1] = '\0'; //Sets destinationArray[MAX-1] = NULL terminating character
                                //ends the char array

}

void takeOutZeros(char sourceArray[])
{
    char tempArray[MAX];
    int total = strlen(sourceArray);//num of elements in array (excluding NULL)
    int counter = 0, i = 0;//counter will count how many 0's until the first nonzero
    while( sourceArray[i] == '0')
    {
        ++i;
        counter++;
    }

    int k = 0;//start new temp array at index zero
    //we start at index of first non zero element
    //from the source array (which is the one we want!)
    for(int j = counter; j<total+1; ++j)
    {

        tempArray[k] = sourceArray[j];
        k++;//incrementing until we get out of the loop and we are done copying
            //everything that we need onto the temp array
    }
    //finally we copy the temp array onto the source array
    //and change the source array completely since arrays are always passed by reference
    strcpy(sourceArray,tempArray);
    //now the source array is the array we want without the padding!!


}


void Add(char num1[], char num2[], char result[], int base){

//    cout<<"CHAR ARRAY NUMBER 1 REVERSED AND PADDED: ";
    reverseArray(num1);
    inputZeros(num1);
//    printArray(num1);

//    cout<<"CHAR ARRAY NUMBER 2 REVERSED AND PADDED: ";
    reverseArray(num2);
    inputZeros(num2);
//    printArray(num2);

    int total = 0;//Initializing
    for( int i = 0; i < base-1; i++){
        //STARTS: [0] ----->ENDS: [9]
         total += (num1[i] - '0') + (num2[i] - '0'); // - '0' to get the char as int
         if ( total >= 10){
             total = total - 10; //getting the single value we want less than 10
             result[i] = total + '0'; // + '0' to convert int back to char
             total = 1; //carries the extra 1 back to the top to add to the next addition
         }
         else
         {
             result[i] = total + '0'; //total less than 10 so we convert single int back to char
             total = 0; //reset total as it goes back to the top of the for loop
         }
        }

//    cout<<"CHAR ARRAY 1 AND 2 ADDED: ";
//    printArray(result);

//    cout<<"CHAR ARRAY 1 AND 2 REVERSED: ";
    reverseArray(result);
//    printArray(result);

//    cout<<"RESULT: ";
    takeOutZeros(result);
}


void reverseArray(char sourceArray[], char destArray[MAX]){

    int total = strlen(sourceArray); //Getting the length of the array we want to store
    cout<<"TOTAL STRLEN = "<<total<<endl;
    for( int index = 0; index<MAX-1; index++){
    //START: [0] ----> ENDS: [9]
        if(index < total){ //if [index] < length of array
            destArray[index] = sourceArray[total - 1 - index];
            //destinationArray[0] = sourceArray[length - 1 - 0]
            //sourceArray[length - 1] is the last element in the sourceArray
            //and we store that as the first element in destinationArray
        }
        else{
            //Once we get out of that if statement
            destArray[index] = '0'; //Sets the remaining characters to '0' after the integer characters
        }

    }
    destArray[MAX - 1] = '\0'; //Sets destinationArray[MAX-1] = terminating character, ends the char array


}

void reverseResult(char sourceArray[], char resultArray[]){
    int total = strlen(sourceArray); //get the length of the @sourceArray
    char tempArray[total]; //Initializing our @tempArray
    int counter = 0; //Initializing a counter
    for( int i = 0; i<MAX-1; i++){
        //STARTS: [0] ----> ENDS[8]:
        if(i < total){//Using the same reverse method we used in ReverseArray
            tempArray[i] = sourceArray[total - 1 - i];
        }
    }

    tempArray[MAX - 1] = '\0'; //Sets tempArray[9] = terminating character, ends the char array

    //Now we reversed the array but we still have an issue, we have to take out all the 0's until
    //the very first non '0' char

    //WE SOLVE BY:
    for( int i = 0; i<MAX-1; i++){ //Iterates throughout the whole array
        if ( tempArray[i] != '0' || counter < i){
            //if the values of the array at each index do not equal '0'
            // counter will always be = to index until the tempArray[i] = to non 0 char
            resultArray[i - counter] = tempArray[i];
        }
        else{
            counter++; //increments counter so it is always equal to the index
        }
    }
    resultArray[total - counter] = '\0';
}




