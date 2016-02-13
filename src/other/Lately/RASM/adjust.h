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

typedef struct _anchor_{
	WORD uhex;
	BYTE posix;
	BYTE xhex;
	BOOL inverse;
	int type;	// 0:uhex, 1:posix, 2:xhex
}	AdjustAnchor, *PAdjustAnchor;

void AdjustPreCharacter(const char const **ptr, const char ch);
void AdjustPostCharacter(const char const **ptr, const char ch);
void AdjustPreWithScope(const char const **ptr, const char lch, const char rch);
void AdjustPostWithScope(const char const **ptr, const char lch, const char rch);
BOOL AdjustEqualCharacter(const char const **ptr, const char ch);
BOOL DropRegexPosixConstant(const char const **constant, const char ch);
BOOL DropRegexSideScope(const char const **scope, const char ch);
BOOL DropRegexPosixMatch(BYTE posix, char ch);
PAdjustAnchor DropRegexAnchor(const char const **ptr);
BOOL DropRegexScopeSubtraction(const char const **ptr, const char ch);
BOOL DropRegexPreRepeatCharacter(const char const **repeat, const char ch, size_t count);
BOOL DropRegexPostRepeatCharacter(const char const **repeat, const char ch, size_t count);

#endif