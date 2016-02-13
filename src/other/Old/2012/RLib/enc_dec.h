/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _enc_dec_
#define _enc_dec_

#include "xstrfmy.h"

/*----------------------------------------------------------------

				The Complex Programming Project

	The headers in C/C++ is all about grammar as much as 
	possible.

	LEVELS:

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
	
template<class _Ty0>
	void Xor_(_Ty0 *thing, _Ty0 *what, _Ty0 *that)
	{ // xor function
	_Ty0 *F = what;
	while(*thing){
		if(!*F)
			F = what;
		*that++ = *thing++ ^ *F++;
		}
	*that = 0;
	}

template<class _Ty0>
	void Left_(_Ty0 *thing, int around)
	{ // left function
	while(*thing++)
		*thing = *thing >> around;
	}

template<class _Ty0>
	void Right_(_Ty0 *thing, int around)
	{ // left function
	while(*thing++)
		*thing = *thing << around;
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