/************************************************************
 *															*
 *															*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX			*
 *															*
 *															*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.	*
 *															*
 *															*
 ************************************************************/

#pragma once

#ifndef __APVL_GATHER
#define __APVL_GATHER

#include "apvlDef.h"

#define TYPE_INT		0
#define TYPE_CHAR		1
#define TYPE_CHARP		2
#define TYPE_UINT		3
#define TYPE_SHORT		4
#define TYPE_USHORT		5
#define TYPE_U			6
#define TYPE_UCHAR		7
#define TYPE_UCHARP		8
#define TYPE_LONG		9
#define TYPE_DLONG		10
#define TYPE_UDLONG		11
#define TYPE_DOUBLE		12
#define TYPE_FLOAT		13
#define TYPE_BOOL		14
#define TYPE_BYTE		15
#define TYPE_WORD		16
#define TYPE_DWORD		17
#define TYPE_IGNORE		18
#define TYPE_TIME		19
#define TYPE_POS		20

struct _tag_apvl_gather{
	void *	INDEX;
	int	iError;
	HTYPE	tTyd;		// cast type
};

#define ERROR_ANYMOREUSEDNOT		1

struct _tag_apvl_gather *CreateGather(HTYPE tTyd)
{
	struct _tag_apvl_gather ixt;
	ixt.tTyd = tTyd;
	return &ixt;
}

typedef struct _tag_apvl_gather GATHER;

// force cast
void GatherDataToProcessing(struct _tag_apvl_gather * x, ... )
{
	// connecting		: Error Report
	va_list vx;
	x->iError = 0;
	va_start(vx, x);
	switch(x->tTyd)
	{
	case TYPE_INT:
		x->INDEX = &va_arg(vx, int);
		break;
	case TYPE_CHAR:
		x->INDEX = &va_arg(vx, char);
		break;
	case TYPE_CHARP:
		x->INDEX = &va_arg(vx, char *);
		break;
	case TYPE_UINT:
		x->INDEX = &va_arg(vx, uint);
		break;
	case TYPE_SHORT:
		x->INDEX = &va_arg(vx, short);
		break;
	case TYPE_USHORT:
		x->INDEX = &va_arg(vx, ushort);
		break;
	case TYPE_U:
		x->INDEX = &va_arg(vx, unsigned);
		break;
	case TYPE_UCHAR:
		x->INDEX = &va_arg(vx, uchar);
		break;
	case TYPE_UCHARP:
		x->INDEX = &va_arg(vx, uchar *);
		break;
	case TYPE_LONG:
		x->INDEX = &va_arg(vx, long);
		break;
	case TYPE_DLONG:
		x->INDEX = &va_arg(vx, llong);
		break;
	case TYPE_UDLONG:
		x->INDEX = &va_arg(vx, ullong);
		break;
	case TYPE_DOUBLE:
		x->INDEX = &va_arg(vx, double);
		break;
	case TYPE_FLOAT:
		x->INDEX = &va_arg(vx, float);
		break;
	case TYPE_BOOL:
		x->iError = ERROR_ANYMOREUSEDNOT;
		break;
	case TYPE_BYTE:
		x->INDEX = &va_arg(vx, BYTE);
		break;
	case TYPE_WORD:
		x->INDEX = &va_arg(vx, WORD);
		break;
	case TYPE_DWORD:
		x->INDEX = &va_arg(vx, DWORD);
		break;
	case TYPE_IGNORE:
		x->INDEX = &va_arg(vx, void *);
		break;
	case TYPE_TIME:
		x->INDEX = &va_arg(vx, TIME);
		break;
	case TYPE_POS:
		x->INDEX = &va_arg(vx, _apvl_pos);
		break;
	}
	va_end(vx);
}

#endif
