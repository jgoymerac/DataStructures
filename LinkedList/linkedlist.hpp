#include <iostream>
#include <string>
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

using namespace std;

template<typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	if(this != &rhs)
	{
		LinkedList<T>* tmp1=this->m_next; 
		while(this->m_next != NULL)   
		{
			this->m_data=tmp1->m_data;
			this->m_next=tmp1->m_next;
			delete tmp1;
			tmp1=NULL;	
		}
			
			const LinkedList<T>* tmp2 =&rhs;	
			LinkedList<T>* tmp3 =this;
			
			while(tmp2->m_next != NULL)  								   
			{															  
			 	tmp3->m_next=new LinkedList<T>;
				tmp3->m_data=tmp2->m_data;
				tmp3=tmp3->m_next;
				tmp2 = tmp2 -> m_next;
				cout<<*this<<"\n";
			}
			tmp3->m_next=NULL;
	
	}															  
	return *this;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	const LinkedList<T>* tmp2 =&rhs;	
	LinkedList<T>* tmp3 =this;
			
		while(tmp2->m_next != NULL)  								   
		{							
				tmp3->m_next=new LinkedList<T>;
				tmp3->m_data=tmp2->m_data;			
				tmp3=tmp3->m_next;			
				tmp2 = tmp2 -> m_next;
		}
	tmp3->m_next=NULL;
			
}

template<typename T>
int LinkedList<T>::size() const
{	
	if(this->m_next ==NULL)
	{
		return 0;
	}
	else
	{
		int counter=0;
		const LinkedList<T>* r;
		r = this;
		
		while(r->m_next !=NULL)
		{
			counter++;
			r=r->m_next;
		}			
		return counter;
		delete r;
		r=NULL;
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if(this->m_next == NULL)
	{
		return true;
	}
	return false;
}

template<typename T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
	if(this->m_next == NULL)
	{
		cout<<"PANIC in LINKEDLIST!!! .getFirstPtr() -- empty list\n";
		return NULL;
	}
	return this;
}

template<typename T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
	if(this->m_next == NULL)
	{
		cout<<"PANIC in LINKEDLIST!!! .getLastPtr() -- empty list\n";
		return NULL;
	}
	
	LinkedList<T>* t= this;
	int counter=0;
	while(t->m_next !=NULL && counter<this->size()-1)
	{
		t=t->m_next;
		counter++;
	}
	return t;
	delete t;
	t=NULL;
}

template<typename T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
	if(i<0 || i>this->size()){
	   cout<<"PANIC in LINKEDLIST!!! .getAtPtr() -- index out of bounds\n";
		return NULL;
	}
	
	
	LinkedList<T>* t= this;
	int counter=0;
	while(t->m_next !=NULL && counter<i)
	{
		t=t->m_next;
		counter++;
	}
	return t;
	delete t;
	t=NULL;
}

template<typename T>
void LinkedList<T>::clear()
{
	if(this->m_next == NULL)
	{
		
		return;
	}
	else
	{
	LinkedList<T>* tmp2;

		while(this->m_next != NULL)   
		{
			tmp2=this->m_next;
			this->m_data=tmp2->m_data;
			this->m_next=tmp2->m_next;
			delete tmp2;
			tmp2=NULL;
		}
	}
	this->m_next=NULL; 
	return;
	}


template<typename T>
void LinkedList<T>::insert_front(const T& x)
{
	
		LinkedList<T> *tmp= new LinkedList<T>;
		
		tmp->m_next=this->m_next;							   
		tmp->m_data=this->m_data;
		this->m_data=x;
		this->m_next=tmp;
		
		return ;
}

template<typename T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{ 
	
	LinkedList<T> *tmp= new LinkedList<T>;
	tmp->m_data=pos->m_data;
	tmp->m_next=pos->m_next;
	pos->m_data=x;
	pos->m_next=tmp;
	return;
}

template<typename T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
	LinkedList<T>* tmp = pos->m_next;
	pos->m_data=tmp->m_data;
	pos->m_next=tmp->m_next;
	delete tmp;
	return;
}

template<typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
	const LinkedList<T>* tmp1=this;
	const LinkedList<T>* tmp2=&rhs;
	while(tmp1->m_next != NULL && tmp2->m_next != NULL)
	{
		if (tmp1->m_data != tmp2->m_data)
		{
			return false;
		}
		tmp1=tmp1->m_next;
		tmp2=tmp2->m_next;
	}
	return true;	
}

template<typename T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
	LinkedList<T>* t= this;
	while(t->m_next !=NULL && t->m_data!=x)
	{
		t=t->m_next;

	}
	return t;
}

template<typename T>
void LinkedList<T>::reverse()
{
	LinkedList<T>* tmp  = new LinkedList<T>;
	LinkedList<T>* tmp2 = this;

	while(tmp2->m_next != NULL)
	{
		tmp->insert_front(tmp2->m_data);
		tmp2=tmp2->m_next;

	}
	this->clear();
	this->m_data=tmp->m_data;
	this->m_next=tmp->m_next;	
	delete tmp;
	tmp=NULL;
	return;
}

template<typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
	LinkedList<T>* tmp1;
	const LinkedList<T>* tmp2=&xlist;
	tmp1=this;
	while (tmp2->m_next !=NULL)
	{
		tmp1->insert(tmp2->m_data , getLastPtr());
		tmp2=tmp2->m_next;
	}
	
	return;
}
	
#endif
