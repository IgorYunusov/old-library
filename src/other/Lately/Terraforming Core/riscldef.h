/*************************************************************************
 *
 * FILE NAME : risldef.h
 *
 * RollRat ISO Standard C Library
 *
 *
 * CREATION : 2014.12.06
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _RISCL_DEF_
#define _RISCL_DEF_

#define _NULL		0L

typedef unsigned short _wchar_t;
typedef unsigned int   _size_t;

#define _SHRT_MIN	(-32768)
#define _SHRT_MAX	  32767
#define _USHRT_MAX	  0xffff
#define _INT_MIN	(-2147483647 - 1)
#define _INT_MAX	  2147483647
#define _UINT_MAX	  0xffffffff
#define _LONG_MIN	(-2147483647L - 1)
#define _LONG_MAX	  2147483647L
#define _ULONG_MAX	  0xffffffffUL
#define _LLONG_MAX	  9223372036854775807i64
#define _LLONG_MIN	(-9223372036854775807i64 - 1)
#define _ULLONG_MAX	  0xffffffffffffffffui64

#endif