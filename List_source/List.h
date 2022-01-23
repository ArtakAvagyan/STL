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
				//void insert(iterator,T);
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
				/*      void revers();
					void unique();
					void sort();*/
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
				Node* root;
		};/*class List*/
};/*namespace STL*/
#endif /*LIST_H*/
