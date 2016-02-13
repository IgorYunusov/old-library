/*************************************************************************
 *
 * FILE NAME : strlen.h - get string length
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

_size_t _strlen_asc(
	const char * str
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	const char * ptr = str;

	while( *ptr++ )
		;

	return ptr - str + 1;
#else
	_size_t size = 0;

	while( str[i] )
		i++;

	return i;
#endif
}