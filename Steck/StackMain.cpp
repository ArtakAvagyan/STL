#include"Stack.h"

#include<iostream>
int main()
{
	STACK<int> a;
	a.push(15);
	a.push(45);
	a.push(65);
	std::cout << a.pop() << std::endl;
	std::cout << a.pop() << std::endl;
	std::cout << a.pop() << std::endl;
	return 0;
}
