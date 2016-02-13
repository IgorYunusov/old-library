/*************************************************************************
 *
 * FILE NAME : rasm_assemble.c - RASM assemble module
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

#include "rasm.h"
#include <string.h>
#include <Windows.h>
#include <malloc.h>

PBYTE assemble(const char *code, OPTION option, size_t pbsize)
{
	PBYTE pb = (PBYTE) malloc (sizeof(BYTE) * pbsize);
	PVARIABLE pv = (PVARIABLE) malloc (sizeof(VARIABLE));
	PJCC jcc = clist.create();
	size_t pb_point = 0;
	const char *ptr = code;

	zeroset(pb, pbsize);

	// skip \n
	while(*ptr++) {
		assemble_code(ptr, option, jcc, pb, &pb_point);
	}

	return pb;
}

void directive_code(const char *code, OPTION option, 
	PVARIABLE pv, PBYTE pb, size_t *pb_point)
{

}

void assemble_code(const char *code, OPTION option, 
	PJCC jcc, PBYTE pb, size_t *pb_point)
{
	char operator[10] = { 0, };
	size_t operator_point = 0;
//----------------------------------------
	if _isreturn(*code)
		return;
	else if (*code == ';')
		return;
	while _isspace(*code++)
		;
	if (*code == ';')
		return;
//----------------------------------------
	while (!_isspace(*code++)) {
		operator[operator_point++] = *code;
	}
	operator[operator_point] = 0;
}