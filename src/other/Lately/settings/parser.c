/*************************************************************************
 *
 * FILE NAME : parser.c - SLC Parser
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

#include "parser.h"
#include "corex-tool.h"

PSLC_VAR variable_tc;

PSLC_VAR slc_list_init()
{
	PSLC_VAR def = (PSLC_VAR) malloc (sizeof(PSLC_VAR));
	def->data = 0;
	def->_Next = 0;
	return def;
}

void slc_list_release(PSLC_VAR ps)
{
	for (; ps; ps = ps->_Next)
		free(ps->data);
}

static char *slc_annote_prev(const char *_Ptr)
{
	slc_remove_ws(&_Ptr);
	while (*_Ptr && *_Ptr != ';')
		_Ptr++;
	return ++_Ptr;
}

static char *slc_parse_condition(const char *_Ptr)
{
	// 조건 구문 : <value1> <op> <value2>
}

static char *slc_var(const char *_Ptr)
{

}

static char *slc_var_announce(const char *_Ptr)
{

}