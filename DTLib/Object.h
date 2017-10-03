#ifndef OBJECT_H
#define OBJECT_H

/**************************************************
  *************���㸸��******************
  ************************************************/


namespace DTLib
{

class Object                              //ͳһ��̬�ڴ�������Ϊ
{
public:
    void* operator new(unsigned int size) throw();
    void operator delete (void* p);
    void* operator new[] (unsigned int size) throw();
    void operator delete[] (void* p);
    bool operator == (const Object& obj);
    bool operator != (const Object& obj);
    virtual ~Object() = 0;                      //���鸸��
};

}

#endif // OBJECT_H
