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
        this->m_array = new T[capacity];             //����ռ�

        if( this->m_array != NULL)                    //����ɹ�
        {
            this->m_length = 0;                       //����ֵ
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

    void resize(int capacity)                          //���ô洢�ռ�
    {
        if( capacity != m_capacity )                  //����¿ռ��뵱ǰ��ͬ
        {
            T* array = new T[capacity];               //arrayָ�������Ķѿռ�
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
