/*************************************************************************
 *
 * FILE NAME : strlwr.h - string lower
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

char * _strlwr_asc(
	char * str
	)
{
	char * ptr = str;

	while( *ptr )
		*ptr++ = _to_lower(str);

	return ptr;
}