/*************************************************************************
 *
 * FILE NAME : costume.h
 *
 * ROLLRAT SOFTWARE Robust Assembler (RASM)
 *
 *
 * LANGUAGE : ANSI C
 * CREATION : 2014.12.27
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _COSTUME_
#define _COSTUME_

#include "type.h"

#define _COTM_ARROW_RIGHT			'>'
#define _COTM_ARROW_LEFT			'<'
#define _COTM_IF					'?'
#define _COTM_ELSE					':' // also using scope
#define _COTM_PATH_OPEN				'{'
#define _COTM_PATH_CLOSE			'}'
#define _COTM_BRET_OPEN				'('
#define _COTM_BRET_CLOSE			')'
#define _COTM_PAREN_OPEN			'['
#define _COTM_PAREN_CLOSE			']'
#define _COTM_OPEN					';'
#define _COTM_CLOSE					';'
#define _COTM_FUNCTION				'%' // both open and close
#define _COTM_OPTIONS				'\\'
#define _COTM_LVALUE				'='
#define _COTM_VARIABLE				'@' // integer
#define _COTM_STRVARIABLE			'$' // string
#define _COTM_STRDELIMITER			'"'
#define _COTM_DELIMITER				'/'
#define _COTM_SHARP					'#' // #:add[0x], 
#define _COTM_CONNECTION			'+'

//#define _CTOM_FUNCTION_LENGTH			"length"

#define _CTOM_SUCCESS								0
#define _CTOM_ERROR_NOT_EXIST_FORAMT				1
#define _CTOM_ERROR_NOT_FOUND_OPTION				2
#define _CTOM_ERROR_FUNCTIONCALL_BEFOR_LVALUE		3
#define _CTOM_ERROR_ALREADY_EXIST_VARIABLE			4
#define _CTOM_ERROR_NOT_FOUND_IF_SCOPE				5
#define _CTOM_ERROR_NOT_FOUND_SCOPE_CLOSE			6
#define _CTOM_ERROR_STRINGPTR_BEFOR_LVALUE			7
#define _CTOM_ERROR_NOT_FOUND_VARIABLE				8
#define _CTOM_ERROR_INTEGERPTR_BEFOR_LVALUE			9


#ifdef _X86PROC
typedef struct _costume_strxt{
	struct _costume_str* _Next;
	CHAR *data;
	char *name;
}	costumex, costumestrx, *pcostumex, *pcostumestrx;
#else
typedef struct _costume_str{
	struct _costume_str* _Next;
	u32 data;
	char *name;
}	costumex, *pcostumex;

typedef struct _costume_strx{
	struct _costume_str* _Next;
	CHAR *data;
	char *name;
}	costumestrx, *pcostumestrx;
#endif

BOOL process_costume(const CHAR *target, CHAR *source, const CHAR *format);

#endif