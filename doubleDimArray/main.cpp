#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;
// The null pointer is never a valid target, however.
// If you try to dereference the null pointer, you
// WILL get a segmentation fault.
// “does not belong to you.”
int** makeArray(int &row, int &col);
// Creates our two d array based on the # of rows and columns given

int getInput(const char *title, int min, int max);
// Printing the title and setting the min and max parameters
//this function is used in makeArray function

void loadArray(int **array, int row, int col);
//loading the array with random numbers

void display(int **array, int row, int col);
//displaying the array to the user

void destroyArray(int **&array, int row, int col);
//destroying the dynamic array we created in makeArray

int main(int argc, char *argv[])
{
    //Initializing 2-d array pointer, row, and column
    int **twoDarray, row, col;

    //Creating Our Random Array
    srand(time(NULL));
    twoDarray = makeArray(row, col);

    //Loading the array
    loadArray(twoDarray, row, col);

    //Displaying the array
    display(twoDarray, row, col);

    //Destroying our dynamic array
    destroyArray(twoDarray,row,col);

    return 0;
}

int** makeArray(int &row, int &col)
{
    int **array;
    row = getInput("How many rows: ",1, 10);
    col = getInput("How many columns: ", 1, 10);
    array = new int*[row];
    for(int i = 0; i < row; ++i)
        array[i] = new int[col];
    return array;
}

int getInput(const char *title, int min, int max)
{
    bool again;
    int value;
    do
    {
        again = false;
        cout<<title;
        cin>> value;
        if (!cin) // checking if the fail bit is not an integer
        {
            again = true;
            cout<<"Invalid Input! Try again! "<<endl;
            cin.clear(); // clears the input
            cin.ignore(256,'\n'); // ignore until enter (line feed)
        }
        else if(value < min || value > max)
        {
            again = true;
            cout<<"Your input is out of the range of "<<min<<" to "<<max<<endl
                <<"Please re-enter!"<<endl;
        }

    }while(again);
    return value;
}

void loadArray(int **array, int row, int col)
{
    // Makes our rows, stays in the for (column) loop until
    // the whole row is filled up to the max number of columns
    // Then goes back up to the for(row) loop and goes to the next row
    // and repeats the process
    for(int i = 0; i < row; ++i)
// for(initial condition; while conditions; whatever want to be done as the last thing in the loop)
        for(int j = 0; j < col; ++j)
// for(initial condition; while conditions; whatever want to be done as the last thing in the loop)
            array[i][j] = rand()%100;
}


void display(int **array, int row, int col)
{
    cout<<"The array contents are:"<<endl<<endl;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            cout<<setw(4)<<array[i][j];
            // setw(4) sets max # of characters to 4 so array is even
        cout<<endl;
    }
    cout<<endl<<endl;
}

void destroyArray(int **&array, int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            array[i][j] = 0; // sets the whole row to zero's
        delete [] array[i]; // deletes the whole row after all items in row are 0
        array[i] = NULL;
    }
    delete [] array; // delete the dynamic array
    array = NULL; // set array to NULL
}


