#ifndef FRANK_LIST_H
#define FRANK_LIST_H

#include <initializer_list>

namespace STL
{
template <typename T>
class FrancList
{
public:
	FrancList() = default;
	FrancList(const FrancList<T>&);
	FrancList(FrancList<T>&&);
	FrancList(const std::initializer_list<T>&);
public:
	void push_back(const T&);
	void push_front(const T&);
	size_t size()const;
	bool empty()const;
private:
	struct Node
	{
		T _elem{};
		Node* _prev{};
		Node* _next{};
		Node* _greator{};
		Node* _smoler{};
	public:
		Node()=default;
		Node(const T& elem, Node* next = nullptr , Node* prev = nullptr):_elem{elem},_prev{prev},
								_next{next},_greator{},_smoler{} {}
	};
private:
	void putSort(Node*);
public:
	class iterator
	{
	public:
		iterator()=default;
		iterator(Node* p)
		{
			this->_ptr = p;
		}
		iterator operator++()
		{
			_ptr=_ptr->_next;
			return _ptr;
		}
		iterator operator++(int)
		{
			_ptr=_ptr->_greator;
			return _ptr;
		}
		iterator operator--()
		{
			_ptr=_ptr->_prev;
			return _ptr;
		}
		iterator operator--(int)
		{
			_ptr=_ptr->_smoler;
			return _ptr;
		}
		bool operator==(iterator other)
		{
			return _ptr == other._ptr;
		}
		bool operator!=(iterator other)
		{
			return _ptr != other._ptr;
		}
		T& operator*()
		{
			return _ptr->_elem ;
		}
	private:
		Node* _ptr{};
	};
	iterator begin()const
	{
		iterator beg(_head);
		return beg;
	}
	iterator end()const
	{
		iterator end;
		return end;
	}
	iterator sbegin()
	{
		iterator beg(_sHead);
		return beg;
	}
private:
	Node* _head{};
	Node* _tail{};
	Node* _gHead{};
	Node* _sHead{};
};/*end of FrancList*/

}/*end of namespace STL*/

#include "Frankenshtein_list.hpp"

#endif /* FRANK_LIST_H */
