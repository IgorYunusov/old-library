/*************************************************************************
 *
 * FILE NAME : strncat.h - bind two string
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

char * _strncat_asc(
	char * dest,
	const char * src,
	_size_t n
	)
{
	char * dest_ptr = dest;

	while( *dest_ptr )
		dest_ptr++;

	while( (*dest_ptr++ = *src++) && n-- )
		;

	if( *src )
		*dest_ptr = '\0';

	return dest;
}

_wchar_t * _strncat_w(
	_wchar_t * dest,
	const _wchar_t * src,
	_size_t n
	)
{
	_wchar_t * dest_ptr = dest;
	
	while( *dest_ptr )
		dest_ptr++;

	while( (*dest_ptr++ = *src++) && n-- )
		;
	
	if( *src )
		*dest_ptr = '\0';

	return dest;
}