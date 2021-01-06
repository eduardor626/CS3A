#include <iostream>
#include <string>

using namespace std;
bool getInput(string &line);
int convert(string &line);

int main()
{
    int value;
    string line;
    while(getInput(line))
    {
        value = convert(line);
        cout<<"The numeral contained is: "<<value<<endl;
    }
    return 0;
}

bool getInput(string &line)
{
    bool again;
    do{
    cout<<"Input: ";
    getline(cin,line);
    if(line.find_first_not_of("0123456789") < string::npos)
    {
        cout<<"Invalid number!"<<endl;
        again = true;
    }
    } while(again);
    return !line.empty();

}


int convert(string &line)
{
    int value = 0 ,powerOf10 = 1, pos = line.size()-1;
    for(;pos >= 0; --pos) //had to make >= 0 or else will be one number short
    {
        value += (line[pos]-48) * powerOf10;
        powerOf10 *= 10;
    }
    return value;
}
