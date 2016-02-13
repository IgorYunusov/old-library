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

#ifndef _TREE_EX_
#define _TREE_EX_

#include "tree.h"
	
	// reference : Kasper Peeters [ STL-like templated tree class ]
	
template<class _Tree_val> class
	_xtree_node
		: public _Container_base
	{
public:
	typedef _xtree_node<_Tree_val> _Myt;
	
	typedef typename __SIZE_TYPE		size_type;
	typedef typename __OTHER_TYPE		difference_type;
	typedef typename _Tree_val*			pointer;
	typedef typename const _Tree_val*	const_pointer;
	typedef typename _Tree_val&			reference;
	typedef typename const _Tree_val&	const_reference;
	typedef typename _Tree_val			value_type;

	_xtree_node() : 
		_Left(nullptr), _Right(nullptr), _Parent(nullptr), _Data(0)
		{
		}

	_xtree_node(value_type _data) : 
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
	_Myt *_Prev, *_Next;
	value_type _Data;
	};

	// ultimate tree
template<typename _Ty, typename _Node = _xtree_node<_Ty>,
		class _Alloc = t_allocator<_Node>> class
	xtree
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

	xtree()
		: _Mybase()
		{
		this->_Myhead = this->_get().allocate();
		this->_Mylast = this->_Myhead;
		}

	explicit xtree(pointer& _Head)
		: _Mybase()
		{
		this->_Myhead = _Head;
		this->_Mylast = this->_Myhead;
		}

	~xtree()
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

	//////////////////////////////
	//-> ultimate tree method

	};

#endif