/*************************************************************************
 *
 * FILE NAME : strncmp.h - string compare
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

int _strncmp_asc(
	const char * s1,
	const char * s2,
	_size_t n
	)
{
	int ret = 0;

	while( n-- && *s1 ) {
		if( *s1 != *s2)
			if ( *s1 > *s2 )
				return 1;
			else
				return -1;
		s1++, s2++;
	}
	
	return 0;
}