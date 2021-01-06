#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

int** makeArray(int &row, int &col);
// Creates our two d array based on the # of rows and columns given

int getInput(const char *title, int min, int max);
// Printing the title and setting the min and max parameters
//this function is used in makeArray function

void loadArray(int **array, int row, int col);
//loading the array with random numbers

void display(int **array, int row, int col);
//displaying the array to the user

void menu(int **array, int row, int col, ofstream &out);
//menu of choice

void destroyArray(int **&array, int row, int col);
//destroying the dynamic array we created in makeArray

bool saveArray(int **array, int row, int col);
//Saving our array onto a file in the build folder

int checkValue();
//making sure user inputs number less than 1000

int checkRowCol(const char *title, int number);
//makings sure user inputs a row and column that are visible in the display

int main(int argc, char *argv[])
{
    //Initializing 2-d array pointer, row, and column
    int **twoDarray, row, col;
    ofstream out;

    //Creating Our Random Array
    srand(time(NULL));
    twoDarray = makeArray(row, col);

    //Loading the array
    loadArray(twoDarray, row, col);

    //Displaying the array
    display(twoDarray, row, col);

    //Displaying the menu and giving user options
    menu(twoDarray,row,col,out);

    //Destroying our dynamic array
    destroyArray(twoDarray,row,col);

    cout<<"Exiting..."<<endl;

    return 0;
}

void menu(int** array, int row, int col,ofstream &out){

    int answer, rowvalue, colvalue , value;
    char again = 'y';
    while(again == 'y')
    {
        cout<<"Enter what you would like to do to the array"<<endl
           <<"[1] Delete "<<endl
          <<"[2] Randomize "<<endl
         <<"[3] Change Value at Column/Row "<<endl
        <<"[0] Quit"<<endl<<": ";
        cin>>answer;
//        cout<<endl;
        switch(answer)
        {
        case 0: cout<<"Exiting the program..."<<endl;
                destroyArray(array,row,col);
                cout<<"Exiting..."<<endl;
                exit(0);
                break;
        case 1: cout<<"Deleting all values in the array..."<<endl;
                for(int i = 0; i < row; ++i){
                for(int j = 0; j < col; ++j){
                    array[i][j] = 0;
                    }
                }
                display(array,row,col);
                saveArray(array,row,col);
                break;
        case 2: cout<<"Randomizing all values in the array..."<<endl;
                srand(time(NULL));
                loadArray(array, row, col);
                display(array,row,col);
                saveArray(array,row,col);
                break;
        case 3: colvalue = checkRowCol("Which column: ",col);
                rowvalue = checkRowCol("Which row: ", row);
                value = checkValue();
                array[rowvalue][colvalue] = value;
                display(array,row,col);
                saveArray(array,row,col);
                break;
        default: cout<<"Incorrect input... "<<endl;
                break;
        }
        cout<<"Again (y/n) : ";
        cin>>again;
        cout<<endl<<endl;
    }
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
    /* Makes our rows, stays in the for (column) loop until
     the whole row is filled up to the max number of columns
     Then goes back up to the for(row) loop and goes to the next row
     and repeats the process
     */
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
        array[i] = NULL; //setting the array[i] to NULL
    }
    delete [] array; // delete the dynamic array
    array = NULL; // set array to NULL
}


bool saveArray(int** array, int row, int col)
{
    ofstream out;
    out.open("ArrayFile.txt");
    if(out.fail())
    {
        cout<<"ERROR OPENING FILE OUTSTREAM"<<endl;
        return false;
    }
    else
    {
        for (int i = 0; i<row; i++){
            for(int j = 0; j<col; j++ ){
                out<<setw(4)<<array[i][j];
            }
            out<<endl;
        }
        return true;
    }
    out.close();
}


int checkValue(){
    bool again;
    int value;
    do
    {
        again = false;
        cout<<"Value you want inserted here: ";
        cin>>value;
        if(value > 99)
        {
            cout<<"ERROR IN INPUT! (0-99) "<<endl;
            again = true;
        }
    } while(again);
    return value;
}

int checkRowCol(const char *title, int number){
    bool again;
    int value;
    do
    {
        again = false;
        cout<<title;
        cin>>value;
        if (!cin) // checking if the fail bit is not an integer
        {
            again = true;
            cout<<"Invalid Input! Try again! "<<endl;
            cin.clear(); // clears the input
            cin.ignore(256,'\n'); // ignore until enter (line feed)
        }
        else if(value > number || value < 0)
        {
            again = true;

            cout<<"ERROR IN INPUT! Exceeds the amount in array! "<<endl;
        }
    } while(again);
    return (value-1);
}


