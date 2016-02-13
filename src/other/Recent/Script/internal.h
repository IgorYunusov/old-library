/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   internal

------
   AUTHOR: HyunJun Jeong  2015-08-08

***************************************************************************/

#ifndef _INTERNAL_
#define _INTERNAL_

#include "dogu.h"


#define stq_t(xts)	static const char * stq_g_##xts = #xts;
#define _at		// @
#define _slash	// /

_slash stq_t(if)
	_slash stq_t(ifs)
		_slash _at stq_t(exist)
		_slash _at stq_t(equal)
		_slash _at stq_t(notequal)
		_slash _at stq_t(less)
		_slash _at stq_t(lessequal)
		_slash _at stq_t(greater)
		_slash _at stq_t(greaterequal)
	_slash stq_t(else)
	_slash stq_t(elif)
_slash stq_t(eif)

_slash stq_t(create)
	_slash _at stq_t(structure)
	_slash _at stq_t(variable)

#undef stq_t 
#undef def_prefix
	


/*
	struct.c methods
*/

typedef struct _element_names_ {
	struct _elemet_names_ *next;
	char *name;
	char *data;	// if this structre using in compile mode\
		this variable action for real substituted data.
}	ENAME, *PTR_ENAME;

typedef struct _create_struct_ {
	ENAME *element_names;
	unsigned short element_count;
	char *name;
}	CRESTR, *PTR_CRESTR;

typedef struct _static_struct_storage_ {
	struct _static_struct_storage_ *next;
	CRESTR *data;
}	SSTRAGE, *PTR_SSTRAGE;

void initialization_structure_storage();
PTR_CRESTR synx_make_structure(const char *behind);
boolean chkd_exist_structure(const char *cond);
void add_structrue(PTR_CRESTR pss);
int get_structure_count();



/*
	variable.c methods
*/

typedef enum _variable_types_ {
	None=0,	// no undecided
	Integer,
	Double,
	String,
	Structure,
}	VarType;

typedef struct _create_variable_ {
	char *name;
	void *data;
	VarType type;
}	CREVAR, *PTR_CREVAR;

typedef struct _static_variable_storage_ {
	struct _static_variable_storage_ *next;
	CREVAR *data;
}	VSTRAGE, *PTR_VSTRAGE;

void initialization_variable_storage();
PTR_CREVAR synx_make_variable(const char *behind);
void add_variable(PTR_CREVAR pss);
PTR_CREVAR get_variable(const char *pss);
boolean chkd_exist_variable(const char *cond);



/*
	create.c method
*/

boolean synx_create(const char *str);

#endif