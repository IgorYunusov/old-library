/*--------------------------------------------------------------------

		AIM Library
		(Another Imaginary Management)

		Copyright (c) Kuroko_decs. 2013. All rights reserved.

--------------------------------------------------------------------*/

#pragma once

#ifndef _AIM_LIB_ALGORITHM
#define _AIM_LIB_ALGORITHM

template<class _Alg> FORCEINLINE
	void 
	swap(_Alg& _vTl, _Alg& _vTr)
	{ // swap
	_Alg buf = _vTr;
	_vTr = _vTl;
	_vTl = buf;
	}

template<class _Alg> FORCEINLINE
	_Alg * 
	realloc(typename _Alg*& _vTl, size pt_S, size pt_E)
	{ // realloc array
	_Alg buf = new _Alg[pt_E];
	for(int n = 0; n <= pt_S;n++) 
		buf[n] = _vTl[n];
	return buf;
	}



#endif