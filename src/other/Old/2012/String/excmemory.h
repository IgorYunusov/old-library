/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_EXCMEM_
#define _ROLLRAT_EXCMEM_

#include "rutil.h"

#if defined(_EX_SUCCESS)

_X_LIB_BEGIN
	
	// TEMPLATE STANDARD MEMORY ALLOCATE FUNCTION

template<class identical_type> inline
	void _Construct(identical_type *_xPtr)
	{ // creat new memory
	void *_Ptr = _xPtr;
	_xPtr = new identical_type(0);
	}

template<class identical_type> inline
	void _Destructor(identical_type _Class)
	{ // execute to destructor of class
	_Class->~identical_type();
	}

template<class identical_type> inline
	identical_type *_Allocate(size_t _Size, identical_type *)
	{ // allocate memory scale
	void *_Ptr = 0;
	if (_Size) _Ptr = new(_Size * sizeof(identical_type));
	return (identical_type *)_Ptr;
	}

template<class identical_type> inline
	identical_type *_Allocate(size_t _Size)
	{ // allocate memory scale
	void *_Ptr = 0;
	if (_Size)
		_Ptr = new identical_type(_Size * sizeof(identical_type));
	return (identical_type *)_Ptr;
	}

template<class identical_type> inline
	void _Construct_n(identical_type *_xPtr)
	{ // construct array
	_xPtr = new identical_type[0];
	}

template<class identical_type> inline
	void _Destroy(identical_type *_xPtr)
	{ // destroy ptr in memory
	delete[] _xPtr;
	}

	// TEMPLATE NON-STANDARD MEMORY ALLOCATE FUNCTION

template<class identical_type> inline
	void _Allocate(identical_type *_left, size_t _lsize, size_t _rsize)
	{ // allocate memory with keeping on data
	identical_type *_temp;
	_temp = _Allocate<identical_type> (_rsize);
	for(int n = 0; n <= _lsize; n++)
		_temp[n] = _left[n];
	_Destroy(_left);
	_left = _temp;
	}

	// TEMPLATE LINKED CLASS

template<class linked_type>
	class _Node
	{ // linked class node struct
	public:
	_Node(size_t key) : _NextPtr(0), _Key(key), _data(0) {}
	~_Node() {}
	_Node *_NextPtr; // single link
	_Node *_PrevPtr; // double link
	size_t _Key;
	linked_type _data;
	};

template<class linked_type>
	class _Linked_Sequencer
	{ // linekd class sequencer
	_Node<linked_type> *_Head;
	_Node<linked_type> *_Tail;
	size_t point;

	public:

	_Linked_Sequencer(_Node _head, _Node _tail)
		: _Head(_head), _Tail(_tail), point(1)
		{ // load entry point
		}

	bool operator++(int)
		{ // point at forward
		point += 1;
		return true;
		}

	bool operator--(int)
		{ // point at back
		if(point)
		{point -= 1;
			return true;}
		return false;
		}

	bool operator+(int _left)
		{ // point at size +
		point += _left;
		return true;
		}
	
	bool operator-(int _left)
		{ // point at size -
		if(point >= _left)
		{point -= _left;
			return true;}
		return false;
		}

	_Node* operator*()
		{ // return node pointed at pointer
		_Node<linked_type> *temp = _Head;
		if(point)
			while(temp->_Key != point && temp != tail)
				temp = temp->_NextPtr;
		return temp;
		}

	_Node& operator&()
		{ // return node pointed at pointer
		_Node<linked_type> *temp = _Head;
		if(point)
			while(temp->_Key != point && temp != tail)
				temp = temp->_NextPtr;
		return temp;
		}

	};

