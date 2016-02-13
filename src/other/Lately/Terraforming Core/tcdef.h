/*************************************************************************
 *
 * FILE NAME : tcdef.h - Terraforming Core Defines Macro
 *
 * RollRat Terraforming Core
 *
 *
 * CREATION : 2014.12.10
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

/*

	[UNICODE ONLY]

	This file has been created in Unicode, perhaps.

 */

/*

	Introduce :] the Terraforming Project

	The Terraforming Project is started for os interaction system and
	logical artificial intelligence processing unit. When using the 
	abstract machine ( ex: computer, computer or computer ... ), you 
	know what you cannot know the internal of what is abstraction. 
	However, you can be also be used without knowing the exact operation 
	principle. So, the real purpose is that provide what programming 
	terra anywhere. This program is to record the user's environment, by
	providing the same environment that was stored in the user's, this
	project will pursue the user's convenience. And also this allows you
	to quickly constructuin in any environment. It is now planning to
	construction from C language programming environment.
	
	For thos who have me read my poor Eng until now, I would like to thank.

 */

/*
	The RollRat Terraforming Core Native Source
 */

#ifndef _TCDEF_		// [ !_TCDEF_
#define _TCDEF_

// Make Number Method
#define _Make_Number(x)					x
#define _Make_Number_type(x, type)		( *( type * ) (x) )
#define _Make_Number_volitale(x, type)	( *( volatile type * ) (x) )

#ifdef _DRIVER_MODE	// [ _DRIVER_MODE
#undef _Make_Number
#define _Make_Number(x)					( *( volatile long * ) (x) )
#else	// >- !_DRIVER_MODE
#endif	// ] <- _DRIVER_MODE


//
//		TC Internal SBCS and MBCS Method.
//		Ref: tcsmcs.h
//

#ifdef _UNICODE		// [ _UNICODE
#define _USING_UNICODE			_Make_Number(1)
#define _CHAR_SET				wchar_t
#else	// >- !_UNICODE
#define _USING_UNICODE			_Make_Number(0)
#define _CHAR_SET				char
#endif	// ] <- _UNICODE

typedef _CHAR_SET	TCCHAR, *PTCCHAR;


//
//		TC Internal Accr-to-Status-Optimize Method.
//		Ref: tcvirtual.h & tcbfield.h
//

#define _Logic_Copy(x, t)			((x) << (t)) | (x)
//#define _Logic_Copy_Time1(x)		_Logic_Copy(x,  1)
//#define _Logic_Copy_Time2(x)		_Logic_Copy(x,  2)
//#define _Logic_Copy_Time4(x)		_Logic_Copy(x,  4)
#define _Logic_Cpy8(x)				_Logic_Copy(x,  8)
#define _Logic_Cpy16(x)				_Logic_Copy(x, 16)
#ifndef _X86		// [ !_X86
#define _Logic_Cpy32(x)				_Logic_Copy(x, 32)
#endif	// ] <- !_X86

// Recommendation in embedded programming
#define _Swap_Xor(x, y)				(x) ^= (y), (y) ^= (x), (x) ^= (y);
#define _Swap_Xor_tmp(x, y)			(x) ^= (y) ^= (x) ^= (y);

		// arithmetic shift
#ifndef _SAFE_INT	// [ !_SAFE_INT
#define _Rotate_Left(x, r, n)		(((x) << (r)) | ((b) >> ((n)-(r))))
#define _Rotate_Right(x, r, n)		(((x) >> (r)) | ((b) << ((n)-(r))))
#define _Rotate_Left32(x, r)		_Rotate_Left(x, r, 32)
#define _Rotate_Right32(x, r)		_Rotate_Right(x, r, 32)
#define _ROTATE_USING
#else	// >- _SAFE_INT
#ifdef _ROTATE_USING	// [ _ROTATE_USING
#error _SAFE_INT is set, so you will not be able to perform the rotate operation.
#endif	// ] <- _ROTATE_USING
#endif	// ] <- _SAFE_INT

		// bit switch
#define _Switch_Bit(p)				(1 << ((p) - 1))

		// get/set/release bit using position with origin
#define _Bit_Get(b, r)				((b) & _Switch_Bit(r))
#define _Bit_Set(b, r)				(_Bit_Get(b, r) & _Switch_Bit(r))
#define _Bit_Rel(b, r)				(_Bit_Set(b, r) ^ _Switch_Bit(r))

		// get bit using position
#define _Bit_Get_s(b, r)			(_Bit_Get(b, r) >> (r))

// User Bitfields.

#include "tcbfield.h"


//
//		TC Internal Structure Method.
//

// from to linux kernel.h
#define offset_of(st, m)	((size_t)(&((st *)0)->m))
#define container_of(ptr, type, member) \
	((type *)((char *)ptr - offset_of(type, member)))
#ifdef __cplusplus
#define _typeof(x)			decltype (x)
#endif

//
//		TC Internal Type
//		Ref: tctype.h
//

#include "tctype.h"

//
//		TC Internal Virtual
//		Ref: tcvirtual.h
//

#include "tcvirtual.h"


#endif	// ] <- _TCDEF_