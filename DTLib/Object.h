#ifndef OBJECT_H
#define OBJECT_H

/**************************************************
  *************顶层父类******************
  ************************************************/


namespace DTLib
{

class Object                              //统一动态内存申请行为
{
public:
    void* operator new(unsigned int size) throw();
    void operator delete (void* p);
    void* operator new[] (unsigned int size) throw();
    void operator delete[] (void* p);
    bool operator == (const Object& obj);
    bool operator != (const Object& obj);
    virtual ~Object() = 0;                      //纯虚父类
};

}

#endif // OBJECT_H
