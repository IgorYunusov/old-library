/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _xtree_
#define _xtree_

#include "xstrfmy.h"
#include "xalloc.h"

/*----------------------------------------------------------------

				The Complex Programming Project

	The headers in C/C++ is all about grammar as much as 
	possible.

	LEVELS:

	CM LEVEL : (Complexity Metric)
		NOTE : http://en.wikipedia.org/wiki/Cyclomatic_complexity

	+----------+---------------------------------------------+
	| TYPENAME | Standard Expression						 |
	+----------+---------------------------------------------+
	| _Ty(n)A  | 1											 |
	| _Ty(n)B  | 1.5 or x									 |
	| _Ty(n)C  | log x										 |
	| _Ty(n)D  | log 2x										 |
	| _Ty(n)E  | 2 log x									 |
	| _Ty(n)F  | 2 ^ x										 |
	| _Ty(n)G  | 3 ^ x										 |
	+----------+---------------------------------------------+

----------------------------------------------------------------*/

		// The prefix 'X' means using iterator class.

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<class _Mybase>
	class x_tree_node
	{
public:
	typedef x_tree_node<_Mybase> _MyVal;

	typedef typename _Mybase::value_type value_type;
	typedef typename _Mybase::const_pointer pointer;
	typedef typename _Mybase::difference_type difference_type;
	typedef typename _Mybase::const_reference reference;
	typedef typename _Mybase::pointer _TyPtr;

	x_tree_node()
		{
		_next = _MyVal();
		_prev = _MyVal();
		}

	_MyVal *_next;
	_MyVal *_prev;

	value_type _data;
	};

template<class _Mybase>
	class x_tree_val
	{	// tree value
public:
	typedef typename _Mybase::value_type value_type;
	typedef typename _Mybase::const_pointer pointer;
	typedef typename _Mybase::difference_type difference_type;
	typedef typename _Mybase::const_reference reference;
	typedef typename _Mybase::pointer _TyPtr;
	
	typedef x_tree_node<value_type> _Mynode;
	typedef x_tree_val<value_type> _MyVal;

	x_tree_val()
		{
		_start = _MyVal();
		_end = _MyVal();
		_last = _MyVal();
		}

	_MyVal *_start;
	_MyVal *_last;
	_MyVal *_end;

	_Mynode *_data;
	};

template<class _Mybase>
	class x_tree_stack
		: public x_tree_val<_Mybase>
	{	// tree stack
public:
	typedef typename _Mybase::value_type value_type;
	typedef typename _Mybase::const_pointer pointer;
	typedef typename _Mybase::difference_type difference_type;
	typedef typename _Mybase::const_reference reference;
	typedef typename _Mybase::pointer _TyPtr;
	
	x_tree_stack()
		{
		_start = virtual_alloc<x_tree_val<_Mybase>::_MyVal> (1);
		_end = virtual_alloc<x_tree_val<_Mybase>::_MyVal> (1);
		_data = virtual_alloc<x_tree_val<_Mybase>::_Mynode> (1);
		_last = _start;
		}

	void push(value_type _Set)
		{	// push back
		x_tree_val<_Mybase> *_Ptr = 
			virtual_alloc<x_tree_val
				<_Mybase>::_MyVal> (1);
		_Ptr->_data->_data = _Set;
		_Ptr->_start = _last;
		_Ptr->_end = _end;
		_last = _Ptr;
		}

	value_type pop()
		{	// pop back
		value_type x = _last->_data;
		_last->_prev = _end;
		delete _last;
		return x;
		}

	};

_X_LIB_END
#endif
#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/

/*
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-06-01
 *	C/C++ syntax of the total complex made ​​possible by mobilizing header.
 *	If you understand all this, you C/C++ will have 
 *	completed all of the grammar.
L1_H*/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/