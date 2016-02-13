/*****
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   type.h - [Private]

------
   AUTHOR: HyunJun Jeong  2015-01-05
	- Update: 2015-01-23

******/

#ifndef _TYPE_
#define _TYPE_

#define TRUE		1
#define FALSE		0
#define NULL		0

typedef unsigned long int		u32;
typedef unsigned long long int	u64;
typedef long int				l32;
typedef long long int			l64;
typedef long double				ld;
typedef unsigned short int		u8;
typedef short int				s8;

typedef unsigned long int		DWORD;
typedef unsigned short int		WORD;
typedef unsigned char			BYTE;
typedef int						BOOL;
typedef BOOL					*PBOOL;
typedef BYTE					*PBYTE;
typedef DWORD					*PDWORD;
typedef WORD					*PWORD;

typedef unsigned int			size_t;

typedef char					CHAR, *PCHAR;

typedef BYTE					OPTION;
typedef BOOL					STATEMENT;

#define IN
#define OUT
#define INTERNAL

#endif