/*
 ******************************************************
 **
 **		ROLLRAT APVL
 **
 **		LUNATIC PROJECT
 **
 ******************************************************
 */

#ifndef __lcdef
#define __lcdef

#define IN
#define OUT
#define INOUT

typedef void *			invalid;

typedef unsigned long int	uint4;
typedef unsigned char		uint8_t;
typedef unsigned long		dword;
typedef unsigned short		word;

#define LOWORD(l)           ((word)(((dword)(l)) & 0xffff))
#define HIWORD(l)           ((word)((((dword)(l)) >> 16) & 0xffff))

#define TYPE_INT		1
#define TYPE_CHAR		2
#define TYPE_UINT		3
#define TYPE_UCHAR		4
#define TYPE_CHARP		5
#define TYPE_HTY		6
#define TYPE_NO			7

typedef struct _Class_
{
	invalid		handle;
	invalid *	function;
	uint4		size;
}	Class, *PClass;

typedef struct _Call_
{
	struct _Call_ * next;
	invalid		data;
	dword		type;		// low : 타입, high : 핸들
}	CStackNode;

typedef struct _Head_
{
	CStackNode * Head;
}	CStack;

typedef dword	RDWORD;
typedef dword	LDWORD;

typedef struct _PARAM_
{
	RDWORD	right;
	LDWORD	left;
}	PARAM, *PPARAM;

#endif