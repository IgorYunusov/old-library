/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   ifs.c

Project:

   Functional condition syntax.

------
   AUTHOR: HyunJun Jeong  2015-08-09

***************************************************************************/

#include "internal.h"

/****

	How to make or use structure syntax?

	[1] Create

	[2] Apply
		/ifs@<function>
			...
			...
			...
		/eif

		function list:
			exist<@,/><what>: Check if exist.
				- At: Check compiler syntax.
				- Slash: Check user syntax.
			equal/<what>: Check whether both values are equal.
				equal/variable{x,123} % etc...
			notequal/<what>: not equal check.
			less/<what>: less than( < )
			lessequal/<what>: less qual than ( <= )
			greater/<what>: greater than ( > )
			greaterequal/<what>: greater equal than ( >= )

		Sytanx Stack:
			When this syntax used in real time, interpreter, for proper 
			verification of syntax, use the stack. In addition, by 
			applying the number value of each syntax is increased, 
			you can create an index of each other.

	[3] Alreay existing check.

	[4] Debug

****/

#define STACK_SIZE_MAX		25

typedef struct _insizeable_stack_ {
	unsigned int _top_position;
	int ifinfo[STACK_SIZE_MAX];
}	IFS_STACK, *PTR_IFS_STACK;

static IFS_STACK ifs_stack;
static int id_count;

#define IS_FULL_STACK	(ifs_stack._top_position == STACK_SIZE_MAX)
#define get_top		ifs_stack.ifinfo[ifs_stack._top_position]

void initializtaion_ifs_storage()
{
	ifs_stack._top_position = 0;
	id_count = 0;
}

static boolean push_ifsstack(int pii)
{
	if (IS_FULL_STACK)
		return false;
	ifs_stack.ifinfo[ifs_stack._top_position++] = pii;
	return true;
}

static boolean pop_ifsstack()
{
	if (ifs_stack._top_position == 0)
		return false;
	ifs_stack._top_position--;
	return true;
}

boolean synx_ifs(const char *str)
{
	const char *iter = str;
	const char *iter2 = str;
	char *str_chk = 0;
	char *str_chk2 = 0;
	void *ptr;
	int status;

	if (*iter++ != '@')
		return error;
	while (*iter != '/' && *iter != '@' && *iter)
		iter++;
	if (!*iter)
		return error;
	if (error == (str_chk = get_string(str + 1, iter - str - 1)))
		return error;
	iter2 = iter;
	
	if (*iter++ == '/')
	{
		if (check_collect_string(str_chk, stq_g_exist)) 
		{
			while (*iter != '{' && *iter)
				iter++;
			if (!*iter)
				return error;
			if (error == (str_chk = get_string(iter2 + 1, iter - iter2 - 1)))
				return error;
			iter2 = iter;

			while (*iter != '}' && *iter)
				iter++;
			if (!*iter)
				return error;
			if (error == (str_chk2 = get_string(iter2 + 1, iter - iter2 - 1)))
				return error;
			iter2 = iter;

			if (check_collect_string(str_chk, stq_g_variable)) 
			{
				return chkd_exist_variable(str_chk2);
			}
			else if (check_collect_string(str_chk, stq_g_structure))
			{
				return chkd_exist_structure(str_chk2);
			}
		}

	}

	push_ifsstack(id_count++);
	return true;
}

#include <stdarg.h>

//int main()
//{
//	initialization_variable_storage();
//	initialization_structure_storage();
//
//	char *asdf = "asdf";
//	const char *ptr = asdf;
//
//	while (*ptr != (char)NULL)
//		ptr++;
//
//	synx_create("@variable{x,integer}");
//	synx_ifs("@exist/variable{x}");
//}