template<class linked_type>
	class link
	{ // linekd class sequencer
	typedef typename _Node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;
	size_t point;
	int sizeofit;

	public:

	link()
		: _Head(0), _Tail(0), point(-1), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Init(_Head, _Tail);
		}

	bool operator++(int)
		{ // point at forward
		if (point < (sizeofit-1) || point == -1)
			{
			point++;
			return true;
			}
		point = -1;
		return false;
		}

	bool operator--(int)
		{ // point at back
		if(point)
			{
			point--;
			return true;
			}
		return false;
		}

	bool operator+(int _left)
		{ // point at size +
		point += _left;
		return true;
		}
	
	bool operator-(int _left)
		{ // point at size -
		if(point >= _left)
		{point -= _left;
			return true;}
		return false;
		}

	_MyNode *_New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode(sizeof(_MyNode));
		return ptr;
		}

	_MyNode* operator*()
		{ // return node pointed at pointer
		_MyNode *temp = _Head;
		if (!point)
			return temp->_NextPtr;
		else 
			while(temp->_Key != point && temp != _Tail)
				temp = temp->_NextPtr;
		return temp;
		}

	_MyNode& operator&()
		{ // return node pointed at pointer
		_MyNode *temp = _Head;
		if (!point)
			;
		else 
			while(temp->_Key != point && temp != _Tail)
				temp = temp->_NextPtr;
		return temp;
		}

	void push_back(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_Key = sizeofit;
		temp->_data = _left;
		if (sizeofit)
			_Connect(_Lastest, temp, _Tail);
		else
			_Connect(_Head, temp, _Tail);
		_Lastest = temp;
		sizeofit++;
		}

	linked_type pop_back()
		{ // pop back item
		_MyNode *temp = _Head;
		linked_type prev;
		while(temp->_NextPtr != _Tail)
			{
			temp = temp->_NextPtr;
			prev = temp->_data;
			}
		temp->_NextPtr = _Tail;
		delete temp;
		sizeofit--;
		return prev;
		}

	};

	// TEMPLATE LINKED CLASS ALLOCATE FUNCTION USE OF S-LL

template<class linked_type> inline 
	_Node<linked_type>* _New_Link()
	{ // create new link
	_Node<linked_type> *ptr = new _Node<linked_type> (0);
	return ptr;
	}

template<class linked_type> inline
	void _Connect(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _target;
	_target->_NextPtr = _tail;
	}

template<class linked_type> inline
	void _Translate(linked_type _left, linked_type _right)
	{ // translate link
	linked_type _node(0);
	_node->_Key = _left->_Key;
	_node->_NextPtr = _left->_NextPtr;
	_left->_Key = _right->_Key;
	_left->_NextPtr = _right->_NextPtr;
	_right->_Key = _node->_Key;
	_right->_NextPtr = _node->_NextPtr;
	}

template<class linked_type> inline
	void _Disconnect(linked_type _linked)
	{ // diconnect in memory field
	_Destructor(_linked);
	}

template<class linked_type> inline
	void _Init(linked_type _head, linked_type _tail)
	{ // initialization the link
	_head->_NextPtr = _tail;
	_tail->_NextPtr = _tail;
	}

template<class linked_type> inline
	void _Move(linked_type _llinked, linked_type _rlinked)
	{ // move data
	_llinked->_Key = _rlinked->_Key;
	_llinked->_NextPtr = _rlinked->_NextPtr;
	_llinked->_data = _rlinked->_data;
	_llinked->_PrevPtr = _rlinked->_PrevPtr;
	}

	// TEMPLATE LINKED CLASS ALLOCATE FUNCTION USE OF D-LL

template<class linked_type> inline
	void _Connect_D(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect lind double
	_head->_NextPtr = _target;
	_target->_PrevPtr = _head;
	_target->_NextPtr = _tail;
	_tail->_PrevPtr = _target;
	}

template<class linked_type> inline
	void _Init_D(linked_type _head, linked_type _tail)
	{ // initialization the link double
	_head->_PrevPtr = _head;
	_head->_NextPtr = _tail;
	_head->_PrevPtr = _head;
	_tail->_NextPtr = _tail;
	}


_X_LIB_END


#endif

#endif
/*
 *	the rollrat library
 *	http://blog.naver.com/rollrat
V0.1:1600****/