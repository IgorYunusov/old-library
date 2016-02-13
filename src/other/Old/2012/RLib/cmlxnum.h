/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _cmlxnum_
#define _cmlxnum_

#include "xstring.h"

 #pragma warning(disable: 4100 4345)

_X_LIB_BEGIN

template<class _Ty2>
	struct cmlx_sign
	{ // complex sign
	_Ty2 numberic;
	_Ty2 cmlx_numberic;
	};
	
template<class _Ty0 = int>
	class cmlx
	{ // complex int
	cmlx_sign<_Ty0> numberic;
public:
	explicit cmlx()
		{numberic.numberic = 0;
		numberic.cmlx_numberic = 0;}
	explicit cmlx(_Ty0 i)
		{numberic.numberic = i;
		numberic.cmlx_numberic = 0;}
	cmlx<_Ty0>*& operator+(cmlx<_Ty0> _left)
		{cmlx_plus(_left); return *this;}
	cmlx<_Ty0>*& operator-(cmlx<_Ty0> _left)
		{cmlx_minus(_left); return *this;}
	cmlx<_Ty0>*& operator*(cmlx<_Ty0> _left)
		{cmlx_multiple(_left); return *this;}
	cmlx<_Ty0>*& operator/(cmlx<_Ty0> _left)
		{cmlx_divide(_left); return *this;}
	_Ty0& operator&()
		{return numberic.cmlx_numberic;}
	_Ty0& operator*()
		{return numberic.numberic;}
	string<char>& operator()()
		{ // operator()
		string<char> cht;
		cht += numberic.numberic;
		cht += " ";
		cht += numberic.cmlx_numberic;
		cht += "i";
		return cht;}
private:
	void cmlx_plus(cmlx_sign<_Ty0> numberic)
		{ // cmlx +
		this->numberic.numberic += numberic.numberic;
		this->numberic.cmlx_numberic 
			+= numberic.cmlx_numberic;
		}
	void cmlx_minus(cmlx_sign<_Ty0> numberic)
		{ // cmlx -
		this->numberic.numberic -= numberic.numberic;
		this->numberic.cmlx_numberic 
			-= numberic.cmlx_numberic;
		}
	void cmlx_multiple(cmlx_sign<_Ty0> numberic)
		{ // cmlx *
		this->numberic.numberic *= numberic.numberic;
		this->numberic.cmlx_numberic 
			*= numberic.cmlx_numberic;
		}
	void cmlx_divide(cmlx_sign<_Ty0> numberic)
		{ // cmlx *
		this->numberic.numberic /= numberic.numberic;
		this->numberic.cmlx_numberic 
			/= numberic.cmlx_numberic;
		}
	};

_X_LIB_END
#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/