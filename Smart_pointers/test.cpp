/*#include <iostream>
#include <functional>
template<typename T,typename del = std::function<void(T*)> >
class smartPointer {
public:
    smartPointer(T* n_ptr = nullptr, del deletor = nullptr)
    {
        s_ptr = n_ptr;
        n_ptr = nullptr;
        ptr = deletor ;   
    }
    smartPointer(smartPointer<T>& other){
        this->s_ptr = other.s_ptr;
        other.s_ptr = nullptr;
        ptr = other.ptr;
    }
    smartPointer(smartPointer<T>&& other){
        this->s_ptr = other.s_ptr;
        other.s_ptr = nullptr;
        ptr = other.ptr;
    }
    void operator=(smartPointer<T>& other){
        if(s_ptr!= nullptr)
            clear();
        this->s_ptr = other.s_ptr;
        other.s_ptr = nullptr;
        ptr = other.ptr;
    }
    void operator=(smartPointer<T>&& other){
        if(s_ptr!= nullptr)
            clear();
        this->s_ptr = other.s_ptr;
        other.s_ptr = nullptr;
        ptr = other.ptr;
    }
    
    void operator=(T* m_ptr){
        if(s_ptr!= nullptr)
            clear();
        this->s_ptr = m_ptr;
    }
    void get_deletor(std::function<void(T*)> deletor)
    {
        ptr = deletor;
    }
    ~smartPointer(){
        clear();
    }
    T& operator*(){return *s_ptr;}
    private:
    void clear()
    {
        if(ptr== nullptr){
            std::cout<<"clap"<<std::endl;
            delete s_ptr ;
            s_ptr = nullptr;
        }
        else
        {
            ptr(s_ptr);
        }
    }
    T* s_ptr;
    del ptr ;
};
int main(){
    int* b = new int; 
    smartPointer<int,std::function<void(int*)>> a (b,[&](int*b){std::cout<< "chlp"<<std::endl;});
    std::cout<< "++++++++++++++++++++++++++++"<<std::endl;
    *a = 15;
    std::cout<<*a<<std::endl;
    std::cout<< "++++++++++++++++++++++++++++"<<std::endl;
    return 0;
}*/

#include <functional>
#include <iostream>
#include "Unique_ptr.h"
int clear(int* ptr)
{
	delete[]ptr;
	return 0;
}
int main()
{
	auto it = [](int*& ptr)->int{delete[]ptr;return 0;};
	int * tmp = new int[5];
	STL::Unique_ptr<int,decltype(it)> p(tmp,it);
	p[0] = 15;
	p[1] = 18;
	std::cout<< p[0] <<std::endl;
	std::cout<< p[1] <<std::endl;
	return 0;
}
