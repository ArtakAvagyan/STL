#ifndef LIST_H
#define LIST_H

#include <iostream>
namespace STL
{
template<typename T>
class List
{
public:
	List();
	List(T);
	List(const List<T>&);
	List(List<T>&&);
	~List();
	//      List(const initializer_list<T>&);
public:
	List<T>& operator+=(const List<T>&);
	List<T>& operator=(const List<T>&);
	List<T>& operator=(List<T>&&);
	T& operator[](size_t)const;
/*      bool operator==(const List&)const;
	bool operator!=(const List&)const;*/
public:
	T& front()const;
	T& back()const;
	bool empty()const;
	size_t size()const;
	void clear();
//      void insert(T&);
	void insert(size_t,const T&);
//	void insert(iterator,T);
	void erase(size_t);
	//void erase(iterator);
	void push_back(const T&);
/*      //void emptace_back()
	T& pop_back();*/
	void push_front(const T&);
	T pop_front();
//      void resize(size_t,const T&);
	void swap(List<T>&);
	void swap(size_t,size_t);
//      void marg(List&);
	void splic(List&,size_t,size_t);
        void revers();
/*	void unique();*/
	void sort();
	void traverse(void(*p)(const T&));
private:
	struct Node 
	{
		T m_value;
		Node* m_next;
		Node():m_value{0},m_next{nullptr}{}
		Node(const Node& other):m_next{other.m_next},m_value{other.m_value}{}
		Node(T val,Node* next = nullptr):m_value{val},m_next{next}{}
		Node& operator=(const Node& other)
		{
			if( this == &other){return *this;}
			m_next = other.m_next;
			m_value = other.m_value;
			return *this;
		}
		void swap(Node& other)
		{
			Node tmp(other);
			other = *this;
			*this = tmp;
		}
		Node& operator*(){return *this;}
	};
private:
	void _revers(Node* ptr)
	{
	if(ptr == nullptr) {return;}
	if(ptr->m_next == nullptr)
	{
		root = ptr;
		return;
	}
	_revers(ptr->m_next);
	auto tmp = ptr->m_next;
	tmp->m_next = ptr;
	ptr->m_next = nullptr;
}

public:
	class iterator:public std::iterator<std::forward_iterator_tag,T>
	{
	public:
		iterator() = default;
		iterator(Node* other):_ptr{other}{}
		iterator(const iterator& other):_ptr{other._ptr}{}
	public:
		bool operator!=(const iterator& other)
		{
			return _ptr != other._ptr;
		}
		bool operator==(const iterator& other)
		{
			return _ptr == other._ptr;
		}
	       	iterator& operator=(const iterator& other)
		{
			_ptr = other._ptr;
			return *this;
		}
		T& operator*() { return _ptr->m_value; }
		iterator operator++() 
		{
			_ptr = _ptr->m_next;
			return _ptr;
	       	}
		iterator operator++(int) 
		{
			_ptr = _ptr->m_next;
			return _ptr;
	       	}

	private:
		Node* _ptr{};
	};
	iterator begin()const
	{
		return root;
	}
	iterator end()const
	{
		return nullptr;
	}
private:
	Node* root;
};/*class List*/

};/*namespace STL*/

#endif /*LIST_H*/
