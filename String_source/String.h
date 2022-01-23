#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstddef>

namespace STL
{

class String
{
public:

      String();
      String(size_t , char);
      String(size_t);
      String(const char*);
      String(const String&);
      String(String&&);
      ~String();
public:
      size_t size()const;
      void Print()const;
      char& at(size_t);
      const char& at(size_t)const;
public:
      char& operator[](size_t);
      const char& operator[](size_t)const;
      String& operator=(const String&);
      String& operator=(const char*);
      String& operator=(const String&&);
      bool operator==(const String&)const;
      bool operator!=(const String&)const;
      bool operator>(const String&)const;
      bool operator<(const String&)const;
      bool operator>=(const String&)const;
      bool operator<=(const String&)const;
public:
      friend std::ostream& operator<<(std::ostream&,const STL::String&);
      //friend std::istream& operator>>(std::istream&,String&);
private:
      size_t m_size;
      char* m_buffer;

};//class String
}//namespace STL
#endif //STRING_H
