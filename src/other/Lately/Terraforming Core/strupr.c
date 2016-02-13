/*************************************************************************
 *
 * FILE NAME : strupr.h - string upper
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

char * _strupr_asc(
	char * str
	)
{
	char * ptr = str;

	while( *ptr )
		*ptr++ = _to_upper(str);

	return ptr;
}