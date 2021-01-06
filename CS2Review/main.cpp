#include <iostream>
#include <string>


using namespace std;

const int EXAMPLE = 10;
const int ROWS = 4;
const int COLS = 3;

void StringsAndConcatenation(); //1
void ifStatements(); //2
void constantsAndformattingDecimals(); //3
void Loops(); //4
void NestingExitingContinuingLoops(); //5
void VariableScopeandParamaters(); //6
void PassingByValueAndReference(); //7
void Arrays(); //8
void ArraysAsParameters(); //9
void multidimensionalArrays(); //10
void vectorsAndVectorFunctions(); //11

int main(int argc, char *argv[])
{


//    NestingExitingContinuingLoops();
//    Arrays();
    multidimensionalArrays();



    return 0;
}


void StringsAndConcatenation()
{

    //getline(cin,variable) -- gets whole line/easier to work with

    //Concatenation -- string first += " ";
    //can add strings together

    //Functions:
    // .length() -- returns the number of characters in string
    // .at(int) -- returns character at index 'int'
    // .append(string) -- concatenate string to end of another string ex: first.append(last)
    // .insert(int index, string, int start, int end) -- index u want to insert at, string you
    //want to insert, and the begining of the index of that string, and the ending index of that string
    //you want to go up to
    //.find("char") -- returns index where character is first found
    //.rfind("char") -- finds first char but in reverse (end of the string)
    //.erase(int index) -- will erase everything after that index
    //.erase(int index, int # of elements erasing) -- will erase # of elements after index
    //.find_first_of("char") --finds char index and returns it
}

void ifStatements()
{
    //Operators: == != >= <=

    //Logical Operators: && || ^
    // ^ -- is the exclusive 'or' operator, that limits to only one of the options being true
}

void constantsAndformattingDecimals()
{
    //constants always go on the top of main and prototypes
    //usually CONSTANTS -- ALL CAPS
    //ex: const double fed_tax = 0.15;

    //Fixed Points: -- Will cout only two numbers after decimal ex: 2 = 2.00
    // cout.setf(ios::fixed);
    // cout.setf(ios::showpoint);
    // cout.precision(2);

}

void Loops()
{
    //Loops: While (will execute command while statement is true)
    //Do While (always will execute command at least once) ,
    //For (int start, int end, int increment)


}

void NestingExitingContinuingLoops()
{
    //Nesting -- putting a loop within another loop
    // use backslash to display quotes inside a string
    //Ex: string ouput = " the weatherman said , \"Hello there!\"";

    //Ex: the continue is like a break, it exits the loop it is in
//    for ( int j = 0; j < 5; j++)
//    {
//        if (j ==2)
//        {
//            continue;
//        }
//    }

    //continue -- skip to next iteration
    //break -- exits loop or code indefinitely


    //Nested Loop example that really shows how for loop works and nested loops work

    int i = 1;
    //int j = 1 ---- caused the loop to just go up to i = 1, not all the way to 12
    //because j turned to 13 after the for loop and did not execute the for loop again
    //thats why we declare it always inside the while loop
    while ( i <= 12)
    {
        for( int j = 1; j<=12; j++)
        {
            cout<<i<<" x "<<j<<" = "<<(i*j)<<endl;
        }

        i++;
    }

}

void VariableScopeandParamaters(){

    //Local scope --
    //data type void -- doesnt return anything, usually used for printing

    //Any variable that we use within a function , has a local scope

    // int num1, num2; <-- we can do this because we are declarying more than one int
    //at this time

    //In the prototypes section --
    //void addNums( int, int ); <-- we can just leave the data type, we dont have to
    //write down a certain name like we do in the function defenition

    //Ex: void addNums(int, int);
    //    addNums - adds two integers
    //    @param int - first number to be added
    //    @paramint - second number to be added


    //**MAIN function should always look clean**
}

void PassingByValueAndReference(){
    //void value(int);
    //value - passes parameter by value
    //@param int - number in question(in example case)

    //void reference(int&);
    //reference - passes parameter by reference
    //@param int& - number to be incremented (in example case)

    //If going to change the value of something, pass by Reference!
    //If NOT going to change the value of something, pass by Value!
}


void Arrays()
{

    //Arrays -- DataType NameOfArray[ ];
    //string colors[] = {"red", "blue","green","blue","orange"};

    //Anytime we see arrays we will see:
    //int NumOfElements -- will always be equal to how many elements in the array
    // we actually fill up



    //Use global constants for highest number of elements in array
    int CAPACITY = 5;


    //NumOfElements
    int NumOfElements = 0;
    string colors[CAPACITY];
    int i = 0;
    string input;
    cout<<"Enter your colors (-1 to stop) : ";
    cin>>input;

    while((i<CAPACITY)&&(input != "-1"))
    {
        NumOfElements++;
        colors[i] = input;
        i++;
        cin>>input;
    }

    for ( int j = 0; j < NumOfElements; j++)
    {
       cout<<" Color "<<(j+1)<<" = "<<colors[j]<<endl;
    }

}

void ArraysAsParameters()
{
    //int scores[CAP];
    //int numOfelements = 0;

    //void fillArray( int[], int&);
    //-scores of students
    //@param - number of scores
    //@param - number of students

    //Arrays are always passed by reference! Always possible to change them permenantly inside
    //a function

    //void printArray(const int[], int)
    //- prints Array **const int** because arrays always passed by reference,
    //in printArray we do not want to change the array at all
    //@param const int[] - scores of students
    //@param int - number of students **not by reference bc we do not want to change it**

    //When calling the array in main , we dont need [] anymore
    //Ex: fillArray(scores,numOfelements);

}


void multidimensionalArrays(){

//    int scores[ROWS][COLS] = {{45,50,40},
//                              {90,75,60},
//                              {50,67,99},
//                              {45,78,44}};

//    cout<<scores[1][2]<<endl; couts 60

    //void fillScores(int [ROWS][COLS]);
    //- fills scores
    //@param int[][] - scores of all tests from students
}

void vectorsAndVectorFunctions()
{
    //Format: #include <vector>
    //Format: vector<DataType> nameOfVector

    //Ex: vector<int> myVector;

    //myVector.push_back(value) --> adds an element to the End of the vector (also resizes it)
    //myVecotr.at(index) --> return element at specified index number
    //myVector.size() --> returns an unsigned int equal to number of elements
    //myVector.begin() --> reads vector from first element (index = 0)
    //myVector.insert(myVector.begin()+integer, new value ) --> adds element before specified index number
    //myVector.erase(myVector.begin() + integer) --> removes element AT specified index number
    //myVector.clear() --> removes all elements in vector
    //myVector.empty() --> returns boolean value if whether vector is empty
}










