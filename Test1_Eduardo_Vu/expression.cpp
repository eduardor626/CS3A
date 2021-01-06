#include "expression.h"
//CONSTRUCTORS AND DESTRUCTOR:
expression::expression()
{
    //DEFAULT CONSTRUCTOR
}

expression::expression(const expression &other)
{
    copy(other);
}

expression::expression(string input)
{
    expressionToStore = input;
    makeTerms(expressionToStore);
    getTerms();
    addCommonTerms();
    changeExpression();
}

expression::~expression()
{
    //TO-DO
}

//CLASS OPERATOR
expression& expression::operator=(const expression &other)
{
    if(this != &other)
        copy(other);
    return *this;
}


expression& expression::operator<<(const string &input)
{
      variable = "X";
      this->expressionToStore = input;
      makeTerms(expressionToStore);
      getTerms();
      addCommonTerms();
      changeExpression();
      return *this;
}

expression& expression::operator+=(const expression &other)
{
    *this = *this + other;
    return *this;
}

expression& expression::operator-=(const expression &other)
{
    *this = *this - other;
    return *this;
}

expression& expression::operator*=(const expression &other)
{
    *this = *this * other;
    return *this;
}

//CLASS PUBLIC FUNCTIONS:
fraction expression::evaluateAt(const fraction &value)
{
    double resultD = 0;
    for (unsigned int i = 0 ; i < terms.size(); ++i)
    {
        term temp = terms[i];
        double powerD = double(temp.power.getNumer())/temp.power.getDenom();
        double valueD = double(value.getNumer())/value.getDenom();
        double coefD = double(temp.coef.getNumer())/temp.coef.getDenom();
        resultD += (coefD * pow(valueD, powerD));
    }
    return fraction(resultD);
}

expression expression::derivative(unsigned int x)
{
    expression temp;
    temp.terms = this->terms;
    for(unsigned int i = 0; i < terms.size(); ++i)
    {
        for(unsigned int j = 1; j <= x; ++j)
        {
            temp.terms[i].coef = temp.terms[i].coef * temp.terms[i].power;
            temp.terms[i].power = temp.terms[i].power - 1;
        }
    }
    temp.changeExpression();
    return temp;
}

//ONLY WHEN THE DEGREE OF ALL TERMS ARE POSITIVE INTEGER.
expression expression::composition (const expression &one, const expression &two)
{
    expression result = expression("0");
    for (unsigned int i = 0 ; i < one.terms.size(); ++i)
    {
        expression temp;
        temp = two;
        if (one.terms[i].power > 0)
        {
           fraction pow = one.terms[i].power;
           int num = pow.getNumer();
           int denom = pow.getDenom();
           int degree = num/denom;
           temp = two^degree;
           temp = temp * one.terms[i].coef;
           result = result + temp;
        }else if (one.terms[i].power == 0)
        {
           result.terms.push_back(one.terms[i]);
        }
    }
    result.addCommonTerms();
    result.changeExpression();
    return result;
}

//******************************************************************************
//******************************************************************************
//FRIEND INPUT/OUTPUT OPERATORS
istream& operator>>(istream &in, expression &exp)
{
    string line;
    expression temp;
    getline(cin,line);
    if (!line.empty())
       temp = expression(line);
    exp = temp;
    return in;
}

ostream& operator<<(ostream &out, const expression &exp)
{
    out<< exp.expressionToStore;
    return out;
}

//FRIEND BASIC OPERATORS
expression operator+(const expression &one, const expression &two)
{
    expression third;
    for (unsigned int i = 0 ; i < one.terms.size() ; ++i)
        third.terms.push_back(one.terms[i]);
    for (unsigned int i = 0 ; i < two.terms.size() ; ++i)
        third.terms.push_back(two.terms[i]);
    third.addCommonTerms();
    third.changeExpression();
    return third;
}

