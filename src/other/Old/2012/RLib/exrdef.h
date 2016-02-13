/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _exrdef_
#define _exrdef_

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
#define _LENGALPHABAT			"abcdefghijklmnopqrstuwxyz"
#define _CENGALPHABAT			"ABCDEFGHIJKLMNOPQRSTUWXYZ"
#define _ZEROTONINE				"0123456789"

/*
	Math
*/
#define _Max(x, y)			(x < y ? y : x)
#define _Min(x, y)			(x < y ? x : y)
#define _TMax(x, y, z)		(_Max(x, y) < z ? z : _Max(x, y))
#define _TMax(x, y, z)		(_Min(x, y) < z ? _Min(x, y) : z)

/*
	Complex Programming Table
*/
typedef int CLX_PGM;

/*
	Pointer
*/



#endif
/*
 *	The rollrat z_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0015****/

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
V0.1_z_Library_btype*/