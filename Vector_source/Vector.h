#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include <iostream>
#include <initializer_list>
#include <exception>

namespace STL
{
	template<typename T,typename Allocator = std::allocator<T>>
		class Vector
		{
			public:
				Vector(const std::initializer_list<T>&);/*Ctor initializer*/
				Vector();/*Defoult Ctor*/
				Vector(const Vector<T>&);/*Copy Ctor*/
				Vector (size_t);
				Vector(const Vector<T>&&);/*Move Ctor*/ /* +11 begin  */
				~Vector();/*Dtor*/
			public:
				T& operator[](size_t)const;
				//const T& operator[](size_t);
				const Vector<T> operator+(const Vector<T>&)const;/*arithmetic operator*/
				const Vector<T>& operator+=(const Vector<T>&);
				Vector<T>& operator=(const Vector<T>&); /*Copy assignment operator*/
				Vector<T>& operator=(Vector<T>&&);/*Move assignment operator*/ /*+11 begin*/
				bool operator==(const Vector<T>&)const;/*Logic operators*/
				bool operator!=(const Vector<T>&)const;
				bool operator>(const Vector<T>&)const;
				bool operator<(const Vector<T>&)const;
				bool operator>=(const Vector<T>&)const;
				bool operator<=(const Vector<T>&)const;
			public:
				T& at(size_t)const;
				size_t size()const;
				//	size_t max_size();
				size_t capacity()const;
				void shrint_to_fit();
				void swap(Vector<T>&);
				void reserve(size_t);
				void resize(size_t);
				void push_back(const T&);
				void assign(size_t,const T&);
				void clear();
				T pop_back();
				T& front()const;
				T& back()const;
				void erase(size_t);
				void erase(size_t,size_t);
			private:
				size_t m_size;
				size_t m_capacity;
				T* m_buffer;
				bool is_free;
			public:
				class iterator
				{
					public:
						iterator(T* it = nullptr)
						{
							m_it = it;
						}
						iterator(const iterator& it)
						{
							m_it = it.m_it;
						}
						T& operator*()const
						{
							return *m_it;
						}
						T& operator++()
						{
							++m_it;
							return *m_it;
						}
						T& operator++(int)
						{
							return ++m_it;
						}
						iterator& operator--()
						{
							return --m_it;
						}
						iterator& operator--(int)
						{
							return --m_it;
						}
						bool operator==(const iterator& rhs)const
						{
							return m_it == rhs.m_it;
						}
						bool operator!=(const iterator& rhs)const
						{
							return m_it != rhs.m_it;
						}
						const iterator operator+(size_t size)
						{
							return m_it + size;
						}
						const iterator operator-(size_t size)
						{
							return m_it - size;
						}
					private:
						T* m_it;
				};
				typename Vector<T,Allocator>::iterator begin()
        		        {
        		 		Vector<T,Allocator>::iterator it(m_buffer) ;
                			return it ;
               			}
            			typename Vector<T,Allocator>::iterator end()
    			        {
                   			Vector<T,Allocator>::iterator it(m_buffer + m_size) ;
               				return it ;
               			}
		};/*class Vector*/

};/*STL*/


#endif /*VECTOR_H*/
