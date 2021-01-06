#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;

enum myVector_ERRORS {FULL = 1314, EMPTY, INDEX_OUT_OF_BOUNDS, INVALID_INPUT, LESS_THAN_2_IN_SIZE};

template<typename M = int>
class myVector
{
    public:
        myVector();
        myVector(unsigned int s);
        myVector(const myVector &other);
        ~myVector();

        myVector& operator=(const myVector &other);
        unsigned int size();
        void resize(unsigned int newSize);
        void push_back(const M &v);
        void sortVector();
        void swap(myVector &other);
        void clear();
        void clean();
        M pop_back();
        M peek();
        M& operator[](unsigned int i);

        template<typename Z>
        friend
        ostream& operator<<(ostream& out, const myVector<Z> &array);

        template<typename Z>
        friend
        istream& operator>>(istream& in, myVector<Z> &array);

    private:
        M *ptr;
        unsigned int capacity;
        unsigned int tos;
        void copy(const myVector &other);
        void nukem();
};

/*******************************************************************************
*******************************************************************************/
template<typename M>
myVector<M>::myVector()
{
    capacity = 10;
    ptr = new M[capacity];
    tos = 0;
}

template<typename M>
myVector<M>::myVector(unsigned int s)
{
    if(s <= 2)
        throw LESS_THAN_2_IN_SIZE;
    capacity = s;
    ptr = new M[s];
    tos = 0;
}

template<typename M>
myVector<M>::myVector(const myVector &other)
{
    copy(other);
}

template<typename M>
myVector<M>::~myVector()
{
    nukem();
}

template<typename M>
myVector<M>& myVector<M>::operator=(const myVector<M> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

template<typename M>
M& myVector<M>::operator[](unsigned int i)
{
    if(i < 0 || i >= tos)
        throw INDEX_OUT_OF_BOUNDS;
    else if (tos == 0)
        throw EMPTY;
    else if (tos == INT_MAX)
        throw FULL;
    return ptr[i];
}

template<typename M>
unsigned int myVector<M>::size()
{
    return tos;
}

template<typename M>
void myVector<M>::resize(unsigned int newSize)
{
    if(newSize <= 0)
        throw INDEX_OUT_OF_BOUNDS;
    M *ptr2 = new M[newSize];
    for(unsigned int j = 0; j < (newSize < capacity ? newSize : capacity) ;++j)
        ptr2[j] = ptr[j];
    nukem();
    ptr = ptr2;
    capacity = newSize;
}

template<typename M>
void myVector<M>::push_back(const M &v)
{
    if (tos == capacity)
       this->resize(capacity*2);
    ptr[tos] = v;
    tos++;
}

template<typename M>
M myVector<M>::pop_back()
{
    M temp = ptr[tos];
    tos--;
    return temp;
}

template<typename M>
M myVector<M>:: peek()
{
    return ptr[tos];
}

template<typename M>
void myVector<M>::sortVector()
{
    sort(&ptr[0] , &ptr[tos]);
}

template<typename M>
void myVector<M>::swap(myVector &other)
{
    unsigned int temp = other.capacity;
    unsigned int temp2 = other.tos;
    M *temp3 = other.ptr;

    other.capacity = capacity;
    other.tos = tos;
    other.ptr = ptr;

    capacity = temp;
    tos = temp2;
    ptr = temp3;
}

template<typename M>
void myVector<M>::clear()
{
    myVector<M> defaultVector;
    copy(defaultVector);
}

template<typename M>
void myVector<M>::clean()
{
    nukem();
}

template<typename M>
void myVector<M>::copy(const myVector &other)
{
    capacity = other.capacity;
    tos = other.tos;
    ptr = new M[capacity];
    for(unsigned int i = 0; i < capacity; ++i)
        ptr[i] = other.ptr[i];
}

template<typename M>
void myVector<M>::nukem()
{
   for(unsigned int i = 0; i < capacity; ++i)
       ptr[i] = M();
   delete [] ptr;
}

template<typename Z>
ostream& operator<<(ostream& out, const myVector<Z> &array)
{
   if(&out == &cout)
   {
      out<<"Array contains: ";
      for(unsigned int i = 0; i < array.capacity; ++i)
          out<<array.ptr[i]<<" ";
   }
   else
   {
      out<<"SIZE: "<<array.capacity<<endl;
      for(unsigned int i = 0; i < array.capacity; ++i)\
        out<<array.ptr[i]<<" ";
   }
   return out;
}

template<typename Z>
istream& operator>>(istream& in, myVector<Z> &array)
{
    unsigned int size;
    Z input, index = 0;
    if(&in == &cin)
    {
        cout<<"New array size: ";
        cin>>size;
        array = array(size);
        while(in>>input)
            array.ptr[index++] = input;
    }
    else
    {
        stringstream ss;
        string line;
        getline(in,line);
        ss<<line.substr(line.find(':')+1);
        ss>>size;
        array = array(size);
        while(in>>input)
          array.ptr[index++] = input;
    }
    return in;
}
#endif // MYVECTOR_H
