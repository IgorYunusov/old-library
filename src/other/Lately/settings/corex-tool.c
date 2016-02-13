/*************************************************************************
 *
 * FILE NAME : corex-tool.h - SLC Tools
 *
 * Settings Language Compiler
 *
 *
 * CREATION : 2014.11.28
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include "corex-tool.h"
#include <malloc.h>
#include <string.h>

void slc_remove_ws(const char ** _ptr)
{
	while _isspace(**_ptr)
		(*_ptr)++;
}

int slc_get_oct(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;

	if (*_t == '-')
		*_t++, h = -1;

	for (; *_Ptr != 'o'; _Ptr++)
		g *= 8, 
		g += *_Ptr & 0xf;

	return g*h;
}

int slc_get_integer(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;

	if (*_t == '-')
		*_t++, h = -1;

	for (; _isdigit(*_Ptr); _Ptr++)
		 g *= 10, 
		 g += *_Ptr & 0xf;

	return g*h;
}

int slc_get_hex(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0, h = 1;

	if (*_t == '-')
		*_t++, h = -1;

	for (; *_Ptr != 'h'; _Ptr++)
		g *= 16, 
		g += (_isdigit(*_Ptr)) ? (*_Ptr & 0xf) : (*_Ptr  - 'a' + 0xa);

	return g*h;
}

char *slc_alloc(size_t length)
{
	void *_temp = malloc(length * sizeof(char));
	return (char *)_temp;
}

char *strncpy0(char *dest, const char *src, size_t count)
{
    strncpy_s(dest, count, src, count-1);
    dest[count - 1] = '\0';
    return dest;
}