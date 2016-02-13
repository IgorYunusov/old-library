/*************************************************************************
 *
 * FILE NAME : aghead.h - Auto Generator
 *
 * ROLLRAT SOFTWARE RUNTIME COMPILER(RTC)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.6
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _AGHEAD_
#define _AGHEAD_

#include <Windows.h>

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

#define zeroset(dst, size)		memset(dst, 0, size)

typedef struct _aghead_define {
	int size;
	char *deftext, *serial;
	struct _aghead_define *_Next;
}	DEFINE, *PDEFINE;

typedef struct _agsprintf {
	void *data;
	struct _agsprintf *_Next;
}	SPRINTF, *PSPRINTF;

PSPRINTF ag_sprintf_init();
PDEFINE ag_def_init();
void ag_sprintf_release(PSPRINTF ps);
void ag_def_release(PDEFINE pd);
BOOL ag_excuate_filedata(const char *src, const char *dst);
int agsprintf(char * str, const char * format, PSPRINTF _VAL);

#endif