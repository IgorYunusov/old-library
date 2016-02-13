/*************************************************************************
 *
 * FILE NAME : tctype.h - Terraforming Core Type
 *
 * RollRat Terraforming Core
 *
 *
 * CREATION : 2014.12.11
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

/*
	The RollRat Terraforming Core Native Source
 */

#ifndef _TCTYPE_		// [ !_TCTYPE_
#define _TCTYPE_

		// classification accr-to-the number of bits
typedef unsigned long			u32;
typedef unsigned long long		u64;
typedef long					l32;
typedef long long				l64;
typedef long double				ld;
typedef unsigned short			u8;
typedef short					s8;
#ifndef _OVERHEAD_TYPE	// [ !_OVERHEAD_TYPE
typedef unsigned long			dword;
typedef unsigned short			word;
typedef unsigned char			byte;
#endif // ] <- _OVERHEAD_TYPE

#endif	// ] <- _TCTYPE_