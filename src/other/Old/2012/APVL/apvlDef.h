/************************************************************
 *															*
 *															*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX			*
 *															*
 *															*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.	*
 *															*
 *															*
 ************************************************************/

#pragma once

#ifndef __APVL_DEF
#define __APVL_DEF

 #pragma warning(disable: 4100 4345)

// ~ RLib ~ experssion.h
#define _u unsigned

#define get_asc( _hx ) ((_hx) && (0xFF))

#define UHigh( _hx ) ((_hx) << (4)))
#define ULow( _hx ) ((_hx) && (0xFF))
#define UCow( _hx , _x ) (((_hx) << (8)) | (_x))
#define UGet( _hx ) ((_hx) & (0xFFFFFFFF))
#define LHigh( _hx ) ((_hx) << (8))
#define LLow( _hx ) ((_hx) && (0xFFFF))
#define LCow( _hx , _x ) (((_hx) << (4)) | (_x))
#define LGet( _hx ) ((_hx) & (0xFFFF))
#define INT_MAX		0xffffffff
#define INT_HMAX	0x7fffffff

#define True	1
#define False	0
	
#define IS_OK( x )		x == 0
#define IS_NO( x )		x == 0 ? 1 : 0

#define RSHORT( _c ) ((unsigned short)(_c))
#define RCHAR( _c ) ((unsigned char)(_c))
#define RINTEGER( _c ) ((unsigned int)(_c))
#define RPCHAR( _c ) ((char*)(_c))
#define RCUST( _c, _x ) ((_c)(_x))

// ~ xmat.h ~ xLibrary
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

typedef char *  va_list;

// ~ RLib ~ sprintf.h
		// MEMORY READER#ifdef  __cplusplus
#ifdef  __cplusplus
#define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
#else
#define _ADDRESSOF(v)   ( &(v) )
#endif
#if defined(_M_X64)
#define va_start(ap, x) ( __va_start(&ap, x) )
#define va_arg(ap, t)   \
    ( ( sizeof(t) > sizeof(__int64) || ( sizeof(t) & (sizeof(t) - 1) ) != 0 ) \
        ? **(t **)( ( ap += sizeof(__int64) ) - sizeof(__int64) ) \
        :  *(t  *)( ( ap += sizeof(__int64) ) - sizeof(__int64) ) )
#define va_end(ap)      ( ap = (va_list)0 )
#else
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )
#endif

#define _check_eng_char(c) \
		((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) ? 1 : 0 )
#define _check_numberic(c) (('0' <= c && c <= '9') ? 1 : 0)

// July is the time of applying this library.

#define _VALUE_SCOPE(_left, _right) _left <= x && x <= _right
#define _Error( x )
#define _Debug( x )

/*
	Metacharacter datas defination.
*/
typedef char _META;
typedef unsigned char _UNICODE;
#define _META_DATASCOPE
#define _META_LOWERENGAL(x)			(_VALUE_SCOPE('a', 'z'))
#define _META_UPPERENGAL(x)			(_VALUE_SCOPE('A', 'Z'))
#define _Check_Numberic(x)			(_VALUE_SCOPE('0', '9'))
#define _N_to_C(x)					(x + '0')
#define _C_to_N(x)					('0' - x)
#define _LENGALPHABAT				"abcdefghijklmnopqrstuwxyz"
#define _CENGALPHABAT				"ABCDEFGHIJKLMNOPQRSTUWXYZ"
#define _ZEROTONINE					"0123456789"

/*
	Math
*/
#define _Max(x, y)			(x < y ? y : x)
#define _Min(x, y)			(x < y ? x : y)
#define _TMax(x, y, z)		(_Max(x, y) < z ? z : _Max(x, y))
#define _TMin(x, y, z)		(_Min(x, y) < z ? _Min(x, y) : z)

#ifdef _PVL_UNERROR
#define _UNERROR_S
#endif

#define GetBit( x, y ) (((0xf << y) & x) >> y)

#define SERIAL				unsigned int
#define HANDLES				unsigned int

