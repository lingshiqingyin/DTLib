#ifndef SMARTPOINT_H
#define SMARTPOINT_H

#include "Object.h"
namespace DTLib
{

/*******************************************************************************
���������� ָ���������ڽ���ʱ�����ͷ��ڴ�
         һƬ�ѿռ����ֻ����һ��ָ���ʶ
         �ž�ָ�������ָ��Ƚ�
*******************************************************************************/
template <typename T>
class SmartPoint : public Object
{
protected:
    T* m_pointer;
public:
    SmartPoint(T* p = NULL)                                  //pָ��գ����캯��
    {
        m_pointer = p;                                       //m_pointerָ���
    }

    SmartPoint(const SmartPoint <T>& obj)                    //���ƹ��캯��
    {
        m_pointer = obj.m_pointer;
        const_cast<SmartPoint<T>&>(obj).m_pointer = NULL;    //ǿ������ת��ȥ��obj��const����,�˾��Ӧ���������������ͷ�
    }

    SmartPoint<T>& operator = (const SmartPoint<T>& obj)     //��Ӧ������������Ұָ��
    {
        if(this != &obj)                                     //���㲻���Ը�ֵʱ
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

    bool isNull()                                                    //�жϵ�ǰ������ָ���Ƿ�Ϊ��
    {
        return (m_pointer == NULL);
    }

    T* get()
    {
        return m_pointer;
    }

    ~SmartPoint()                                        //�����ͷŶѿռ䣬����ָ������ĵĹ���
    {
        delete m_pointer;
    }
};
}
#endif // SMARTPOINT_H
