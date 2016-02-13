/*************************************************************************
 *
 * FILE NAME : rvalue.c - Enable Right Value
 *
 * RollRat Compiler x4 Language Invention Compiler 
 *
 *
 * CREATION : 2014.12.31
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include "rvalue.h"
#include "elc.h"
#include "rocket.h"
#include "elc_option.h"
#include "costume.h"
#include <malloc.h>

const char *_rvalue_it; // internal text
ptree _parse_rvalue_tree;
BOOL __rvalue_internal_stmt();
BOOL __rvalue_internal_var();

#define _NULL		(const char *)(0)
#define SUCCESS		0
#define digit		type

#define _RVU_ERROR_FULL_TREE			1

PRVALUE _parse_rvalue(const CHAR *ptr)
{
	PRVALUE ret = (PRVALUE) malloc( sizeof(RVALUE) );

	_parse_rvalue_tree = ctree.create();
	_rvalue_it = (char *)(ptr);

	__rvalue_internal_stmt(); // main loop

	ret->tree = _parse_rvalue_tree;
	ret->ptr = _rvalue_it;

	return ret;
}

/////////////////////////////////////////////////////////////////////////////////////
	void __rvalue_internal_skipws()
	{
		while (_isspace((int)(*_rvalue_it)))
			_rvalue_it++;
	}

	BOOL __rvalue_internal_stmt()
	{
		BOOL ret = SUCCESS;
	
		return ret;
	}
	
	BOOL __rvalue_internal_var()
	{
		BOOL ret = SUCCESS;
		__rvalue_internal_skipws();
		if(*_rvalue_it == '(') {
			_rvalue_it++;
			__rvalue_internal_stmt();
			if (*_rvalue_it == ')')
				_rvalue_it++;
			else
				ret = SUCCESS;
		} else if (_isnumeric((int)(*_rvalue_it))) {
			u32 set = 0;
			if(*_rvalue_it == '0') {
				if(*++_rvalue_it == 'x') { // only lower
					_rvalue_it++;
					while(TRUE) {
						if(_isnumeric(*_rvalue_it)) {
							set = set * 16 + *_rvalue_it++ - '0';
						} else if (_isalpha(*_rvalue_it)) {
							set = set * 16 + _to_lower(*_rvalue_it++) - 'a';
						} else {
							break;
						}
					}
				} else {
					while(_isnumeric(*_rvalue_it)) {
						set = set * 8 + *_rvalue_it++ - '0';
					}
				}
			} else {
				while(_isnumeric(*_rvalue_it)) {
					set = set * 10 + *_rvalue_it++ - '0';
				}
			}
			if (!ctree.is_left(_parse_rvalue_tree))
				tree_pushleft(_parse_rvalue_tree, set, _NULL);
			else if (!ctree.is_right(_parse_rvalue_tree))
				tree_pushright(_parse_rvalue_tree, set, _NULL);
			else
				ret = _RVU_ERROR_FULL_TREE;
		} else if (_isalpha(*_rvalue_it) || *_rvalue_it == '_') {
			char *_temp;
			int count;
			
		REALLOC:
			if(!(_temp = (char *)malloc(sizeof(char) * 128)))
				goto REALLOC;
			for (count = 0; _isalnumub((int)(*_rvalue_it)); _rvalue_it++, count++)
				_temp[count] = *_rvalue_it;
			_temp[count] = 0;

			ret = _temp;
		} 
		return ret;
	}
/////////////////////////////////////////////////////////////////////////////////////