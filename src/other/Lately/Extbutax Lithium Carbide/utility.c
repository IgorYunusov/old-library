/*************************************************************************
 *
 * FILE NAME : utility.h - Compiler Utility
 *
 * RollRat Compiler x4 Language Invention Compiler 
 *
 *
 * CREATION : 2014.12.28
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include <malloc.h>

#include "utility.h"
#include "rocket.h"

size_t _util_move_next_line(CHAR const const* *target)
{
	const CHAR *p = *target, *o = *target;

	while (!_isreturn(*p))
		p++;

	if (_isreturn(*(*target = ++p)))
		(*target)++;
	
	return p - o - 1;
}

size_t _util_find_strchr(CHAR const const* *target, const CHAR *source)
{
	const CHAR *p = *target, *o = *target;

	while(*p)
		if(_strchr_asc(source, (int)*p))
			return (*target = p) - o;
		else
			p++;

	return -1;
}

size_t _util_find_function(CHAR const const* *target, void *(*func(void *)))
{
	const CHAR *p = *target, *o = *target;

	while(*p)
		if((char *)func((void *)*p))
			return (*target = p) - o;
		else
			p++;

	return -1;
}

size_t _util_skip_strchr(CHAR const const* *target, const CHAR *source)
{
	const CHAR *p = *target, *o = *target;

	while(*p)
		if(!_strchr_asc(source, (int)*p))
			return (*target = p) - o;
		else
			p++;

	return -1;
}

size_t _util_skip_function(CHAR const const* *target, void *(*func(void *)))
{
	const CHAR *p = *target, *o = *target;

	while(*p)
		if(!(char *)func((void *)*p))
			return (*target = p) - o;
		else
			p++;

	return -1;
}