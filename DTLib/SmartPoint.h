#ifndef SMARTPOINT_H
#define SMARTPOINT_H

#include "Object.h"
namespace DTLib
{

/*******************************************************************************
三个条件： 指针生命周期结束时主动释放内存
         一片堆空间最多只能由一个指针标识
         杜绝指针运算和指针比较
*******************************************************************************/
template <typename T>
class SmartPoint : public Object
{
protected:
    T* m_pointer;
public:
    SmartPoint(T* p = NULL)                                  //p指向空，构造函数
    {
        m_pointer = p;                                       //m_pointer指向空
    }

    SmartPoint(const SmartPoint <T>& obj)                    //复制构造函数
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPoint<T>&>(obj).m_pointer = NULL;    //强制类型转换去除obj的const属性,此句对应条件二，避免多次释放
    }

    SmartPoint<T>& operator = (const SmartPoint<T>& obj)     //对应条件三，避免野指针
    {
        if(this != &obj)                                     //满足不是自赋值时
        {
            delete m_pointer;
            m_pointer = obj.m_pointer;
            const_cast<SmartPoint<T>&>(obj).m_pointer = NULL;
        }
        return *this;
    }
    T* operator -> ()
    {
        return m_pointer;
    }

    T& operator *()
    {
        return *m_pointer;
    }

    bool isNull()                                                    //判断当前的智能指针是否为空
    {
        return (m_pointer == NULL);
    }

    T* get()
    {
        return m_pointer;
    }

    ~SmartPoint()                                        //主动释放堆空间，智能指针最核心的功能
    {
        delete m_pointer;
    }
};
}
#endif // SMARTPOINT_H
