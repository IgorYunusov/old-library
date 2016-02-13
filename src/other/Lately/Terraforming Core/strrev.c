/*************************************************************************
 *
 * FILE NAME : strchr.h - set string reverse
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

char * _strrev_asc(
	char * str
	)
{
	char * start = str;
	char * ptr = str;
	char ch;

	while( *str++ )
		;
	str -= 2;

	while( ptr < str )
	{
		ch = *ptr;
		*ptr++ = *str;
		*str-- = ch;
	}

	return start;
}