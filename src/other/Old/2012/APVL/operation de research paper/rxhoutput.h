/*************************************************************************
 *
 *                    ROLLRAT AUTO PERSONA VERBOTER LIBROFEX
 *								DE RESEARCH PAPER
 *
 *                         (C) Copyright 2009-2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _RXHOUTPUT
#define _RXHOUTPUT

typedef int (*PUTC_PTR)(int);

int printf_r(
	PUTC_PTR putc,
	const char * format, 
	... 
	);

int sprintf_r(
	char * str,
	const char * format, 
	... 
	);

#endif