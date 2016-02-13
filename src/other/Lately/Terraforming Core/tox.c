/*************************************************************************
 *
 * FILE NAME : tox.h - toupper, tolower ...
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

int _to_upper(
	int ch
	)
{
	int ret = ch;

	if ('a' <= ret && ret <= 'z')
		ret -= 'a' - 'A';
	
	return ret;
}

int _to_lower(
	int ch
	)
{
	int ret = ch;

	/*if (!_isalpha(ret))
		return ch;

	ret |= 0x20;*/
	
	if ('A' <= ret && ret <= 'Z')
		ret += 'a' - 'A';

	return ret;
}