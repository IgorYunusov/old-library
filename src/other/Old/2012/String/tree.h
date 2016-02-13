/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#pragma warning( disable: 4049 )

#ifndef _ROLLRAT_QUREY_
#define _ROLLRAT_QUREY_

#include "rutil.h"
#include "cutilityex.h"

#if defined(_EX_SUCCESS)

_X_LIB_BEGIN

template<class linked_type>
	class stack_node
	{ // linked class node struct
	public:
	stack_node *_NextPtr;
	stack_node *_PrevPtr;
	linked_type _data;
	};

template<class linked_type> inline
	void __Connect(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _target;
	_target->_PrevPtr = _head;
	_target->_NextPtr = _tail;
	_tail->_PrevPtr = _target;
	}

template<class linked_type> inline
	void __Connect(linked_type _head, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _tail;
	_tail->_PrevPtr = _head;
	}

template<class linked_type> inline
	void __Init(linked_type _head, linked_type _tail)
	{ // initialization the link
	_head->_PrevPtr = _head;
	_head->_NextPtr = _tail;
	_head->_PrevPtr = _head;
	_tail->_NextPtr = _tail;
	}

template<class linked_type>
	class stack
	{ // tree stack
	typedef typename stack_node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;
	int sizeofit;

	public:

	stack()
		: _Head(0), _Tail(0), point(-1), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		__Init(_Head, _Tail);
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
			__Connect(_Lastest, temp, _Tail);
		else
			__Connect(_Head, temp, _Tail);
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
		__Connect(prev, _Tail);
		return ret;
		}

	};

template<class linked_type>
	class tree
	{ // linekd class
	typedef typename tree<linked_type> _MyNode;
	typedef typename stack_node<linked_type> _MyNodes;

	_MyNode *_Head;
	_MyNodes *_NextPtr;
	_MyNodes *_PrevPtr;
	linked_type _data;

	public:

	stack_node<linked_type> _Stack;

	tree()
		: _Head(0)
		{ // load entry point
		_Head = _New_Node();
		}

	__forceinline _MyNode *_New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode;
		return ptr;
		}

	void _Root(linked_type _left)
		{ // create root
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		__Connect(_Head, temp);
		}

	__forceinline _MyNode* _Left()
		{ // get left
		return _Head->_Head;
		}

	__forceinline _MyNode* _Right()
		{ // get Right
		return _Head->_NextPtr;
		}

	};


_X_LIB_END


#endif

#endif