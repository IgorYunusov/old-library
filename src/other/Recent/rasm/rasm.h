/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   rasm.h - [Private]

Project:

   Robust Assembler (RASM)

------
   AUTHOR: HyunJun Jeong  2015-01-05

***************************************************************************/

#ifndef _RASM_
#define _RASM_


#if !defined(_M_IX86) && !defined(_M_IA64) && !defined(_IA64) && !defined(__amd64) && !defined(_M_X64) && !defined(_IA64) && !defined(_SENDIAN)
	#error This platform is not accepted little endian.
#endif

#define ZeroSet(dst, size)		memset(dst, 0, size)

#include "type.h"
#include <stdio.h>

typedef struct _rasm_option {
	u32 assembly_type;
	u32 cpuset;
} Option, *POption;

//
//	Option :: assembly_type
//
#define RASM_OPTION_ASSEMBLY_TYPE_NATIVE		1
#define RASM_OPTION_ASSEMBLY_TYPE_SHELLCODE		2
#define RASM_OPTION_ASSEMBLY_TYPE_EXCUATE		3

#endif