/*************************************************************************
 *
 * FILE NAME : dfa_rep.h - dfa reiteration
 *
 * ROLLRAT SOFTWARE IA-32 SHELL ASSEMBLER(RASM)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.10.18
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _DFA_REP_
#define _DFA_REP_

#include <string.h>

int fn_dna_rep(const char *dst, const char *src)
{
	const char *ptr = dst;
	for( ; *ptr; ptr++)
		for(; *src; src++)
		{
			switch(*src)
				{
			case '(':
			case '|':
			case '\\':
				if (*(++src) != *ptr)
					break;
			default:
				if (*src != *ptr)
					break;
				}
		}
END:
	return (int)ptr;
}

#endif