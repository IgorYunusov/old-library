/*************************************************************************
 *
 * FILE NAME : rasm.c
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2015.01.02
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _RASM_
#define _RASM_

#ifdef __GNUC__
#define USING_COMPILER	1
#define COMPILER_NAME	"GCC"

#elif defined(_MSC_VER)
#define USING_COMPILER	2
#define COMPILER_NAME	"Microsoft"

#elif defined(__INTEL_COMPILER)
#define USING_COMPILER	3
#define COMPILER_NAME	"Intel"

#elif defined(__Turbo-c___)
#define USING_COMPILER	4
#define COMPILER_NAME	"Turbo -C"

#endif

#ifdef _DEBUGGING_MODE
	#error _DEBUGGING_MODE flag is already defined!
#else
	#ifdef _DEBUG
		#define _DEBUGGING_MODE 1		// debug mode
	#else
		#define _DEBUGGING_MODE 0		// release mode
	#endif
#endif

// RASM Macro
#define MakeModRM(mod, reg, rm)		((rm & 7) | ((reg & 7) << 3) | ((mod & 3) << 6))
#define MakeSIB(ss, index, base)	((ss & 7) | ((index & 7) << 3) | ((base & 3) << 6))

#if !defined(_M_IX86) && !defined(_M_IA64) && !defined(_IA64) && !defined(__amd64) && !defined(_M_X64) && !defined(_IA64) && !defined(_SENDIAN)
	#error This platform is not accepted little endian.
#endif

#define zeroset(dst, size)		memset(dst, 0, size)

#include "type.h"
#include <stdio.h>

typedef struct _rasm_option {
	u32 assembly_type;
	u32 endian;
	u32 cpuset;
} Option, *POption;

#define RASM_OPTION_ASSEMBLY_TYPE_NATIVE		1
#define RASM_OPTION_ASSEMBLY_TYPE_SHELLCODE		2
#define RASM_OPTION_ASSEMBLY_TYPE_EXCUATE		3

//
//	ef. SMALL = LITTLE;
//
#define RASM_OPTION_SMALLENDIAN					0
#define RASM_OPTION_BIGENDIAN					1

#endif