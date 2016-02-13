/***********************************************************************
 ***********************************************************************
 ***********************************************************************
 *******														 *******
 *******	ROLLRAT SOFTWARE									 *******
 *******														 *******
 *******	WX DEFINE											 *******
 *******														 *******
 ***********************************************************************
 *********************************************************************** 
 ***********************************************************************/

#pragma once

#ifndef _WXDEF
#define _WXDEF

typedef int                 BOOL;
typedef float               FLOAT;
typedef signed char         INT8, *PINT8;
typedef signed short        INT16, *PINT16;
typedef signed int          INT32, *PINT32;
typedef signed int			LONG32, *PLONG32;
typedef unsigned			U;
typedef unsigned short      WORD;
typedef unsigned short      UINT16, *PUINT16;
typedef unsigned char		UCHAR, *PUCHAR;
typedef unsigned char       BYTE;
typedef unsigned char       UINT8, *PUINT8;
typedef unsigned int        UINT32, *PUINT32;
typedef unsigned int		ULONG32, *PULONG32;
typedef unsigned int		DWORD32, *PDWORD32;
typedef unsigned long       DWORD;

#define VOID				void
#define NULL				((void *)0)
#define STRUCTURE			struct

#define _B1(x) x
#define _B2(x) x << 4
#define _B3(x) x << 8
#define _B4(x) x << 12
#define _B5(x) x << 16
#define _B6(x) x << 20
#define _B7(x) x << 24
#define _B8(x) x << 28
#define _B9(x) x << 32
#define _B10(x) x << 36
#define _B11(x) x << 40
#define _B12(x) x << 44
#define _B13(x) x << 48
#define _B14(x) x << 52
#define _B15(x) x << 56
#define _B16(x) x << 60

#define _D1(x) x << 2
#define _D2(x) x << 4
#define _D3(x) x << 6
#define _D4(x) x << 8
#define _D5(x) x << 10
#define _D6(x) x << 12
#define _D7(x) x << 14
#define _D8(x) x << 16
#define _D9(x) x << 18

#define MAKEBINARY(_0, _1, _2, _3) _0 << 3 | _1 << 2 | _2 << 1 | _3
#define MAKEHEX(_x0, _x1, _x2, _x3, _x4, _x5, _x6, _x7) \
	_x7 | _x6 << 4 | _x5 << 8 | _x4 << 12 |\
	_x3 << 16 | _x2 << 20 | _x1 << 24 | _x0 << 28
#define MAKEWORD(x, y)	((BYTE)x | _B3((WORD)y))
#define MAKEDWORD(x, y) ((WORD)x | _B5((DWORD)y))
#define _E_C(_x, x) (_x & (0xf << (_D1(x)))) // get bit w pos
#define _E(_x, x) (_E_C(_x, x) >> (_D1(x)))	// get bit
#define _E_BP(_x, x) ((_x) & ((0xff) << (_D1(x) + 1))) // get byte w pos
#define _E_B(_x, x) ((_E_BP(_x, x)) >> (_D1(x) + 1)) // get byte
#define _LBYTE(_x) ((uChar)_x) // get pos 0xff
#define _HBYTE(_x) ((WORD)_x >> 8 & 0xff) // get pos 0xff00
#define _E_WP(_x, x) (_x & (0xffff << (_D2(x)))) // get word w pos
#define _E_W(_x, x) (_E_WP(_x, x) >> (_D2(x))) // get word
#define _LWORD(_x) ((WORD)_x) // get pos 0xffff
#define _HWORD(_x) ((u int)_x >> 16 & 0xffff) // get pos 0xffff0000
#define _E_DP(_x, x) (_x & (0xffffffff << (_D3(x)))) // get dword w pos
#define _E_D(_x, x) (_E_D(_x, x) >> (_D3(x))) // get dword
#define _EX_C(_x, x, y) ((_x ^ (_E_C(_x, x)) ^ (_E_C(_x, y))) \
		| ((_E(_x, x) << y) | (_E(_x, y) << x))) // exc bit
#define _EX_B(_x, x, y) (_x ^ (_E_BP(_x, x)) ^ (_E_BP(_x, y)) \
		| ((_E_B(_x, x) << (_D1(y) + 1)) | \
		((_E_B(_x, y) << (_D1(x) + 1))))) // exc byte

#define MAXSIZE(x)	((x)~((x)0))

#ifndef _SYSINTERRUPTED_SIGNATURE_SERVICE
#define _signature_sign			DWORD

typedef STRUCTURE _SIGNATURE_SERVICE_INTER{
	_signature_sign lowSignatureSign;
	_signature_sign highSignatureSign;
}	_tag_signature_service;
#endif

_tag_signature_service 
MAKESIGNATURE
(
	_signature_sign left, 
	_signature_sign right
	)
{ // make signature
	_tag_signature_service sx;
	sx.lowSignatureSign = left;
	sx.highSignatureSign = right;
	return sx;
}

#endif

// RollRat Software WX Library
// Copyright (c) rollrat. 2013. ALL RIGHTS RESERVED.