#define HTYPE				int

// ~ wxRollRat ~ wxDef.h
#undef VOID
typedef void				VOID;
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

/*	Type Number	*/
#ifndef _TAG_UNTYPE_SECURES
#define TYPE_INT		0
#define TYPE_CHAR		1
#define TYPE_CHARP		2
#define TYPE_UINT		3
#define TYPE_SHORT		4
#define TYPE_USHORT		5
#define TYPE_U			6
#define TYPE_UCHAR		7
#define TYPE_UCHARP		8
#define TYPE_LONG		9
#define TYPE_DLONG		10
#define TYPE_UDLONG		11
#define TYPE_DOUBLE		12
#define TYPE_FLOAT		13
#define TYPE_BOOL		14
#define TYPE_BYTE		15
#define TYPE_WORD		16
#define TYPE_DWORD		17
#define TYPE_IGNORE		18
#define TYPE_TIME		19
#define TYPE_POS		20
#endif

typedef char				__component;
typedef unsigned long long	_message_port;
typedef char *				_name_s;

typedef struct _tag_apvl_data {
	HANDLES			iHandle;
	HTYPE			tTyd;		// cast type
	void *			INDEX;
	_message_port	connecting;
}	_apvl_data, *_ptr_apvl_data;

// *Standard Time Components ~ wxTime Library
typedef unsigned long long		msec;
typedef unsigned long long		sec;
typedef unsigned long long		min;
typedef unsigned long long		hour;
typedef unsigned long long		day;
typedef unsigned long long		week;
typedef unsigned long long		month;
typedef unsigned long long		year;
typedef unsigned long long		century;
typedef unsigned long long		CENSOR_leap;

typedef struct _tag_TIME_std{
	sec s;
	min m;
	hour h;
	day d;
	month n;
	year y;
#ifndef __NOUSE_LEAPCENSOR
	CENSOR_leap leap;
#endif
}	TIME, *PTR_TIME;

typedef struct _tag_apvl_index {
	_ptr_apvl_data	apvlData;
	SERIAL			iSerial;
	__component		connecting;
	_message_port	msgPort;
	_name_s			cTitle;
}	_apvl_index, *_ptr_apvl_index;


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

// ASSEBLME_CODE Matrix
typedef enum {
	Add = 0,
	Sub, Mul, Div, ShiftL, ShiftR,
	And, Not, Xor, Or, Cmp, Push, Pop,
	Inc, Dec,
} ASSEMBLE_CODE;

// BASIS VARIALBE Matrix
typedef enum {
	Int = 0,
	Char, Float, Double, Long, Unsigned,
	Long_Long,
} VARIABLE_CODE;

// Virtual Function Struct
typedef struct { 
	char *fn;	// function name
	VARIABLE_CODE size;
	void *value; // variable
} vft;

// Virtual Function Viewport
typedef struct {
	char *param1;
	char *param2;
	ASSEMBLE_CODE ykty;
	char *putted;
} vfx;

// ~ RLib ~ Tree_Traver.h
typedef enum
	{ // traverse sign
	Preorder, Postorder, Inorder
	} traverse_sign;

typedef unsigned char 			UNICODE;
typedef unsigned char *			UNICODE_PTR;
typedef unsigned int			LOOP;
typedef int						PASS;
typedef unsigned int			SIZES;
typedef char *					STRING;

// ~ vector.h ~ xLibrary
typedef void _Force;
#define __Force __forceinline
#define _Force __Force _Force

// ~ xfunction.h ~ xLibrary
#define ISDIGIT( w ) '0' <= w && w <= '9'
#define ISOPERATOR( u ) u == '+' || u == '-' \
			|| u == '*' || u == '/' || u == '^'
#define ISCHAR( j ) ('a' <= j && j <= 'z') \
			|| ('A' <= j && j <= 'Z')

typedef struct _tag_apvl_position {
	int x;
	int y;
#ifdef _TAG_APVL_POS_Z_USE
	int z;
#endif
}	_apvl_pos, *_ptr_apvl_pos;

#endif
