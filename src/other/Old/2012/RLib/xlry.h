/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_xlry
#define _x_lib_xlry

#include "xstrfmy.h"

/*------------------------------------------------------------

					The Link Array

	This header provides the class that is used to be 
	complex hard cording Array or programming code. You can
	also feel free to existing grammar in c++, by the subject, 
	you can provides extreme code that can be provided. The 
	encyclopedic knowledge about pointers and references, 
	and operated before using this header is required.

------------------------------------------------------------*/

 #undef array

 #pragma push_macro( "array" )
 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<class _In_0>
	struct _xlry_Fn_Lno
	{ // linked node
	public:
	typedef typename __type<_In_0>
		::value_type _Fn_T;
	_xlry_Fn_Lno(_In_0 _First)
		: _data(_First) { /* ... */ }
	_xlry_Fn_Lno() 
		: _data(0) { /* ... */ }
	_xlry_Fn_Lno *_next;
	_xlry_Fn_Lno *_prev;
	_In_0		  _data;
	};

template<class _In_1>
	class _xlry_iter_Fn
	{ // the iterator class
	typedef typename _xlry_Fn_Lno<_In_1> _MyNode;
	_MyNode *point;
	public:
	_In_1& operator*()
		{
		return point->_data;
		}
	void operator++(int)
		{
		point = point->_next->_next;
		}
	void operator--(int)
		{
		point = point->_prev;
		}
	void operator=(_MyNode *_left)
		{
		point = _left;
		}
	bool operator==(_MyNode *_left)
		{
		return point == _left;
		}
	bool operator!=(_MyNode *_left)
		{
		return point != _left;
		}
	bool operator==(_In_1 _left)
		{
		return this->operator* == _left;
		}
	bool operator!=(_In_1 _left)
		{
		return this->operator* != _left;
		}
	bool operator<(_In_1 _left)
		{
		return this->operator* < _left;
		}
	bool operator>(_In_1 _left)
		{
		return this->operator* > _left;
		}
	bool operator<=(_In_1 _left)
		{
		return this->operator* <= _left;
		}
	bool operator>=(_In_1 _left)
		{
		return this->operator* >= _left;
		}
	};

template<class _In_1>
	class _xlry_citer_Fn
	{ // the citerator class
	typedef typename _xlry_Fn_Lno<_In_1> _MyNode;
	_MyNode *point;
	public:
	_In_1 operator*() const
		{
		return point->_data;
		}
	void operator++(int)
		{
		point = point->_next;
		}
	void operator--(int)
		{
		point = point->_prev;
		}
	void operator=(_MyNode *_left)
		{
		point = _left;
		}
	bool operator==(_MyNode *_left) const
		{
		return point == _left;
		}
	bool operator!=(_MyNode *_left) const
		{
		return point != _left;
		}
	bool operator==(_In_1 _left) const
		{
		return this->operator* == _left;
		}
	bool operator!=(_In_1 _left) const
		{
		return this->operator* != _left;
		}
	bool operator<(_In_1 _left) const
		{
		return this->operator* < _left;
		}
	bool operator>(_In_1 _left) const
		{
		return this->operator* > _left;
		}
	bool operator<=(_In_1 _left) const
		{
		return this->operator* <= _left;
		}
	bool operator>=(_In_1 _left) const
		{
		return this->operator* >= _left;
		}
	};

template<class _Out_0,
		class _InputT_ = int>
	class array
	{ // link array fn
	typedef typename _xlry_Fn_Lno<typename 
		__type<_Out_0>::value_type> _MyLno;
	typedef typename 
		__type<_MyLno>::pointer _Input_;
	typedef typename 
		__type<_MyLno>::reference _Output_;

	_MyLno *_Head, *_Tail;
	_InputT_ _Pointer, _Back_PP;
	_MyLno *_Lastest;

	public:

	typedef typename _xlry_iter_Fn<_Out_0> iterator;
	typedef typename _xlry_citer_Fn<_Out_0> const_iterator;

	explicit array() _NOTHROW
		: _Pointer(0), _Back_PP(0)
		{ // array entry
		_Head = _New_Node();
		_Tail = _New_Node();
		__Init(_Head, _Tail);
		}

	__forceinline _MyLno *_New_Node()
		{ // create new node
		_MyLno *ptr = new _MyLno;
		return ptr;
		}

	__forceinline void operator++(_InputT_)
		{ // operator ++
		_Pointer++;
		}

	__forceinline void operator--(_InputT_)
		{ // operator --
		if(!_Pointer)
			_Pointer--;
		}

	__forceinline _MyLno *&begin()
		{ // begin function
		return _Head;
		}

	__forceinline _MyLno *&end()
		{ // end function
		return _Tail;
		}

	_MyLno *operator*()
		{ // operator *
		_MyLno *_Temp = _Head;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _Pointer; Fn_n++)
			_Temp = _Temp->_next;
		return _Temp;
		}

	_MyLno *&operator&()
		{ // operator &
		_MyLno *_Temp = _Head;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _Pointer; Fn_n++)
			_Temp = _Temp->_next;
		return _Temp;
		}

	_MyLno *&operator[](_InputT_ _First)
		{ // operator []
		_MyLno *_Temp = _Head;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_next;
		return _Temp;
		}

	_MyLno *&operator()(_InputT_ _First)
		{ // opeartor ()
		_MyLno *_Temp = _Tail;
		for(_InputT_ Fn_n = 0; 
				Fn_n <= _First; Fn_n++)
			_Temp = _Temp->_prev;
		return _Temp;
		}

	void push_back(_Out_0 _left)
		{ // push back item
		_MyLno *temp = _New_Node();
		temp->_data = _left;
		if (_Back_PP)
			__Connect(_Lastest, temp, _Tail);
		else
			__Connect(_Head, temp, _Tail);
		_Lastest = temp;
		_Back_PP++;
		}

	void push_front(_Out_0 _left)
		{ // push back item
		_MyLno *temp = _New_Node();
		temp->_data = _left;
		__Connect(_Head, temp, _Head->_next);
		_Lastest = temp;
		_Back_PP++;
		}

	_Out_0 pop_back()
		{ // pop back item
		_MyLno *ptr = _Head;
		_MyLno *prev = _Head;
		_Out_0 ret;
		for(int f = -1; ; f++)
			{
			if(ptr == _Tail)
				break;
			ret = ptr->_data;
			if(f > 0)
				prev = prev->_next;
			ptr = ptr->_next;
			}
		delete prev->_next;
		_Connect(prev, _Tail);
		_Back_PP--;
		return ret;
		}

	_Out_0 pop_front()
		{ // pop back item
		_MyLno *ptr = _Head->_next;
		_Out_0 ret = ptr->_data;
		_Connect(_Head, ptr->_next);
		delete ptr;
		_Back_PP--;
		return ret;
		}

	private:

	__forceinline void _Connect(_MyLno *_head, _MyLno *_tail)
		{ // connect link
		_head->_next = _tail;
		_tail->_prev = _head;
		}
	
	__forceinline void __Connect(_MyLno *_head, 
			_MyLno *_target, _MyLno *_tail)
		{ // connect link
		_head->_next = _target;
		_target->_prev = _head;
		_target->_next = _tail;
		_tail->_prev = _target;
		}

	__forceinline void __Init(_MyLno *_head, _MyLno *_tail)
		{ // initialization the link
		_head->_prev = _head;
		_head->_next = _tail;
		_head->_prev = _head;
		_tail->_next = _tail;
		}

	protected:
		array *_Compho;
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