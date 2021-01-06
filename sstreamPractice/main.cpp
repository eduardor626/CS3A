#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

bool getLine(string &line);
bool partition(const string &line,double &x, char & op, double &y);
double convert(string &number);
void output(double x, char op, double y);

int main()
{
   string line;
   double x, y;
   char op;
   while(getLine(line))
   {
       if(partition(line, x,op,y))
           output(x,op,y);
       else
           cout<<"Illegal expression entered!!!"<<endl;
   }
   return 0;
}

bool partition(const string &line, double &x, char & op, double &y)
{
    int pos = line.find_first_of("*/-+");
    string first,second;
    if(pos == string::npos)
        return false;
    op = line[pos];
    first = line.substr(0,pos);
    second = line.substr(pos+1);
    x = convert(first);
    y = convert(second);
    return true;
}
bool getLine(string &line)
{
   cout<<"Expression: ";
   getline(cin,line);
   return !line.empty();
}


//gets rid of all unwanted characters that are not numbers
void sanitize(string &number)
{
    int pos;
    while((pos = number.find_first_not_of("0123456789")) < number.size())
        number.erase(pos,1);
}

double convert(string &number)
{
    stringstream ss;
    double ans;
    sanitize(number);
    ss<<number;
    ss>>ans;
    return ans;
}


void output(double x, char op, double y)
{
    cout<<setw(2)<<x<<setw(2)<<op<<setw(2)<<y<<" = ";
    switch(op)
    {
       case '*' : cout<<x*y<<endl;
                  break;
       case '+' : cout<<x+y<<endl;
                  break;
       case '-' : cout<<x-y<<endl;
                  break;
       case '/' : cout<<x/y<<endl;
    }
}
