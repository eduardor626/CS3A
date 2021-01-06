#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool again(string title);
void getInput(vector<string> &list);
bool getInputLine(string &line);
void display(string title, const vector<string> &list);
void sort(vector<string> &title);
void sanitize(string &line);
void swap(char &x, char &y);

int main()
{
    vector<string> names;
    do
    {
       getInput(names);
       display("Unsorted", names);
       sort(names);
       display("Sorted", names);
       names.clear();
    }while(again("\nDo you wish to sort more names? "));
    return 0;
}


bool again(string title)
{
   string line;
   cout<<title<<": ";
   getline(cin,line);
   return toupper(line[0]) == 'Y';
}


void getInput(vector<string> &list)
{
    string line;
    while(getInputLine(line))
        list.push_back(line);
}

bool getInputLine(string &line)
{
   cout<<"Name: ";
   getline(cin,line);
   sanitize(line);
   return !line.empty();
}

void display(string title, const vector<string> &list)
{
    cout<<"\n----"<<title<<"----\n";
    for(int i = 0; i < list.size(); ++i)
        cout<<"list["<<i<<"] = "<<list[i]<<endl;
}

void sort(vector<string> &list)
{
    for(int i = 0; i < list.size(); ++i)
        for(int j = 0; j < list.size(); ++j)
            if(list[i] < list[j])
                swap(list[i], list[j]);
}

void sanitize(string &line)
{
    //erasing everything after a space, this program only
    //takes in first names
    int pos = line.find(' ');
    if(pos < line.size())
        line.erase(pos);
    //lowering every character in the name
    for(int i = 0; i < line.size(); ++i)
        line[i] = tolower(line[i]);
    //then changing the first letter of the name to capital
    line[0] = toupper(line[0]);

}


void swap(char &x, char &y)
{
    char temp = y;
    y = x;
    x = temp;
}
