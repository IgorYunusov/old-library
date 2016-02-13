/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   struct.c

Project:

   Using structure syntax.

------
   AUTHOR: HyunJun Jeong  2015-08-08

***************************************************************************/

#include "internal.h"

/****

	How to make or use structure syntax?

	[1] Create
		/create@structure{point{x,y}}

	[2] Apply
		ptrxy :: point
		ptrxy :: 0, 1
		/output@writeline{ptrxy->x}
		/output@writeline{ptrxy}

	[3] Alreay existing check.
		/ifs@exist/structure{point}
			/create@structure{point{x,y}}
		/eif

	[4] Debug
		-1 point structure datas catched.

****/

static PTR_SSTRAGE structure_storage;

void initialization_structure_storage()
{
	structure_storage = _malloc(SSTRAGE);
	structure_storage->next = 0;
}

/*
	Create structure struct.
*/
PTR_CRESTR synx_make_structure(const char *behind)
{
	CRESTR *crestr = _malloc(CRESTR);
	const char *iter = behind;
	char *str_chk = 0;
	int elem_c = 0;
	ENAME *enamer = _malloc(ENAME);
	ENAME *ename_p = enamer;
	
	if (*iter++ != '{')
		return error;

	/* count string length */
	while (*iter != '{' && *iter)
		iter++;
	if (!*iter)
		return error;
	if (error == (str_chk = get_string(behind, iter - behind)))
		return error;
	crestr->name = str_chk;

	/* get element */
	if (*iter++ != '{')
		return error;
	do {
		ENAME *elements = _malloc(ENAME);
		const char *iter_tmp = iter;

		while (*iter_tmp != ',' && *iter_tmp != '}' && *iter_tmp)
			iter_tmp++;
		if (error == (str_chk = get_string(iter, iter_tmp - iter)))
			return error;
		
		elements->next = 0;
		ename_p->name = str_chk;
		ename_p->next = elements;
		ename_p = elements;
		iter = iter_tmp;
		elem_c++;

		if (*iter != ',')
			break;
		iter++;
	} while (true);
	if (*iter != '}')
		return error;

	crestr->element_count = elem_c;
	crestr->element_names = enamer;
	return crestr;
}

/*
	Check if already exist structure.
*/
boolean chkd_exist_structure(const char *cond)
{
	const SSTRAGE *iter = structure_storage;
	for (; iter->next; iter = iter->next)
		if (true == check_collect_string(cond, iter->data->name))
			return true;
	return false;
}

void add_structrue(PTR_CRESTR pss)
{
	SSTRAGE *iter = structure_storage;
	SSTRAGE *new = _malloc(SSTRAGE);
	for (; iter->next; iter = iter->next)
		;
	iter->data = pss;
	new->next = 0;
	iter->next = new;
}

int get_structure_count()
{
	const SSTRAGE *iter = structure_storage;
	int i = 0;
	for (; iter->next; iter = iter->next)
		i++;
	return i;
}
