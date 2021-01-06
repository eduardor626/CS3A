#ifndef ADDCHARARRAYS_H
#define ADDCHARARRAYS_H

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//CONSTANTS------------------------------------------------------
const int MAX = 12;

//FUNCTION DECLARATIONS-------------------------------------------

void printArray(const char array[]);
//printArray - prints the array that is fed into it
//@param const char array - array that is going to be printed

//Overloaded function
void reverseArray(char sourceArray[]);
//reverseArray - reverses an character array passed into it
//@param char sourceArray - the array that will be reversed

void reverseArray(char sourceArray[], char destArray[MAX]);
//reverseArray - reverses an character array passed into it
//@param char sourceArray - the array that will be reversed
//@param char destArray - array that will be the resulting array

void inputZeros(char sourceArray[]);
//inputZeros - pads the whole array until the maximuim number of elements with zeros
//@param char sourceArray - the array that gets padded with 0's unti the end

void takeOutZeros(char sourceArray[]);
//takeOutZeros - takes out the first zeros of a padded array until hitting the first nonzero int
//@param char sourceArray - array that will be modified
//Ex: 0000549 ---> 549


void Add(char num1[], char num2[], char result[], int base);
//Add - adds two character numbers, and gives result
//@param char num1 - first character array of integers to be added
//@param char num2 - second character array of integers to be added
//@param char result - final sum of both character integer arrays
//@param int base - is the size of the array

void reverseResult(char sourceArray[], char resultArray[]);
//After we get our resulting array from the Add function we have to
//reverse it again and store the result in @resultArray which
//is in the correct format that we want


#endif // ADDCHARARRAYS_H
