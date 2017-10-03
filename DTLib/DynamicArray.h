#ifndef _DYNAMICARRAY_H_
#define _DYNAMICARRAY_H_

#include "Array.h"
#include "exception.h"
namespace DTLib
{
/*********************************************
**************动态确定数组内部空间的大小*****
**************实现函数返回数组长度大小******
**************拷贝构造和赋值操作***********
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
        if( this != &obj )                               //判断是否自赋值
        {

            update( copy(obj.m_array, obj.m_length, obj.m_length), obj.m_length);   //优化后的程序
          /*  *************************************************************初始代码
            T* array = new T[obj.m_length];              //申请新的数组堆空间，长度以参数对象的长度为准
            if( array != NULL )
            {
                for(int i=0; i<obj.m_length; i++)       //实现拷贝
                {
                    array[i] = obj.m_array[i];
                }
                T* temp = this->m_array;

                this->m_array = array;                   //将新申请的堆空间挂接到m_array
                this->m_length = obj.m_length;           //将长度保存下来

                delete[] temp;                           //释放m_array指向的堆空间
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
    void resize(int length)                //动态设置数组长度
    {
        if( length != m_length )
        {


            T* array = copy(this->m_array, m_length, length);

            update(array, length);                                   //优化后的代码
            /*************************************************************初始代码
            T* array = new T[length];
            if( array != NULL )
            {
                int size = (length < m_length) ? length : m_length;       //当小于时意味着要舍弃部分元素

                for( int i=0; i<size; i++)
                {
                    array[i] = this->m_array[i];
                }
                T* temp = this->m_array;

                this->m_array = array;                   //将新申请的堆空间挂接到m_array
                this->m_length = length;           //将长度保存下来

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
