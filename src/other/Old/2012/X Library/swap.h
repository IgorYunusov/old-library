/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _swap_
#define _swap_

#include "xstrfmy.h"

 #pragma warning(disable: 4100 4345)

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
	// STANDARD SWAP ALGORITHM ONE LEVELS
template<class _Ty1> inline
	void _swap(_Ty1& _Left, _Ty1& _Right)
	{ // standard one level swap
	_Ty1 temp = _Left;
	_Left = _Right;
	_Right = temp;
	}

template<class _Ty1> inline
	void _pswap(_Ty1& _Left, _Ty1& _Right)
	{ // pointer swap
	_Ty1 temp = _Left;
	*_Left = *_Right;
	*_Right = *temp;
	}

template<class _Ty1> inline
	void _cswap(_Ty1& _Left, _Ty1& _Right)
	{ // complex swap
	swap((swap(_Left, _Right), 
		swap(_Left, _Right), _Left), _Right)
	}

template<class _Ty1, 
	class _Ty2> inline
	void _rswap(_Ty1& _Left, _Ty2& _Right)
	{ // reinterpret swap
	swap(_Left, reinterpret_cast<_Ty2> (_Right));
	}

	// STANDARD SWAP ALGORITHM TWO LEVELS
template<class _Ty1> inline
	void swap(_Ty1*& _Left, _Ty1*& _Right, int size)
	{ // standard two level swap
	for(int i = 0; i <= size; i++)
		_swap(_Left[i], _Right[i]);
	}

template<class _Ty1> inline
	void pswap(_Ty1*& _Left, _Ty1*& _Right)
	{ // pointer swap
	_Ty1 temp = *_Left;
	*_Left = *_Right;
	*_Right = temp;
	}

template<class _Ty1> inline
	void aswap(_Ty1*& _Left, _Ty1*& _Right, int that)
	{ // array swap 1
	swap(_Left[that], _Right[that]);
	}

template<class _Ty1> inline
	void aswap(_Ty1*& _Left, int that, int thats)
	{ // array swap 2
	swap(_Left[that], _Left[thats]);
	}

	// STANDARD SWAP ALGORITHM THREE LEVELS
template<class _Ty1> inline
	void tswap(_Ty1**& _Left, int i, int j, int size)
	{ // ta swap
	for(int f = 0; f <= size; f++)
		swap(_Left[i][f], _Left[j][f]);
	}

template<class _Ty1> inline
	void jswap(_Ty1**& _Left, _Ty1**& _Right, 
		int size, int around)
	{ // j swap
	for(int f = 0; f <= size; f++)
		swap(_Left[f][around], _Right[f][around]);
	}

_X_LIB_END
#endif

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/