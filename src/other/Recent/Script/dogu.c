/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   dogu.c

Project:

   Syntax analyze toolbox.

------
   AUTHOR: HyunJun Jeong  2015-08-08

***************************************************************************/

#include "dogu.h"

boolean check_collect_string(const char *p1, const char *p2)
{
	/*while(!(*p1 - *p2) && *p1 && *p2) {
		p1++;
		p2++;
	}

	if (!*p1 && !*p2)
		return true;
	else
		return false;*/
	return !strcmp(p1, p2);
}

char *get_string(const char *p, int length)
{
	if (length <= 0)
		return error;

	char *string = (char *)malloc(length+1);
	int i = 0;

	for (; i < length; i++)
		string[i] = *p++;
	string[length] = 0;

	return string;
}