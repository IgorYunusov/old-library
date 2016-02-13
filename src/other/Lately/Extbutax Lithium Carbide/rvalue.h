/*************************************************************************
 *
 * FILE NAME : rvalue.h - Enable Right Value
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

#ifndef _RVALUE_
#define _RVALUE_

#include "type.h"
#include "rocket.h"

typedef struct _rvalue_set {
	ptree tree;
	CHAR *ptr;	// return ptr
}	RVALUE, *PRVALUE;

#endif