#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "functionpointers.h"


using namespace std;

//creating a dynamic array and allocating memory in the heap
//size of the dynamic array is the size user inputs for size
//new int --> integer type memory , whatever we create we must destroy when we are done

int main(int argc, char *argv[])
{
    cout<<endl;

    int size; //Initializing our integer variables
    size = sizeOfArray(); //storing size of the array in size
    int *dArray; //initializing integer pointer
    dArray = new int[size];

    initializeArray(dArray, size); //Generating random numbers into an array
    display(dArray,size); //Displaying the set of random numbers
    processEvents(dArray,size); //All options/events that are executed in program
    destroy(dArray,size); //Destroying our array in case user gets out of
                          //processEvents without properly exiting

    cout<<"Exiting..."<<endl;

    return 0;
}

