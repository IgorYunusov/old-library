/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _zfrmy_
#define _zfrmy_
# // while waiting for creating my operating system...
#if !defined(_UNDEF_NAMESPACE) && defined(__cplusplus)
#
#	ifndef _Z_LIB
#			define	_Z_LIB_BEGIN	namespace zlib	{
#			define	_Z_LIB_END		}
#			define	_Z_LIB			::zlib::
#		else
#			undef	_Z_LIB_BEGIN
#			undef	_Z_LIB_END
#			undef	_Z_LIB
#			define	_Z_LIB_BEGIN	namespace zlib	{
#			define	_Z_LIB_END		}
#			define	_Z_LIB			::zlib::
#	endif
#
#else
#
#	if defined(_Z_LIB)
#		undef	_Z_LIB
#		define	_Z_LIB
#		if defined(_Z_LIB_BEGIN) || defined(_Z_LIB_END)
#			undef	_Z_LIB_BEGIN
#			define	_Z_LIB_BEGIN
#			undef	_Z_LIB_END
#			define	_Z_LIB_END
#		endif
#	else
#		define	_Z_LIB
#		define	_Z_LIB_BEGIN
#		define	_Z_LIB_END
#	endif
#
#endif
#if defined(_MMX_CHARGE) || defined(_WIN64) // Q. If using 64bit alchitecture
#
#	if !defined(_MMX_ALCHITECTURE)
#		define _MMX_ALCHITECTURE
#	else
#		undef _MMX_ALCHITECTURE
#		define _MMX_ALCHITECTURE
#	endif
#
#endif
#if defined(_Z_FMC_HALP) // Q. Fm Channel Settings
#
#	if defined(_Z_FMC_RAMP) // A. RAMP is Rollrat Artificiality Msg Project
#		define _Z_FMC_READY
#	else
#		if defined(_Z_FMC_COMP) // B. COMP is Computer OS Msg Project
#			define _Z_FMC_CREADY
#		else
#			define _Z_FMC_ERROR
#		endif
#	endif
#
#endif
#if defined(_Z_CORE) // Q. Using core of z library
#
#	if defined(_Z_FMC_HALP)
#		define _Z_CORE_READY
#	endif
#
#endif
#if !defined(_UNDEF_NAMESPACE) && defined(__cplusplus) && defined(_MMX_ALCHITECTURE)
#
#	ifndef _Z_LIB64
#			define	_Z_LIB64_BEGIN	namespace zlib64	{
#			define	_Z_LIB64_END	}
#			define	_Z_LIB64		::zlib::
#		else
#			undef	_Z_LIB_BEGIN64
#			undef	_Z_LIB_END64
#			undef	_Z_LIB64
#			define	_Z_LIB_BEGIN64	namespace zlib64	{
#			define	_Z_LIB_END64	}
#			define	_Z_LIB64		::zlib64::
#	endif
#
#else
#
#	if defined(_Z_LIB64)
#		undef	_Z_LIB64
#		define	_Z_LIB64
#		if defined(_Z_LIB64_BEGIN) || defined(_Z_LIB64_END)
#			undef	_Z_LIB_BEGIN64
#			define	_Z_LIB_BEGIN64
#			undef	_Z_LIB_END64
#			define	_Z_LIB_END64
#		endif
#	else
#		define	_Z_LIB64
#		define	_Z_LIB_BEGIN64
#		define	_Z_LIB_END64
#	endif
#
#endif
#if defined(__cplusplus)
#define _EZ_SUCCESS
#endif
#if defined(_EZ_SUCCESS)
_Z_LIB_BEGIN
#define INLINE			inline
#define FORCE_INLINE	__forceinline
#define USING			using
#define CDECL			_cdecl
#define FIXED( func )	const func	// fixed struct
typedef unsigned long long		HANDLE;
typedef int						BOOL;
typedef unsigned long long		PARAMETER;
typedef void					VOID;
typedef unsigned int			UINT;
typedef unsigned char			UCHAR;

/*----------------------------------------------------------------

				The Complex Programmings Project

	The headers in C/C++ is all about grammar as much as 
	possible.

	LEVELS:

	+----------+---------------------------------------------+
	| TYPENAME | Expression of difficulty					 |
	+----------+---------------------------------------------+
	|   _Zf0   | General degree of difficulty.				 |
	|   _Zf1   | Intermediate level of difficulty.           |
	|   _Zf2   | High degree of difficulty.                  |
	|   _Zf3   | Expert.								     |
	+----------+---------------------------------------------+

	CM LEVEL : (Complexity Metric)
		NOTE : http://en.wikipedia.org/wiki/Cyclomatic_complexity

	+----------+---------------------------------------------+
	| TYPENAME | Standard Expression						 |
	+----------+---------------------------------------------+
	| _Zf(n)A  | 1											 |
	| _Zf(n)B  | 1.5 or x									 |
	| _Zf(n)C  | log x										 |
	| _Zf(n)D  | log 2x										 |
	| _Zf(n)E  | 2 log x									 |
	| _Zf(n)F  | 2 ^ x										 |
	| _Zf(n)G  | 3 ^ x										 |
	+----------+---------------------------------------------+

----------------------------------------------------------------*/

template<class _Zf1> INLINE
	_Zf1 *GetAddressOfVal(_Zf1 &_Val)
	{	// return address of _Val
	return (reinterpret_cast<_Zf1 *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val)))));}

