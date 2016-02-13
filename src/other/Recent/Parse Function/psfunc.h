/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   psfunc.h

Purpose:

	Parse c function syntax.

Author:

   09-13-2015:   HyunJun Jeong, Creation

***/

#ifndef _PSFUNC_
#define _PSFUNC_

#include <stdbool.h>

typedef struct _parse_c_ {
	char name[255];
		// including function in target
	struct _parse_c_ *icld;
	struct _parse_c_ *next;
}	FUNC_LIST, *PFUNC_LIST;

typedef struct _def_arg_list_ {
	char name[255];
	int index;
	struct _def_arg_list_ *next;
}	DEF_ARG_LIST, *PDEF_ARG_LIST;

typedef struct _def_macro_list_ {

	/*
		0: Standard characters
		1: Macro Variable
		2: Pasting Function (##)   // non-necessary
		3: Macro Variable Pasting Function ( var## )

		1 and 3 are same processing in parsing.
	*/
	int processor;

	/*
		Macro Variable index number
		(Define argument index number)
	*/
	int index;

	struct _def_macro_list_ *next;
	char ch;

}	DEF_MACRO_LIST, *PDEF_MACRO_LIST;

typedef struct _def_general_list_ {

	char data[255];
	struct _def_general_list_ *next;

}	DEF_GENERAL_LIST, *PDEF_GENERAL_LIST;

typedef struct _parse_def_ {
	char name[30];
	int index;

	/*
		0: General
		1: Macro
	*/
	int processor;
	DEF_ARG_LIST *dal;
	DEF_MACRO_LIST *dml;
	DEF_GENERAL_LIST *dgl;
	struct _parse_def_ *next;
}	DEF_LIST, *PDEF_LIST;

typedef struct _line_ {
	struct _line_ *next;
	char *pointer;
}	LINE_LIST, *PLINE_LIST;

PDEF_LIST parse_define(PLINE_LIST lines);
LINE_LIST *set_line(const char *target);
void put_line(PLINE_LIST ll, const char *target);
void replace_defines(PDEF_LIST dl, const char *target, char *buffer);

#endif