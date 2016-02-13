/*************************************************************************
 *
 * FILE NAME : isx.h - is_x methods
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

int _isspace(
	int ch
	)
{
	int ret = 0;

	switch ( ch )
	{
	case ' ':
	case '\t':
	case '\n':
	case '\f':
	case '\r':
	case '\0':
		ret = 1;
	}

	return ret;
}

int _isnumeric(
	int ch
	)
{
	int ret = 0;

	if( '0' <= ch && ch <= '9' )
		ret = 1;

	return ret;
}

int _isdigit(
	int ch
	)
{
	return _isnumeric(ch);
}

int _isalpha(
	int ch
	)
{
	int ret = 0;

	if( 'a' <= ch && ch <= 'z' )
		ret = ch;
	else if( 'A' <= ch && ch <= 'Z' )
		ret = ch;

	return ret;
}

int _isupper(
	int ch
	)
{
	int ret = 0;

	if ( 'A' <= ch && ch <= 'Z' )
		ret = ch;

	return ret;
}

int _islower(
	int ch
	)
{
	int ret = 0;

	if ( 'a' <= ch && ch <= 'z' )
		ret = ch;

	return ret;
}

int _isalnum(
	int ch
	)
{
	int ret = 0;

	if (_isalpha(ch) || _isdigit(ch))
		ret = ch;

	return ret;
}

int _isxdigit(
	int ch
	)
{
	int ret = 0;

	if (_isdigit(ch) || 
		('a' <= ch && ch <= 'f') || 
		('A' <= ch && ch <= 'Z'))
		ret = ch;

	return ret;
}