template<class _Zf1 = PARAMETER>
	struct Message
	{	// z lib message transfer class
	_Zf1 left, right;};

template<class _Zf1> INLINE
	_Zf1 GetMessageLeftLower(Message<_Zf1> _Msg)
	{ // get message left lower
	return ((_Msg.left) & 0xffff);}

template<class _Zf1> INLINE
	_Zf1 GetMessageLeftHigher(Message<_Zf1> _Msg)
	{ // get message left higher
	return (((_Msg.left) >> 16) & 0xffff);}

template<class _Zf1> INLINE
	_Zf1 GetMessageRightLower(Message<_Zf1> _Msg)
	{ // get message right lower
	return ((_Msg.right) & 0xffff);}

template<class _Zf1> INLINE
	_Zf1 GetMessageRightHigher(Message<_Zf1> _Msg)
	{ // get message right higher
	return (((_Msg.right) >> 16) & 0xffff);}

template<class _Zf1> INLINE
	void SetMessageLeft(Message<_Zf1> _Msg, 
		_Zf1 _Lower, _Zf1 _Higher)
	{ // set message left
	_Msg.left = (_Lower | (_Higher << 16));}

template<class _Zf1> INLINE
	void SetMessageRight(Message<_Zf1> _Msg, 
		_Zf1 _Lower, _Zf1 _Higher)
	{ // set message right
	_Msg.right = (_Lower | (_Higher << 16));}

template<class _Zf1>
	class _Temp
	{ // temp class
public: _Temp() : { P = new _Zf1[1]; }
	~_Temp() { delete[] P; } INLINE _Zf1 
	&operator*() {return *P;} _Zf1 *P;};

template<class _Zf1> INLINE
	_Zf1 *CreateMemoryAddress(_Zf1 *_Ptr)
	{ // create memory address
	_Zf1 *_Ptrs = _Ptr;
	return _Ptrs;}

template<class _Zf1> INLINE
	_Zf1 CalculateRectSize(_Zf1 _length, _Zf1 _breadth)
	{ // calculate rect size
	return _length * _breadth;}

template<class _Zf1> INLINE
	_Zf1 CalculateRectSize(_Zf1 x, _Zf1 y, _Zf1 _lenth, _Zf1 _breadth)
	{ // calculate rect size
	return (_lenth - x) * (_breadth - y);}

template<class _Zf1> INLINE
	_Zf1 CalculateFact(_Zf1 _val)
	{ // calculate factorial
	_Zf1 i; if(_val >= 2)
	i = _val * CalculateFact(_val - 1); else i = 1; 
	return i;}

template<class _Zf1> INLINE
	_Zf1 CalculateTriangleFunctionX(_Zf1 scala, _Zf1 x)
	{ // calculate trianlge function x
	return (scala ^ x) / CalculateFact(x);}

template<class _Zf1> INLINE
	_Zf1 CalculateSin(_Zf1 x)
	{ // calculate sine value
	x *= 0.01745329251994329576923690768489;
	return x - CalculateTriangleFunctionX(x, 3) + CalculateTriangleFunctionX(x, 5) -
		CalculateTriangleFunctionX(x, 7) + CalculateTriangleFunctionX(x, 9) - 
		CalculateTriangleFunctionX(x, 11);}

template<class _Zf1> INLINE
	_Zf1 CalculateCos(_Zf1 x)
	{ // calculate cosine value
	x *= 0.01745329251994329576923690768489;
	return 1 - CalculateTriangleFunctionX(x, 2) + CalculateTriangleFunctionX(x, 4) -
		CalculateTriangleFunctionX(x, 6) + CalculateTriangleFunctionX(x, 8) -
		CalculateTriangleFunctionX(x, 10);}

template<class _Zf1> INLINE
	_Zf1 CalculateExp(_Zf1 x)
	{ // caculate e ^ x
	return 1 + x + (1/CalculateFact(2))*x^2 + (1/CalculateFact(3)*x^3 + 
		(1/CalculateFact(4))*x^4 + (1/CalculateFact(5))*x^5;}

template<class _Zf1> INLINE
	_Zf1 CalculateCirclePos(_Zf1 x, _Zf1 y, _Zf1 radius, int angle)
	{ // calculate circle pos
	return CalculateSin(angle) * radius;}

template<class _Zf1> INLINE
	_Zf1 CalculateCirclePosX(int x, _Zf1 pos, int angle)
	{ // calculate circle pos x
	if(angle <= 90 || (270 < angle <= 360)) return pos + x;
	else return x - pos;}

template<class _Zf1> INLINE
	_Zf1 CalculateCirclePosY(int y, _Zf1 pos, int angle)
	{ // calculate circle pos y
	if(angle <= 180) return y - pos;
	else return y + pos;}

template<class _Zf1> INLINE
	_Zf1 CalculateNormalDistribution(int x)
	{ // calucte normal distribution
	
	}

template<class _Func, class _Y = _Func*&> INLINE
	_Y CreateFunctionVirtual(_Func what)
	{ // create function memory
	typedef _Y (_Func::*Vt)();
	Vt x = &what;
	return x;}

_Z_LIB_END
#endif
#endif
/*
 *	The rollrat z_library
 *  Updated : 2013-06
 *	RollRat New Project 'Z' - Bet
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/