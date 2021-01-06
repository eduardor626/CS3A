#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
#include <sys/stat.h>
#include <unistd.h>
#include <myvector.h>
/*myvector is our own STL -> which is a vector whose capacity will grow double
 *  every time it reaches to the max capacity*/

using namespace std;

void loadingAlphabet(string &alphabet);
void checkExt( string &fileName);
void askExit();
bool askToSave();
string getInput(const string &title);
string readingLevel (const int &w, const int &s, const int & syl);
string getReadingLevel (const double &score);
inline bool fileExists(const string& name);

int main()
{
    srand(0);
    ofstream out;
    ifstream in;
    stringstream ss;
    const string vowel = "aeiouy";
    const string endOfS = ".!?";
    const string stars (80,'*');
    string alphabet, line, temp, word, inputName;
    loadingAlphabet(alphabet);
    int numOfPars, numOfLines, numOfWords, numOfSen, numOfVows;
    myVector<string> toPrint;

    while (1)
    {
        inputName = getInput("Enter a 'plain ASCII' text file to analyze: ");
        checkExt(inputName);
        in.open(inputName);

        if (in.is_open())
        {
            cout <<"Opened "<<inputName <<" and start analyzing............ \n";
            numOfPars = 1;
            numOfLines = 0;
            numOfWords = 0;
            numOfSen = 0;
            numOfVows = 0;

            //START!!
            const long double start = time(0);
            bool prevLineIsEmpty = false;
            bool prevLetterIsAVow;
            int sylables;
            map <string, map<int,vector<int>>> map_Of_String_Map;
            map<string,int> map_Of_String_Int;

            while (getline(in,line))
            {
                numOfLines++;
                if(line[0] == (char)(13) || line.empty() )
                    prevLineIsEmpty = true;

                //IF THE PREV-LINE IS EMPTY, AND THE CURRENT IS NOT->1 PARAG.
                if (prevLineIsEmpty && !line.empty())
                {
                    numOfPars++;
                    prevLineIsEmpty = false;
                }

                //WHILE LINE STILL HAS SOMETHING TO GIVE TO SS.
                while (ss<<line && line.size() != 0 )
                {
                    ss>>temp;
                    ss.str(string());
                    ss.clear();

                    if (line.size() > (line.find(temp) + temp.size()))
                        line = line.substr(line.find(temp) + temp.size() + 1);
                    else
                        line.clear();

                    //TRIM TEMP.
                    for (unsigned int i = 0 ; i < temp.length() ; ++i)
                    {
                        if (i == (temp.length()-2) &&
                                (endOfS.find(temp[i]) != string::npos||
                                 endOfS.find(temp[i+1]) != string::npos ))
                            numOfSen++;

                        if (alphabet.find_first_of(temp[i]) > alphabet.length())
                            temp.replace(i,1," ");
                        else
                            temp[i] = tolower(temp[i]);
                    }

                    ss<<temp;
                    ss>>word;
                    ss.str(string());
                    ss.clear();

                    //IF WORD IS NOT EMPTY.
                    if (word.size() != 0)
                    {
                        prevLetterIsAVow = false;
                        sylables = 0;

                        //COUNTING SYLABLE:
                        if (word.size() <= 3)
                        {
                            sylables = 1;
                        }
                        else
                        {
                            for(unsigned int i = 0; i<word.size(); ++i)
                            {
                                if(vowel.find(word[i]) != string::npos && prevLetterIsAVow == false)
                                {
                                    sylables++;
                                    prevLetterIsAVow = true;
                                }else
                                    prevLetterIsAVow = false;
                            }

                            if(word[word.size()-1] == 'e')
                                sylables--;
                            if(word[0] == 'y')
                                sylables--;

                            if (word[word.size()-2] == 'e' && word[word.size()-1] == 'd' )
                            {
                                if(word[word.size()-3] != 'd' && word[word.size()-3] != 't' && word[word.size()-3] != 'l')
                                    sylables--;
                            }
                            else if (word[word.size()]-1 == 'y' && word[word.size()-2] != 't' && word[word.size()-2] != 'l')
                            {
                                    sylables--;
                            }else if (word[word.size()-1] == 'e' && word[word.size()-2] == 'l')
                                    sylables++;
                        }

                        numOfVows += sylables;
                        numOfWords++;

                        //IF MAP CONTAINS WORD, VALUE OF WORD INCREASE.
                        if (map_Of_String_Int.count(word))
                            map_Of_String_Int[word]++;
                        else    //ELSE INSERT WORD TO MAP AND SET IT VALUE TO 1.
                            map_Of_String_Int[word] = 1;

                        /*map_Of_String_Map[word] -> ACCESS TO SMALL MAP.
                         * map_Of_String_Map[word][numOfPars] -> ACESS TO VALUE
                         * OF THE SMALL MAP.*/
                        map_Of_String_Map[word][numOfPars].push_back(numOfLines);
                    }
                    temp.clear();
                    word.clear();
                }
            }
            in.close();

            //MAKE A FLIP MAP TO GET THE MOST USED WORDS.
            multimap<int,string> map_Of_Int_String;
            for (map<string, int>::iterator it = map_Of_String_Int.begin();
                 it != map_Of_String_Int.end(); ++it )
                map_Of_Int_String.emplace(it->second , it->first);

            //CALCULATE THE READING LEVEL.
            string readingLv =  readingLevel(numOfWords, numOfSen, numOfVows);

            //ADD STUFFS TO THE VECTOR, WHICH WILL BE USE FOR COUT OR OFSTREAM
            toPrint.push_back(stars);
            toPrint.push_back("SUMMARY: ");
            toPrint.push_back("Total words: " + to_string(numOfWords) + ".");
            toPrint.push_back("Total paragraphs: "+ to_string(numOfPars) + ".");
            toPrint.push_back("Total sentences: " + to_string(numOfSen) + ".");
            toPrint.push_back("Reading Level: " + readingLv);
            toPrint.push_back(stars);
            toPrint.push_back("Top 10 most frequently used words are : ");

            //ADD INFO OF 10 MOST USED WORD FROM MAP TO VECTOR.
            int counter = 0;
            for (multimap<int, string>::reverse_iterator it = map_Of_Int_String.rbegin() ;
                 it != map_Of_Int_String.rend() && counter < 10; ++it )
            {
                string s = it->second;
                s[0] = toupper(s[0]);
                toPrint.push_back("\"" + s + "\" has been used " +
                                  to_string(it->first) + " times.");
                counter++;
            }

            //CLEANING UP.
            toPrint.push_back(stars);
            map_Of_Int_String.clear();

            //LOOP THE BIG MAP.
            for (map<string, map<int,vector<int>>>::iterator it = map_Of_String_Map.begin();
                 it != map_Of_String_Map.end() ; ++it)
            {
                string w = it->first;
                w[0] = toupper(w[0]);
                toPrint.push_back("");
                toPrint.push_back( "Found " + to_string(map_Of_String_Int[it->first]) + " occurrence(s) of \"" + w + "\": ");
                //LOOP THE SMALL MAP INSIDE BIG MAP.
                for (map<int,vector<int>>::iterator itt = it->second.begin();
                     itt != it->second.end(); ++itt)
                {
                    //LOOP TO THE VECTOR WHICH IS THE VALUE OF SMALL MAP.
                    unsigned int i = 0;
                    string print;
                    for (; i < itt->second.size() ; ++i)
                    {
                       print += to_string(itt->second[i]) + " ";
                        if ((i+1)%8 == 0)  // 8 ITEMS PER LINE.
                        {
                            toPrint.push_back(to_string(itt->second.size()) +
                                              " in paragraph#" + to_string(itt->first) + " - Line#: " + print);
                            print.clear();
                        }
                    }
                    if (i < 8)
                    {
                        toPrint.push_back(to_string(itt->second.size()) +
                                          " in paragraph#" + to_string(itt->first) + " - Line#: " + print);
                         print.clear();
                    }
                    else if (i >8 && i%8 != 0)
                        toPrint.push_back(print);
                    print.clear();
                }
            }
            //CLEAN UP BIG MAP.
            map_Of_String_Int.clear();
            map_Of_String_Map.clear();

            //PRINTING RESULT.
            for (unsigned int i = 0 ; i < toPrint.size() ; ++i)
                cout << toPrint[i] << endl;

            //CALCULATING TIME.
            const long double end = time(0);
            cout << stars << endl;
            cout <<"Finish analyzing file and printing the result!" << endl;
            cout <<"Process time: " << end - start << " seconds." <<endl;

            bool wantTosave = askToSave();
            if (wantTosave)
            {
                string outputName = getInput("Enter output name: ");
                checkExt(outputName);
                string ans;
                 if(fileExists(outputName))
                 {
                     ans = getInput(outputName + " already exists. Do you want"
                                                 " to overwrite? (Y/N)");
                     while( toupper(ans[0]) != 'Y' && toupper(ans[0]) != 'N')
                     {
                         cout << "Invalid output! Re-enter";
                         getline (cin,ans);
                         ans[0] = toupper(ans[0]);
                     }

                     if(toupper(ans[0]) == 'Y')
                         out.open(outputName);
                     else
                         askExit();

                 }else
                 {
                     out.open(outputName);
                 }

                 if (out.is_open())
                 {
                     cout <<"Processing............" << endl;
                     for (unsigned int i = 0 ; i < toPrint.size() ; ++i)
                         out << toPrint[i] << endl;
                     cout << "Successfully writing infomation to file "
                          << outputName << ".\n";
                     out.close();
                     toPrint.clear();
                     askExit();
                 }
            }
            else
            {
                toPrint.clear();
                askExit();
            }
        }else
        {
            cout << "Can't open " << inputName << " ." << endl;
            askExit();
        }
        cout << endl;
    }
    cout << toPrint.size() << endl;
    return 0;
}

