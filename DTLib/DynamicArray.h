#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include "Array.h"
#include "exception.h"
namespace DTLib
{
/*********************************************
**************��̬ȷ�������ڲ��ռ�Ĵ�С*****
**************ʵ�ֺ����������鳤�ȴ�С******
**************��������͸�ֵ����***********
*********************************************/


template <typename T>
class DynamicArray : public Array <T>
{
protected:
    int m_length;
    T* copy(T* array, int len, int newLen)
    {
        T* ret = new T[newLen];
        if( ret != NULL )
        {
            int size = ( len < newLen ) ? len : newLen;

            for(int i=0; i<size; i++)
            {
                ret[i] = array[i];
            }
        }
        return ret;
    }

    void update(T* array,int length)
    {
        if( array != NULL )
        {
            T* temp = this->m_array;

            this->m_array = array;
            this->m_length = length;

            delete[] temp;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoeryException,"No memory to update DynamicArray object...");
        }
    }

    void init(T* array, int length)
    {
        if( array != NULL )
        {
            this->m_array = array;
            this->m_length = length;
        }

        else
        {
            THROW_EXCEPTION(NoEnoughMemoeryException,"No memory to update DynamicArray object...");
        }
    }
public:
    DynamicArray(int length)
    {
        init(new T[length], length);
        /*****************************************************
        this->m_array = new T[length];
        if( this->m_array != NULL)
        {
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoeryException,"No memery to create DynamicArray object...");
        }*****************************************************/
    }
    DynamicArray(const DynamicArray<T>& obj)
    {
        T* array = copy(obj.m_array, obj.m_length, obj.m_length);

        init(array, obj.m_length);


        /*******************************************************
        this->m_array = new T[obj.m_length];
        if( this->m_array != NULL)
        {
            this->m_length = obj.m_length;
            for(int i=0; i<obj.m_length; i++)
            {
                this->m_array[i] = obj.m_array[i];
            }

        }
        else
        {
            THROW_EXCEPTION(NoEnoughMemoeryException,"No memery to create DynamicArray object...");
        }*********************************************************/
    }
    DynamicArray<T>& operator = (const DynamicArray<T>& obj)
    {
        if( this != &obj )                               //�ж��Ƿ��Ը�ֵ
        {

            update( copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);   //�Ż���ĳ���
          /*  *************************************************************��ʼ����
            T* array = new T[obj.m_length];              //�����µ�����ѿռ䣬�����Բ�������ĳ���Ϊ׼
            if( array != NULL )
            {
                for(int i=0; i<obj.m_length; i++)       //ʵ�ֿ���
                {
                    array[i] = obj.m_array[i];
                }
                T* temp = this->m_array;

                this->m_array = array;                   //��������Ķѿռ�ҽӵ�m_array
                this->m_length = obj.m_length;           //�����ȱ�������

                delete[] temp;                           //�ͷ�m_arrayָ��Ķѿռ�
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoeryException,"No memery to create DynamicArray object...");
            }*******************************************************************************/
        }

        return *this;
    }
    int length() const
    {
        return m_length;
    }
    void resize(int length)                //��̬�������鳤��
    {
        if( length != m_length )
        {


            T* array = copy(this->m_array, m_length, length);

            update(array, length);                                   //�Ż���Ĵ���
            /*************************************************************��ʼ����
            T* array = new T[length];
            if( array != NULL )
            {
                int size = (length < m_length) ? length : m_length;       //��С��ʱ��ζ��Ҫ��������Ԫ��

                for( int i=0; i<size; i++)
                {
                    array[i] = this->m_array[i];
                }
                T* temp = this->m_array;

                this->m_array = array;                   //��������Ķѿռ�ҽӵ�m_array
                this->m_length = length;           //�����ȱ�������

                delete[] temp;

            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoeryException,"No memery to resize object...");
            }**********************************************************************/

        }
    }
    ~DynamicArray()
    {
        delete[] this->m_array;
    }
};

}
#endif // DYNAMICARRAY_H
