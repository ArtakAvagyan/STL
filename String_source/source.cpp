#include "String.h"

#include <cstring>

STL::String::String()
{
      m_size = 0;
      m_buffer = new char[m_size];
      m_buffer[0] = '\0' ;
}
STL::String::String(size_t size , char ch)
{
      m_size = size;
      m_buffer = new char[m_size+1];
      for (int i = 0 ; i < size;++i)
      {
            m_buffer[i] = ch ;
      }
      m_buffer[m_size] = '\0';
}
STL::String::String(size_t size)
{
      m_size = size;
      m_buffer = new char[m_size+1];
      for (int i = 0 ; i < size ; ++i)
      {
            m_buffer[i] = '\0';
      }
}
STL::String::String(const char* ch)
{
      m_size = strlen(ch);
      m_buffer = new char[m_size+1];
      for (int i = 0 ; i < m_size;++i)
      {
            m_buffer[i] = ch[i];
      }
      m_buffer[m_size] = '\0';
}
STL::String::String(const String& str)
{
      m_size = str.m_size;
      m_buffer = new char[m_size];
      for(int i = 0 ; i < m_size;++i)
      {
            m_buffer[i] = str.m_buffer[i];
      }
}

STL::String::String(String&& str)
{
      m_size = str.m_size;
      m_size = str.m_size;
      m_buffer = str.m_buffer;
      str.m_buffer = nullptr ;
}

STL::String::~String()
{
      delete[]m_buffer;
}
size_t STL::String::size()const
{
      return m_size;
}
void STL::String::Print()const
{
      std::cout<<m_buffer<<std::endl;
}
char& STL::String::operator[](size_t pos)
{
      return m_buffer[pos];
}
const char& STL::String::operator[](size_t pos)const
{
      return m_buffer[pos];
}

char& STL::String::at(size_t pos)
{
      if (pos > m_size+1){throw std::out_of_range("DUrses ekel taracqic");}
      return m_buffer[pos];
}

const char& STL::String::at(size_t pos)const
{
      if (pos > m_size+1){throw std::out_of_range("DUrses ekel taracqic");}
      return m_buffer[pos];
}

STL::String& STL::String::operator=(const STL::String& str)
{
      if (this == &str){return *this;}
      delete[] m_buffer;
      m_size = str.m_size;
      m_buffer = new char[m_size];
      for (int i = 0 ; i < m_size ; ++i)
      {
            m_buffer[i] = str[i];
      }
      return *this ;
}

STL::String& STL::String::operator=(const char* ch)
{
      delete[] m_buffer;
      m_size = std::strlen(ch);
      m_buffer = new char[m_size+1];
      for (int i = 0 ; i < m_size ; ++i)
      {
            m_buffer[i] = ch[i];
      }
      m_buffer[m_size] = '\0';
      return *this ;
}

std::ostream& STL::operator<<(std::ostream& os ,const STL::String& str)
{
      os<<str.m_buffer;
      return os ;
}

STL::String& STL::String::operator=(STL::String&& str)
{
      delete[] m_buffer;
      m_size = str.m_size;
      m_buffer = str.m_buffer;
      str.m_buffer = nullptr;
      return *this ;
}

int main()
{
      STL::String s;
      STL::String str("Artak");
      STL::String str2 (str);
      s = str ;
      std::cout<< s << "   " << str << "   " << str2 << std::endl;
}
