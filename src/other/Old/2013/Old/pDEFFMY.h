/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*
 ┃												 ┃
 │			RollRat Software Library			 │
 │												 │
 │	Copyright (c) rollrat. All rights reserved.  │
 *━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/


/***************************************************

					Warning!

	Follow All of Library User.

	- Don't use of DXDS Library, Boost Library.


	All rights for this library is protected from 
	copyright. 

	And

	Unauthorized reproduction without the author's 
	consent, modification, distribution is prohibited.

	Copyright (c) rollrat. All rights reserved.

****************************************************/
#pragma once

#ifndef _PDEFFMY_
#define _PDEFFMY_
#
#define TRUE	0
#define FALSE	1
#
#define IS_OK( x )		x == TRUE
#define IS_FAIL( x )	x == FALSE
#
#ifndef _LOG_FINALCHECKEXTEND
#	define _CCL_OPERTERING	0
#else
#	define _CCL_OPERTERING	1
#endif
#ifndef _FORCE_ZIPOLOTECCL
#	define _CCL_ZOPOLOTE	_CCL_OPERTERING << 8
#else
#	define _CCL_ZOPOLOTE	(-1)
#endif
#
#define LOOPC( p, x ) LOOP p = 0; p <= x; p++
#define LOOPR( p, x ) LOOP p = x; p >= 0; p--

typedef unsigned char 			UNICODE;
typedef unsigned char *			UNICODE_PTR;
typedef unsigned int			LOOP;
typedef int						PASS;
typedef unsigned int			HANDLES;
typedef int						BOOL;
typedef unsigned int			SIZE;
typedef char *					STRING;

#define FIXED const 

typedef HANDLES (PROC_ENGINE)(HANDLES, UNICODE *, UNICODE *);


#endif
/*
 *	The rollrat z_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0001****/

/*
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-06-15
 *	C/C++ syntax of the total complex made ​​possible by mobilizing header.
 *	If you understand all this, you C/C++ will have 
 *	completed all of the grammar.
L1_H*/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_p_Library_btype*/