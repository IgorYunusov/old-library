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

template<class _operator_type> class
	_qurey_array_allocator
	{ // the allocator class
	_operator_type* _array;
	int point;
	int size;

	public:

	explicit _qurey_array_allocator()
		: _array(0), size(0), point(0)
		{ // entry point
		}

	_operator_type& operator[](int _left)
		{ // return element
		if(size < _left)
			THROW_ERROR_INPUT(_left)
		return _array[_left];
		}

	_qurey_array_allocator* operator->()
		{ // return array reference
		return (**this);
		}

	_operator_type& begin()
		{ // begin
		return this->operator*;
		}

	_operator_type& last()
		{ // last
		return _array[size];
		}

	int Size() const
		{ // size of this
		return size;
		}

	bool operator++(int)
		{ // point at forward
		if(size == point)
		{	
			point = 0;
			return false;
		}
		point++;
		return true;
		}

	bool operator--(int)
		{ // point at back
		if(point == 0)
			return false;
		point--;
		return true;
		}

	bool operator+(int _left)
		{ // point at size +
		if(size < (point + _left))
			return false;
		point += _left;
		return true;
		}

	bool operator-(int _left)
		{ // point at size -
		if((point - _left) == 0)
			return false;
		point -= _left;
		return true;
		}

	int ptr()
		{ // return pointer
		return point;
		}

	bool status()
		{ // if point == size
		if(point == size)
			return false;
		return true;
		}

	void at(int _left)
		{ // at
		if(size >= _left)
			point = _left;
		}

	void operator=(_qurey_array_allocator _left)
		{ // equal
		_array = _left._array;
		size = _left.size;
		point = _left.point;
		}

	void operator=(int _left)
		{ // point at
		point = _left;
		}

	_operator_type operator*()
		{ // return point
		return _array[point];
		}

	_operator_type& operator&()
		{ // return reference
		return _array[point];
		}

	int operator^(int)
		{ // return size of this
		return size;
		}

	bool operator^(_qurey_array_allocator _left)
		{ // compare to allocator
		if(_left->_array != _array)
			return false;
		else if(_left->size != size)
			return false;
		return true;
		}

	bool operator==(_qurey_array_allocator _left)
		{ // operator ==
		return this->operator* == *_left;
		}

	bool operator!=(_qurey_array_allocator _left)
		{ // operator !=
		return this->operator* != *_left;
		}

	bool operator<(_qurey_array_allocator _left)
		{ // operator <
		return this->operator* < *_left;
		}

	bool operator>(_qurey_array_allocator _left)
		{ // operator >
		return this->operator* > *_left;
		}

	bool operator<=(_qurey_array_allocator _left)
		{ // operator <=
		return this->operator* <= *_left;
		}

	bool operator>=(_qurey_array_allocator _left)
		{ // operator >=
		return this->operator* >= *_left;
		}

	bool operator==(int _left)
		{ // operator ==
		return size == _left;
		}

	bool operator!=(int _left)
		{ // operator !=
		return size != _left;
		}

	bool operator<(int _left)
		{ // operator <
		return size < _left;
		}

	bool operator>(int _left)
		{ // operator >
		return size > _left;
		}

	bool operator<=(int _left)
		{ // operator <=
		return size <= _left;
		}

	bool operator>=(int _left)
		{ // operator >=
		return size >= _left;
		}

	bool operator&&(_qurey_array_allocator _left)
		{ // operator &&
		return this->operator* && *_left;
		}

	bool operator||(_qurey_array_allocator _left)
		{ // operator ||
		return this->operator* || *_left;
		}

	int size_of() const
		{ // get size
		return size;
		}

	void allocate(int _size)
		{ // allocatre all array
		_operator_type* _buf = _new<_operator_type> (_size);
		size = _size;
		_array = _buf;
		}

	_qurey_array_allocator& copythis()
		{ // copy this
		_qurey_array_allocator<_operator_type> _temp;
		_temp.allocate(size);
		for(int i = 0; i <= size; i++)
			_temp[i] = _array[i];
		return _temp;
		}

	};

template<class _operator_type> class
	_qurey_array_allocator_double
	: public _qurey_array_allocator<_qurey_array_allocator<_operator_type> >
	{ // the allocatore class by two dimention
	};

template<class _operator_type> class
	_qurey_array_allocator_square
	: public _qurey_array_allocator_double<_qurey_array_allocator<_operator_type> >
	{ // the array allocatore by three dimention
	};

