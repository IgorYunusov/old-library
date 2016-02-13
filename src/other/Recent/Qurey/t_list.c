/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   t_list.c - [Private]
   
Abstract:

	Table/Section list

------
   AUTHOR: HyunJun Jeong  2015-05-13

***************************************************************************/

#include <malloc.h>
#include "qyt.h"

BOOL TListInit(
	OUT PTABLE_LIST *p_tl,
	IN char *qt
	)
{
	PTABLE_LIST p_tl_ret = (TABLE_LIST *)malloc(sizeof(TABLE_LIST));
	if (!p_tl_ret)
		return FALSE;

	p_tl_ret->qt = qt;
	p_tl_ret->next = 0;

	*p_tl = p_tl_ret;
	return TRUE;
}

BOOL TListPushBack(
	OUT PTABLE_LIST tl,	// last access
	IN PQUREY_TABLE qt
	)
{
	PTABLE_LIST tlc;
	if (!TListInit(&tlc, (char *)qt))
		return FALSE;
	tl->next = tlc;
	return TRUE;
}