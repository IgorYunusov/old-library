/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_stack
#define _x_lib_stack

#include "xstrfmy.h"

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

template<class linked_type>
	class stack
	{ // stack

	template<class linked_type>
		class stack_node
		{ // linked class node struct
		public:
		stack_node *_NextPtr;
		stack_node *_PrevPtr;
		linked_type _data;
		};

	typedef typename stack_node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;
	int sizeofit;

	public:

	stack()
		: _Head(0), _Tail(0), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Head->_PrevPtr = _Head;
		_Head->_NextPtr = _Tail;
		_Head->_PrevPtr = _Head;
		_Tail->_NextPtr = _Tail;
		}

	__forceinline _MyNode *_New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode;
		return ptr;
		}

	void push(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		if (sizeofit)
			{
			_Lastest->_NextPtr = temp;
			temp->_PrevPtr = _Lastest;
			temp->_NextPtr = _Tail;
			_Tail->_PrevPtr = temp;
			}
		else
			{
			_Head->_NextPtr = temp;
			temp->_PrevPtr = _Head;
			temp->_NextPtr = _Tail;
			_Tail->_PrevPtr = temp;
			}
		_Lastest = temp;
		sizeofit++;
		}

	linked_type pop()
		{ // pop back item
		_MyNode *ptr = _Head;
		_MyNode *prev = _Head;
		linked_type ret;
		for(int f = -1; ;f++)
			{
			if(ptr == _Tail)
				break;
			ret = ptr->_data;
			if(f > 0)
				prev = prev->_NextPtr;
			ptr = ptr->_NextPtr;
			}
		delete prev->_NextPtr;
		prev->_NextPtr = _Tail;
		_Tail->_PrevPtr = prev;
		return ret;
		}

	};

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-04
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/