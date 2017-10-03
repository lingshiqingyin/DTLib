#include "exception.h"
#include <cstring>
#include <cstdlib>
using namespace std;
namespace DTLib
{
void Exception::init(const char *message, const char *file, int line)    //file文件名，line行号
{
    m_message = strdup(message);                   //m_message指向堆空间的一个字符串

    if( file != NULL )
    {
            char sl[16] = {0};
            itoa(line, sl, 10);
            m_location =static_cast<char*>( malloc(strlen(file) + strlen(sl) + 2));      //将文件名和行号拼接，2一部分存储：，一部分存储结束符

            if( m_location != NULL )
            {
                m_location = strcpy(m_location,file);
                m_location = strcat(m_location, ":");
                m_location = strcat(m_location,sl);
            }

    }
    else
    {
       m_location = NULL;
    }
}
Exception::Exception(const char* message)
{
    init(message, NULL, 0);
}
Exception::Exception(const char* file, int line)
{
    init(NULL,file, line);
}
Exception::Exception(const char* message,const char* file, int line)
{
    init(message, file, line);
}

Exception::Exception(const Exception& e)
{
    m_message =  strdup(e.m_message);
    m_location = strdup(e.m_location);
}
Exception& Exception::operator= (const Exception& e)
{
    if( this != &e)                      //判断是否自赋值
    {
        free(m_message);
        free(m_location);

    m_message =  strdup(e.m_message);           //深拷贝
    m_location = strdup(e.m_location);

    }
    return *this;
}
const char* Exception:: message() const
{
      return m_message;
}
const char* Exception:: location() const
{
      return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}

}
