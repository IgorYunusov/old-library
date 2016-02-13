/*************************************************************************
 *
 * FILE NAME : strrchr.h - return first match with ch, or with reverse ch
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

char * _strrchr_asc(
	const char * str,
	int ch
	)
{
	const char * str_ptr = str;

	while( *str++ )
		;

	while( --str != str_ptr && (*str != ch) )
		;

	if (*str == ch)
		return (char *)str;

	return _NULL;
}