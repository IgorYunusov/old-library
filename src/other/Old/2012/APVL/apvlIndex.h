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

#ifndef __APVL_INDEX
#define __APVL_INDEX

#include <malloc.h>

//#include "vector.h"
#include "apvlDef.h"
#include "apvlGather.h"

typedef struct _tag_apvl_UNION_Filter {
	struct _tag_apvl_UNION_Filter*		Prev;
	_ptr_apvl_index						Data;
	struct _tag_apvl_UNION_Filter*		Next;
}	FILTER, *PTR_FILTER;

void StateConnectingHead(PTR_FILTER apvlFilter)
{
	apvlFilter->Prev = apvlFilter;
	apvlFilter->Data->connecting = 0;	// Head Sign
	apvlFilter->Next = apvlFilter;
}

void StateConnectingNextPtr(PTR_FILTER apvlFilter)
{
	apvlFilter = apvlFilter->Next;
}

void StateConnectingPrevPtr(PTR_FILTER apvlFilter)
{
	apvlFilter = apvlFilter->Prev;
}

void StateConnecting(PTR_FILTER apvlFilter, PTR_FILTER pNv)
{
	apvlFilter->Next = pNv;
	pNv->Prev = apvlFilter;
}

void StateConnectingInit(PTR_FILTER apvlFilter)
{
	apvlFilter->Data->apvlData->connecting = 0;
	apvlFilter->Data->apvlData->INDEX = NULL;
	apvlFilter->Data->apvlData->tTyd = TYPE_IGNORE;
	apvlFilter->Data->connecting = 1;
	apvlFilter->Data->iSerial = 0;
	apvlFilter->Data->msgPort = 0;
}

PTR_FILTER StateConnectingNew()
{
	PTR_FILTER sct = (FILTER *)malloc(sizeof(FILTER));
	sct->Data = (_apvl_index *)malloc(sizeof(_apvl_index));
	sct->Data->apvlData = (_apvl_data *)malloc(sizeof(_apvl_data));
	StateConnectingInit(sct);
	return sct;
}

struct _tag_apvl_UNION_Index {
	PTR_FILTER Head;
	PTR_FILTER Now;
	PTR_FILTER Tail;
};

typedef struct _tag_apvl_UNION_Index	Index;

#ifdef __cplusplus
template<class _Index> class
	Library
	{ // Library
public:

private:
	Index iTex;
	};
#endif

#endif
