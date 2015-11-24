/*/////////////////////////////////////////////////////////////////////////////
///@file LinkListStack.hpp													///
///@author Jeff Goymerac 153 sec a											///
///@this file is defines a LinkedList Stack as a child of the Abstract		///
///	parent class															///
/// 																		///
/////////////////////////////////////////////////////////////////////////////*/
#ifndef LINKEDLISTSTACK_HPP
#define LINKEDLISTSTACK_HPP
#include "abstractstack.h"


#include <string>
#include <iomanip>
#include <iostream>
#include <cstdlib>

using namespace std;
template <typename T>
class LLStack : public AbstractStack<T>
{

protected:
			int	x,
				y,
				z;

public:
	T m_data;
	LLStack<T>* m_next;


	
	LLStack() :m_next(NULL) {}
	
	// Purpose: clears the stack
	// Postconditions: the stack is now empty 
	void clear()
	{
		if (this->m_next == NULL)
		{

			return;
		}
		else
		{
			LLStack<T>* tmp2;

			while (this->m_next != NULL)
			{
				tmp2 = this->m_next;
				this->m_data = tmp2->m_data;
				this->m_next = tmp2->m_next;
				delete tmp2;
				tmp2 = NULL;
			}
		}
		this->m_next = NULL;
		return;

	};

	// Purpose: push an element into the stack
	// Parameters: x is the value to push into the stack
	// Postconditions: x is now the element at the top of the stack, 
	void push(const T& x)
	{
		LLStack<T> * tmp = new LLStack<T>;
		tmp->m_next =this-> m_next;
		tmp->m_data = this->m_data;
		this->m_data = x;
		this->m_next = tmp;
		return;

	};

	// Purpose: pop the stack
	// Postconditions: the element formerly at the top of the stack has
	// been removed
	// Note: Poping an empty stack results in an empty stack.
	void pop()
	{
		LLStack<T> *tmp = this->m_next;
		this->m_data = tmp->m_data;
		this->m_next = tmp->m_next;
		delete tmp;
	};


	// Purpose: looks at the top of the stack
	// Returns: a const reference to the element currently on top of the stack
	// Exception: if the stack is empty, throw a string with an error message!!!
	const T& top() const throw (std::string)
	{
		if (this->m_next == NULL)
		{
			throw string("Error List is Empty!!!!\n");
		}
		else
		{
			return m_data;
		}
	};

	// Purpose: Checks if a stack is empty
	// Returns: 'true' if the stack is empty
	//     'false' otherwise  
	bool isEmpty() const
	{
		if (this->m_next == NULL)
		{
			return true;
		}
		else
			return false;
	};


	
	void add()  throw (std::string)
	{
		if (this->m_next == NULL)
		{
			throw string("Error list is Empty!!!\n");
		}
		else if (this->m_next->m_next == NULL)
		{
			throw string("Error List only contains 1 value!!!!!\n");
		}

		else
		{
			x = this->top();
			this->pop();
			y = this->top();
			this->pop();
			z = x + y;
			push(z);
		}
	}
	void subtract()  throw (std::string)
	{
		if (this->m_next==NULL)
		{
			throw string("Error list is Empty!!!\n");
		}
		else if (this->m_next->m_next == NULL)
		{
			throw string("Error List only contains 1 value!!!!!\n");
		}
		
		else 
		{
			x = this->top();
			this->pop();
			y = this->top();
			this->pop();
			z = y - x;
			push(z);
		}
	}

	void multiply() throw (std::string)
	{
		if (this->m_next == NULL)
		{
			throw string("Error list is Empty!!!\n");
		}
		else if (this->m_next->m_next == NULL)
		{
			throw string("Error List only contains 1 value!!!!!\n");
		}

		else
		{
			x = this->top();
			this->pop();
			y = this->top();
			this->pop();
			z = y * x;
			push(z);
		}
	}
	void divide() throw (std::string)
	{
		if (this->m_next == NULL)
		{
			throw string("Error list is Empty!!!\n");
		}
		else if (this->m_next->m_next == NULL)
		{
			throw string("Error List only contains 1 value!!!!!\n");
		}

		else
		{
			x = this->top();
			this->pop();
			y = this->top();
			this->pop();
			z = y / x;
			push(z);
		}
	}
	void mod() throw (std::string)
	{
		
		if (this->m_next == NULL)
		{
			throw string("Error list is Empty!!!\n");
		}
		else if (this->m_next->m_next == NULL)
		{
			throw string("Error List only contains 1 value!!!!!\n");
		}

		else
		{
			x = this->top();
			this->pop();
			y = this->top();
			this->pop();
			z = y % x;
			push(z);
		}
	}
	
	void negative() throw (std::string)
	{
		if (this->m_next == NULL)
		{
			throw string("Error list is Empty!!!\n");
		}
		else
		{

			y = 0;
			x = this->top();
			this->pop();
			z = y - x;
			push(z);
		}

	}
	
	void sum()
	{
		LLStack<T> *tmp = this;
		while (tmp->m_next != NULL)							
		{
			this->add();
			tmp = this->m_next;
		}
		
	}
	
	void prod()
	{
		LLStack<T> *tmp = this;
		while (tmp->m_next != NULL)							
		{
			this->multiply();
			tmp = this->m_next;
		}
	}
	
	void print()
	{
		LLStack<T> *tmp = this;
		cout << "[ ";
		
		if (tmp->m_next != NULL)
		{
			cout << tmp->m_data;
			tmp = tmp->m_next;
			while (tmp->m_next != NULL)
			{
				//tmp = tmp->m_next;
				cout << ", " << tmp->m_data;
				tmp = tmp->m_next;
			}
		}

		cout << " ] \n";
	}





};




#endif


