/*************************************************************************
 *
 * FILE NAME : parser.h - SLC Parser
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

#ifndef _SLC_PARSER_
#define _SLC_PARSER_

#include "corex-tool.h"

#define VARTYPE_INTEGER			1
#define VARTYPE_STRING			2
#define VARTYPE_ARRAY			3

typedef struct _slc_parser {
	int type;
	void *data;
	struct _agsprintf *_Next;
}	SLC_VAR, *PSLC_VAR;

#endif