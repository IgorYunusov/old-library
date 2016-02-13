/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   asm.c - [Private]

Project:

   Robust Assembler (RASM)
   
Abstract:

   Assemble module

------
   AUTHOR: HyunJun Jeong  2015-01-06

***************************************************************************/

#include "reg.h"
#include "rocket.h"
#include <malloc.h>

#define _LEAK_TEST
#include "leak.h"

static void pushByte(BYTE target, BYTE *bytes, size_t *byteptr);
static void pushWord(WORD target, BYTE *bytes, size_t *byteptr);
static void pushDWord(DWORD target, BYTE *bytes, size_t *byteptr);

#define MakeModRM(mod, reg, rm)		((rm & 7) | ((reg & 7) << 3) | ((mod & 3) << 6))
#define MakeSIB(ss, index, base)	((ss & 7) | ((index & 7) << 3) | ((base & 3) << 6))

void assemble(const char *str, BYTE *bytes, size_t *byteptr)
{
	
}

static void pushByte(BYTE target, BYTE *bytes, size_t *byteptr)
{
	bytes[(*byteptr)++] = target;
}

static void pushWord(WORD target, BYTE *bytes, size_t *byteptr)
{
	*(WORD *)(bytes + *byteptr) = (BYTE)(target) << 8 | (BYTE)(target >> 8);
	*byteptr += 2;
}

static void pushDWord(DWORD target, BYTE *bytes, size_t *byteptr)
{
	*(DWORD *)(bytes + *byteptr) = (BYTE)(target) << 24 | (BYTE)(target >> 8) << 16 
		| (BYTE)(target >> 16) << 8 | (BYTE)(target >> 24);
	*byteptr += 4;
}