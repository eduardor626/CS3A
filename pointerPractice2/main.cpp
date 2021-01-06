#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>

using namespace std;

bool getInput(int &size,int &min, int &max);
void  generateRandomNumbers(int* &list, int size, int min, int max);
void display(char *title, int *list, int size);
void sort(int *list, int size);
void swap(int &x, int &y);

int main()
{
    srand(time(NULL));
    int *list, size, min, max;
    while(getInput(size, min, max))
    {
        generateRandomNumbers(list,size,min, max);
        display("Unsorted list:", list, size);
        sort(list,size);
        display("Sorted list:", list, size);
        //always HAVE to make sure we delete the allocated memory from
        //the heap!
        delete [] list;
    }
    return 0;
}


bool getInput(int &size,int &min, int &max)
{
    string line;
    stringstream ss;
    cout<<"How many random numbers do you want? ";
    getline(cin, line);
    if(line.empty())
        return false;
    ss<<line;
    ss>>size;
    cout<<"What is the smallest value to display? ";
    getline(cin, line);
    if(line.empty())
        min = 0;
    else
    {
        ss.clear();
        ss<<line;
        ss>>min;
    }
    cout<<"What is the largest value to display? ";
    getline(cin, line);
    if(line.empty())
        max = 100;
    else
    {
        ss.clear();
        ss<<line;
        ss>>max;
    }
    return true;
}

//pass by reference the integer pointer because we will be changing
//the contents of it
void  generateRandomNumbers(int* &list,int size,int min, int max)
{

    //creating a dynamic array and allocating memory in the heap
    list = new int[size];
    for(int i = 0; i < size; i++)
        list[i] = min + (rand()%max);
}
//not passing by reference because we are just printing and integer pointer
//pointers & arrays go hand in hand
void display(char *title, int* list, int size)
{

    cout<<endl<<title<<endl;
    for(int i = 0;i<size;++i)
        cout<<list[i]<<" ";
    cout<<endl<<endl;
}

void sort(int *list, int size)
{
    //sorting values of integer pointer, pointing to
    //integer arrat
    for(int i = 0; i < size; i++)
      for(int j = 0; j < size; j++)
          if(*(list+i) < list[j])
              swap(list[i], *(list+j));
}

void swap(int &x, int &y)
{
    //swapping values
    int temp = x;
    x = y;
    y = temp;
}
