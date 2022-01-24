#ifndef Stack
#define Stack

#include<iostream>
#include<vector>
template<typename T>
class STACK
{
public:
	STACK(){ sp = -1;}
	~STACK(){}
	void push(T);
	T pop();
private:
	int sp;
	std::vector<T>vec;
};

#include"Stack.hpp"

#endif
