/*************************************************************************
 *
 * FILE NAME : rasm_util.h - RASM utility
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

#ifndef _RASM_UTIL_
#define _RAMS_UTIL_

#include "rasm_def.h"
#include <Windows.h>

#define MakeModRM(mod, reg, rm)		((rm & 7) | ((reg & 7) << 3) | ((mod & 3) << 6))

typedef struct _register_types{
	int bit;
	int first, second, sign;
	int type;
}	REGISTER, *PREGISTER;

typedef struct _variable_list{
	struct _variable_list *_next;
	char *next;
	int type;
}	VARIABLE, *PVARIABLE;

#define REGISTER_TYPE_NORMAL				1
#define REGISTER_TYPE_REFERENCE				2
#define REGISTER_TYPE_SIGNLE_REFERENCE		3
#define REGISTER_TYPE_DOUBLE_REFERENCE		4

#define REGISTER_REFERENCE_SIGN_PLUS		1
#define REGISTER_REFERENCE_SIGN_MINUS		2

PREGISTER get_register(const char *str);
int get_oct(const char *_t);
int get_integer(const char *_t);
int get_hex(const char *_t);

typedef struct _option_types {
	int endian;
}	OPTION, *POPTION;

#endif