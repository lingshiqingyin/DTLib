#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H


#include "SeqList.h"
namespace DTLib
{

template <typename T>
class DynamicList : public SeqList<T>
{
protected:
    int m_capacity;
public:
    DynamicList(int capacity)
    {
        this->m_array = new T[capacity];             //申请空间

        if( this->m_array != NULL)                    //如果成功
        {
            this->m_length = 0;                       //赋初值
            this->m_capacity = capacity;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoeryException,"No memory to create DynamicList object...");
        }

    }
    int capacity() const
    {
        return m_capacity;
    }

    void resize(int capacity)                          //重置存储空间
    {
        if( capacity != m_capacity )                  //如果新空间与当前不同
        {
            T* array = new T[capacity];               //array指向连续的堆空间
            if( array != NULL )                       //
            {
                int length = (this->m_length < capacity ? this->m_length : capacity);        //
                for( int i=0; i<length; i++)
                {
                    array[i] = this->m_array[i];
                }

                T* temp = this->m_array;

                this->m_array = array;
                this->m_length = length;
                this->m_capacity = capacity;

                delete[] temp;
            }

            else
            {
                 THROW_EXCEPTION(NoEnoughMemoeryException,"No memory to create DynamicList object...");
            }
        }
    }

    ~DynamicList()
    {
        delete[] this->m_array;
    }
};








}


#endif // DYNAMICLIST_H
