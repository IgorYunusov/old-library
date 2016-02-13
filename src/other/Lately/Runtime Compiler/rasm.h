/*************************************************************************
 *
 * FILE NAME : rasm.h - RASM utility
 *
 * ROLLRAT SOFTWARE IA-32 SHELL ASSEMBLER(RASM)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.5
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _RASM_
#define _RAMS_

#include "rasm_util.h"
#include "utility.h"	// RTC
#include <limits.h>
#include <string.h>

#define RASM_LBYTE_SIZE_MAX			16
#define RASM_BYTE_SIZE_MAX			USHRT_MAX

typedef list		JCC, *PJCC;

#define _isspace(x)		(isspace((unsigned char)x))
#define _isalpha(x)		(isalpha((unsigned char)x))
#define _isdigit(x)		(isdigit((unsigned char)x))
#define _isalnum(x)		(isalnum((unsigned char)x))
#define _isxdigit(x)	(isxdigit((unsigned char)x))
#define _isreturn(x)	(x == '\n')
#define _iszero(x)		(x == '\0')
#define _ismatch(x)

#define _isnspace(x)	(!isspace((unsigned char)x))
#define _isnalpha(x)	(!isalpha((unsigned char)x))
#define _isndigit(x)	(!isdigit((unsigned char)x))
#define _isnalnum(x)	(!isalnum((unsigned char)x))
#define _isnxdigit(x)	(!isxdigit((unsigned char)x))
#define _isnreturn(x)	(x != '\n')
#define _isnzero(x)		(x != '\0')

#define _and(x, y)		(x && y)
#define _or(x, y)		(x || y
#define __and(x, y, z)		((x && y) && z)
#define __or(x, y, z)		((x || y) || z)

PBYTE assemble(const char * code, OPTION option, size_t pbsize);
void assemble_code(const char *code, OPTION option,
	PJCC jcc, PBYTE pb, size_t *pb_point);

#define zeroset(dst, size)		memset(dst, 0, size)

#endif