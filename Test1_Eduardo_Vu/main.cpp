//by: Eduardo Rocha and Vu Ngyuen

#include "expression_calculator.h"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        expression_calculator(argc,argv);
    }
    catch (FRACTION_ERRORS e)
    {
        cout << "Error ";
        switch(e)
        {
               case DEVIDED_BY_ZERO:
                    cout << " TRYING DO DIVIDE A NUMBER BY ZERO ";
                    break;
               case DENOMINATOR_EQUALS_TO_ZERO:
                    cout << "DENOMINATOR OF FRACTION EQUALS TO ZERO ";
                    break;
        }
        cout << "occured!" << endl;
    }
    return 0;
}


