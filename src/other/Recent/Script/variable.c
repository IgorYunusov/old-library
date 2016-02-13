/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   variable.c

Project:

   Using variable syntax.

------
   AUTHOR: HyunJun Jeong  2015-08-08

***************************************************************************/

#include "internal.h"

/****

	How to make or use structure syntax?

	[1] Create 
		-1 frame: <variable-name> :: <type>
			test :: integer
		-2 /create@variable{<variable-name>(,optional <type>)}

		basic provided <type> list 
				none: auto detective.
				integer or int: integer
				string: string
				double: floating point

		extra <type> list
				structure: view struct.c

		string-set:
			test :: string
			test :: (put text this box)

	[2] Apply
		-1 initialization: <variable-name> :: <value>	[force set constant variable]
			test :: 123456
			or
			/init{test,123456}
		-2 substitute: <variable-name> <- <value>
			test <- 123456
			or
			/set{test,123456}

		string-set:
			test :: text
			test <- (text)
			or
			/init{text,(text)}
			/set{text,(text)}

	[3] Alreay existing check.
		/ifs@exist/variable{test}
			/create@variable{test}
		/eif

	[4] Debug
		-1 test variable datas catched.

****/

static PTR_VSTRAGE variable_storage;

void initialization_variable_storage()
{
	variable_storage = _malloc(VSTRAGE);
	variable_storage->next = 0;
}

static VarType synx_check_type(const char *behind)
{
	if (!strcmp(behind, "integer"))
		return Integer;
	if (!strcmp(behind, "double"))
		return Double;
	if (!strcmp(behind, "string"))
		return String;
	// check structure
	return None;
}

/*
	Create variable struct.
*/
PTR_CREVAR synx_make_variable(const char *behind)
{
	CREVAR *crevar = _malloc(CREVAR);
	const char *iter = behind, *iter2;
	char *str_chk = 0;
	
	if (*iter++ != '{')
		return error;
	iter2 = iter;
	while (*iter != '}' && *iter != ',' && *iter)
		*iter++;
	if (!*iter)
		return error;
	if (error == (str_chk = get_string(iter2, iter - iter2)))
		return error;
	crevar->name = str_chk;
	crevar->type = None;

	if (*iter == '}')
		return crevar;

	else if (*iter++ != ',')
		return error;
	iter2 = iter;
	while (*iter2 != '}' && *iter2)
		iter2++;
	if (!*iter2)
		return error;
	if (error == (str_chk = get_string(iter, iter2 - iter)))
		return error;
	crevar->type = synx_check_type(str_chk);

	return crevar;
}

void add_variable(PTR_CREVAR pss)
{
	VSTRAGE *iter = variable_storage;
	VSTRAGE *new = _malloc(VSTRAGE);
	for (; iter->next; iter = iter->next)
		;
	iter->data = pss;
	new->next = 0;
	iter->next = new;
}

PTR_CREVAR get_variable(const char *pss)
{
	VSTRAGE *iter = variable_storage;
	for (; iter->next; iter = iter->next)
		if (true == check_collect_string(pss, iter->data->name))
			return iter;
	return error;
}

void set_variable(const char *pss, void *obj)
{
	get_variable(pss)->data = obj;
}

/*
	Check if already exist variable.
*/
boolean chkd_exist_variable(const char *cond)
{
	const VSTRAGE *iter = variable_storage;
	for (; iter->next; iter = iter->next)
		if (true == check_collect_string(cond, iter->data->name))
			return true;
	return false;
}
