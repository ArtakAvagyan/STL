#include<iostream>
#include<vector>

template<typename T>
void STACK<T>::push(T el)
{
	vec.push_back(el);
	sp++;
}

template<typename T>
T STACK<T>::pop()
{
	return vec[sp--];
}
