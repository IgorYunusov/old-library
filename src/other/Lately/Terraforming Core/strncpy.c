/*************************************************************************
 *
 * FILE NAME : strncpy.h - String Copy with size
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

char * _strncpy_asc(
	char * dest,
	const char * src,
	_size_t n
	)
{
	char * dest_ptr = dest;
	const char * target_ptr = src;

	while( *target_ptr && n--)
		*dest_ptr++ = *target_ptr++;

	*dest_ptr = _NULL;
	
	return dest;
}

_wchar_t * _strncpy_w(
	_wchar_t * dest,
	const _wchar_t * src,
	_size_t n
	)
{
	_wchar_t * dest_ptr = dest;
	const _wchar_t * target_ptr = src;

	while( *target_ptr && n--)
		*dest_ptr++ = *target_ptr++;
	
	*dest_ptr = _NULL;

	return dest;
}