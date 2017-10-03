#include <iostream>
#include "Object.h"
#include <cstdlib>
using namespace std;
namespace DTLib
{
    void* Object::operator new(unsigned int size) throw()          //throw表明当前重载函数不会抛出任何异常
    {
        return malloc(size);
    }
    void Object::operator delete (void* p)
    {
        free(p);
    }
    void* Object::operator new[] (unsigned int size) throw()
    {
        return malloc(size);
    }
    void Object::operator delete[] (void* p)
    {
        free(p);
    }

    bool Object :: operator == (const Object& obj)
    {
        return (this == &obj);
    }

    bool Object :: operator != (const Object& obj)
    {
        return (this != &obj);
    }
    Object::~Object()
    {

    }

}
