/*************************************************************************
 *
 * FILE NAME : strcmp.h - string compare
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

int _strcmp_asc(
	const char * s1,
	const char * s2
	)
{
	int ret = 0;

	while( *s2 && !(ret = *s1 - *s2) )
		s1++, s2++;

	if (ret < 0)
		return -1;
	else if (ret > 0)
		return 1;
	
	return 0;
}