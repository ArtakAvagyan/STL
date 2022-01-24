#include <iostream>
#include <vector>
#include <initializer_list>

#ifndef DEQUE_H
#define DEQUE_H

namespace STL
{

template <typename T>
class Deque
{
public:
	Deque();
	Deque(size_t,size_t);
	Deque(const Deque<T>&);
	Deque(Deque<T>&&);
	Deque(const std::initializer_list<T>&);

public:
	void push_back(const T&);
	void push_front(const T&);
	inline void shrink_to_fit();
	void clear();
	T& at(const size_t);
	inline size_t size()const;
	inline bool empty()const;
	const T& at(const size_t)const;
	inline T& front()const;
	inline T& back()const;

public:
	T& operator[](const size_t);
	const T& operator[](const  size_t)const;
	Deque<T>& operator=(const Deque<T>&);
	Deque<T>& operator=(Deque<T>&&);
	Deque<T>& operator+(const Deque<T>&);
	Deque<T>& operator+=(const Deque<T>&);

private:
	std::vector<T>_left;
	std::vector<T>_right;
	int _balansFactor;

};/* end of class Deque */


}/* end of STL */

#endif /* DEQUE_H */
