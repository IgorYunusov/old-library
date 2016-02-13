/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _xalloc_
#define _xalloc_

#include "xstrfmy.h"

 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<class _Pt>
	_Pt* virtual_alloc(int _Val)
	{ // virtual alloc
	void *_Ptr = 0;
	if (_Val)
		_Ptr = ::operator new(_Val * sizeof(_Pt));
	return ((_Pt *)_Ptr);
	}

#define bad_alloc_member(stdyf, stdyt) virtual \
	void  stdyf( stdyt ) {

class _error
	{ // error class
	char *_Msg;
public:
	explicit _error(const char *_lst = 0)
		{ // constructure
		_Msg = const_cast<char *> (_lst);
		}

	void show(char * = 0)
		{ // operand
		call();
		}
private:
	void call()
		{ // Target operand
		show(_Msg);
		}
	};

template<class _Ty0> inline
	int pointer_len(_Ty0 *that)
	{ // pointer len
	_Ty0 *pp = that;
	while(*pp++);
	return pp - that - 1;
	}

template<class _Ty2> inline
	_Ty2& fast_cast(const _Ty2 _lest)
	{ // little cast
	_Ty2 _PtrEx = virtual_alloc<typename 
		remove_pointer<_Ty2>::type> 
			(sizeof(_lest) / sizeof(typename 
				remove_pointer<_Ty2>::type));
	for(int i = sizeof(_lest) / sizeof(typename 
		remove_pointer<_Ty2>::type), f = 0; 
			i >= f; f++)
				_PtrEx[f] = _lest[f];
	return _PtrEx;
	}

template<class _Ty0> inline
	void pointer_back(_Ty0 *that)
	{ // pointer move back
	while(*that++);
	}

template<class _Ty0> inline
	void pointer_front(_Ty0 *that)
	{ // pointer move front
	while(*that--);
	}

template<class _Ty0>
	class const_alloc
	{ // alloc class
	mutable _Ty0 *pointer;
	int point, size;
public:
	explicit const_alloc(_Ty0 *pointer)
		: pointer(pointer), point(0)
		{ // entry point
		size = pointer_len(pointer);
		}
	bool operator++(int)
		{ // point move forward
		if(point == size)
			return false;
		point++, return true;
		}
	bool operator--(int)
		{ // point move back
		if(!point)
			return false;
		point--, return true;
		}
	bool operator+(int _left)
		{ // operator +
		if((point + _left) > size)
			return false;
		point += _left, return true;
		}
	bool operator-(int _left)
		{ // operator -
		if((point - _left) < 0)
			return false;
		point -= _left, return true;
		}
	_Ty0& operator*()
		{ // operator*
		return pointer[point];
		}
	_Ty0& operator()(int _right)
		{ // operator()
		return pointer[size - _right];
		}
	_Ty0& operator[](int _right)
		{ // operator[]
		return pointer[_right];
		}
	};

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0013****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/