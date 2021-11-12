#include "Vector.h"
	template<typename T,typename Allocator>
	STL::Vector<T,Allocator>::Vector(const std::initializer_list<T>& other)
	{
		m_size = other.size();
		m_capacity = other.size();
		m_buffer = new T [m_capacity];
		int i = 0;
		for(auto it : other)
		{
			m_buffer[i++] = it;
		}
		is_free = true ;
	}
	template<typename T,typename Allocator>
	STL::Vector<T,Allocator>::Vector()
	{
		m_capacity = 1;
		m_size = 0;
		m_buffer = new T [m_capacity];
		is_free = true ;
	}
	
	template<typename T,typename Allocator>
	STL::Vector<T,Allocator>::Vector(size_t size)
	{
		m_capacity = size;
		m_size = size;
		m_buffer = new T [m_capacity];
		is_free = true ;
	}
	
	template<typename T,typename Allocator>
	STL::Vector<T,Allocator>::~Vector()
	{
		if(is_free){delete[]m_buffer;}
		else{std::free(m_buffer);}
		
	}
	
	template<typename T,typename Allocator>
	STL::Vector<T,Allocator>::Vector(const Vector<T>& other)
	{
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_buffer = new T [m_size];
		for(int i = 0;i<m_size;++i)
		{
			m_buffer[i]=other.m_buffer[i];
		}
		is_free = true ;
	}

	template<typename T,typename Allocator>
	STL::Vector<T,Allocator>::Vector(const Vector<T>&& other)
	{
		m_capacity = other.m_capacity;
		m_size = other.m_size;
		m_buffer = other.m_buffer;
		other.m_buffer = nullptr;
		is_free = true ;
	}
	
	template<typename T,typename Allocator>
	T& STL::Vector<T,Allocator>::operator[](size_t index)const
	{
		return m_buffer[index];
	}

	template<typename T,typename Allocator>
	STL::Vector<T>& STL::Vector<T,Allocator>::operator=(const Vector<T>& other)
	{
		if(this == &other){return *this;}
		m_capacity = other.m_size;
		m_size = other.m_size;
		if(is_free){delete[]m_buffer;}
		else{std::free(m_buffer);}
		m_buffer = new T[m_capacity];
		for(int i = 0 ; i < m_size ;++i)
		{
			m_buffer[i]=other.m_buffer[i];
		}
		is_free = true ;
		return *this;
	}

	template<typename T,typename Allocator>
	STL::Vector<T>& STL::Vector<T,Allocator>::operator=(Vector<T>&& other)
	{
		m_size = other.m_size;
		m_capacity = m_size;
		if(is_free){delete[]m_buffer;}
		else{std::free(m_buffer);}
		m_buffer = other.m_buffer;
		other.m_buffer = nullptr;
		is_free = true;
	}

	template<typename T,typename Allocator>
	T& STL::Vector<T,Allocator>::at(size_t index)const
	{
		if(index >= m_size){throw std::out_of_range("OUT OF RANGE !!!");}
		return m_buffer[index];
	}	
	
	template<typename T,typename Allocator>
	const STL::Vector<T> STL::Vector<T,Allocator>::operator+(const STL::Vector<T>& other)
	{
		STL::Vector<T>tmp = other;
		for(int i = 0;i<m_size;++i)
		{
			tmp.push_back(m_buffer[i]);
		}
		return tmp;
	}
	template<typename T,typename Allocator>
	const STL::Vector<T>& STL::Vector<T,Allocator>::operator+=(const STL::Vector<T>& other)
	{
		for(int i = 0;i<other.m_size;++i)
		{
			push_back(other.m_buffer[i]);
		}
		return *this;
	}
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::push_back(const T& elem)
	{
		if(m_size == m_capacity)
		{
			is_free = true ;
			m_capacity*=2;
			T* tmp = new T[m_capacity];
			for(int i = 0 ; i < m_size ;++i)
			{
				tmp[i]=m_buffer[i];
			}
			delete[]m_buffer;
			m_buffer = tmp;
		}
		m_buffer[m_size++] = elem;
	}
	template<typename T,typename Allocator>
	size_t STL::Vector<T,Allocator>::size()const
	{
		return m_size;
	}

	template<typename T,typename Allocator>
	size_t STL::Vector<T,Allocator>::capacity()const
	{
		return m_capacity;
	}
	
	template<typename T,typename Allocator>
	bool STL::Vector<T,Allocator>::operator==(const Vector<T>& other)const
	{
		size_t size = m_size > other.m_size ? other.m_size : m_size ;
		for(int i = 0 ; i < size ; ++i)
		{
			if(m_buffer[i] != other.m_buffer[i])
			{
				return false;
			}
		}
		return true;
	}
	template<typename T,typename Allocator>
	bool STL::Vector<T,Allocator>::operator!=(const Vector<T>& other)const
	{
		size_t size = m_size > other.m_size ? other.m_size : m_size ;
		for(int i = 0 ; i < size ; ++i)
		{
			if(m_buffer[i] == other.m_buffer[i])
			{
				return false;
			}
		}
		return true;
	}
	template<typename T,typename Allocator>
	bool STL::Vector<T,Allocator>::operator>(const Vector<T>& other)const
	{
		size_t size = m_size > other.m_size ? other.m_size : m_size ;
		for(int i = 0 ; i < size ; ++i)
		{
			if(m_buffer[i] <= other.m_buffer[i])
			{
				return false;
			}
		}
		return true;
	}
	template<typename T,typename Allocator>
	bool STL::Vector<T,Allocator>::operator<(const Vector<T>& other)const
	{
		size_t size = m_size > other.m_size ? other.m_size : m_size ;
		for(int i = 0 ; i < size ; ++i)
		{
			if(m_buffer[i] >= other.m_buffer[i])
			{
				return false;
			}
		}
		return true;
	}
	template<typename T,typename Allocator>
	bool STL::Vector<T,Allocator>::operator<=(const Vector<T>& other)const
	{
		size_t size = m_size > other.m_size ? other.m_size : m_size ;
		for(int i = 0 ; i < size ; ++i)
		{
			if(m_buffer[i] > other.m_buffer[i])
			{
				return false;
			}
		}
		return true;
	}
	template<typename T,typename Allocator>
	bool STL::Vector<T,Allocator>::operator>=(const Vector<T>& other)const
	{
		size_t size = m_size > other.m_size ? other.m_size : m_size ;
		for(int i = 0 ; i < size ; ++i)
		{
			if(m_buffer[i] < other.m_buffer[i])
			{
				return false;
			}
		}
		return true;
	}
	
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::swap(Vector<T>& other)
	{
		is_free = true ;
		size_t tmp = m_size;
		m_size = other.m_size;
		other.m_size = tmp;
		
		tmp = m_capacity;
		m_capacity = other.m_capacity;
		other.m_capacity = tmp;
		
		T* tmp_ptr = m_buffer;
		m_buffer = other.m_buffer;
		other.m_buffer = tmp_ptr;
	}
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::shrint_to_fit()
	{
		T* tmp = new T[m_size];
		for(int i = 0 ; i < m_size ; ++i)
		{
			tmp[i]= m_buffer[i];
		}
		if(is_free){delete[]m_buffer;}
		else{std::free(m_buffer);}
		is_free = true ;
		m_buffer = tmp;
	}
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::assign(size_t size,const T& elem)
	{
		if(is_free){delete[]m_buffer;}
		else{std::free(m_buffer);}
		m_size = size ;
		m_capacity = size;
		for(int i = 0 ; i < size ; ++i)
		{
			m_buffer[i] = elem ;
		}
		is_free = true;
	}
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::clear()
	{
		m_size = 0;
		m_capacity = 1;
		if(is_free){delete[]m_buffer;}
		else{std::free(m_buffer);}
		is_free = true ;
		m_buffer = new T[m_capacity];
	}
	template<typename T,typename Allocator>
	T STL::Vector<T,Allocator>::pop_back()
	{
		m_buffer[--size]={};
	}
	
	template<typename T,typename Allocator>
	T& STL::Vector<T,Allocator>::back()const
	{
		return m_buffer[size-1];
	}
	template<typename T,typename Allocator>
	T& STL::Vector<T,Allocator>::front()const
	{
		return m_buffer[0];
	}
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::erase(size_t pos)
	{
		for(int i = pos ; i < m_size ; ++i)
		{
			m_buffer[i]=m_buffer[i+1];
		}
		m_size--;
	}
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::erase(size_t pos,size_t count)
	{
		for(int i = pos+count ; i < m_size ; ++i)
		{
			m_buffer[i-count]=m_buffer[i];
		}
		m_size-= count;
	}
	template<typename T,typename Allocator>
	void STL::Vector<T,Allocator>::reserve(size_t count)
	{
		if(m_size == 0)
		{
			m_buffer =(T*)std::malloc(count * sizeof(T));
		}
		else
		{
			T* tmp =(T*)std::malloc(count * sizeof(T));
			for(int i = 0 ; i < count ; ++i)
			{
				tmp[i] = m_buffer[i];
			}
			if(is_free){delete[]m_buffer;}
			else{std::free(m_buffer);}
			m_buffer = tmp ;
			m_size = count;
		}
		m_capacity = count ;
		is_free = false ;
	}

