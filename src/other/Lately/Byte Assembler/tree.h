/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						ULTRA TREE CLASS
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _TREE_
#define _TREE_
#pragma once

#include "rac.h"

#define TREE_SET_ZERO			0L

template<typename _Ty, class _Alloc> struct 
	_Tree_base_types
	{
	typedef typename _Alloc::template rebind<_Ty>::other _Alty;

	typedef typename _Alty::pointer _Tptr;
	typedef typename _Alty::template rebind<_Tptr>::other _Alpty;
	};

template<class _Tree_val> class
	_tree_node
		: public __Container_base
	{
public:
	typedef _tree_node<_Tree_val> _Myt;
	
	typedef typename __SIZE_TYPE		size_type;
	typedef typename __OTHER_TYPE		difference_type;
	typedef typename _Tree_val*			pointer;
	typedef typename const _Tree_val*	const_pointer;
	typedef typename _Tree_val&			reference;
	typedef typename const _Tree_val&	const_reference;
	typedef typename _Tree_val			value_type;

	_tree_node() : 
		_Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(0)
		{
		}

	_tree_node(value_type _data) : 
		_Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(_data)
		{
		}

	reference operator*()
		{
		return _Data;
		}

	bool is_left()
		{
		return _Left != nullptr;
		}

	bool is_right()
		{
		return _Right != nullptr;
		}

	bool is_parent()
		{
		return _Parent != nullptr;
		}

	_Myt *_Left, *_Right, *_Parent;
	value_type _Data;
	};

template<class _Val_node> class
	_tree_transfer
		: public __Container_base
	{
public:
	typedef _tree_transfer<_Val_node> _Myt;

	typedef typename _Val_node::value_type value_type;
	typedef typename _Val_node::pointer pointer;
	typedef typename _Val_node::reference reference;
	typedef typename _Val_node::const_pointer const_pointer;
	typedef typename _Val_node::const_reference const_reference;
	typedef typename _Val_node::size_type size_type;
	typedef typename _Val_node::difference_type difference_type;

	_tree_transfer()
		{
		_Myhead = pointer();
		_Mylast = pointer();
		}

	~_tree_transfer()
		{
		}

	pointer& operator*()
		{
		return _Mylast;
		}

	pointer _Myhead;
	pointer _Mylast;
	};

	// TREE ALLOCATOR
template<typename __base_types> class
	_tree_alloc
		: public _tree_transfer<typename __base_types::_Alty>
	{
public:
	typedef _tree_alloc<__base_types>	_Myt;
	typedef typename __base_types::_Alty _Alty;
	typename _Alty _Alval;

	_tree_alloc(const _Alty& _Al = _Alty())
		: _Alval(_Al)
		{
		typename _Alty::template rebind<__Container_proxy>::other
			_Alproxy(this->_Alval);
		this->_Myproxy = _Alproxy.allocate();
		_Alproxy.construct(this->_Myproxy, __Container_proxy());
		}

	~_tree_alloc()
		{
		typename _Alty::template rebind<__Container_proxy>::other
			_Alproxy(this->_Alval);
		_Alproxy.destroy(this->_Myproxy);
		_Alproxy.deallocate(this->_Myproxy);
		this->_Myproxy = 0;
		}

	void _replace(const _Alty& _Al)
		{
		typename _Alty::template rebind<__Container_proxy>::other
			_Alproxy(this->_Alval);
		_Alproxy.destroy(this->_Myproxy);
		_Alproxy.deallocate(this->_Myproxy);
		this->_Myproxy = 0;
		this->_Alval = _Al;
		this->_Myproxy = _Alproxy.allocate();
		_Alproxy.construct(this->_Myproxy, __Container_proxy());
		}

	template<typename _Mt>
		void Swaping(_Mt& _Left, _Mt& _Right)
		{
		_Mt _l = _Left;
		_Left = _Right;
		_Right = l;
		}

	void _swap(_Myt& _N_alloc)
		{
		Swaping(this->_Alval, _N_alloc._Alval);
		Swaping(this->_Myproxy, _N_alloc._Myproxy);
		}

	_Alty& _get()
		{
		return this->_Alval;
		}

	const _Alty& _get() const
		{
		return this->_Alval;
		}
	
	};

	// BINARY TREE
