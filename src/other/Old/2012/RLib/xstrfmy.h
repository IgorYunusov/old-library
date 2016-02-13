/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _x_lib_strfmy
#define _x_lib_strfmy

#include "xmate.h"

#if defined(_EX_SUCCESS)
_X_LIB_BEGIN

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

	// TEMPLATE STRUCT TYPE FAMILY
template<class _Ty01>
	struct __type
	{ // str type
	typedef _Ty01 value_type;
	typedef _Ty01 &reference;
	typedef _Ty01 *pointer;
	};

template<class _Ty01>
	struct __type<const _Ty01>
	{ // str type
	typedef _Ty01 value_type;
	typedef _Ty01 &reference;
	typedef _Ty01 *pointer;
	};

template<class _Ty01>
	struct _type
	{ // str type
	typedef __type<_type> type;
	};

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

	// TEMPLATE STRUCT REMOVE FAMILY
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

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/