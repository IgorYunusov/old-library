/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _xpoint_
#define _xpoint_

#include "xstrfmy.h"
#include "xalloc.h"

/*----------------------------------------------------------------

				The Complex Programming Project

	The headers in C/C++ is all about grammar as much as 
	possible.

	LEVELS:
	
	+----------+---------------------------------------------+
	| TYPENAME | Expression of difficulty					 |
	+----------+---------------------------------------------+
	|   _Ty0   | General degree of difficulty.				 |
	|   _Ty1   | Intermediate level of difficulty.           |
	|   _Ty2   | High degree of difficulty.                  |
	|   _Ty3   | Expert.								     |
	|   _Ty4   | The public can not interpret.		         |
	|   _Ty5   | Producers can be interpreted only.		     |
	|   _Ty6   | Kiss my chuddies!							 |
	|   _Ty7   | I'll give you a yeot.						 |
	+----------+---------------------------------------------+

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

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<class _Ty1A> INLINE
	void _ptr_last(_Ty1A *_Ptr)
	{ // move point last of ptr
	while(*_Ptr++)
			;
	}

template<class _Ty1A> INLINE
	int _ptr_last_i(_Ty1A *_Ptr)
	{ // move point last of ptr
	int i = 0;
	for( ; *_Ptr; _Ptr++, i++)
		;
	return i;
	}

template<class _Ty2A> INLINE
	_Ty2A _ptr_length(const _Ty2A *_Left, _Ty2A _Hide_Right = 255)
	{ // get length
	const _Ty2A *_Ptr = _Left;
	_Ty2A n;
	for(n = 0; n < _Hide_Right && *_Ptr; _Ptr++, n++)
		; // go end of ptr
	return ((int)_Ptr - (int)_Left - 1); // check return
	}

template<class _Ty5A> INLINE
	_Ty5A _ptr_next(_Ty5A *_Ptr)
	{ // get next ptr
	return *(_Ty5A *)(AddressOf(*_Ptr) + sizeof(_Ty5A));
	}

template<class _Ty5A> INLINE
	_Ty5A _ptr_prev(_Ty5A *_Ptr)
	{ // get next ptr
	return *(_Ty5A *)(AddressOf(*_Ptr) - sizeof(_Ty5A));
	}

template<class _Ty1A> INLINE
	_Ty1A **_ptr_spect(_Ty1A *_Ptr)
	{ // get pointer data
	return (_Ty1A **)*(AddressOf(*_Ptr));
	}

template<class _Ty1A> INLINE
	_Ty1A **_ptr_read(_Ty1A *_Ptr)
	{ // read pointer
	return AddressOf(_Ptr);
	}

template<class _Ty2A> INLINE
	_Ty2A *_ptr_check(const _Ty2A *_Left, _Ty2A _Right)
	{ // ptr checker
	_Ty2A *_Ptr = _Left;
	for( ; *_Ptr; )
		if(*_Ptr++ == _Right)
			return _Ptr;
	return 0;
	}

template<class _Ty2A> INLINE 
	_Ty2A *_ptr_checkl(_Ty2A *_Left, 
		_Ty2A _Right, _Ty2A _Times)
	{ // ptr loof checker
	int i = 1;
	_Ty2A *_Ptr = _Left;
	for(bool x = false; *_Ptr
			&& x ? i != _Times : 1; x ? i++ : 0)
		if(*_Ptr++ == _Right)
			x = true;
		else if(x)
			x = false, i = 1;
	return _Ptr - _Times + 1;
	}

template<class _Ty1A> INLINE
	_Ty1A *_ptr_new(_Ty1A *_Ptr)
	{ // ptr new
	_Ty1A *_Check_Ptr = _Ptr;
	return _Check_Ptr;
	}

template<class _Ty7A> INLINE
	_Ty7A **_ptr_upper(_Ty7A *_Ptr)
	{ // ptr upper limit
	_Ty7A *_First = _Ptr, *_Last = _Ptr;
	while(*_Last++)
		;
	return (_Ty7A **)*((_Ty7A *)_ptr_read(*_Last) - _First + 1);
	}

template<class _Ty7A> INLINE
	_Ty7A **_ptr_lower(_Ty7A *_Ptr)
	{ // ptr upper limit
	_Ty7A *_First = _Ptr, *_Last = _Ptr;
	while(*_Last++)
		;
	return (_Ty7A **)*((_Ty7A *)_ptr_read(*_Last));
	}

template<class _Ty1A> INLINE
	bool _ptr_perpectmatch_prefix(_Ty1A *_Left, _Ty1A *_Right)
	{ // ptr perpect match prefix
	_Ty1A *_Ptr = _Left, *_Sptr = _Right;
	for( ; *_Ptr; _Ptr++, _Sptr++)
		if(*_Ptr != *_Sptr)
			return false;
	return true;
	}

template<class _Ty1A> INLINE
	bool _ptr_perpectmatch(_Ty1A *_Left, _Ty1A *_Right)
	{ // ptr perpect match
	_Ty1A *_Ptr = _Left, *_Sptr = _Right;
	for( ; *_Ptr; _Ptr++, _Sptr++)
		if(*_Ptr != *_Sptr)
			return false;
	for(_Ptr = _Left, _Sptr = _Right
			; *_Sptr; _Sptr++, _Ptr++)
		if(*_Ptr != *_Sptr)
			return false;
	return true;
	}

template<class _Ty2A> INLINE
	_Ty2A *_ptr_find_match(_Ty2A *_Left, _Ty2A *_Right)
	{ // ptr find match
	_Ty2A *_Ptr = _Left, *_Sptr = _Right;
	for(_Ty2A *_N; *_Ptr; _Ptr++)
		if(*_Ptr == *_Sptr)
			for(_N = _Ptr; ; _N++, _Sptr++)
				if(!*_Sptr)
					return _Ptr;
				else if(*_N != *_Sptr){
					_Sptr = _Right;
					_Ptr++;
					break;
				}
	return _Left;
	}

template<class _Ty2A> INLINE
	_Ty2A *_ptr_find_match_n(_Ty2A *_Left, _Ty2A *_Right)
	{ // ptr find match
	_Ty2A *_Ptr = _Left, *_Sptr = _Right;
	for(_Ty2A *_N; *_Ptr; _Ptr++)
		if(*_Ptr == *_Sptr)
			for(_N = _Ptr; ; _N++, _Sptr++)
				if(!*_Sptr)
					return _N;
				else if(*_N != *_Sptr){
					_Sptr = _Right;
					_Ptr++;
					break;
				}
	return _Left;
	}

template<class _Ty2A> INLINE
	void _ptr_forcemerge(_Ty2A *_Left, _Ty2A *_Right)
	{ // ptr force merge
	_Ty2A *_Ptr = _Left, *_Sptr = _Right;
	int i = _ptr_last_i(_Ptr);
	while(*_Sptr)
        *(_Ty2A *)(AddressOf(*_Ptr) 
			+ sizeof(_Ty2A) * (_Sptr - _Right)) = *_Sptr++;
	for(int f = 0; f <= i; f++)
		_Ptr++;
	}

template<class _Ty2A> INLINE
	void _ptr_merge(_Ty2A *_Left, _Ty2A *_Right)
	{ // ptr merge
	_Ty2A *_V_ptr = _Left; // virtual
	_Ty2A *_Ptr = _Right;
	_ptr_forcemerge(_Left, _Right);
	if(!*_Left)
		_ptr_merge(_V_ptr, _Ptr);
	_ptr_forcemerge(_Ptr, _V_ptr);
	}

template<class _Ty2A> INLINE
	void _ptr_change(_Ty2A *_Left, _Ty2A *_Right)
	{ // ptr change
	_Ty2A _First = *_Right;
	_Ty2A *_Ptr = ++_Left;
	(*--_Ptr = _First, _Ptr++);
	while(*_Right++)
		*(_Ptr++) = *(_Right);
	}

template<class _Ty3A> 
	class shared_ptr
	{	// shared ptr
public:
	
	shared_ptr()
		: _Ptr(0), size(0)
		{ // Entry Point
		_Ptr = pointer_alloc(1);
		_Reset(_Ptr, _Ptr);
		}

	~shared_ptr()
		{ // desconductor
		delete _Ptr;
		}

	INLINE _Ty3A *&operator*()
		{ // ptr ptr
		return *_Ptr;
		}

	INLINE _Ty3A &operator->() 
		{ // ptr refer
		return _Ptr;
		}

	INLINE void extend(int i)
		{ // extend ptr
		ptr_extend(i);
		}

	INLINE void realloc(int i)
		{ // reallocate ptr
		ptr_realloc(i);
		}

	INLINE _Ty3A &operator[](int i)
		{ // operator []
		return _Ptr[i];
		}

	INLINE _Ty3A &operator()(int i)
		{ // operator ()
		return _Ptr[size - i];
		}
	
	INLINE void fill(_Ty3A _Val)
		{ // fill
		ptr_fill(_Val);
		}

	INLINE void fill(int i, int f, _Ty3A _Val)
		{ // fill
		ptr_fill(i, f, _Val);
		}

private:
	
	void _Reset(_Ty3A *_Ptr_EP, _Ty3A *_Ptr_First)
		{ // reset shared pointer
		_Ptr = _Ptr_EP; 
		_First = _Ptr_First;
		}

	_Ty3A* pointer_alloc(int _Val)
		{ // virtual alloc
		void *_Ptr = 0;
		if (_Val)
			_Ptr = ::operator new(_Val * sizeof(_Ty3A));
		return ((_Ty3A *)_Ptr);
		}

	void ptr_extend()
		{ // extend ptr
		_Ty3A *_Ptr = pointer_alloc(++size);
		for(int i = 0; i <= (size-1); i++)
			_Ptr[i] = this->_Ptr[i];
		this->_Ptr = (_Ty3A *)_Ptr;
		_Reset(this->_Ptr, this->_Ptr);
		}

	void ptr_extend(int i)
		{ // extend ptr
		_Ty3A *_Ptr = pointer_alloc((size, size += i));
		for(int i = 0; i <= (size - i); i++)
			_Ptr[i] = this->_Ptr[i];
		this->_Ptr = (_Ty3A *)_Ptr;
		_Reset(this->_Ptr, this->_Ptr);
		}

	void ptr_realloc(int i)
		{ // realloc
		_Ty3A *_Ptr = pointer_alloc(i);
		for(int f = 0; size > i 
				? f <= i : f <= size; f++)
			_Ptr[f] = this->_Ptr[f];
		this->_Ptr = (_Ty3A *)_Ptr;
		_Reset(this->_Ptr, this->_Ptr);
		size = i;
		}

	void ptr_fill(int size_mi, 
			int size_ma, _Ty3A _what)
		{ // ptr fill
		if(size_ma > size)
			ptr_realloc(size_ma);
		for(int i = size_mi; i <= size_ma; i++)
			_Ptr[i] = _what;
		}

	void ptr_fill(_Ty3A _what)
		{ // ptr fill
		for(int i = 0; i <= size; i++)
			_Ptr[i] = _what;
		}

	_Ty3A *_First;
	_Ty3A *_Ptr;

	int size;
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