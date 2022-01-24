#include <iostream>
#include <list>

#include "Queue.h"

namespace STL
{

template <typename T>
void Queue<T>::push(const T& elem)
{
	_ls.push_back(elem);	
}

template <typename T>
T Queue<T>::pop()
{
	T tmp = _ls.front();
	_ls.pop_front();
	return tmp;
}

template <typename T>
size_t Queue<T>::size()const
{
	return _ls.size();
}

template <typename T>
bool Queue<T>::empty()const
{
	return _ls.size() == 0 ;
}

}/*end of STL*/
