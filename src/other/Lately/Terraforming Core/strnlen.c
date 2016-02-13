/*************************************************************************
 *
 * FILE NAME : strnlen.h - get string length
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

_size_t _strnlen_asc(
	const char * str,
	_size_t n
	)
{
	const char * ptr = str;

	while( *ptr++ && n-- )
		;

	return ptr - str + 1;
}