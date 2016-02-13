/*************************************************************************
 *
 * FILE NAME : lirt.h	- redefined logic for interactivity and type	
 *
 * Interactive Legibility Works
 *
 *
 * CREATION : 2014.11.16
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _LIRT_
#define _LIRT_

typedef unsigned short		I_WORD, *I_PWORD;
typedef unsigned long		I_DWORD, *I_PDWORD;

#define _MAKEDWORD(high, low)	(I_DWORD)((I_WORD)(high) << 4 | (I_WORD)(low))

typedef char *		_PTR;
typedef I_PDWORD DWORD_PTR;
typedef I_WORD	WORD_PTR;
typedef const char * _REFERENCE;
typedef void *unknow_t;

class _access_random {
	};



#endif