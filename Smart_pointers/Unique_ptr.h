#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>
#include <functional>

namespace STL{
template<typename T , typename deletor = std::function<void(T*)> >
class Unique_ptr
{
public:
	Unique_ptr(T*);
	Unique_ptr(T*,deletor);
	Unique_ptr(deletor);
	Unique_ptr(Unique_ptr&);
	~Unique_ptr();
public:
	T& get()const;
	deletor getDeletor()const;
public:
	T& operator*()const;
	T& operator->()const;
	T& operator[](size_t);
	const T& operator[](size_t)const;
	bool operator==(const Unique_ptr&)const;
	bool operator!=(const Unique_ptr&)const;
	bool operator>=(const Unique_ptr&)const;
	bool operator<=(const Unique_ptr&)const;
	bool operator>(const Unique_ptr&)const;
	bool operator<(const Unique_ptr&)const; 
private:
	void clear();
	T* ptr;
	deletor del;
};/*end of class Unique_ptr*/
};/*end of namespace STL*/
#include "Unique_ptr.hpp"

template<typename T , typename deletor>
std::ostream& operator<<(std::ostream& os,const STL::Unique_ptr<T,deletor>& other)
{
	os<< other.get();
	return os;
}

#endif /*UNIQUE_PTR_H*/
