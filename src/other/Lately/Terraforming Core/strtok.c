/*************************************************************************
 *
 * FILE NAME : strtok.h - String split
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

char * _strtok_asc(
	char * str,
	const char * src
	)
{
	static char * ptr;
	const char * p;

	if( str == _NULL )
		str = ptr;
	else
		ptr = str;

	while( *ptr )
	{
		p = src;
		while( *p )
		{
			if( *ptr == *p )
			{
				*ptr = '\0';
				ptr++;
				return str;
			}
			p++;
		}
		ptr++;
	}

	return str;
}
