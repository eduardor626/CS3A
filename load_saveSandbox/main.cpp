#include <iostream>
#include <fstream>
#include <string>

//ifstream - reading data from a file
//ofstream - riding data to a file

using namespace std;
int getwhattheywant();
void displayItems(int number);



//main function
int main(int argc, char *argv[])
{
    int whatTheywant = getwhattheywant();
    while(whatTheywant != 4)
    {
        switch (whatTheywant) {

        case 1:
            displayItems(1);
            break;
        case 2:
            displayItems(2);
            break;
        case 3:
            displayItems(3);
            break;
        default:

            break;
        }

        whatTheywant = getwhattheywant();

    }

    return 0;
}

//displayItems function
void displayItems(int number)
{
    ifstream inFile("objects.txt");
    string name;
    double power;
    if( number == 1)
        while(inFile>>name>>power)
        {
            if(power == 0)
                cout<<name<<" , "<<power<<endl;
        }
    if( number == 2)
        while(inFile>>name>>power)
        {
            if(power > 0)
                cout<<name<<" , "<<power<<endl;
        }
    if( number == 3)
        while(inFile>>name>>power)
        {
            if(power < 0)
                cout<<name<<" , "<<power<<endl;
        }



}


//getwhattheywant function
int getwhattheywant()
{
    int choice;
    cout<<"1 - plain items\n"
          "2 - helpful items\n"
          "3 - deadly items\n"
          "4 - quit \n";
    cin>>choice;
    return choice;
}

