#ifndef LINKLIST_H
#define LINKLIST_H

/******************************************
  *****线性表的链式存储结构之单链表实现******
  ****************************************/

#include "List.h"
#include "exception.h"
namespace DTLib
{

template <typename T>

class LinkList : public List<T>
{
protected:
    struct Node : public Object
    {
        T value;
        Node* next;
    };
   mutable struct : public Object
    {
         char reserved[sizeof(T)];//数组
         Node* next;
     }m_header;
   int m_length;
   int m_step;
   Node* m_current;

   Node* position(int i)const                       //用来优化代码
   {
       Node* ret = reinterpret_cast<Node*>(&m_header);

       for(int p=0; p<i; p++)
       {
           ret = ret->next;
       }
       return ret;
   }

  virtual Node* create()                  //封装new行为
   {
       return new Node();
   }

   virtual void destroy(Node* pn)
   {
       delete pn;
   }


public:
    LinkList()
    {
      m_header.next = NULL;
      m_length = 0;
      m_step = 1;
      m_current = NULL;
    }
    bool insert(const T& e)                        //O(n)
    {
        return  insert(m_length, e);
    }
    bool insert(int i,const T& e)                  //O(n)
    {
        bool ret =((0 <= i) && (i <= m_length));

        if( ret )
        {
            Node* node = create();          //申请一个中间节点

            if( node != NULL )
            {
                /**********************************************
                Node* current = &m_header;    //当前指针指向头结点

                for(int p = 0; p < i; p++)
                {
                    current = current->next;   //寻找目标位置
                }
                **********************************************/

                Node* current = position(i);//优化后的代码
                node->value = e;
                node->next = current->next;
                current->next = node;

                m_length++;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughMemoeryException,"No memory to insert new element...");
            }

        }

        return ret;
    }
    bool remove(int i)                                    //O(n)
    {
         bool ret =((0 <= i) && (i <= m_length));

         if( ret )
         {
             /********************************************
             Node* current = &m_header;

             for(int p = 0; p < i; p++)
             {
                 current = current->next;
             }
             **********************************************/
             Node* current = position(i);

             Node* toDel = current->next;

             current->next = toDel->next;
             destroy(toDel);

             m_length--;

         }

         return ret;
    }
    bool set(int i,const T& e)                                 //O(n)
    {
         bool ret =((0 <= i) && (i <= m_length));
         if( ret )
         {
             /************************************
             Node* current = &m_header;

             for(int p = 0; p < i; p++)
             {
                 current = current->next;
             }
             ************************************/

             Node* current = position(i);
             current->next->value = e;
         }
         return ret;

    }

    T get(int i)const
    {
        T ret;

        if( get(i, ret) )
        {
            return ret;

        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"Invalid parameter i to get element...");
        }

        return ret;
    }
    bool get(int i,T& e) const                                //O(n)
    {
        bool ret =((0 <= i) && (i <= m_length));
        if( ret )
        {
            /*********************************************
            Node* current = &m_header;

            for(int p = 0; p < i; p++)
            {
                current = current->next;
            }
            **********************************************/
            Node* current = position(i);
            e = current->next->value;
        }
        return ret;

    }

    int find(const T& e)const                     //O(n)
    {
        int ret = -1;
        int i = 0;
        Node* node = m_header.next;

        while( node )
        {
            if( node->value == e)               //当T类型为类类型，则无法通过
            {
                ret = i;
                break;
            }

            else
            {
                node = node->next;
                i++;
            }

        }

        return ret;
    }
    int length() const                                 //O(1)
    {
       return m_length;

    }
    void clear()                                        //O(n)
    {
        while( m_header.next )
        {
            Node* toDel = m_header.next;

            m_header.next = toDel->next;

            destroy(toDel);
        }

        m_length = 0;

    }

    int move(int i, int step = 1)
    {
        bool ret = (0 <= i) && (i <= m_length) && (step > 0);

        if( ret )
        {
            m_current = position(i)->next;
            m_step = step;
        }
        return ret;

    }

    bool end()
    {
        return (m_current == NULL);
    }

    T current()
    {
        if(!end())
        {
            return m_current->value;
        }
        else
        {
            THROW_EXCEPTION(InvalidOperationException,"No value at current position..");
        }
    }

    bool next()
    {
        int i = 0;
        while((i < m_step) && !end())
        {
            m_current = m_current->next;
            i++;
        }
        return(i == m_step);
    }
    ~LinkList()                                        //O(n)
    {
        clear();
    }

};

}
#endif // LINKLIST_H
