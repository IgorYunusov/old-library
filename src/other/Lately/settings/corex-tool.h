/*************************************************************************
 *
 * FILE NAME : corex-tool.h - SLC Core tool
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

#ifndef _CORE_TOOL_
#define _CORE_TOOL_

#include "utility.h"	// RTC
#include "md5.h"
#include "aghead.h"

#include <limits.h>
#include <string.h>

#define _isspace(x)		(isspace((unsigned char)x))
#define _isalpha(x)		(isalpha((unsigned char)x))
#define _isdigit(x)		(isdigit((unsigned char)x))
#define _isalnum(x)		(isalnum((unsigned char)x))
#define _isxdigit(x)	(isxdigit((unsigned char)x))
#define _isreturn(x)	(x == '\n')
#define _iszero(x)		(x == '\0')
#define _ismatch(x)

#define _isnspace(x)	(!isspace((unsigned char)x))
#define _isnalpha(x)	(!isalpha((unsigned char)x))
#define _isndigit(x)	(!isdigit((unsigned char)x))
#define _isnalnum(x)	(!isalnum((unsigned char)x))
#define _isnxdigit(x)	(!isxdigit((unsigned char)x))
#define _isnreturn(x)	(x != '\n')
#define _isnzero(x)		(x != '\0')

#define _and(x, y)		(x && y)
#define _or(x, y)		(x || y
#define __and(x, y, z)		((x && y) && z)
#define __or(x, y, z)		((x || y) || z)
#define zeroset(dst, size)		memset(dst, 0, size)

void slc_remove_ws(const char ** _ptr);
int slc_get_oct(const char *_t);
int slc_get_integer(const char *_t);
int slc_get_hex(const char *_t);
char *slc_alloc(size_t length);
char *strncpy0(char *dest, const char *src, size_t count);


#endif