#ifndef NAMESPACES_H
#define NAMESPACES_H
#include <iostream>


using namespace std;


namespace english
{
    void hello();
    void goodBye();

    namespace aussie
    {
        void hello();
        void goodBye();
    }

    namespace uk
    {
        void hello();
        void goodBye();
    }
}

namespace french
{
    void hello();
    void goodBye();
}

namespace spanish
{
    void hello();
    void goodBye();
}

namespace portuguese
{
    void hello();
    void goodBye();
}

#endif // NAMESPACES_H
