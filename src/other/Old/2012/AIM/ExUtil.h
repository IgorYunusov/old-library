/*--------------------------------------------------------------------

		AIM Library
		(Another Imaginary Management)

		Copyright (c) Kuroko_decs. 2013. All rights reserved.

--------------------------------------------------------------------*/

#pragma once

#ifndef _AIM_LIB_EXUTIL
#define _AIM_LIB_EXUTIL

template<class _Alx> FORCEINLINE
	void 
	SetPtrLast(
		ref _Alx *_Ptr
		)
	{ // move pointer last
	while(*_Ptr++)
		;
	}

template<class _Alx> FORCEINLINE
	size 
	GetPtrSize(
		const _Alx *_Ptr,
		_Alx z = 0
		)
	{ // get const array size
	const _Alx *xPt = _Ptr;
	while( *xPt++ != z ) ;
	return(xPt - _Ptr - 1);
	}

template<class _Alx> FORCEINLINE
	_Alx *
	SetPtrVal(
		ref _Alx *_Ptr,
		_Alx val,
		_Alx z = 0
		)
	{ // set pointer value
	_Alx *xPt = _Ptr;
	while(*_Ptr != z)
		*_Ptr++ = val;
	return SetPtrVal;
	}

template<class _Alx> FORCEINLINE
	BOOL
	CmpPtr(
		const _Alx *_Ptr,
		const _Alx *_Target,
		_Alx z = 0
		)
	{ // compare ptr to ptr
	while(!(*_Ptr != *_Target) && *_Ptr != z)
		xPt++, _Target++;
	if(*_Ptr == *_Target)
#ifndef _CRT_NOUSEOF_ENUM_FORBOOL
		return _ENU_BOOLEAN::True;
	return _ENU_BOOLEAN::False;
#else
		return 1;
	return 0;
#endif
	}

template<class _Alx> FORCEINLINE
	unsigned long long
	MakeFromBinary(
		const _Alx _0=0,const _Alx _1=0,const _Alx _2=0,const _Alx _3=0,
		const _Alx _4=0,const _Alx _5=0,const _Alx _6=0,const _Alx _7=0,
		const _Alx _8=0,const _Alx _9=0,const _Alx _10=0,const _Alx _11=0,
		const _Alx _12=0,const _Alx _13=0,const _Alx _14=0,const _Alx _15=0,
		const _Alx _16=0,const _Alx _17=0,const _Alx _18=0,const _Alx _19=0,
		const _Alx _20=0,const _Alx _21=0,const _Alx _22=0,const _Alx _23=0,
		const _Alx _24=0,const _Alx _25=0,const _Alx _26=0,const _Alx _27=0,
		const _Alx _28=0,const _Alx _29=0,const _Alx _30=0,const _Alx _31=0
#if _CCLN_006
		,
		const _Alx _32=0,const _Alx _33=0,const _Alx _34=0,const _Alx _35=0,
		const _Alx _36=0,const _Alx _37=0,const _Alx _38=0,const _Alx _39=0,
		const _Alx _40=0,const _Alx _41=0,const _Alx _42=0,const _Alx _43=0,
		const _Alx _44=0,const _Alx _45=0,const _Alx _46=0,const _Alx _47=0,
		const _Alx _48=0,const _Alx _49=0,const _Alx _50=0,const _Alx _51=0,
		const _Alx _52=0,const _Alx _53=0,const _Alx _54=0,const _Alx _55=0,
		const _Alx _56=0,const _Alx _57=0,const _Alx _58=0,const _Alx _59=0,
		const _Alx _60=0,const _Alx _61=0,const _Alx _62=0,const _Alx _63=0
#endif
		)
	{ // make form binary
	unsigned long long x = _0;
	x |= _1 << 1 | _2 << 2 | _3 << 3 | _4 << 4 | 
		_5 << 5 | _6 << 6 | _7 << 7 | _8 << 8 | 
		_9 << 9 | _10 << 10 | _11 << 11 | _12 << 12 | 
		_13 << 13 | _14 << 14 | _15 << 15 | _16 << 16 | 
		_17 << 17 | _18 << 18 | _19 << 19 | _20 << 20 | 
		_21 << 21 | _22 << 22 | _23 << 23 | _24 << 24 | 
		_25 << 25 | _26 << 26 | _27 << 27 | _28 << 28 | 
		_29 << 29 | _30 << 30 | _31 << 31 
#if _CCLN_006
		|
		_32 << 32 | 
		_33 << 33 | _34 << 34 | _35 << 35 | _36 << 36 | 
		_37 << 37 | _38 << 38 | _39 << 39 | _40 << 40 | 
		_41 << 41 | _42 << 42 | _43 << 43 | _44 << 44 | 
		_45 << 45 | _46 << 46 | _47 << 47 | _48 << 48 | 
		_49 << 49 | _50 << 50 | _51 << 51 | _52 << 52 | 
		_53 << 53 | _54 << 54 | _55 << 55 | _56 << 56 | 
		_57 << 57 | _58 << 58 | _59 << 59 | _60 << 60 | 
		_61 << 61 | _62 << 62 | _63 << 63 
#endif
		;
	return x;
	}

template<class _Alx> FORCEINLINE
	unsigned long long
	MakeFromHex(
		const _Alx _0x3=0, const _Alx _4x7=0, const _Alx _8x11=0, 
		const _Alx _12x15=0, const _Alx _16x19=0, const _Alx _20x23=0, 
		const _Alx _24x27=0, const _Alx _28x31=0
#if _CCLN_006
		, 
		const _Alx _32x35=0, 
		const _Alx _36x39=0, const _Alx _40x43=0, const _Alx _44x47=0, 
		const _Alx _48x51=0, const _Alx _52x55=0, const _Alx _56x59=0,
		const _Alx _60x63=0
#endif
		)
	{ // make from hex
	unsigned long long x = _0x3;
	x |= _4x7 << 4 | _8x11 << 8 | _12x15 << 12 | _16x19 << 16 |
		_20x23 << 20 | _24x27 << 24 | _28x31 << 28 
#if _CCLN_006
		| _32x35 << 32 |
		_36x39 << 36 | _40x43 << 40 | _44x47 << 44 | _48x51 << 48 | 
		_52x55 << 52 | _56x59 << 56 | _60x63 << 60 
#endif
		;
	return x;
	}

#endif