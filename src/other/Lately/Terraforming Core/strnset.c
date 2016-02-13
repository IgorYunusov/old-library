/*************************************************************************
 *
 * FILE NAME : strnset.c - string set with ch
 *
 * RollRat ISO Standard C Library
 *
 *
 * CREATION : 2014.12.06
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include "string.h"

char * _strnset_asc(
	char * str,
	int ch,
	_size_t n
	)
{
	char * ptr = str;

	while ( *str && (*str++ = (char) ch) && n--)
		;
	
	return ptr;
}