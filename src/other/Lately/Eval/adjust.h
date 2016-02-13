/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   debug.h - [Private]

Project:

   Robust Assembler (RASM)

------
   AUTHOR: HyunJun Jeong  2015-01-15

***************************************************************************/

#ifndef _ADJUST_
#define _ADJUST_

#include "type.h"

typedef struct _anchor_{
	WORD uhex;
	BYTE posix;
	BYTE xhex;
	BOOL inverse;
	int type;	// 0:uhex, 1:posix, 2:xhex
}	AdjustAnchor, *PAdjustAnchor;

BOOL AdjustCharacter(const char const **ptr, const char ch);
void AdjustPreCharacter(const char const **ptr, const char ch);
void AdjustPostCharacter(const char const **ptr, const char ch);
void AdjustPreWithScope(const char const **ptr, const char lch, const char rch);
void AdjustPostWithScope(const char const **ptr, const char lch, const char rch);
BOOL AdjustEqualCharacter(const char const **ptr, const char ch);
void AdjustBracketCharacter(const char const **ptr, const char ch1, const char ch2);
size_t AdjustPreFindFunction(const char const **ptr, void *(*func(void *)));
size_t AdjustPreSkipFunction(const char const **ptr, void *(*func(void *)));
size_t AdjustPostFindFunction(const char const **ptr, void *(*func(void *)));
size_t AdjustPostSkipFunction(const char const **ptr, void *(*func(void *)));
void AdjustLeftTrim(const char const **ptr);
void AdjustRightTrim(const char const **ptr);
void AdjustLastPointer(const char const **ptr);
char *DropLeft(const char *ptr, const size_t sz);
char *DropRight(const char *ptr, const size_t sz);
char *DropMid(const char *ptr, const size_t _Left, const size_t _Right);
char *DropLSet(const char *ptr, const size_t sz);
char *DropRSet(const char *ptr, const size_t sz);
size_t DropContainsLength(const char *src, const char *ptr);
char **DropSplit(const char *_Ptr, const char *_T);
BOOL DropStartsWith(const char *src, const char *chp);
BOOL DropEndsWith(const char *src, const char *chp);
BOOL DropRegexPosixConstant(const char const **constant, const char ch);
BOOL DropRegexSideScope(const char const **scope, const char ch);
BOOL DropRegexPosixMatch(BYTE posix, char ch);
PAdjustAnchor DropRegexAnchor(const char const **ptr);
BOOL DropRegexGlobal(const char *ptr, const char *chr);
BOOL DropRegexPreRepeatCharacter(const char const **repeat, const char ch, size_t count);
BOOL DropRegexPostRepeatCharacter(const char const **repeat, const char ch, size_t count);

#define RTrim		AdjustRightTrim
#define LTrim		AdjustLeftTrim
#define Left		DropLeft
#define Right		DropRight
#define Mid			DropMid
#define LSet		DropLSet
#define RSet		DropRSet
#define Len			DropContainsLength
#define Split		DropSplit
#define StartsWith	DropStartsWith
#define EndsWith	DropEndsWith

#endif