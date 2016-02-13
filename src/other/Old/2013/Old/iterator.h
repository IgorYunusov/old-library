/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_iterator
#define _x_lib_iterator

#include "xstrfmy.h"

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

template<class linked_type>
	class iterator_node
	{ // linked class node struct
	public:
	iterator_node *_NextPtr;
	iterator_node *_PrevPtr;
	linked_type _data;
	};

template<class identical_type>
	class iterator
	{ // the _sequencer class
	typedef typename iterator_node<identical_type> _MyNode;

	_MyNode *point;

	public:

	__forceinline identical_type& operator*()
		{ // return point
		return point->_data;
		}

	__forceinline void operator++(int)
		{ // point at forward
		point = point->_NextPtr;
		}

	__forceinline void operator--(int)
		{ // point at forward
		point = point->_PrevPtr;
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	__forceinline bool operator==(_MyNode *_left)
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left)
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left)
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left)
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left)
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left)
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left)
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left)
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class identical_type>
	class const_iterator
	{ // the _sequencer class
	typedef typename iterator_node<identical_type> _MyNode;
	
	_MyNode *point;

	public:

	__forceinline identical_type operator*() const
		{ // return point
		return point->_data;
		}

	__forceinline void operator++(int)
		{ // point at forward
		point = point->_NextPtr;
		}

	__forceinline void operator--(int)
		{ // point at forward
		point = point->_PrevPtr;
		}

	__forceinline void operator=(_MyNode *_left)
		{
		point = _left;
		}

	__forceinline bool operator==(_MyNode *_left) const
		{ // operator ==
		return point == _left;
		}

	__forceinline bool operator!=(_MyNode *_left) const
		{ // operator !=
		return point != _left;
		}

	__forceinline bool operator==(identical_type _left) const
		{ // operator ==
		return this->operator* == _left;
		}

	__forceinline bool operator!=(identical_type _left) const
		{ // operator !=
		return this->operator* != _left;
		}

	__forceinline bool operator<(identical_type _left) const
		{ // operator <
		return this->operator* < _left;
		}

	__forceinline bool operator>(identical_type _left) const
		{ // operator >
		return this->operator* > _left;
		}

	__forceinline bool operator<=(identical_type _left) const
		{ // operator <=
		return this->operator* <= _left;
		}

	__forceinline bool operator>=(identical_type _left) const
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class linked_type> inline
	void _Link_Connect(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _target;
	_target->_PrevPtr = _head;
	_target->_NextPtr = _tail;
	_tail->_PrevPtr = _target;
	}

template<class linked_type> inline
	void _Link_Connect(linked_type _head, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _tail;
	_tail->_PrevPtr = _head;
	}

template<class linked_type> inline
	void _Link_Init(linked_type _head, linked_type _tail)
	{ // initialization the link
	_head->_PrevPtr = _head;
	_head->_NextPtr = _tail;
	_head->_PrevPtr = _head;
	_tail->_NextPtr = _tail;
	}

template<class linked_type>
	class link
	{ // linekd class
		
	typedef typename iterator_node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;

	int sizeofit;

	public:
		
	typedef typename iterator_node<linked_type> _NodeIt;
	typedef typename iterator<linked_type> iterator;
	typedef typename const_iterator<linked_type> const_iterator;

	link()
		: _Head(0), _Tail(0), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Link_Init(_Head, _Tail);
		}

	__forceinline _MyNode*& begin()
		{ // begin function
		return _Head->_NextPtr;
		}

	__forceinline _MyNode*& end()
		{ // end function
		return _Tail;
		}
	
	__forceinline _MyNode* _New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode;
		return ptr;
		}

	int operator^(int) const
		{ // operator ^
		return sizeofit;
		}

	void push_back(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		if (sizeofit)
			_Link_Connect(_Lastest, temp, _Tail);
		else
			_Link_Connect(_Head, temp, _Tail);
		_Lastest = temp;
		sizeofit++;
		}

	void push_front(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		_Link_Connect(_Head, temp, _Head->_NextPtr);
		_Lastest = temp;
		sizeofit++;
		}

	linked_type pop_back()
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
		_Link_Connect(prev, _Tail);
		return ret;
		}

	linked_type pop_front()
		{ // pop back item
		_MyNode *ptr = _Head->_NextPtr;
		linked_type ret = ptr->_data;
		_Link_Connect(_Head, ptr->_NextPtr);
		delete ptr;
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