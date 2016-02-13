/*************************************************************************
 *
 * FILE NAME : strchr.h - return first match with ch, or with reverse ch
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

char * _strchr_asc(
	const char * str,
	int ch
	)
{
	while( *str && (*str != ch) )
		str++;

	if (*str == ch)
		return (char *)str;

	return _NULL;
}