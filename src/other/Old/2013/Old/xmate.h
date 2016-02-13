/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_mate
#define _x_lib_mate
#
#if !defined(_UNDEF_NAMESPACE) && defined(__cplusplus)
#
#	ifndef _X_LIB
#			define	_X_LIB_BEGIN	namespace xlib	{
#			define	_X_LIB_END		}
#			define	_X_LIB			::xlib::
#		else
#			undef	_X_LIB_BEGIN
#			undef	_X_LIB_END
#			undef	_X_LIB
#			define	_X_LIB_BEGIN	namespace xlib	{
#			define	_X_LIB_END		}
#			define	_X_LIB			::xlib::
#	endif
#
#else
#
#	if defined(_X_LIB)
#		undef	_X_LIB
#		define	_X_LIB
#		if defined(_X_LIB_BEGIN) || defined(_X_LIB_END)
#			undef	_X_LIB_BEGIN
#			define	_X_LIB_BEGIN
#			undef	_X_LIB_END
#			define	_X_LIB_END
#		endif
#	else
#		define	_X_LIB
#		define	_X_LIB_BEGIN
#		define	_X_LIB_END
#	endif
#
#endif
#if defined(__cplusplus)
#define _EX_SUCCESS
#endif
#if defined(_EX_SUCCESS)
_X_LIB_BEGIN
#ifndef _SIZE_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64    size_t;
#else
typedef _w64 unsigned int   size_t;
#endif
#define _SIZE_T_DEFINED
#endif
#define _u	unsigned
typedef _u	int			uint;
typedef _u	char		uchar;
typedef _u	short		ushort;
typedef long long		llong;
typedef _u	long long	ullong;
#define UHigh( _hx )			((_hx) << (4)))
#define ULow( _hx )				((_hx) && (0xFF))
#define UCow( _hx , _x )		(((_hx) << (8)) | (_x))
#define UGet( _hx )				((_hx) & (0xFFFFFFFF))
#define LHigh( _hx )			((_hx) << (8))
#define LLow( _hx )				((_hx) && (0xFFFF))
#define LCow( _hx , _x )		(((_hx) << (4)) | (_x))
#define LGet( _hx )				((_hx) & (0xFFFF))
#define INT_MAX		0xffffffff
#define INT_HMAX	0x7fffffff
#define THROW_ERROR_INPUT(that) throw (that);
#define _NOTHROW				throw ()
#define BEGIN_TRY				try {
#define BEGIN_CATCH(what)		catch(what){
#define END_CATCH				}
#define END_TRY					}
#define INLINE			inline
#define FORCE_INLINE	__forceinline

template<class _Ty> inline
	_Ty *AddressOf(_Ty& _Val)
	{	// return address of _Val
	return (reinterpret_cast<_Ty *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val)))));
	}

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