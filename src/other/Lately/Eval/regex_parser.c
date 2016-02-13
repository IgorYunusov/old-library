/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   regex_parser.c - [Private]
   
Abstract:

   Regular Expression Parser

------
   AUTHOR: HyunJun Jeong  2015-01-26

***************************************************************************/

#include "type.h"
#include "rocket.h"
#include "regex.h"
#include <malloc.h>

#define _LEAK_TEST
#include "leak.h"


#define _REGEX_ERROR			-1
#define _REGEX_CHAR				 0
#define _REGEX_KEYWORD			 1
#define _REGEX_XHEX				 2
#define _REGEX_UHEX				 3

static PREGEX_PATTERN _internal_regex;
static char *patn;

static PREGEX_PATTERN _internal_regex_new_pattern();
static PREGEX_PATTERN _internal_regex_new_pattern_s(DWORD dt, int op);
static void _internal_regex_connect_with_replace(PREGEX_PATTERN _p_regex);
static void _internal_regex_init(const char *pattern);
static void _internal_regex_put(DWORD dt, int op);

static BOOL MultiLine;

static void _internal_regex_parse_multiline();
static void _int_put_keyword_x();

regex_pattern regex_scan(const char *pattern, int iOption)
{
	_internal_regex_init(pattern);

	if (iOption & REGEX_MULTILINE)
		_internal_regex_parse_multiline();

	return _internal_regex;
}

////////////////////////////////
////
////	Regex 구조체 자원할당
////
////////////////////////////////

static PREGEX_PATTERN _internal_regex_new_pattern()
{
	REGEX_PATTERN *rp;

	rp = (REGEX_PATTERN *)malloc(sizeof(REGEX_PATTERN));
	rp->_Next = NULL;
	rp->_Prev = NULL;

	return rp;
}

static PREGEX_PATTERN _internal_regex_new_pattern_s(DWORD dt, int op)
{
	REGEX_PATTERN *rp;

	rp = (REGEX_PATTERN *)malloc(sizeof(REGEX_PATTERN));
	rp->_Next = NULL;
	rp->_Prev = NULL;

	return rp;
}

static void _internal_regex_connect_with_replace(PREGEX_PATTERN _p_regex)
{
	_internal_regex->_Next = _p_regex;
	_p_regex->_Prev = _internal_regex;
	_internal_regex = _p_regex;
}

static void _internal_regex_init(const char *pattern)
{
	patn = pattern;

	_internal_regex = _internal_regex_new_pattern();
}

static void _internal_regex_put(DWORD dt, int op)
{
	_internal_regex_connect_with_replace(
					_internal_regex_new_pattern_s(dt, op)
					);
}

////////////////////////////////
////
////	Regex Parser 본체
////
////////////////////////////////

static void _internal_regex_parse_multiline()
{
	char ch;
	PREGEX_PATTERN save_ptr;
	for(; *patn;) {
		switch(ch = *patn++) {
		case '[':
			save_ptr = _internal_regex;

			break;
		case '\\':
			if (_isnalnumub(*patn))
				_internal_regex_put(*patn++, _REGEX_CHAR);
			else
				if (*patn != 'x')
					_internal_regex_put(*patn++, _REGEX_KEYWORD);
				else
					_int_put_keyword_x();
			break;
		default:
			if(_isalnumub(ch))
				_internal_regex_put(ch, _REGEX_CHAR);
			patn++;
			break;
		}
	}
}

static void _int_put_keyword_x()
{
	DWORD xhex;

	patn++;
	
	if(!_isxdigit(*patn)) {
		return; // error
	}

	xhex = _to_xdigit(*patn++);
	if(_isxdigit(*patn)) {
		xhex = xhex << 4 | _to_xdigit(*patn++);
	} else {
		_internal_regex_put(xhex, _REGEX_XHEX);
		return;
	}
	if(_isxdigit(*patn)) {
		xhex = xhex << 4 | _to_xdigit(*patn++);
	} else {
		_internal_regex_put(xhex, _REGEX_XHEX);
		return;
	}
	if(_isxdigit(*patn)) {
		xhex = xhex << 4 | _to_xdigit(*patn++);
	}
	_internal_regex_put(xhex, _REGEX_UHEX);
}