/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#pragma once

#ifndef __STD_DEF_ROLLRAT
#define __STD_DEF_ROLLRAT

#ifdef USING_C_ONLY	// Please use c++.
#define __onlyc
#endif

#ifndef ALREADY_HAVE_ANOTHER_DEFINESFOR_DATA
#undef VOID					// WINDOWS DEF
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
#endif

#ifndef _SIZE_T_DEFINED	// WINDOWS DEF
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

#if defined( __cplusplus) && !defined(__onlyc)
#define AddressOfDef(v)   ( &reinterpret_cast<const char &>(v) )
template<class _Ty> inline
	_Ty *AddressOf(_Ty& _Val)
	{	// return address of _Val
	return (reinterpret_cast<_Ty *>(
		(&const_cast<char&>(
		reinterpret_cast<const volatile char&>(_Val)))));
	}
#else
#define AddressOfDef(v)   ( &(v) )
#endif

#define _Max(x, y)			(x < y ? y : x)
#define _Min(x, y)			(x < y ? x : y)
#define _TMax(x, y, z)		(_Max(x, y) < z ? z : _Max(x, y))
#define _TMin(x, y, z)		(_Min(x, y) < z ? _Min(x, y) : z)

#define MAKEBINARY(_0, _1, _2, _3) _0 << 3 | _1 << 2 | _2 << 1 | _3
#define MAKEHEX(_x0, _x1, _x2, _x3, _x4, _x5, _x6, _x7) \
	_x7 | _x6 << 4 | _x5 << 8 | _x4 << 12 |\
	_x3 << 16 | _x2 << 20 | _x1 << 24 | _x0 << 28
#define MAKEWORD(x, y)	((BYTE)x | (WORD)y << 8)
#define MAKEDWORD(x, y) ((WORD)x | (DWORD)y << 16)
#define _E_C(_x, x) (_x & (0xf << (x << 2))) // get bit w pos
#define _E(_x, x) (_E_C(_x, x) >> (x << 2))	// get bit
#define _E_BP(_x, x) ((_x) & ((0xff) << (x << 2 + 1))) // get byte w pos
#define _E_B(_x, x) ((_E_BP(_x, x)) >> (x << 2 + 1)) // get byte
#define _LBYTE(_x) ((uChar)_x) // get pos 0xff
#define _HBYTE(_x) ((WORD)_x >> 8 & 0xff) // get pos 0xff00
#define _E_WP(_x, x) (_x & (0xffff << (x << 4))) // get word w pos
#define _E_W(_x, x) (_E_WP(_x, x) >> (x << 4)) // get word
#define _LWORD(_x) ((WORD)_x) // get pos 0xffff
#define _HWORD(_x) ((u int)_x >> 16 & 0xffff) // get pos 0xffff0000
#define _E_DP(_x, x) (_x & (0xffffffff << (x << 6))) // get dword w pos
#define _E_D(_x, x) (_E_D(_x, x) >> (x << 6)) // get dword
#define _EX_C(_x, x, y) ((_x ^ (_E_C(_x, x)) ^ (_E_C(_x, y))) \
		| ((_E(_x, x) << y) | (_E(_x, y) << x))) // exc bit
#define _EX_B(_x, x, y) (_x ^ (_E_BP(_x, x)) ^ (_E_BP(_x, y)) \
		| ((_E_B(_x, x) << (y << 2 + 1)) | \
		((_E_B(_x, y) << (x << 2 + 1))))) // exc byte
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
#define MAXSIZE(x)	((x)~((x)0))
#define INLINE			inline
#define FORCE_INLINE	__forceinline


#if defined( __cplusplus) && !defined(__onlyc)

#define THROW_ERROR_INPUT(that) throw (that);

/*-------------------------------------------------

			Template Level Grid

	+-------+-----------------------------------+
	| _Ty1  | One level inherit or complexible  |
	| _Ty2  | Two level inherit or complexible  |
	|_Ty3~10| Three level inherit or complexible|
	+-------+-----------------------------------+
	| _Ty6  | Poly or unlimited level inherit   |
	+-------+-----------------------------------+
	| _Ty11 | Complex high level inherit        |
	+-------+-----------------------------------+

-------------------------------------------------*/

template<class _Ty01, class _Ty02 = int>
	struct _Base
	{ // base type
	typedef _Ty01 value_type;
	typedef const _Ty01 const_value_type;
	typedef _Ty01* pointer;
	typedef const _Ty01* const_pointer;
	typedef _Ty01& reference;
	typedef const _Ty01& const_reference;
	typedef _Ty02 difference_type;
	typedef const _Ty02 const_difference_type;
	};
template<class _Ty01> struct 
	ridof_const
	{ // remove const
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct 
	ridof_const<const _Ty01>
	{ // remove const
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct 
	ridof_const<const _Ty01[]>
	{ // remove const
	typedef typename _Ty01 type[];
	};
template<class _Ty01> struct 
	ridof_vole
	{ // remove volatile
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct 
	ridof_vole<volatile _Ty01>
	{ // remove volatile
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct 
	ridof_vole<volatile _Ty01[]>
	{ // remove volatile
	typedef typename _Ty01 type[];
	};
template<class _Ty01> struct 
	ridof_cv
	{ // remove const and volatile
	typedef typename ridof_const
	<typename ridof_vole
	<_Ty01>::type>::type type;
	};
template<class _Ty01> struct
	ridof_pointer
	{ // remove pointer
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct
	ridof_pointer<_Ty01*>
	{ // remove pointer
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct
	ridof_pointer<_Ty01[]>
	{ // remove pointer
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct
	ridof_reference
	{ // remove reference
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct
	ridof_reference<_Ty01&>
	{ // remove reference
	typedef typename _Ty01 type;
	};
template<class _Ty01> struct 
	ridof_pr
	{ // remove pointer and reference
	typedef typename ridof_reference
	<typename ridof_reference
	<_Ty01>::type>::type type;
	};
template<class _Ty01> struct
	ridof_cvpr
	{ // remove c v p r
	typedef typename ridof_cv
	<typename ridof_pr
	<_Ty01>::type>::type type;
	};
template<class _Ty> struct 
	remove_pointer
	{ // remove pointer
	typedef _Ty type;
	};
template<class _Ty> struct 
	remove_pointer<_Ty *>
	{ // remove pointer
	typedef _Ty type;
	};
template<class _Ty> struct 
	remove_pointer<_Ty *const>
	{ // remove pointer
	typedef _Ty type;
	};
template<class _Ty> struct 
	remove_pointer<_Ty *volatile>
	{ // remove pointer
	typedef _Ty type;
	};
template<class _Ty> struct 
	remove_pointer<_Ty *const volatile>
	{ // remove pointer
	typedef _Ty type;
	};
#endif

#endif