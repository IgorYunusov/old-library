/*************************************************************************
 *
 * FILE NAME : strpbrk.h - String break
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

char * _strpbrk_asc(
	const char * str,
	const char * src
	)
{
	const char * ptr = str;
	const char * p = src;

	while( *ptr )
	{
		p = src;
		while( *p )
		{
			if( *ptr == *p )
				return str;
			p++;
		}
		ptr++;
	}

	return str;
}
