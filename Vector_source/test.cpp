#include <iostream>
#include <vector>
#include <string>
/*
union ui
{
	int a = 12;
	double d;
	char ch;

	void foo()
	{
		std::cout << "hello Artak" <<std::endl;
	}
};
template <typename T>
struct is_void
{
	enum th {T=1};
};
template <void T>
struct is_void
{
	enum th {T};
};
int main()
{
	//SFINAE
	//CTAD
	//<=>
	bool a = is_void<int>();
//	ui a;
	std::cout << "What is a CTAD" << std::endl;
//	a.foo();

}*/
int main()
{
	int n = sizeof(0)["abcdef"];
	std::cout<< n <<std::endl;


}
