/*************************************************************************
 *
 * FILE NAME : utility.h
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2015.01.02
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
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