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

#ifndef _UTILITY_
#define _UTILITY_

#include "type.h"

size_t _util_move_next_line(CHAR const const* *target);
size_t _util_find_strchr(CHAR const const* *target, const CHAR* source);
size_t _util_find_function(CHAR const const* *target, void *(*func(void *)));
size_t _util_skip_strchr(CHAR const const* *target, const CHAR *source);
size_t _util_skip_function(CHAR const const* *target, void *(*func(void *)));

#endif