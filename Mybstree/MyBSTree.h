/*/////////////////////////////////////////////////////////////////////////////
///@file MyBsTree.h															///
///@author Jeff Goymerac 153 sec a											///
///@this file is an implimentation of a recursive Binary search tree		///
/// 																		///
/////////////////////////////////////////////////////////////////////////////*/
#ifndef MYBSTREE_H
#define MYBSTREE_H
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>
#include "abstracttree.h"
#include "treenode.h"

using namespace std;

template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
public:
	MyBSTree();								//Constructor				DONE
	~MyBSTree(){ clear(); };				//Destructor				DONE
	MyBSTree(const MyBSTree<T>& rhs);			//copy constructor		DONE
	const MyBSTree<T>& operator= (const MyBSTree<T>&);	//operator =	DONE
	int size() const;						//done
	bool isEmpty() const;					//done
	int height() const;						//done
	const T& findMax() const;				//done
	const T& findMin() const;				//done
	int contains(const T& x) const;			//done
	void clear();							//done
	void insert(const T& x);				//done
	void remove(const T& x);				//done
	void printPreOrder() const;				//done
	void printPostOrder() const;			//done
	void print() const;						//done

private:
	TreeNode<T>* m_root;
	int m_size; 
	int rec_height(TreeNode<T>* tmp) const;
	const T& rec_findMax(TreeNode<T>* tmp) const throw (std::string);
	const T& rec_findMin(TreeNode<T>* tmp) const throw (std::string);
	int rec_contains(TreeNode<T>* tmp, const T& x, int level) const;
	void rec_clear(TreeNode<T>* &tmp);
	void rec_insert(TreeNode<T>* &tmp, const T& x);
	void rec_remove(TreeNode<T>* &t, const T& x);
	void rec_printPreOrder(TreeNode<T>* const &t) const ;
	void rec_printPostOrder(TreeNode<T>* const &t) const;
	void prettyPrint(const TreeNode<T>* t, int pad) const;
	void copy(TreeNode<T> * t);
	TreeNode<T>* clone(const TreeNode<T>* &t);
};
template <typename T>
MyBSTree<T>::MyBSTree()
{
	m_root=NULL;
	m_size = 0;
}
template <typename T>
MyBSTree<T>::MyBSTree(const MyBSTree<T>& rhs)			//copy constructor
{	
	m_root = NULL;
	copy(rhs.m_root);
	m_size = rhs.m_size;
}
template <typename T>
const MyBSTree<T>& MyBSTree<T>::operator= (const MyBSTree<T>& rhs) //operator =
{
	if (this != &rhs)
	{
		this->clear();
		this->m_root = NULL;
		this->copy(rhs.m_root);
		this->m_size = rhs.m_size;
	}
		return *this;
}
template <typename T>
int MyBSTree<T>::size() const
{
	int x;
	x = this->m_size;
	return x;
}
template <typename T>
bool MyBSTree<T>::isEmpty() const
{
	if (m_root == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>				
int MyBSTree<T>::height() const 
{
	return rec_height(m_root);
}
template <typename T>
int MyBSTree<T>::rec_height(TreeNode<T>* tmp) const
{
	if (tmp == NULL)
	{
		return 0;
	}
	else
	{
		int left = rec_height(tmp->m_left);
		int right = rec_height(tmp->m_right);
		if (left > right)
			return (left + 1);
		else
			return (right + 1);
	}
}
template <typename T>
const T& MyBSTree<T>::findMax() const
{
	return rec_findMax(m_root);
}
template <typename T>
const T& MyBSTree<T>::rec_findMax(TreeNode<T>* tmp) const throw (std::string)
{
	if (tmp == NULL)
	{
		throw string("Panic : Tree is Empty!!!!\n");
	}
	if (tmp->m_right == NULL)
	{
		return tmp->m_data;
	}
	else {
		return rec_findMax(tmp->m_right);
	}
}
template <typename T>
const T& MyBSTree<T>::findMin() const
{
	return rec_findMin(m_root);
}
template <typename T>
const T& MyBSTree<T>::rec_findMin(TreeNode<T>* tmp) const throw (std:: string)
{
	if (tmp == NULL)
	{
		throw string("Panic : Tree is EMpty!!!!\n");
	}
	if (tmp->m_left == NULL)
	{
		return tmp->m_data;
	}
	else {
		return rec_findMin(tmp->m_left);
	}
}
template <typename T>				
int MyBSTree<T>::contains(const T& x) const
{
	return rec_contains(m_root, x, 1);
}
template <typename T>
int MyBSTree<T>::rec_contains(TreeNode<T>* tmp, const T& x, int level) const
{
	if (tmp == NULL )
	{
		return 0;
	}
	else if (tmp->m_data == x )
	{
		
		return level;
		
	}
	else if (x < tmp->m_data && tmp->m_left !=NULL)
	{
		return rec_contains(tmp->m_left, x, level + 1);
	}
	else if (x < tmp->m_data && tmp->m_left == NULL)
	{
		return (level+1) *( -1);
	}
	else if (x> tmp->m_data && tmp->m_right != NULL)
	{
		return rec_contains(tmp->m_right, x, level + 1);
	}
	else
	{
		return (level+1)*(-1);
	}
	
}
template <typename T>				
void MyBSTree<T>::clear()
{
	while (m_root != NULL)
	{
		remove(this->m_root->m_data);
	}
}
template <typename T>
void MyBSTree<T>::rec_clear(TreeNode<T>* &tmp)
{
	while (tmp->m_data != NULL)
	{
		return;
	}
}
template <typename T>
void MyBSTree<T>::insert(const T& x)
{
	rec_insert(m_root, x);
}
template <typename T>
void MyBSTree<T>::rec_insert(TreeNode<T>* &tmp, const T& x)
{
	if (tmp == NULL)
	{
		tmp = new TreeNode<T>;
		tmp->m_data = x;
	
		tmp->m_left = NULL;
		tmp->m_right = NULL;
		m_size++;
	}
	else if (x == tmp->m_data)
	{

	}
	else if (x < tmp->m_data)
	{
		rec_insert(tmp->m_left, x);
	}
	else if (x> tmp->m_data)
	{
		rec_insert(tmp->m_right, x);
	}
	
	
}
template <typename T>
void MyBSTree<T>::remove(const T& x)
{
	rec_remove(this->m_root, x);
}
template <typename T>
void MyBSTree<T>::rec_remove(TreeNode<T>* &t, const T& x)
{
	TreeNode<T>* tmp = NULL;
	
	if (t == NULL)
	{
		return;
	}
	if (x < t->m_data)
	{
		rec_remove(t->m_left, x);
	}
	else if (x > t->m_data)
	{
		rec_remove(t->m_right, x);
	}
	else if (x == t->m_data)
	{
		if (t->m_right == NULL && t->m_left == NULL)
		{
			delete t;
			t = NULL;
			m_size--;
			return;

		}
		else if (t->m_right == NULL)
		{
			tmp = t;
			t = t->m_left;
			delete tmp;
			m_size--;
			return;
		}
		else if (t->m_left == NULL)
		{
			tmp = t;
			t = t->m_right;
			delete tmp;
			m_size--;
			return;
		}
		else
		{
			t->m_data = rec_findMax(t->m_left);
			rec_remove(t->m_left, t->m_data);
			return;
		}

	}
}


template <typename T>
void MyBSTree<T>:: printPreOrder() const
{
		rec_printPreOrder(m_root);
}
template <typename T>
void MyBSTree<T>::rec_printPreOrder(TreeNode<T>* const &t) const
{
	if (t != NULL)
	{
		cout << t->m_data << "\n";
		rec_printPreOrder(t->m_left);
		rec_printPreOrder(t->m_right);
	}
}
template <typename T>
void MyBSTree<T>::print() const
{
	prettyPrint(m_root, 0);
}
template <typename T>
void MyBSTree<T>::printPostOrder() const
{
	rec_printPostOrder(m_root);
}
template <typename T>
void MyBSTree<T>::rec_printPostOrder(TreeNode<T>* const &t) const
{
	if (t != NULL)
	{
		rec_printPostOrder(t->m_left);
		rec_printPostOrder(t->m_right);
		cout << t->m_data << "\n";
	}
}
template <typename T>
void MyBSTree<T>::prettyPrint( const TreeNode<T>* t , int pad) const
{
	string s(pad, ' ');
	if (t == NULL)
		cout << endl;
	else{
		prettyPrint(t->m_right, pad + 4);
		cout << s << t->m_data << endl;
		prettyPrint(t->m_left, pad + 4);
	}
}
template <typename T>
TreeNode<T>* MyBSTree<T>::clone(const TreeNode<T>* &t)
{
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		return new TreeNode<T>*(t->m_data, clone(t->m_left), clone(t->m_right));
	}
}
template <typename T>
void MyBSTree<T>::copy(TreeNode<T>* t)
{
	if (t != NULL)
	{
		insert(t->m_data);
		copy(t->m_left);
		copy(t->m_right);

	}
}











#endif