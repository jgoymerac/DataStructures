//////////////////////////////////////////////////////////////////////////////
///@file maxheap.h														   ///
///@author Jeff Goymerac 153 sec a										   ///
///@this file defines the maxheap clsss									   ///
//////////////////////////////////////////////////////////////////////////////
#ifndef MAXHEAP_H
#define MAXHEAP_H
#include "abstractheap.h"
#include <iomanip>
#include <iostream>
#include <string>
//#include <cstdlib>

using namespace std;

template<typename T>
class maxHeap: public AbstractHeap<T>
{
public:
	maxHeap();													//Done
	~maxHeap();													//Done
	const maxHeap<T>& operator = (const maxHeap<T>&);			//Done
	maxHeap(const maxHeap<T>& cpy);							//Done
	bool isEmpty() const;										//Done
	int size() const;											//Done
	const T& top() const throw (std::string);					//Done
	void print() const;											//Done
	void clear();												//Done				
	void insert(const T& x);
	void remove();
	int max() const;
	T& operator[] (int i) throw(std::string);
	T& operator[] (int i) const throw(std::string);


private:
	T* m_data;
	int m_size;		//size of array
	int m_max;		//Max size of array
	void prettyPrint(int ix, int pad) const;


};
template<typename T>
maxHeap<T>::maxHeap()
{
	m_data = NULL;
	m_size = 0;
	m_max = 0;
}

template<typename T>
maxHeap<T>::~maxHeap()
{
	clear();
}

template <typename T>
const maxHeap<T>& maxHeap<T>::operator=(const maxHeap<T>& rhs)
{
	if (this != &rhs)
	{
		delete[]m_data;
		m_size = rhs.size();
		m_max = rhs.max();
		m_data = new T[m_size];
		for (int k = 0; k<=m_size; k++)
		{
			m_data[k] = rhs[k];
		}
	}
	return *this;
}

template<typename T>
maxHeap<T>::maxHeap(const maxHeap<T>& cpy)
{
	m_max = cpy.m_max;
	m_size = cpy.m_size;
	m_data = new T[m_max];

	for (int i = 0; i <= m_size; i++)
	{
		m_data[i] = cpy[i];
	}

}

template<typename T>
bool maxHeap<T>::isEmpty() const
{
	if(m_size > 0)
	{
	return false;
	}
	else
	{
		return true;
	}
}

template <typename T>
int maxHeap<T>::size() const
{
	return m_size;
}

template <typename T>
const T& maxHeap<T>::top() const throw(std::string)
{
	if (!isEmpty())
	{
		return m_data[1];
	}
	else
	{
		throw string("Panic : MaxHeap is EMpty!!!");
	}
}

template <typename T>
void maxHeap<T>::print() const
{
	prettyPrint(1, 0);
	return;
}

template <typename T>
void maxHeap<T>::clear()
{
	delete[]m_data;
	m_size=0;
	m_max=0;
	m_data=NULL;
}

template <typename T>
void maxHeap<T>::prettyPrint(int ix, int pad) const
{
	string s(pad, ' ');
	if (ix > m_size)
	{
		cout << endl;
	}
	else
	{
		prettyPrint((ix * 2) + 1, pad + 4);
		cout << s << m_data[ix] << endl;
		prettyPrint(ix * 2, pad + 4);
	}
}
template <typename T>
void maxHeap<T>::insert(const T& x)
{
	m_size++;
	if (m_data == NULL)
	{
		delete [] m_data;
		m_data = new T[(m_max+1)*2];
		m_data[1] = x;
		m_max=(m_max+1)*2;
		return;
	}

	else if (m_size > m_max-2)
	{
		T* tmp;
		m_max = m_max * 4;
		tmp = new T[m_max];
		for (int j = 1; j<m_size; j++)
		{
			tmp[j] = m_data[j];
		}
		delete[]m_data;
		m_data = new T[m_max];
		for (int k = 1; k<m_size; k++)
		{
			m_data[k] = tmp[k];
		}
		
	}	
	int hole;
	hole = m_size;
	while (hole > 1 && x > m_data[(hole / 2)])
	{
		m_data[hole] = m_data[(hole / 2)];
		hole = hole / 2;
	}
	m_data[hole] = x;
	
}
template <typename T>
int maxHeap<T>::max() const
{
	return m_max;
}

template <typename T>
void maxHeap<T>::remove()
{
	if(m_size==0)
	{
		return;
	}

	T tmp = m_data[m_size];
	m_size--;
	int hole = 1;
	bool done = false;
	while (hole * 2 <= m_size && !done)
	{
		int child = hole * 2;
		if (child <=m_size && m_data[child + 1] >m_data[child])
		{
			child++;
		}
		if (m_data[child] > tmp)
		{
			m_data[hole] = m_data[child];
			hole = child;
		}
		else 
		{
			
			done = true;
		}
	}
	m_data[hole] = tmp;
	/*if (m_size<(m_max / 8))
	{
		T* tmp;
		tmp = new T[m_max /2 ];
		for (int j = 0; j<m_size; j++)
		{
			tmp[j] = m_data[j];
		}
		delete[]m_data;
		m_data = tmp;
		m_max = m_max / 2;
	}*/
}


template<typename T>
T& maxHeap<T>::operator[] (int i) throw (std::string)
{
	if (i<0 || i>m_size)
	{
		throw string ("Panic in operator [] MaxHeap is Empty");
	}
	return m_data[i];
}
template<typename T>
T& maxHeap<T>::operator[] (int i) const throw(std::string)
{
	if (i<0 || i>m_size)
	{
		throw string("Panic in operator [] MaxHeap is Empty");
	}
	return m_data[i];
}
#endif
