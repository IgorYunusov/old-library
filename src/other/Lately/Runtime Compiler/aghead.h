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