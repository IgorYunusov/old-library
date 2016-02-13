/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   regex.h - [Private]
   
Abstract:

   Regular Expression Parser

------
   AUTHOR: HyunJun Jeong  2015-01-26

***************************************************************************/

#ifndef _REGEX_
#define _REGEX_

#include "type.h"

typedef enum {
	REGEX_MULTILINE,
	REGEX_CAPTURE,
	REGEX_REPLACE
}	regex_option;

typedef struct _tag_regex_ {
	DWORD Data;
	int Option;
	struct _tag_regex_  *_Next;
	struct _tag_regex_  *_Prev;
	struct _tag_regex_ **_Jump;
}	*regex_pattern, REGEX_PATTERN, *PREGEX_PATTERN;

//typedef struct _tag_regex_bracket_ {
//};

regex_pattern regex_scan(const char *pattern);

#endif