#include <iostream>
#include <iomanip>
#include <ctime>
#define SIZE 10 //we will have a 10x10 (n,m) matrix

using namespace std;

void initialize(bool graph[][SIZE], uint size);
void printGraph(bool graph[][SIZE], uint size);



int main()
{
    bool graph[SIZE][SIZE];
    srand(time(NULL));
    cout <<setfill('*')<<setw(10)<<"Eduardo\n";
    cout <<setfill(' ')<<setw(10)<<"Rocha\n";
    cout<<"===================\n\n";
    cout<<setw(7)<<"Bob\n";
    cout<<"Bob"<<endl;
    cout<<setfill('-')<<setw(6)<<1<<endl;
    cout<<setfill('-')<<setw(6)<<12<<endl;
    cout<<setfill('-')<<setw(6)<<123<<endl;
    cout<<setfill('-')<<setw(6)<<1234<<endl;
    cout<<setfill('-')<<setw(6)<<12345<<endl;
    cout<<setfill('-')<<setw(6)<<123456<<endl;
    cout<<setfill('-')<<setw(6)<<1234567<<endl;
    cout<<"Bob"<<endl;
    cout<<"===================\n\n";
    cout<<setw(10)<<"Eduardo"<<setfill('-')<<endl;
    cout<<setw(10)<<"Rocha"<<setfill('-')<<endl;
    cout<<setw(10)<<"Yee"<<setfill('-')<<endl;
    cout<<setfill('.')<<setw(10)<<"Eduardo"<<endl;
    cout<<setw(10)<<"1"<<setfill('-')<<endl;
    cout<<setw(10)<<"Eduardo"<<endl;
    cout<<setfill(' ')<<setw(10)<<"Rocha"<<endl;
    cout<<"===================\n";
    cout<<"CREATING 2D TABLE OF ALIGNED VALUES\n\n";

    for(unsigned int i = 0; i<10; ++i)
    {
        for(unsigned int j =0; j<10; ++j)
            cout<<setfill(' ')<<setw(3)<<rand()%100;
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<<"CREATING 2D TABLE WITH HEADER AND SIDE HEADER";


    initialize(graph,10);
    printGraph(graph,10);




    return 0;
}

void initialize(bool graph[][SIZE], uint size)
{
    for(uint i = 0; i < size; ++i)
      for(uint j = 0; j < size; ++j)
          graph[i][j] = false;
    //setting the 2d array to all false
}

void printGraph(bool graph[][SIZE], uint size)
{
    cout<<endl<<endl<<setw(3)<<"|";
    for(uint i = 0; i < size; ++i)
        cout<<setw(3)<<i+1; //setting the top headers 1 2 3 4... depending on size that user input
    cout<<endl<<setfill('-')<<setw(3+size*3)<<"-"<<setfill(' ')<<endl;
    //sets a continuous ---- line under the top headers
    for(uint i = 0; i < size; ++i)
    {
        cout<<setw(2)<<i+1<<"|"; //creating the side columns of numbers 1 2 3 4 ....
        for(uint j = 0; j < size; ++j)
        {
            if(graph[i][j] == true)
                cout<<setw(3)<<"*";
            else
                cout<<setw(3)<<"F";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
