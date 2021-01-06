#include <iostream>

using namespace std;

/* More practice with templates
 * Always write typename to indentify any variable type inserted
 * and label variable to represent whatever type
 */
template<typename T, typename U> //always needed before prototype of function
void maximum(T x, U y);

template<typename T, typename U> //always needed before prototype of function
void minimum(T x, U y);



int main()
{
    //program displaying example of different types being used
    //for the templated functions
    minimum(3,3.2);
    maximum(4,5);
    minimum('A', 402);
    maximum(true,false);
    minimum(1,false);

    return 0;
}

//always needed before defintion of function as well
template<typename T, typename U>
void maximum(T x, U y)
{
    cout<<"The maximum of "<<x<<" and "<<y<<" is "
        <<((x >= y) ? x : y)<<endl;
}

//always needed before defintion of function as well
template<typename T, typename U>
void minimum(T x, U y)
{
    cout<<"The minimum of "<<x<<" and "<<y<<" is "
        <<((x < y) ? x : y)<<endl;
}