template<class identical_type>
	class qurey_array_import_data_escator
	{ // qurey_import_data_escator
	protected:

	typedef typename _qurey_array_allocator<identical_type> _MyQuarya;

	_qurey_array_allocator_double<identical_type> _qurey_allocator;

	_MyQuarya _qurey_allocator_pointer;
	_MyQuarya _qurey_allocator_standard_data_set;
	_MyQuarya _qurey_allocator_virtual;
	_MyQuarya _qurey_allocator_backup;

	public:

	explicit qurey_array_import_data_escator() 
		{ // qurey entry point
		_qurey_allocator_pointer.allocate(5);
		for( ; _qurey_allocator_pointer++; )
			&_qurey_allocator_pointer = 0;
		}

	bool put(identical_type _left, int _right)
		{ // put data
		if( _qurey_allocator_pointer[0] >= _right)
			_qurey_allocator[_qurey_allocator_pointer[0]][_right] = _left;
		else
			return false;
		return true;
		}

	identical_type get(int _right)
		{ // get data
		return _qurey_allocator[_qurey_allocator_pointer[0]][_right];
		}

	};

template<class identical_type>
	class qurey_arary_memory
	{ // memory allocator pressure
	protected:

	typedef typename _qurey_array_allocator<identical_type> _MyQuarya;

	_MyQuarya _qurey_allocator_standard_data_set;
	_MyQuarya _qurey_allocator_virtual;
	_MyQuarya _qurey_allocator_backup;

	};

template<class identical_type>
	class qurey_array_sorting
	{ // sorting algorithm
	protected:

	typedef typename _qurey_array_allocator_double<identical_type> _MyQurey;

	_MyQurey _buf_qurey;

	public:

	explicit qurey_array_sorting(_MyQurey& _qurey) 
		: _buf_qurey(_qurey)
		{ // qurey entry point
		}

	_MyQurey& sort(int _right)
		{ // sorting
		_quick_sort(_buf_qurey[_right], _buf_qurey[_right]^0); 
		}

	};

template<class identical_type>
	class qurey_array_sequencer
	{ // the _sequencer class
	identical_type *item;
	int point;
	int size;

	public:

	qurey_array_sequencer(identical_type *_Ptr, int _Size)
		: item(_Ptr), size(_Size)
		{ // sequencer entry point
		}

	identical_type operator*()
		{ // return point
		return item[point];
		}

	identical_type& operator&()
		{ // return reference
		return item[point];
		}

	bool operator++(int)
		{ // point at forward
		if(size == point)
		{	
			point = 0;
			return false;
		}
		point++;
		return true;
		}

	bool operator--(int)
		{ // point at back
		if(point == 0)
			return false;
		point--;
		return true;
		}

	bool operator+(int _left)
		{ // point at size +
		if(size < (point + _left))
			return false;
		point += _left;
		return true;
		}

	bool operator-(int _left)
		{ // point at size -
		if((point - _left) == 0)
			return false;
		point -= _left;
		return true;
		}

	bool operator==(identical_type _left)
		{ // operator ==
		return this->operator* == _left;
		}

	bool operator!=(identical_type _left)
		{ // operator !=
		return this->operator* != _left;
		}

	bool operator<(identical_type _left)
		{ // operator <
		return this->operator* < _left;
		}

	bool operator>(identical_type _left)
		{ // operator >
		return this->operator* > _left;
		}

	bool operator<=(identical_type _left)
		{ // operator <=
		return this->operator* <= _left;
		}

	bool operator>=(identical_type _left)
		{ // operator >=
		return this->operator* >= _left;
		}

	};

template<class linked_type>
	class _qurey_link_node
	{ // linked class node struct
	public:
	_qurey_link_node *_NextPtr;
	_qurey_link_node *_PrevPtr;
	linked_type _data;
	};

template<class linked_type>
	class _qurey_tree_node
	{ // linked class node struct
	public:
	_qurey_tree_node *_Left;
	_qurey_tree_node *_Right;
	linked_type _data;
	};

template<class linked_type>
	class _qurey_stack_node
	{ // linked class node struct
	public:
	_qurey_stack_node *_NextPtr;
	_qurey_stack_node *_PrevPtr;
	linked_type _data;
	};

