#include <iostream>
#include <cstdlib>
#include <ctime>
#include "smartArray.h"

using namespace std;

int main()
{
    cout<<endl<<endl;
    srand(time(0));
    try
    {
        smartArray<int> list(20);
        for(int i = 0; i < 20; ++i)
            list[i] = rand()%20;
        cout<<"List: "<<list<<endl;
        smartArray<int> list2(list);
        list.sort();
        list2.swap(list);
        cout<<"List: "<<list<<endl;
        cout<<"List2: "<<list2<<endl;
    }
    catch(SMARTARRAY_ERRORS e)
    {
        cout<<"Error ";
        switch(e)
        {
          case FULL: cout<<"SMART ARRAY FULL ";
                     break;

          case EMPTY: cout<<"SMART ARRAY EMPTY";
                      break;
          case INDEX_OUT_OF_BOUNDS: cout<<"SMART ARRAY INDEX OUT OF BOUNDS";
                      break;
          case INVALID_INPUT: cout<<"SMART ARRAY INVALID INPUT";
        }
        cout<<" occurred"<<endl;
    }
    return 0;
}
