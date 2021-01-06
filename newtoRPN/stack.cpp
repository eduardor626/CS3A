#include "stack.h"

stack::stack(unsigned int s)
{
    theStack = new string[size = s];
    tos = -1;
}

stack::stack(const stack &other)
{
    copy(other);
}

stack::~stack()
{
    removeAll();
}

stack& stack::operator=(const stack &other)
{
   if(this != &other)
    {
       removeAll();
       copy(other);
    }
    return *this;
}

void stack::push(const string &input)
{
   if(full())
       throw FULL;
   theStack[++tos] = input;
}

string stack::pop()
{
    if(empty())
        throw EMPTY;
    string value = theStack[tos--]; //t-- moves you down one in the array
    return value;
}

string stack::peek()
{
   if(empty())
       throw EMPTY;
    return theStack[tos];
}

bool stack::empty()
{
   return tos == -1;
}

bool stack::full()
{
   return tos == size-1;
}

int stack::items()
{
    return tos+1;
}

void stack::resize(int s)
{
    if(s < 2)
        throw INVALID_SIZE;
    string *temp = new string[s];
    for(unsigned int i = 0; i < s && i < size; ++i)
        temp[i] = theStack[i];
    removeAll();
    theStack = temp;
    size = s;
    if(tos >= s)
        tos = s-1;
}


stack& stack::operator<<(const string &input)
{
    push(input);
    return *this;
} //Another way to push

stack& stack::operator>>(string &output) //Another way to pop
{
    output = pop();
    return *this;
}

void stack::copy(const stack& other)
{
    size = other.size;
    theStack = new string[size];
    tos = other.tos;
    for(unsigned int i = 0; i < size; ++i)
            theStack[i] = other.theStack[i];
}

void stack::removeAll()
{
    for(unsigned int i = 0; i < size; ++i)
        theStack[i] = '\0';
    delete [] theStack;
    theStack = NULL;
}



ostream& operator<<(ostream& out, const stack &output)
{
    if(&out == &cout)
    {
        out<<"The stack contains "<<output.tos+1<<" values. They are: ";
        for(int i = output.tos; i >= 0; i--)
            out<<output.theStack[i]<<" ";
        out<<endl;
    }
    else
    {
        out<<"Size: "<<output.size<<endl;
        for(unsigned int i = 0; i < output.tos; ++i)
            out<<output.theStack[i]<<" ";
    }
    return out;
}

istream& operator>>(istream&in, stack &input)
{
    string line, value;
    int size;
    stringstream ss;
    if(&in == &cin)
    {
        cout<<"What is the size of the stack you wish to enter: ";
        cin>>size;
        input.resize(size);
        cout<<"Please enter values. End with ^D followed by Enter: ";
        while(in>>value)
            input.push(value);
    }
    else
    {
        getline(in,line);
        ss<<line.substr(line.find(' '));
        ss>>size;
        input.resize(size);
        while(in>>value)
            input.push(value);
    }

}