expression operator-(const expression &one, const expression &two)
{
    expression third;
    expression copyOfSecond;
    copyOfSecond = two;

    for (unsigned int i = 0 ; i < copyOfSecond.terms.size() ; ++i)
        copyOfSecond.terms[i].coef = copyOfSecond.terms[i].coef * fraction(-1);
    for (unsigned int i = 0 ; i < copyOfSecond.terms.size() ; ++i)
        third.terms.push_back(copyOfSecond.terms[i]);
    for (unsigned int i = 0 ; i < one.terms.size() ; ++i)
        third.terms.push_back(one.terms[i]);

    copyOfSecond.destroy();
    third.addCommonTerms();
    third.changeExpression();
    return third;
}

expression operator*(const expression &one, const expression &two)
{
    expression third;
    for (unsigned int i = 0 ; i < one.terms.size() ; ++i)
    {
        for (unsigned int j = 0 ; j < two.terms.size() ; ++j)
        {
            term temp;
            temp.coef = one.terms[i].coef * two.terms[j].coef;
            temp.power = one.terms[i].power + two.terms[j].power;
            third.terms.push_back( temp);
        }
    }
    third.addCommonTerms();
    third.changeExpression();
    return third;
}

expression operator/(const expression &one, const expression &two)
{
   //TODO
    return one*two;
}

expression operator+(const expression &one, const fraction &num)
{
    expression two = one;
    term temp;
    temp.coef = num;
    temp.power = 0;
    two.terms.push_back(temp);
    two.addCommonTerms();
    two.changeExpression();
    return two;
}

expression operator-(const expression &one, const fraction &num)
{
    expression two = one;
    term temp;
    temp.coef = num*fraction(-1);
    temp.power = 0;
    two.terms.push_back(temp);
    two.addCommonTerms();
    two.changeExpression();
    return two;
}

expression operator*(const expression &one, const fraction &num)
{
    expression two = one;
    for (unsigned int i = 0 ; i < two.terms.size(); ++i)
    {
        two.terms[i].coef = two.terms[i].coef * num;
    }
    two.addCommonTerms();
    two.changeExpression();
    return two;
}

expression operator/(const expression &one, const fraction &num)
{
    expression two = one;
    for (unsigned int i = 0 ; i < two.terms.size(); ++i)
        two.terms[i].coef = two.terms[i].coef / num;

    two.addCommonTerms();
    two.changeExpression();
    return two;
}

expression operator^(const expression &one, const int degree)
{
    expression two = one;
    if (degree == 0)
    {
        return two;
    }
    else if (degree>0)
    {
        for (int i = 1; i < degree ; ++i)
            two = two * one;
    }else if (degree < 0)
    {
        return two;
    }
    two.addCommonTerms();
    two.changeExpression();
    return two;
}

//******************************************************************************
//******************************************************************************
//PRIVATE FUNCTIONS PART I:
void expression::copy(const expression &other)
{
    expressionToStore = other.expressionToStore;
    terms = other.terms;
}

fraction expression::makeFractionFrom(string input)
{
    if (input.empty())
        return fraction(1);
    else if (input == "-")
        return fraction(-1);

    if (input.find('/') != string::npos) // -> fraction
    {
        string numer = input.substr(0,input.find('/'));
        string denom = input.substr(input.find('/')+1);
        return fraction (stod(numer), stod(denom));
    }else if (input.find('^') != string::npos){
        double base = stod(input.substr(0, input.find('^')));
        double degree = stod(input.substr(input.find('^')+1));
        return fraction (pow(base,degree));
    }else
        return fraction(stod(input));
}

string expression::termToString (term input)
{
    string temp;
    string coef = fractionToString(input.coef);
    string pow = fractionToString(input.power);

    if (coef.empty())
        return "";
    else if (coef == "1")
        temp += "";
    else
        temp += coef;

    if (pow.empty())
        return coef;
    else if (pow == "(-1)")
        return  temp + "/" + variable;
    else if (pow == "1")
        return temp + variable;
    else
        temp += variable + "^" + pow;

    return temp;
}

string expression::fractionToString (fraction input)
{
    int numer = input.getNumer();
    int denom = input.getDenom();
    if (numer == 0)
      return "";

    if (denom == 1 && numer > 0)
        return to_string(numer);
    else if ( denom == 1 && numer < 0)
        return  "(" + to_string(numer) + ")";

    if (input > 0)
      return to_string(numer) + "/" + to_string(denom);
    else
      return  "("+ to_string(numer) + "/" + to_string(denom) + ")";
}

