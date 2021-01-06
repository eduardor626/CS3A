#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <map>
#include <string>
#include <iomanip>


enum class dictionaryFields{firstName,listOfTestScores,avgScore};

using namespace std;
using u_int = unsigned int;
using studentInfo = tuple<string,string,int>;

//Function Prototypes
int averageScore(const string &line);
char gradeCalc(const int &averageTestScore);
string Standardize(string &line);

void readContent(const string fileContent,map<string,studentInfo> &dictionary);

void displayContent(map<string,studentInfo> dictionary);

//function intializing our map


tuple<int,int,int> testAverages(map<string,studentInfo> &dictionary);


int main()
{
    // dictionary is the map and contains all the student info
    // with index being the students last name capitalize
    map<string,studentInfo> dictionary;
    string filename = "test2.txt";
    readContent(filename,dictionary);
    displayContent(dictionary);


}


//Function Definitions
void readContent(const string fileContent,map<string,studentInfo> &dictionary){
    ifstream file(fileContent);
    string line;
    string firstName,lastName,listOfNumbers;
    while(getline(file,line)){
        stringstream ss(line);
        ss>>firstName>>lastName;
        getline(ss,listOfNumbers);
        dictionary[Standardize(lastName)] = make_tuple(firstName,listOfNumbers,averageScore(listOfNumbers));
    }
}

int averageScore(const string &line){
    stringstream ss(line);
    const int AVG = 3;
    int test1,test2,test3;
    ss>>test1>>test2>>test3;
    int avg = (test1+test2+test3)/AVG;
    return avg;
}

char gradeCalc(const int &averageTestScore){
    char grade;
    if(averageTestScore>=90)
        grade = 'A';
    else if(averageTestScore>=80)
        grade = 'B';
    else if(averageTestScore>=70)
        grade ='C';
    else if(averageTestScore>=60)
        grade = 'D';
    else
        grade = 'F';
    return grade;
}

string Standardize(string &line){
    string::size_type pos = line.find(':');
    line.erase(pos);
    for(u_int i = 0;i<line.length();i++)
        line[i] = toupper(line[i]);
    return line;
}



//instead of having tuple<int,int,int> we can do auto testAverages
tuple<int,int,int> testAverages(map<string,studentInfo> &dictionary)
{
    int sum1 = 0, sum2 = 0, sum3 = 0, counter = 0;
    for(auto element: dictionary)
    {
        auto t = element.second;
        string numbers = get<1>(t);
        stringstream ss(numbers);
        int test1,test2,test3;
        ss>>test1>>test2>>test3;
        sum1+= test1;
        sum2+=test2;
        sum3+=test3;
        ++counter;
    }
    return make_tuple(sum1/counter,sum2/counter,sum3/counter);
}

void displayContent(map<string,studentInfo> dictionary){
    cout<<endl<<endl;
    //instead of having tuple<int,int,int> we can do auto testAverages

    auto content = testAverages(dictionary);
    cout<<setw(7)<<"NAME(S)"<<setw(25)<<"TEST 1"<<setw(8)<<"TEST 2"<<setw(8)<<"TEST 3"<<right<<setw(15+4)<<"AVG/GRADE"<<endl;
    cout<<setfill('-')<<setw(68)<<"-"<<endl;
    cout<<setfill(' ');
    for(auto element: dictionary)
    {
        int size = element.first.size();
        cout<<left<<setw(size)<<element.first<<", ";
        auto t = element.second;
        string me = get<0>(t);
        int size2 = me.size();
        string me2 = get<1>(t);
        stringstream ss(me2);
        int test1,test2,test3;
        ss>>test1>>test2>>test3;
        //accesses the elements of the tuple, get<>
       cout<<me<<":"<<right<<setw(32-(size2+size+3))<<test1<<setw(8)<<test2<<setw(8)<<test3<<setw(15)<<"AVG: "<<get<2>(t)<<" "<<gradeCalc(get<2>(t))<<endl;
       size = 0;
    }
    cout<<endl;
    cout<<"TEST 1 AVG: "<<get<0>(content)<<endl;
    cout<<"TEST 2 AVG: "<<get<1>(content)<<endl;
    cout<<"TEST 3 AVG: "<<get<2>(content)<<endl<<endl;
}
