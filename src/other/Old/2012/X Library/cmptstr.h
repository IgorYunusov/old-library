/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _cmptstr_
#define _cmptstr_

#include "zfrmy.h"

#if defined(_EZ_SUCCESS)
_Z_LIB_BEGIN
	
template<class _Ty0> INLINE
	int GetStrSize(_Ty0 *_Ptr,
		int MAX_SIZE = 500)
	{ // get const string size
	int i = 0, f = 0;
	for( ; *_Ptr && MAX_SIZE != f; i++, _Ptr++, f++)
		;
	return i;
	}

template<class _Ty0> INLINE
	_Ty0 *GetMatchFirst(_Ty0 *_Ptr, 
		_Ty0 *_S)
	{ // get first match pos
	_Ty0 *_Ptrs = _Ptr, *_Sptr = _S;
	for(_Ty0 *_N; *_Ptrs; _Ptrs++)
		if(*_Ptrs == *_Sptr)
			for(_N = _Ptrs; ; _N++, _Sptr++)
				if(!*_Sptr)
					return _Ptrs;
				else if(*_N != *_Sptr){
					_Sptr = _S;
					_Ptrs++;
					break;
				}
	return _Ptr;
	}

_Z_LIB_END
#endif
#endif
/*
 *	The rollrat z_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0015****/

/*
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-06-15
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
V0.1_z_Library_btype*/