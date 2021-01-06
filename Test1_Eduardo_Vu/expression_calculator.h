#ifndef EXPRESSION_CALCULATOR_H
#define EXPRESSION_CALCULATOR_H
#include <iostream>
#include <vector>
#include <string>
#include "expression.h"
#include <map>
#include <sys/stat.h>
#include <unistd.h>

class expression_calculator
{
public:
    expression_calculator();
    expression_calculator(int argc, char *argv[]);
private:
    //CLASS VARIABLES:
    vector<string> commandList;
    string numbers;
    string alphabet;
    map<char,expression> myExpressions;
    //CLASS FUNCTIONS:
    int processCommand(string &input);
    int findChar (const string &line);
    int stringToInt(const string x);
    bool expExists(char key);
    inline bool fileExists(const string& name);
    string getCommand(string input);
    string extractName  (const string command);
    string standardize(string input); //standardizes our input
    string trim(const string &input);
    void evalDerivative(string &line);
    void evalExpression(string &line);
    void openFile (const string &fileName);
    void processEvent(string line);
    void processCLA (int argc, char *argv[],string &inputName,
                     string &outputName, string &help);
    void detectInAndOut (int argc , char *argv[],string &inputName,
                         string &outputName, string &help);
    void start(int argc, char *argv[]);
    void processInput(string &input);
    void helpMe();
    void openInput(string &inputName, vector<string> &lines);
    void let(string line);
    void eval(string line);
    void print(string line);
    void load(string line);
    void save(string line);
    void checkExtension(string &filename, string &extension);
};

#endif // EXPRESSION_CALCULATOR_H