template<class linked_type>
	class qurey_link
	{ // linekd class
	typedef typename _qurey_link_node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;
	size_t point;
	int sizeofit;

	public:

	qurey_link()
		: _Head(0), _Tail(0), point(-1), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Qurey_Init(_Head, _Tail);
		}

	__forceinline _MyNode*& begin()
		{ // begin function
		return _Head->_NextPtr;
		}

	__forceinline _MyNode*& end()
		{ // end function
		return _Tail;
		}
	
	__forceinline bool operator++(int)
		{ // point at forward
		if (point < (sizeofit-1) || point == -1)
			{
			point++;
			return true;
			}
		point = -1;
		return false;
		}

	__forceinline bool operator--(int)
		{ // point at back
		if(point)
			{
			point--;
			return true;
			}
		return false;
		}

	__forceinline bool operator+(int _left)
		{ // point at size +
		point += _left;
		return true;
		}
	
	__forceinline bool operator-(int _left)
		{ // point at size -
		if(point >= _left)
		{point -= _left;
			return true;}
		return false;
		}

	__forceinline int operator^(int) const
		{ // return size
		return sizeofit;
		}

	__forceinline _MyNode *_New_Node()
		{ // create new node
		_MyNode *ptr = new _MyNode;
		return ptr;
		}

	_MyNode* operator*()
		{ // return node pointed at pointer
		int i = point+1;
		_MyNode *ptr = _Head;
		while(i--)
			ptr = ptr->_NextPtr;
		return ptr;
		}

	_MyNode& operator&()
		{ // return node pointed at pointer
		int i = point+1;
		_MyNode *ptr = _Head;
		while(i--)
			ptr = ptr->_NextPtr;
		return ptr;
		}

	void push_back(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		if (sizeofit)
			_Qurey_Connect(_Lastest, temp, _Tail);
		else
			_Qurey_Connect(_Head, temp, _Tail);
		_Lastest = temp;
		sizeofit++;
		}

	void push_front(linked_type _left)
		{ // push back item
		_MyNode *temp = _New_Node();
		temp->_data = _left;
		_Qurey_Connect(_Head, temp, _Head->_NextPtr);
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
		_Qurey_Connect(prev, _Tail);
		return ret;
		}

	linked_type pop_front()
		{ // pop back item
		_MyNode *ptr = _Head->_NextPtr;
		linked_type ret = ptr->_data;
		_Qurey_Connect(_Head, ptr->_NextPtr);
		delete ptr;
		return ret;
		}

	};

template<class identical_type>
	class qurey_sequencer
	{ // the _sequencer class
	typedef typename _qurey_link_node<identical_type> _MyNode;

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
	class qurey_const_sequencer
	{ // the _sequencer class
	typedef typename _qurey_link_node<identical_type> _MyNode;
	
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
	void _Qurey_Connect(linked_type _head, linked_type _target, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _target;
	_target->_PrevPtr = _head;
	_target->_NextPtr = _tail;
	_tail->_PrevPtr = _target;
	}

template<class linked_type> inline
	void _Qurey_Connect(linked_type _head, linked_type _tail)
	{ // connect link
	_head->_NextPtr = _tail;
	_tail->_PrevPtr = _head;
	}

template<class linked_type> inline
	void _Qurey_Init(linked_type _head, linked_type _tail)
	{ // initialization the link
	_head->_PrevPtr = _head;
	_head->_NextPtr = _tail;
	_head->_PrevPtr = _head;
	_tail->_NextPtr = _tail;
	}

template<class linked_type>
	class _qurey_tree_stack
	{ // tree stack
	typedef typename _qurey_stack_node<linked_type> _MyNode;

	_MyNode *_Head;
	_MyNode *_Tail;
	_MyNode *_Lastest;
	int sizeofit;

	public:

	_qurey_tree_stack()
		: _Head(0), _Tail(0), point(-1), sizeofit(0)
		{ // load entry point
		_Head = _New_Node();
		_Tail = _New_Node();
		_Qurey_Init(_Head, _Tail);
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
			_Qurey_Connect(_Lastest, temp, _Tail);
		else
			_Qurey_Connect(_Head, temp, _Tail);
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
		_Qurey_Connect(prev, _Tail);
		return ret;
		}

	};

template<class linked_type>
	class qurey_tree_link
	{ // linekd class
	typedef typename qurey_tree_link<linked_type> _MyNode;
	typedef typename _qurey_tree_node<linked_type> _MyNodes;

	_MyNode *_Head;
	_MyNodes *_NextPtr;
	_MyNodes *_PrevPtr;
	linked_type _data;

	public:

	_qurey_tree_stack<linked_type> _Stack;

	qurey_tree_link()
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
		_Qurey_Connect(_Head, temp);
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