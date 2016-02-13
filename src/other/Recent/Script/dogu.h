/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   dogu.h

Project:

   Syntax analyze toolbox.

------
   AUTHOR: HyunJun Jeong  2015-08-08

***************************************************************************/

#ifndef _DOGU_
#define _DOGU_

#include <malloc.h>
#include <string.h>


#define _malloc(type)		(type *)malloc(sizeof(type))

typedef int boolean;

#define true 1
#define false 0
#define error -1

boolean check_collect_string(const char *p1, const char *p2);
char *get_string(const char *p, int length);

#endif