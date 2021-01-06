#include "functionpointers.h"
#include <iomanip>


using namespace std;


int sizeOfArray()
{
    int size;
    cout<<"Enter the amount of random numbers generated: ";
    cin>>size;
    return size;
}


void initializeArray(int list[], int size)
{
    srand(time(NULL)); //always will be a different number for random
    for(int i = 0; i < size; ++i)
        list[i] = rand()%50;
    sort(list,size);
}

void regenerate(int list[], int &size)
{
    size = 0;
    size = sizeOfArray();
    initializeArray(list,size);
    sort(list,size);
}

void showStandardDev(int list[] , int &size)
{
    //setting our double fixed to 2 decimal points
    //EX: 10.333 = 10.33
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double total = standardDev(list,size);
    cout<<total<<endl;
}

void showMean(int list[], int &size)
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double total = mean(list,size);
    cout<<total<<endl;
}

void showMedian(int list[], int &size){

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    double total = median(list,size);
    cout<<total<<endl;
}

void display(int list[], int &size)
{
    cout<<"{ ";
    for(int i = 0; i < size-1; ++i)
        cout<<list[i]<<", ";
    for(int j = size-1; j<size; ++j)
        cout<<list[j]<<" }"<<endl;
}

void menu()
{
    cout<<"PLEASE CHOOSE WHICH YOU WOULD LIKE TO SEE "<<endl;

    cout<<"[1] MEDIAN "<<endl;
    cout<<"[2] MEAN "<<endl;
    cout<<"[3] STANDARD DEVIATION "<<endl;
    cout<<"[4] REGENERATE "<<endl;
    cout<<"[5] DISPLAY CURRENT LIST"<<endl;
    cout<<"[0] QUIT "<<endl;
}

int choice()
{
    int key = 0;
    bool again;
    do
    {
        cout<<":";
        again = false;
        cin>>key;
        if (!cin) // checking if the fail bit is not an integer
        {
            again = true;
            cout<<"Invalid Input! Try again! "<<endl;
            cin.clear(); // clears the input
            cin.ignore(256,'\n'); // ignore until enter (line feed)
        }
        else if (key < 0 || key > 6)
        {
            again = true;
            cout<<"Invalid Input! Try again! "<<endl;
        }
    } while(again);
    cout<<endl;
    return key;
}

void sort(int list[], int &size)
{
    static fptr whatToDo[2] = {noSwap,swap};
    // Create an array of pointers to functions and assign whatToDo[0] to have the value of noSwap
    // and whatToDo[1] to have the value of swap. In other words, the addresses of the functions noSwap
    // and swap are assigned to the array.

    for(int i = 0; i < size; ++i)//For every element in the array
        for(int j = 0; j < size; ++j)//Compare it to every other element of the array (including itself!)
            (whatToDo[list[i] < list[j]])(list[i], list[j]);
            //If list[i] < list[j] swap the two elements. list[i] < list[j]
            //returns either TRUE (1) or FALSE (0). Use the result to index the
            //array of pointers to functions and then call the correct function
}

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void noSwap(int &x, int &y)
{

}

void destroy(int list[], int &size)
{
    delete [] list; //deleting our dynamic array that we created
    list = NULL; //setting the pointer to point to nothing
}


void quit(int list[], int &size){
    cout<<endl;
    for(int i = 0; i<size; ++i)
        list[i] = 0;
    destroy(list,size);
    cout<<"Exiting..."<<endl;
    exit(0);
}


double median(int list[] , int size)
{
    double total = 0.0;
//    (size%2 == 0) && takeCareOfBusiness(total,list,size);
//    (size%2 != 0) && takeCareOfBusiness2(total,list,size);
    if(size%2 == 0)
    {
        total = ((list[size/2]+(list[((size/2) - 1)]))/2.0);
    }
    else
    {
        total = list[size/2] *1.0;
    }
    return total;
}

bool takeCareOfBusiness(double &total, int list[], int size)
{
    total = 0.0;
    total = ((list[size/2]+(list[((size/2) - 1)]))/2.0);
    return true;

}

bool takeCareOfBusiness2(double &total,int list[], int size)
{
    total = 0.0;
    total = list[size/2]*1.0;
    return true;
}


double mean(int list[], int size)
{
    int counter = 0;
    double total;
    for(int i = 0; i<size; ++i)
        counter += list[i];
    total = (counter/(size*1.0));
    return total;
}

double standardDev(int list[] , int size)
{
    double meanTotal;
    double total = 0.0;
    double temp[size];
    meanTotal = mean(list,size);
    for(int i = 0; i<size; ++i)
        temp[i] = pow(list[i] - meanTotal,2);
    for(int j = 0; j<size; ++j)
        total += temp[j];
    total = sqrt(total/size);
    return total;
}


void processEvents(int list[], int &size)
{
    char again = 'y';
    while(again == 'y' || again == 'Y')
    {
    int  choiceOfUser = 0;
    menu(); //displays the menu of the program
    choiceOfUser = choice(); //getting the choice from the user [0-5]

    (choiceOfUser == 0) && output("Exiting the program...",list,size,quit);
    (choiceOfUser == 1) && output("MEDIAN: ",list,size,showMedian);
    (choiceOfUser == 2) && output("MEAN: ",list,size,showMean);
    (choiceOfUser == 3) && output("STANDARD DEV: ",list,size,showStandardDev);
    (choiceOfUser == 4) && output("REGENERATE: ",list,size,regenerate);
    (choiceOfUser == 5) && output("DISPLAY: ",list,size,display);

    cout<<endl<<"TRY AGAIN? (y/n) : ";
    cin>>again;
    cout<<endl;
    display(list,size);cout<<endl;

    }

}

bool output(const char *title, int list[], int &size, fptr1 whatToDo)
{
    cout<<title<<" "; whatToDo(list,size);
    cout<<endl;
    return true;
}