double expression::stod(const string &x) const
{
    stringstream ss;
    double value;
    ss<<x;
    ss>>value;
    return value;
}

void expression::printTerms()     //for testing
{
    for (unsigned int i = 0 ; i < terms.size(); ++i)
    {
        cout << "Term" << i+1 << " :" << endl;
        cout << "coeff = " <<terms[i].coef << endl;
        cout << "power = "<<terms[i].power << endl;
    }
}

//******************************************************************************
//******************************************************************************
//PRIVATE FUNCTIONS PART II:
void expression::makeTerms(string input)
{
    string operators = "+-";
    if (input.empty())
    {
        return;
    }else
    {
        string temp;
        for (unsigned int i = 0 ; i < input.size(); ++i)
        {
            if (operators.find((input[i])) != string::npos && i != 0
                    && input[i-1] != '^'&& input[i-1] != '(')
            {
                tokens.push_back(temp);
                return makeTerms(input.substr(i));
            }
            temp.push_back(input[i]);
            if (i == input.size()-1)
                tokens.push_back(temp);
        }
    }
}

void expression::getTerms()
{
    for (unsigned int i = 0 ; i < tokens.size(); ++i)
        getTerms(tokens[i]);
}

void expression::getTerms(string input)
{
    term aTerm;
    string coef, pow;
    if (input[0] == '+')
        input.erase(0,1);

    if (input.find("X") == string::npos) //not found -> input is a constant
    {
        aTerm.coef = makeFractionFrom (input);
        aTerm.power = fraction (0);
        terms.push_back(aTerm);
        return;
    }
    else //term contains variable
    {
        coef = input.substr(0,input.find("X")); //everything before X
        if (input.find('^') != string::npos )
            pow = input.substr(input.find('^')+1); //everything after ^
        else
            pow = "1";  //there is no ^ -> pow = 1;
    }

     fraction coe = makeFractionFrom(coef);
     fraction po = makeFractionFrom(pow);
     aTerm.coef = coe;
     aTerm.power = po;
     terms.push_back(aTerm);
}

void expression::addCommonTerms()
{
    for (unsigned int i = 0 ; i < terms.size(); ++i)
    {
        for (unsigned int j = i+1; j< terms.size(); ++j)
        {
            if (terms[i].power == terms[j].power)
            {
                terms[i].coef += terms[j].coef;
                terms[j].coef = 0;
            }

        }
    }

}

void expression::removeUselessTerm()
{
    vector<int> whereToErase;
    for (unsigned int i = 0 ; i < terms.size(); ++i)
    {
        if(terms[i].coef == 0)
            whereToErase.push_back(i);
    }
    int counter = 0;
    for ( unsigned int i = 0 ; i < whereToErase.size(); ++i)
    {
            terms.erase(terms.begin()+ whereToErase[i] + counter);
            counter--;
    }
}

void expression::sortTerms ()
{
    for (unsigned int i = 0 ; i < terms.size(); ++i)
    {
         int maxIndex = i;
         for (unsigned int j = i+1 ; j < terms.size(); ++j)
         {
             if (terms[maxIndex].power < terms[j].power)
                 maxIndex = j;
         }
         swapTerms(terms, maxIndex, i);
    }
}

void expression::swapTerms(vector<term> &terms,const int &i,const int &j)
{
    term temp = terms[i];
    terms[i] = terms[j];
    terms[j] = temp;
}

void expression::changeExpression()
{
    removeUselessTerm();
    sortTerms();
    if (terms.size() == 0)
    {
        expressionToStore = "0";
        return;
    }

    string temp;

    for (unsigned int i = 0 ; i < terms.size(); ++i)
    {
        if ( i != 0)
        {
            temp += " + ";
        }
        temp += termToString(terms[i]);
    }
    expressionToStore = temp;
}

void expression::destroy()
{
    term zero;
    zero.coef = 0;
    zero.power = 0;
    for (int i = terms.size()-1 ; i >= 0; --i)
    {
        terms[i] = zero;
        terms.erase(terms.begin()+i);
    }
    expressionToStore.clear();
    terms.clear();
}
