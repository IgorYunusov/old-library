/*************************************************************************
 *
 * FILE NAME : atox.h - string to x
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

int _atoi(
	const char * src
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	int int_str = 0;
	int mark = 1;

	while (_isspace(*src))
		src++;

	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;

	while (*src && _isnumeric(*src))
		int_str = (int_str * 10) + (*src++ & 0xf);

	return mark * int_str;
#else
	 return (int) _strtol_t (src, (char **) NULL, 10);
#endif
}

double _atof(
	const char * src
	)
{
	double _integer = 0.0;
	double _minority = 0.0;
	double _set = 1;
	double mark = 1;

	while (_isspace(*src))
		src++;
	
	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;
	
	while (*src && _isnumeric(*src))
		_integer = (_integer * 10) + (*src++ & 0xf);

	if (*src == '.')
		src++;

	while (*src && _isnumeric(*src))
		_minority = (_minority * 10) + (*src++ & 0xf),
		_set *= 0.1;
	
	return mark * (_integer + _minority * _set);
}

long _atol(
	const char * src
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	long int_str = 0;
	long mark = 1;

	while (_isspace(*src))
		src++;

	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;

	while (*src && _isnumeric(*src))
		int_str = (int_str * 10) + (*src++ & 0xf);

	return mark * int_str;
#else
	 return (long) _strtol_t (src, (char **) NULL, 10);
#endif
}


unsigned long _atoul(
	const char * src
	)
{
#ifndef USING_DEVICE_FLAG_STRINGH
	unsigned long int_str = 0;
	unsigned long mark = 1;

	while (_isspace(*src))
		src++;

	if (*src == '-')
		mark = -1, src++;
	else if(*src == '+')
		src++;

	while (*src && _isnumeric(*src))
		int_str = (int_str * 10) + (*src++ & 0xf);

	return mark * int_str;
#else
	 return _strtoul_t (src, (char **) NULL, 10);
#endif
}