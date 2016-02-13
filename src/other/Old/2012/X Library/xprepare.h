/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _xprepare_
#define _xprepare_

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

// aleph, bet, gimel, dalet, hei, vav, zayin, het, tet, yud

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
	
template<class _Ty1A> INLINE
	void _prepare_scan(_Ty1A *_ptr)
	{ // scanning for
	
	}

template<class _Ty7A> INLINE
	void _prepare_aleph(_Ty7A *_null_ptr)
	{ // aleph algorithm
	_Ty7A *_first = _null_ptr, *last;
	while(*_null_ptr++)
		; last = _null_ptr;
	
	}

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