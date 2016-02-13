/*************************************************************************
 *
 * FILE NAME : bitcon.h
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2015.01.02
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _BIT_CON_
#define _BIT_CON_

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

#endif