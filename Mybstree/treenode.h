/*/////////////////////////////////////////////////////////////////////////////
///@file TreeNode.h															///
///@author Jeff Goymerac 153 sec a											///
///@this file is an implimentation of a recursive Binary search tree		///
/// 																		///
/////////////////////////////////////////////////////////////////////////////*/
#ifndef TREENODE_H
#define TREENODE_H
#include <iomanip>
#include <iostream>


template <typename T>
class MyBSTree;

template<typename T>
struct TreeNode
{
	T m_data;
	TreeNode<T>* m_right;
	TreeNode<T>* m_left;
	TreeNode();
	TreeNode(const T& root, TreeNode<T>* le, TreeNode<T>* ri);
	TreeNode(TreeNode<T>*t);

};
template<typename T>
TreeNode<T>::TreeNode()
{
	m_left = NULL;
	m_right = NULL;
}
template <typename T>
TreeNode<T>::TreeNode(const T& root, TreeNode<T>* le, TreeNode<T>* ri)
{
	m_data = root;
	m_left = le;
	m_right = ri;
}
template <typename T>
TreeNode<T>::TreeNode(TreeNode<T>* t)
{
	m_data = t->m_data;
	m_left = t->m_left;
	m_right = t->m_right;
}
#endif