#ifndef EXCEPTION_H
#define EXCEPTION_H

#include "Object.h"
namespace DTLib
{

#define THROW_EXCEPTION(e, m) (throw e(m,__FILE__,__LINE__))
class Exception : public Object
{
protected:
    char* m_message;                                //异常的详细信息
    char* m_location;                               //异常发生的详细地点

    void init(const char* message,const char* file, int line);   //完成初始化工作
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message,const char* file, int line);

    Exception(const Exception& e);
    Exception& operator= (const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0;
};

class ArithmeticException : public Exception    //计算异常
{
public:
    ArithmeticException() : Exception(0){}
    ArithmeticException(const char* message) : Exception(message){}
    ArithmeticException(const char* file, int line) : Exception(file ,line){}
    ArithmeticException(const char *message, const char* file, int line) : Exception(message, file,line){}

    ArithmeticException(const ArithmeticException& e) : Exception(e){}
    ArithmeticException& operator= (const ArithmeticException &e)
    {
        Exception::operator =(e);
        return *this;
    }
};


class NullPointerException : public Exception                //空指针异常
{
public:
    NullPointerException() : Exception(0){}
    NullPointerException(const char* message) : Exception(message){}
    NullPointerException(const char* file, int line) : Exception(file,line){}
    NullPointerException(const char* message, const char * file, int line) : Exception(message,file,line){}

    NullPointerException(const NullPointerException& e) : Exception(e){}
    NullPointerException& operator =(const NullPointerException &e)
    {
        NullPointerException::operator =(e);
        return *this;
    }
};


class NoEnoughMemoeryException : public Exception         //内存不足异常
{
public:
    NoEnoughMemoeryException() : Exception(0){}
    NoEnoughMemoeryException(const char* message) : Exception(message){}
    NoEnoughMemoeryException(const char* file, int line) : Exception(file ,line){}
    NoEnoughMemoeryException(const char *message, const char* file, int line) : Exception(message, file,line){}

    NoEnoughMemoeryException(const NoEnoughMemoeryException& e) : Exception(e){}
    NoEnoughMemoeryException& operator= (const NoEnoughMemoeryException &e)
    {
        Exception::operator =(e);
        return *this;
    }
};



class InvalidOperationException : public Exception               //参数错误异常
{
public:
    InvalidOperationException() : Exception(0){}
    InvalidOperationException(const char* message) : Exception(message){}
    InvalidOperationException(const char* file, int line) : Exception(file ,line){}
    InvalidOperationException(const char *message, const char* file, int line) : Exception(message, file,line){}

    InvalidOperationException(const InvalidOperationException& e) : Exception(e){}
    InvalidOperationException& operator= (const InvalidOperationException &e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class IndexOutOfBoundsException : public Exception                   //越界异常
{
public:
    IndexOutOfBoundsException() : Exception(0){}
    IndexOutOfBoundsException(const char* message) : Exception(message){}
    IndexOutOfBoundsException(const char* file, int line) : Exception(file ,line){}
    IndexOutOfBoundsException(const char *message, const char* file, int line) : Exception(message, file,line){}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e) : Exception(e){}
    IndexOutOfBoundsException& operator= (const IndexOutOfBoundsException &e)
    {
        Exception::operator =(e);
        return *this;
    }
};


}
#endif // EXCEPTION_H
