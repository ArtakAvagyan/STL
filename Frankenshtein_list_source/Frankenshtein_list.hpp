#include <iostream>

#include "Frankenshtein_list.h"
template <typename T>
STL::FrancList<T>::FrancList(FrancList<T>&& other):_head{std::move(other._head)},_tail{std::move(other._tail)}
			,_gHead{std::move(other._gHead)},_sHead{std::move(other._sHead)} {}
template <typename T>
STL::FrancList<T>::FrancList(const std::initializer_list<T>& l)
{
	for(const auto& it : l )
	{
		this->push_back(*it);
	}
}

template <typename T>
STL::FrancList<T>::FrancList(const FrancList<T>& other)
{
	auto it = other.begin();
	while (it != other.end())
	{
		this->push_back(*it);
		++it;
	}
}

template <typename T>
void STL::FrancList<T>::push_back(const T& elem)
{
	if (_head == nullptr)
	{
		_head = new Node(elem);
		_tail = _gHead = _sHead = _head ;
		return ;
	} else {
		_tail->_next = new Node(elem,nullptr,_tail);
		_tail = _tail->_next;
		putSort(_tail);
	}
}

template <typename T>
void STL::FrancList<T>::push_front(const T& elem)
{
	if (!_head)
	{
		_head = new Node(elem);
		_tail = _gHead = _sHead = _head ;
		return ;
	
	} else {
		_head->_prev = new Node(elem , _head , nullptr);
		_head = _head->_prev ;
		putSort(_head);
	}
}


template <typename T>
void STL::FrancList<T>::putSort(Node* lhs)
{
	if (_sHead->_elem < lhs->_elem)
	{
		Node* cur = _sHead;
		while (cur->_greator != nullptr && cur->_elem < lhs->_elem)
		{
			cur = cur->_greator;
		}
			if (cur->_elem > lhs->_elem)
			{
				cur = cur->_smoler;
			}
		if (cur->_greator)
		{
			Node* i = cur->_greator;
			i->_smoler = lhs;
		}
		lhs->_greator = cur->_greator;
		cur->_greator = lhs;
		lhs->_smoler = cur;
	} else {
		lhs->_greator = _sHead;
		_sHead->_smoler = lhs;
		_sHead = lhs;
	}
}
template <typename T>
size_t STL::FrancList<T>::size()const
{
	size_t size ;
	auto it = begin();
	while(it != this->end())
	{
		it++;
		size++;
	}
	return size;
}

template <typename T>
bool STL::FrancList<T>::empty()const
{
	return _head == nullptr;
}