template<typename _Ty, typename _Node = _tree_node<_Ty>,
		class _Alloc = t_allocator<_Node>> class
	tree
		: public _tree_alloc<_Tree_base_types<_Node, _Alloc>>
	{
public:
	typedef tree<_Ty, _Node, _Alloc> _Mytree;
	typedef _tree_alloc<_Tree_base_types<_Node, _Alloc>> _Mybase;

	typedef typename _Mybase::_Alty _Alty;

	typedef typename _Mybase::size_type size_type;
	typedef typename _Mybase::pointer pointer;
	typedef typename _Mybase::const_pointer const_pointer;
	typedef typename _Mybase::const_reference const_reference;

	typedef typename _Ty	value_type;
	typedef typename _Ty&	reference;

	tree()
		: _Mybase()
		{
		this->_Myhead = this->_get().allocate();
		this->_Mylast = this->_Myhead;
		}

	explicit tree(pointer& _Head)
		: _Mybase()
		{
		this->_Myhead = _Head;
		this->_Mylast = this->_Myhead;
		}

	~tree()
		{
		}

	void push_left(value_type val)
		{
		_Alty _Alval(this->_get());
		pointer _Left = pointer();
		_Left = _Alval.allocate();
		**_Left = val;
		this->_Mylast->_Left = _Left;
		this->_Mylast->_Left->_Parent = this->_Mylast;
		}

	void push_right(value_type val)
		{
		_Alty _Alval(this->_get());
		pointer _Right = pointer();
		_Right = _Alval.allocate();
		**_Right = val;
		this->_Mylast->_Right = _Right;
		this->_Mylast->_Right->_Parent = this->_Mylast;
		}

	void push_left()
		{
		_Alty _Alval(this->_get());
		pointer _Left = pointer();
		_Left = _Alval.allocate();
		**_Left = value_type();
		this->_Mylast->_Left = _Left;
		this->_Mylast->_Left->_Parent = this->_Mylast;
		}

	void push_right()
		{
		_Alty _Alval(this->_get());
		pointer _Right = pointer();
		_Right = _Alval.allocate();
		**_Right = value_type();
		this->_Mylast->_Right = _Right;
		this->_Mylast->_Right->_Parent = this->_Mylast;
		}

	bool into_left()
		{
		if ((*this->_Mylast).is_left())
			{
			this->_Mylast = this->_Mylast->_Left;
			return true;
			}
		else
			return false;
		}

	bool into_right()
		{
		if((*this->_Mylast).is_right())
			{
			this->_Mylast = this->_Mylast->_Right;
			return true;
			}
		else
			return false;
		}

	bool is_left()
		{
		if ((*this->_Mylast).is_left())
			return true;
		else
			return false;
		}

	bool is_right()
		{
		if ((*this->_Mylast).is_right())
			return true;
		else
			return false;
		}

	bool escape()
		{
		if ((*this->_Mylast).is_parent())
			{
			this->_Mylast = this->_Mylast->_Parent;
			return true;
			}
		else
			return false;
		}

	bool is_ground()
		{
		return this->_Mylast == this->_Myhead;
		}

	void ground()
		{
		this->_Mylast = this->_Myhead;
		}

	void into_deep_right()
		{
		for (; into_right();)
			;
		}

	void into_deep_left()
		{
		for (; into_left();)
			;
		}

	reference operator*()
		{
		return **this->_Mylast;
		}

	pointer travel()
		{
		return this->_Myhead;
		}

	};
	
template<class _Iter, class _Func>
	void inorder_travel(_Func& _T, _Iter _Next, _Iter _Head)
	{
	if (_Next == 0)
		return;
	inorder_travel(_T, _Next->_Left, _Head);
	//if(_Next != _Head)
		_T(_Next->_Data);
	inorder_travel(_T, _Next->_Right, _Head);
	}

template<class _Iter, class _Func>
	void postorder_travel(_Func& _T, _Iter _Next, _Iter _Head)
	{
	if (_Next == 0)
		return;
	postorder_travel(_T, _Next->_Left, _Head);
	postorder_travel(_T, _Next->_Right, _Head);
	//if(_Next != _Head)
		_T(_Next->_Data);
	}

template<class _Iter, class _Func>
	void preorder_travel(_Func& _T, _Iter _Next, _Iter _Head)
	{
	if (_Next == 0)
		return;
	//if(_Next != _Head)
		_T(_Next->_Data);
	preorder_travel(_T, _Next->_Left, _Head);
	preorder_travel(_T, _Next->_Right, _Head);
	}

#endif