#ifndef FUNCTIONPOINTERS_H
#define FUNCTIONPOINTERS_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

typedef void (*fptr)(int &, int &);
//takes two integers passed by reference and is a function pointer
//pointing to type void functions

typedef void (*fptr1)(int [], int &);
//function pointer, that points to void functions that take in
//two parameters, both passed by reference
//ALL functions this points to have to have the same parameters

int sizeOfArray();
//Getting the size of the array that the user wishes to work with
//returns an int

void initializeArray(int list[], int size);
//setting up and filling an array[], and making it the size that
//the user input for int sizeOfArray();

void menu();
//Displays the menu and options for the user

int choice();
//getting the users choice from the menu list

void display(int list[], int &size);
//Displays an array of integers, takes in the size of the array

void swap(int &x, int &y);
//function that swaps two integer types with eachothers value

void noSwap(int &x, int &y);
//function that doesnt swap two integer types
//does not change x or y

void sort(int list[], int &size);
//A function to sort an array of integers that has size elements in it

double median(int list[] , int size);
//Prints the median of the array list, takes in the size of the array


double mean(int list[], int size);
//prints the mean of an array of integers by using the elements themselves
//and the number of elements in the array

double standardDev(int list[] , int size);
//prints the standard deviation of a list of numbers

void regenerate(int list[], int &size);
//letting the user regenerate a list of random numbers
//and pick a new size

void quit(int list[], int &size);
//quit function that terminates program after delete dynamica array

void destroy(int list[], int &size);
//destorys a dynamic array

void showMean(int list[], int &size);//displays mean
void showMedian(int list[], int &size);//displays median
void showStandardDev(int list[], int &size);//displays the standard deviation

void processEvents(int list[], int &size);
//does all operations user chooses to do

bool output(const char *title, int list[], int &size, fptr1 whatToDo);
//boolean function that lets us compare with other boolean in processEvents


bool takeCareOfBusiness(double &total, int list[], int size);
bool takeCareOfBusiness2(double &total, int list[], int size);
//these two functions still need work




#endif //FUNCTIONPOINTERS_H
