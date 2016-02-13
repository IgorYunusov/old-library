/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_memory0
#define _x_lib_memory0

#include "xstrfmy.h"

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

template<class _Ty1> inline
	_Ty1* _Allocate(size_t _Val, _Ty1 *)
	{ // allocate memory
	void *_Ptr = 0;
	if (_Val)
		_Ptr = ::operator new(_Val * sizeof(_Ty1));
	return ((_Ty1 *)_Ptr);
	}

template<class _Ty1> inline
	_Ty1* _Allocate(size_t _Val)
	{ // allocate memory
	void *_Ptr = 0;
	if (_Val)
		_Ptr = ::operator new(_Val * sizeof(_Ty1));
	return ((_Ty1 *)_Ptr);
	}

template<class _Ty1> inline
	void _Construct(_Ty1 *_xPtr)
	{ // creat new memory
	void *_Ptr = _xPtr;
	_xPtr = new _Ty1(0);
	}

template<class _Ty1> inline
	void _Delete(_Ty1 _First)
	{ // delete element
	delete _First;
	}

template<class _Ty1> inline
	void _Delete(_Ty1 *_First)
	{ // delete element
	delete[] _First;
	}

template<class _Ty1, 
	class _TySize> inline
	void _Delete(_Ty1 *_First, _TySize _Second)
	{ // delete element
	for(int i = 0; i <= _Second; i++)
		_Delete(_First[i]);
	_Delete(_First);
	}

template<class _Ty1, 
	class _TySize> inline
	void _Realloc_n(_Ty1 *_First, 
		_TySize _Second, _TySize _Third)
	{ // reallocate memory
	_Ty1 *buf = _Allocate<_Ty1> (_Third);
	for(_TySize n = 0; n <= _Second;n++)
		buf[n] = _First[n];
	return buf;
	}

template<class _Ty1> inline
	void _Swap(_Ty1 &_Left, _Ty1 &_Right)
	{ // swap element to element
	_Ty1 t = _Left; 
	_Left = _Right; 
	_Right = _Left;
	}

template<class _Ty1,
	class _TySize> inline
	void _Swap(_Ty1* _Left, _TySize f)
	{ // algorithm element, change from point to point
	_Ty1 _buf;
	_buf = *_Left;
	*_Left = _Left[f];
	_Left[f] = _buf;
	}

template<class _Ty1,
	class _TySize> inline
	void _Swap(_Ty1 *_Left, 
		_TySize i, _TySize f)
	{ // algorithm element, change from _left[i] to _left[f]
	_Ty1 _buf;
	_buf = _Left[i];
	_Left[i] = _Left[f];
	_Left[f] = _buf;
	}

template<class _Ty1, 
	class _TySize> inline
	void _Fill_n(_Ty1 *_Left, 
		_TySize _LSize, _Ty1 _Elem = 0)
	{ // fill element
	for(_TySize n = 0; n <= _LSize;n++)
		_Left[n] = _Elem;
	}

template<class _Ty1,
	class _Ty2,
	class _TySize> inline
	void _Copy_n(const _Ty1 _Left, 
		_Ty2 &_Right, _TySize _LSize)
	{ // copy function
	for(_TySize i = 0; i <= _LSize; i++)
		_Right[i] = _Left[i];
	};

template<class _Ty1,
	class _TySize> inline
	_Ty1* _Copy_n(const _Ty1 *_Left, _TySize _LSize)
	{ // copy function
	_Ty1 *_Ptr = _Allocate<_Ty1> (_LSize);
	_Copy_n(_Left, _Ptr, _LSize);
	return _Ptr;
	};

template<class _Ty1,
	class _Ty2 = _Ty1>
	class ptr
	{ // pointer
	typedef typename ridof_cvpr<_Ty2>::type _MyT;
	typename _MyT* ptrs;
	public:
	explicit ptr(_MyT *_First) : ptrs(_First) 
		{}
	ptr() : ptrs(0) 
		{ptrs = _Allocate<_MyT> (0);}
	_MyT*& operator=(_MyT* _First)
		{return ptrs = _First;}
	void operator++(int)
		{ptrs++;}
	void operator--(int)
		{ptrs--;}
	void operator+=(int _First)
		{ptrs += _First;}
	void operator-=(int _First)
		{ptrs -= _First;}
	_MyT& operator*()
		{return *ptrs;}
	_MyT&& operator&()
		{return &ptrs;}
	virtual ~ptr() 
		{delete[] ptrs;}
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