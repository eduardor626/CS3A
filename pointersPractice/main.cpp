#include <iostream>
#include <cstdlib>

using namespace std;

void printWithPtr(int *ptr, int size);
void printArray(int list[], int size);
void printCombined(int *ptr,int size);
void printViaPtr(int list[],int size);

int main()
{
    int list[10] = {0,1,2,3,4,5,6,7,8,9},
        *listPtr = list;
    printWithPtr(listPtr,10);
    printArray(list,10);
    printWithPtr(list,10);
    printArray(listPtr,10);
    printCombined(list,10);
    printCombined(listPtr,10);
    printViaPtr(list,10);
    return 0;
}


void printWithPtr(int *ptr, int size)
{
    cout<<"Printing a list via a pointer:"<<endl;
    for(int i = 0; i < size; i++)
        cout<<"list["<<i<<"] = "<<*(ptr+i)<<endl;
    cout<<endl;
}


void printArray(int list[], int size)
{
    cout<<"Printing a list the usual way:"<<endl;
    for(int i = 0; i < size; i++)
        cout<<"list["<<i<<"] = "<<list[i]<<endl;
    cout<<endl;
}

void printCombined(int *ptr,int size)
{
    cout<<"Passing one way, print the other:"<<endl;
    for(int i = 0; i < size; i++)
        cout<<"list["<<i<<"] = "<<ptr[i]<<endl;
    cout<<endl;
}

void printViaPtr(int list[],int size)
{
    cout<<"Printing with pointers:"<<endl;
    for(int *ptr = list; ptr-list < size ; ptr++)
        cout<<"list["<<(ptr-list)<<"] = "<<*ptr<<endl;
    cout<<endl;
}
