/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   create.c

Project:

   Create syntax

------
   AUTHOR: HyunJun Jeong  2015-08-09

***************************************************************************/

#include "internal.h"

/****

	How to make or use structure syntax?

	[1] Create

	[2] Apply
		Must used At symbol:
		/create@<create-list> ::= <create-list>{<value>}
						| <creatable-element>

	[3] Alreay existing check.

	[4] Debug

****/

boolean synx_create(const char *str)
{
	const char *iter = str;
	char *str_chk = 0;
	void *ptr;
	int status;

	if (*iter++ != '@')
		return false;

	while (*iter != '{' && *iter)
		iter++;
	if (!*iter)
		return false;
	if (error == (str_chk = get_string(str + 1, iter - str - 1)))
		return false;

	if (check_collect_string(str_chk, stq_g_structure)) 
	{
		if (error != (status = synx_make_structure(iter)))
			add_structrue(status);
	} 
	else if (check_collect_string(str_chk, stq_g_variable)) 
	{
		if (error != (status = synx_make_variable(iter)))
			add_variable(status);
	}

	return status != error;
}