#ifndef SMARTARRAY_H
#define SMARTARRAY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

enum SMARTARRAY_ERRORS {FULL = 1314, EMPTY, INDEX_OUT_OF_BOUNDS, INVALID_INPUT};

template<typename VALUE = int>
class smartArray
{
    public:
        smartArray();
        smartArray(unsigned int s);
        smartArray(const smartArray &other);
        ~smartArray();

        smartArray& operator=(const smartArray &other);
        VALUE& operator[](int i);
        unsigned int size();
        void resize(unsigned int newSize);
        void push_back(const VALUE &v);
        VALUE pop_back();\
        void sort();
        void swap(smartArray &other);

        template<typename Z>
        friend
        ostream& operator<<(ostream& out, const smartArray<Z> &array);

        template<typename Z>
        friend
        istream& operator>>(istream& in, smartArray<Z> &array);

    private:
        VALUE *ptr;
        unsigned int mySize;

        void copy(const smartArray &other);
        void nukem();
};


template<typename VALUE>
smartArray<VALUE>::smartArray()
{
    unsigned int s = 2;
    mySize = 2;
    ptr = new VALUE[s];
}

template<typename VALUE>
smartArray<VALUE>::smartArray(unsigned int s) : mySize(s), ptr(new VALUE[s])
{
}

template<typename VALUE>
smartArray<VALUE>::smartArray(const smartArray &other)
{
    copy(other);
}

template<typename VALUE>
smartArray<VALUE>::~smartArray()
{
    nukem();
}


template<typename VALUE>
smartArray<VALUE>& smartArray<VALUE>::operator=(const smartArray<VALUE> &other)
{
    if(this != &other)
    {
        nukem();
        copy(other);
    }
    return *this;
}

template<typename VALUE>
VALUE& smartArray<VALUE>::operator[](int i)
{
    if(i < 0 || i >= mySize)
        throw INDEX_OUT_OF_BOUNDS;
    return ptr[i]; // return *(ptr+i);
}

template<typename VALUE>
unsigned int smartArray<VALUE>::size()
{
    return mySize();
}

template<typename VALUE>
void smartArray<VALUE>::resize(unsigned int newSize)
{
    if(newSize < 0)
        throw INDEX_OUT_OF_BOUNDS;
    VALUE *ptr2 = new VALUE[newSize];
    for(int j = 0;
        j < (newSize < mySize ? newSize : mySize);
        ++j)
        ptr2[j] = ptr[j];
    nukem();
    ptr = ptr2;
    mySize = newSize;
}

template<typename VALUE>
void smartArray<VALUE>::push_back(const VALUE &v)
{

}

template<typename VALUE>
VALUE smartArray<VALUE>::pop_back()
{

}

template<typename VALUE>
void smartArray<VALUE>::sort()
{
    for(unsigned int i = 0; i < mySize; ++i)
      for(unsigned int j = 0; j < mySize; ++j)
          if(ptr[i] < ptr[j])
          {
              VALUE temp = ptr[i];
              ptr[i] = ptr[j];
              ptr[j] = temp;
          }
}

template<typename VALUE>
void smartArray<VALUE>::swap(smartArray &other)
{
    unsigned int temp = other.mySize;
    other.mySize = mySize;
    mySize = temp;

    VALUE *tptr = other.ptr;
    other.ptr = ptr;
    ptr = tptr;
}

template<typename VALUE>
void smartArray<VALUE>::copy(const smartArray &other)
{
    ptr = new VALUE[mySize = other.mySize];
    for(unsigned int i = 0; i < mySize; ++i)
        ptr[i] = other.ptr[i];
}

template<typename VALUE>
void smartArray<VALUE>::nukem()
{
   for(unsigned int i = 0; i < mySize; ++i)
       ptr[i] = VALUE();
   delete [] ptr;
   mySize = 0;
}

template<typename Z>
ostream& operator<<(ostream& out, const smartArray<Z> &array)
{
   if(&out == &cout)
   {
      out<<"Array values: ";
      for(unsigned int i = 0; i < array.mySize; ++i)
          out<<array.ptr[i]<<" ";
   }
   else
   {
      out<<"SIZE: "<<array.mySize<<endl;
      for(unsigned int i = 0; i < array.mySize; ++i)\
        out<<array.ptr[i]<<" ";
   }
   return out;
}

template<typename Z>
istream& operator>>(istream& in, smartArray<Z> &array)
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
        array=array(size);
        while(in>>input);
          array.ptr[index++] = input;
    }
}

#endif // SMARTARRAY_H
