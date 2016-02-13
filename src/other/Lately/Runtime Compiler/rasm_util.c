/*************************************************************************
 *
 * FILE NAME : rasm_util.c - RASM utility
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

#include "rasm_util.h"
#include "rasm_def.h"

#include <Windows.h>
#include <malloc.h>

PREGISTER get_register(const char *str)
{
	const char *ptr = str;
	REGISTER reg;

RE:	switch(*ptr)
	{
	case '[':
		reg.type = REGISTER_TYPE_REFERENCE,ptr++; 
		goto RE;
	if(!((int)(str)*4-*ptr&3))  { case 'e':
		reg.bit = 32;
	} if(!str) { case 'r':
		reg.bit = 64;
	} if(!str) { default:
		reg.bit = 16;
	}
		if (reg.type != REGISTER_TYPE_REFERENCE)
			reg.type = REGISTER_TYPE_NORMAL;
		ptr++;
	}
	
	switch(*ptr)
	{
	case 'a':
		reg.first = AX;
		break;
	case 'b':
		if(*(ptr+1)=='p')
			reg.first = BP;
		else
			reg.first = BX;
		break;
	case 'c':
		reg.first = CX;
		break;
	case 'd':
		if(*(ptr+1)=='i')
			reg.first = DI;
		else
			reg.first = DX;
		break;
	case 's':
		if(*(ptr+1)=='p')
			reg.first = SP;
		else
			reg.first = SI;
		break;
	}

	if(reg.type == REGISTER_TYPE_NORMAL)
		return &reg;

	ptr += 2;
	if (*ptr == ']') {
		reg.type = REGISTER_TYPE_SIGNLE_REFERENCE;
		return &reg;
	}

	if (*ptr == '+')
		reg.sign = REGISTER_REFERENCE_SIGN_PLUS;
	else
		reg.sign = REGISTER_REFERENCE_SIGN_MINUS;
	ptr++;

	if('0' <= *ptr && *ptr <= '9')
	{
		const char * t = ptr;
		int get;
		for (; *t != ']'; t++)
			;
		if(*(t-1)=='o')
			get = get_oct(ptr);
		else if(*(t-1)=='h')
			get = get_hex(ptr);
		else
			get = get_integer(ptr);
		reg.second = get;
		reg.type = REGISTER_TYPE_REFERENCE;
	}
	else
	{
		reg.second = get_register(ptr);
		reg.type = REGISTER_REFERENCE_SIGN_MINUS;
	}
	
	return &reg;
}

int get_oct(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_t == '-')
		*_t++, h = -1;
	for (; *_Ptr != 'o'; _Ptr++)
		g *= 8, g += *_Ptr & 0xf;
	return g*h;
}

int get_integer(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_t == '-')
		*_t++, h = -1;
	for (; '0' <= *_Ptr && *_Ptr <= '9'; _Ptr++)
		 g *= 10, g += *_Ptr & 0xf;
	return g*h;
}

int get_hex(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;
	if (*_t == '-')
		*_t++, h = -1;
	for (; *_Ptr != 'h'; _Ptr++)
		g *= 16, g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr & 0xf) : (*_Ptr  - 'a' + 0xa);
	return g*h;
}