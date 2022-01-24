#include <iostream>
#include <list>
#ifndef QUEUE_H
#define QUEUE_H

namespace STL
{
template <typename T>
class Queue
{
public:
	void push(const T&);
	T pop();
	size_t size()const;
	bool empty() const;

private:
	std::list<T> _ls ;
};

}/*end of STL*/

#include "Queue.hpp"

#endif /*end of QUEUE_H*/
