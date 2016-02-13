/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ULTRIMATE TREE CLASS
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

// VERSION 1.5		$ LASTEST UPDATE 2014/10/25 $

		// 디자인 패턴이 적용되지 않은 클래스

#ifndef __TREE_
#define __TREE_

namespace inf{

	// 잎
template<class type> class
	_tree_node
	{
public:
	typedef _tree_node<type> _Myt;
	
	typedef typename type*			pointer;
	typedef typename const type*	const_pointer;
	typedef typename type&			reference;
	typedef typename const type&	const_reference;
	typedef typename type			value_type;

	_tree_node() 
		: _Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(0) { }
	_tree_node(value_type _data) 
		: _Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(_data) { }
	reference operator*() {
		return _Data; }
	bool is_left() {
		return _Left != nullptr; }
	bool is_right() {
		return _Right != nullptr; }
	bool is_parent() {
		return _Parent != nullptr; }
	bool is_data() {
		return _Data != 0; }

	_Myt *_Left, *_Right, *_Parent;
	value_type _Data;
	};

template<class type> class
	_tree_transfer
	{
public:
	typedef typename type*			pointer;
	typedef typename const type*	const_pointer;
	typedef typename type&			reference;
	typedef typename const type&	const_reference;
	typedef typename type			value_type;
	};

	// 트리본체
	// BINARY TREE
template<typename _Ty> class
	tree
	{
public:
	typedef typename _tree_node<_Ty> _Node;

	typedef tree<_Ty> _Mytree;
	typedef _tree_transfer<_Node> _Mybase;
	
	typedef typename _Mybase::pointer pointer;
	typedef typename _Mybase::const_pointer const_pointer;
	typedef typename _Mybase::const_reference const_reference;
	typedef typename _Mybase::value_type value_type;
	typedef typename _Mybase::reference	reference;

	typedef typename _Ty	value_type;
	typedef typename _Ty&	reference;
	
	pointer Head;
	pointer Last;

	tree() 
		{
		Head = new pointer();
		Last = Head;
		}

	explicit tree(pointer& _Head) 
		{
		Head = _Head;
		Last = Head;
		}

	void push_left()
		{
		pointer _Left = new pointer();
		**_Left = value_type();
		Last->_Left = _Left;
		Last->_Left->_Parent = Last;
		}
	void push_right()
		{
		pointer _Right = new pointer();
		**_Right = value_type();
		Last->_Right = _Right;
		Last->_Right->_Parent = Last;
		}
	void push_left(value_type val) 
		{
		push_left();
		**Last->_Left = val; 
		}
	void push_right(value_type val) 
		{
		push_right();
		**Last->_Right = val; 
		}

	};

#define INF		inf :: 
}

#endif