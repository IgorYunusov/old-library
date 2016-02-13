/*************************************************************************
 *
 * FILE NAME : strstr.h - find string in string
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

char * _strstr_asc(
	const char * s1,
	const char * s2
	)
{
	char * ptr = (char *)s1;
	char *p1, *p2;

	while( *ptr )
	{
		p1 = ptr, p2 = s2;

		while(*p1 && *p2)
		{
			if (*p1 != *p2)
				break;
			p1++, p2++;
		}
		if( *p2 == 0 )
			return ptr;

		ptr++;
	}

	return _NULL;
}