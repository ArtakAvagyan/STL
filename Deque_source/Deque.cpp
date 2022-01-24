#include <iostream>
#include <vector>
#include <initializer_list>


#include "Deque.h"


namespace STL
{
	template < typename T >
	Deque<T>::Deque():_balansFactor{} {}

	template < typename T >
	Deque<T>::Deque(size_t left ,size_t first):_left{left},
		_right{first},_balansFactor{0}{}

	template < typename T >
	Deque<T>::Deque(const Deque<T>& other): _left{other._left},
		_right{other._right},_balansFactor{ other._balansFactor}{}

	template < typename T >
	Deque<T>::Deque(Deque<T>&& other): _left{std::move(other._left)},
		_right{std::move(other._right)},_balansFactor{std::move(other._balansFactor)}{}

	template < typename T >
	Deque<T>::Deque(const std::initializer_list<T>& list)
	{
		_left.reserve(list.size());
		for(const auto& it : list)
		{
			_left.push_back(it);
		}
		_balansFactor = 0;
	}

	template < typename T >
	void Deque<T>::push_back(const T& elem)
	{
		_left.push_back(elem);
	}

	template < typename T >
	void Deque<T>::push_front(const T& elem)
	{
		_right.push_back(elem);
		_balansFactor--;
	}

	template < typename T >
	inline void Deque<T>::shrink_to_fit()
	{
		_left.shrink_to_fit();
		_right.shrink_to_fit();
	}

	template < typename T >
	void Deque<T>::clear()
	{
		_left.clear();
		_right.clear();
		_balansFactor = 0;
	}

	template < typename T >
	T& Deque<T>::at(const size_t pos)
	{
		if(_left.size() + _right.size() < pos)
		{
			throw std::out_of_range("USHADIR !!!");
		}
		else if(_balansFactor == 0)
		{
			return _left[pos];
		}
		else if((_balansFactor + pos) > 0)
		{
			return _right[_right.size()-pos-1];
		} else {
			return _left[(pos +_balansFactor)];
		}
		//return const_cast<T&>( static_cast<const Deque<T>>(*this).at(pos) );
	}

	template < typename T >
	inline size_t Deque<T>::size()const
	{
		return _left.size() + _right.size() ;
	}

	template < typename T >
	inline bool Deque<T>::empty()const
	{
		return _left.empty() && _right.empty() ;
	}

	template < typename T >
	const T& Deque<T>::at(const size_t pos)const
	{
		if(_left.size() + _right.size() < pos)
		{
			throw std::out_of_range("USHADIR !!!");
		}
		else if(_balansFactor == 0)
		{
			return _left[pos];
		}
		else if((_balansFactor + pos) > 0)
		{
			return _right[_right.size()-pos-1];
		} else {
			return _left[(pos +_balansFactor)];
		}		
	}

	template < typename T >
	inline T& Deque<T>::front()const
	{
		if(_balansFactor != 0)
		{
			return _right[(_right.size()-1)];
		}
		return _left[0];
	}

	template < typename T >
	inline T& Deque<T>::back()const
	{
		return _left[_left.size()-1];
	}

	template < typename T >
	T& Deque<T>::operator[](const size_t pos)
	{
		if(_balansFactor == 0)
		{
			return _left[pos];
		}
		else if((_balansFactor + pos) > 0)
		{
			return _right[_right.size()-pos-1];
		} else {
			return _left[(pos +_balansFactor)];
		}
	
	//	return const_cast<T&>(static_cast<const Deque<T>>(*this)[pos]);
	}

	template < typename T >
	const T& Deque<T>::operator[](const  size_t pos)const
	{
		if(_balansFactor == 0)
		{
			return _left[pos];
		}
		else if((_balansFactor + pos) > 0)
		{
			return _right[_right.size()-pos-1];
		} else {
			return _left[(pos +_balansFactor)];
		}
	}

	template < typename T >
	Deque<T>& Deque<T>::operator=(const Deque<T>& other)
	{
		_left = other._left ;
		_right = other._right ;
		_balansFactor = other._balansFactor ;
	}

	template < typename T >
	Deque<T>& Deque<T>::operator=(Deque<T>&& other)
	{
		_left = std::move(other._left) ;
		_right = std::move(other._right) ;
		_balansFactor = std::move(other._balansFactor);
	}

	template < typename T >
	Deque<T>& Deque<T>::operator+(const Deque<T>& other)
	{
		Deque<T> tmp = *this ;
		tmp += other ;
		tmp._balansFactor = _balansFactor;
		return tmp ;
	}

	template < typename T >
	Deque<T>& Deque<T>::operator+=(const Deque<T>& other)
	{
		_left += other._right;
		_left += other._left;
	}

}



int main()
{
	STL::Deque<int> d;
	d.push_back(5);
	d.push_front(4);
	d.push_front(4);
	std::cout<< d[0] << std::endl;
	std::cout<< d[1] << std::endl;
	std::cout<< d[2] << std::endl;


}
