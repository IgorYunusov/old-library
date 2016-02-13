/*************************************************************************
 *
 * FILE NAME : strcspn.h - find ch in ch array
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

_size_t _strspn_asc(
	const char * str1,
	const char * str2
	)
{
	const char * s1 = str1, *s2;

	while( *s1 ) {
		for( s2 = str2; *s2; s2++ )
			if( *s1 == *s2 )
				goto X;
		break;
	X:
		s1++;
	}

	return s1 - str1;
}