void loadingAlphabet(string &alphabet)
{
    for (char c = 'A'; c <= 'Z' ;  ++c)
    {
        alphabet += c;
        alphabet += (c+32);
    }
}

string getInput(const string &title)
{
    string s;
    cout << title;
    getline(cin,s);
    if (s.empty())
    {
        return getInput(title);
    }
    else
        return s;
}

void checkExt(string &fileName)
{
    string ext;
    if (fileName.find('.') == string::npos)
        ext = getInput("Enter extension please : ");
    else
        return;
    fileName += (ext.find(".") < ext.size()) ? ext : ("." + ext);
}

bool askToSave()
{
    string answer;
    answer = getInput ("Do you want to save this infomation to a file? (Y/N)");
    while (toupper(answer[0]) != 'Y' && toupper(answer[0]) != 'N')
        answer = getInput("Invalid input! Re-enter: ");
    return toupper(answer[0]) == 'Y' ? true : false;
}

inline bool fileExists(const string& name)
{
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

void askExit()
{
    string answer = getInput ("Do you want to continue? (Y/N)");
    while (toupper(answer[0]) != 'Y' && toupper(answer[0]) != 'N')
        answer = getInput("Invalid input! Re-enter: ");
    if (toupper(answer[0]) == 'N')
        exit(1);
}

string readingLevel (const int &w, const int &s, const int & syl)
{
    double B = (-1.015) * ((double)w/s);
    double C = (-84.6) * ((double)(syl)/w);
    return getReadingLevel(206.835 + B + C);
 }

string getReadingLevel (const double &score)
{
    if(score >= 90.0 )
        return "5th grade level, Very easy to read.";
    else if(score <90.0 && score >= 80.0)
        return "6th grad e level, Easy to read.";
    else if(score <80.0 && score >= 70.0)
        return "7th grade level, Fairly Easy to read.";
    else if(score <70.0 && score >= 60.0)
        return "8th and 9th grade level, Easily understood.";
    else if(score <60.0 && score >= 50.0)
        return "10th-12th grade level,  Fairly difficult to read.";
    else if(score <50.0 && score >= 30.0)
        return "College level, Difficult to read.";
    else
        return "College graduate level, Very difficult to read!";
}
