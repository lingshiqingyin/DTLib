#ifndef STATICARRAY_H
#define STATICARRAY_H

#include "Array.h"

namespace DTLib
{
/*****************************************
*****封装原生数组**************
*****使用模板参数决定数组大小****
*****实现函数返回数组长度********
*****拷贝构造和赋值操作**********
*****************************************/
template < typename T, int N >
class StaticArray : public Array<T>
{
protected:
    T m_space[N];
public:
    StaticArray()                  //O(1)
    {
        this->m_array = m_space;
    }
    StaticArray(const StaticArray<T,N>& obj)   //O(n)          拷贝构造
    {
        this->m_array = m_space;

        for(int i = 0; i<N; i++)
        {
            m_space[i] = obj.m_array[i];
        }
    }
    StaticArray<T,N>& operator = (const StaticArray<T,N>& obj)       //O(n)
    {
        if( this != &obj )
        {
            for(int i=0; i<N; i++)
            {
                m_space[i] = obj.m_space[i];
            }
        }
        return *this;
    }
    int length() const                                          //O(1)
    {
        return N;
    }
};





















}

#endif // STATICARRAY_H
