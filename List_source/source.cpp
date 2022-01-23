#include "List.h"
#include <iostream>

template<typename T>
STL::List<T>::List()
{
      this->root = nullptr;
}

template<typename T>
STL::List<T>::~List()
{
      if(root!=nullptr)
      {
            clear();
      }
}
template<typename T>
STL::List<T>::List(T val)
{
      this->root = new Node(val);
}

template<typename T>
STL::List<T>::List(const List<T>& ls)
{
      if(ls.root == nullptr){return;}
      Node* tmp = ls.root;
      this->root = new Node(tmp->m_value);
      Node* m_tmp = this->root->m_next;
      tmp = tmp->m_next;
      while(tmp)
      {
            m_tmp->m_next = new Node (tmp->m_value);
            m_tmp = m_tmp->m_next;
            tmp = tmp->m_next;
      }
}

template<typename T>
STL::List<T>::List(List<T>&& ls)
{
      this->root = ls.root ;
      ls.root = nullptr ;
}

template<typename T>
void STL::List<T>::push_back(const T& val)
{
      if(this->root == nullptr)
      {
            this->root = new Node(val);
            return;
      }
      Node* m_tmp = this->root;
      while(m_tmp->m_next != nullptr)
      {
            m_tmp = m_tmp->m_next;
      };
      m_tmp->m_next = new Node(val);
}

template<typename T>
void STL::List<T>::swap(List<T>& ls)
{
      Node* tmp = ls.root;
      ls.root = root;
      root = tmp ;
}
template<typename T>
STL::List<T>& STL::List<T>::operator=(const List<T>& ls)
{
      if(ls.root == nullptr){return*this;}
      List<T> tmp(ls);
      this->swap(tmp);
      return *this;
}
template<typename T>
STL::List<T>& STL::List<T>::operator+=(const List<T>& ls)
{
      if(this->root == nullptr){*this = ls;}
      Node* tmp = ls.root;
      Node* m_tmp = this->root ;
      while(m_tmp->m_next != nullptr)
      {
            m_tmp = m_tmp->m_next;
      }
      while(tmp)
      {
            m_tmp->m_next = new Node (tmp->m_value);
            m_tmp = m_tmp->m_next;
            tmp = tmp->m_next;
      }
      return *this;
}
template<typename T>
T STL::List<T>::pop_front()
{
      if(root == nullptr){return {};}
      T tmp = root->m_value;
      Node* m_tmp = root;
      root = root->m_next;
      delete m_tmp;
      return tmp ;
}
template<typename T>
void STL::List<T>::push_front(const T& val)
{
      Node* m_tmp = root ;
      root = new Node(val,root);
}
template<typename T>
void STL::List<T>::clear()
{
      while(root != nullptr)
      {
            this->pop_front();
      }
      return ;
}
template<typename T>
void STL::List<T>::swap(size_t pos , size_t pos_)
{
      Node* m_tmp = root;
      Node* tmp = root;
      while(m_tmp->m_next != nullptr && pos)
      {
            std::cout<< 1 ;
            m_tmp = m_tmp->m_next;
            --pos;
      }
      std::cout<<std::endl;
      while(tmp->m_next != nullptr && pos_)
      {
            std::cout<<2;
            tmp = m_tmp->m_next;
            --pos_;
      }
      tmp->swap(*m_tmp);
}
template<typename T>
bool STL::List<T>::empty()const
{
      return root == nullptr;
}
template<typename T>
T& STL::List<T>::front()const
{
      return root->m_value;
}
template<typename T>
T& STL::List<T>::back()const
{
      Node* m_tmp = root ;
      while(m_tmp->m_next != nullptr)
      {
            m_tmp = m_tmp->m_next ;
      }
      return m_tmp->m_value;
}
template<typename T>
size_t STL::List<T>::size()const
{
      Node* m_tmp = root ;
      size_t size =0 ;
      while(m_tmp != nullptr)
      {
            m_tmp = m_tmp->m_next ;
            size++;
      }
      return size;
}
template<typename T>
T& STL::List<T>::operator[](size_t pos)const
{
      Node* m_tmp = root ;
      while(m_tmp->m_next != nullptr && pos )
      {
            m_tmp = m_tmp->m_next;
            pos--;
      }
      return m_tmp->m_value;
}
template<typename T>
STL::List<T>& STL::List<T>::operator=(List<T>&& ls)
{
      clear();
      root = ls.root;
      ls.root = nullptr;
}
template<typename T>
void STL::List<T>::insert(size_t pos,const T& elem)
{
      Node* m_tmp = this->root;
      while(pos)
      {
            m_tmp = m_tmp->m_next;
            pos--;
            if(m_tmp->m_next == nullptr){return;}
      }
      m_tmp->m_next = new Node(elem,m_tmp->m_next);
}
int main()
{
      STL::List<int> ls;
      //ls.push_back(5);
      STL::List<int> ls_2;
      ls_2 = ls ;
      ls_2.push_back(5);
      ls_2.push_back(10);
      ls_2.push_back(15);
      ls_2.push_back(20);
      ls_2.push_front(3);
      ls_2.insert(2,1998);
      ls_2.swap(1,4);
      std::cout<< ls_2[0] <<std::endl;
      std::cout<< ls_2[1] <<std::endl;
      std::cout<< ls_2[2] <<std::endl;
      std::cout<< ls_2[3] <<std::endl;
      std::cout<< ls_2[4] <<std::endl;
      std::cout<< ls_2[5] <<std::endl;
      //ls_2.clear();
      if(ls_2.empty())
      {
            std::cout<<"jishta"<<std::endl;
      }
}