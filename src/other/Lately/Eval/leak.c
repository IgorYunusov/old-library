/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   leak.h - [Private]

Project:

   RollRat Eval

Abstract:

   Memory leak test for all device

------
   AUTHOR: HyunJun Jeong  2015-01-08

***************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#if defined(_MSC_VER)

#define _CRTDBG_MAP_ALLOC

#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW	new (_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DBG_NEW
#endif
#endif

#endif

#include "type.h"
#include "rocket.h"

typedef struct _DbgRtck_Memleack {
	char *strFunc;
	size_t szTotalsize;
	unsigned int uiLine;
	char *pcPointer;
	int iFree;
	long int $;
	char *strFile;
	struct _DbgRtck_Memleack *_Next;
}	_DERTCKLEACK, *_PDERTCKLEACK;

typedef struct _DbgRtck_Error {
	char *_Func;
	int _whatError;
	size_t szTotalsize;
	unsigned int uiLine;
	char *ddPointer;
	char *dwPointer;
	long int $;
	char *_File;
	struct _DbgRtck_Error *_Next;
}	_DERTCKERR, *_PDERTCKERR;

typedef struct _DbgRtck_Point {
	char *strFunc;
	size_t szTotalsize;
	unsigned int uiLine;
	char *pcPointer;
	long int $;
	struct _DbgRtck_Point *_Next;
}	_DERTCKCHK, *_PDERTCKCHK;

typedef struct _DbgRtck_Sort {
	_PDERTCKERR sort_Errc;
	_PDERTCKLEACK sort_LeaCk;
	int iSorted;
}	_DERTCKSORT, *_PDERTCKSORT;

static _PDERTCKLEACK leack_storage, leack_head;
static _PDERTCKERR errck_storage, errck_head;
static _PDERTCKCHK chkk_storage, chkk_head;

static long int $;

void _DeRtck_init()
{
#ifdef _MSC_VER
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	leack_head = leack_storage = (_DERTCKLEACK *)malloc(sizeof(_DERTCKLEACK));
	leack_storage->_Next = NULL;
	errck_head = errck_storage = (_DERTCKLEACK *)malloc(sizeof(_DERTCKLEACK));
	errck_storage->_Next = NULL;
	$ = 0;
}

void _DeRtck_reset()
{
	_PDERTCKLEACK pl = leack_head, plq = leack_head;
	_PDERTCKERR pe = errck_head, peq = errck_head;

	if( pl->_Next != NULL )
		pl = pl->_Next;
	if( pe->_Next != NULL )
		pe = pe->_Next;

	for(; pl; pl = pl->_Next) {
		if( plq != NULL ) {
			free(plq);
		}
		free(pl->strFunc);
		if (pl->iFree == FALSE)
			free(pl->pcPointer);
		plq = pl;
	}
	if (plq != NULL)
		free(plq);

	for(; pe; pe = pe->_Next) {
		if( peq != NULL ) {
			free(peq);
		}
		if( pe->_Next == NULL )
			break;
		free(pe->_Func);
		peq = pe;
	}
	if (peq != NULL)
		free(peq);
}

void *_DeRtck_memmalloc(size_t _size_ptr, const char *_func, const char *_file, unsigned int _line)
{
	auto char *funcset, *fileset;
	_PDERTCKLEACK pd;

	funcset = (char *)malloc(sizeof(char) * _strnlen_asc(_func, 255));
	_strcpy_asc(funcset, _func);
	fileset = (char *)malloc(sizeof(char) * _strnlen_asc(_file, 255));
	_strcpy_asc(fileset, _file);
	
	pd = (_DERTCKLEACK *)malloc(sizeof(_DERTCKLEACK));
	pd->strFunc = funcset;
	pd->strFile = fileset;
	pd->szTotalsize = _size_ptr;
	pd->uiLine = _line;
	pd->pcPointer = (char *)malloc(_size_ptr);
	pd->_Next = NULL;
	pd->iFree = FALSE;
	pd->$ = ++$;
	
	leack_storage->_Next = pd;
	leack_storage = pd;

	return (void *)(leack_storage->pcPointer);
}

void *_DeRtck_memcalloc(size_t _count_ptr, size_t _size_ptr, const char *_func, const char *_file, unsigned int _line)
{
	char *funcset, *fileset;
	_PDERTCKLEACK pd;

	funcset = (char *)malloc(sizeof(char) * _strnlen_asc(_func, 255));
	_strcpy_asc(funcset, _func);
	fileset = (char *)malloc(sizeof(char) * _strnlen_asc(_file, 255));
	_strcpy_asc(fileset, _file);
	
	pd = (_DERTCKLEACK *)malloc(sizeof(_DERTCKLEACK));
	pd->strFunc = funcset;
	pd->strFile = fileset;
	pd->szTotalsize = _count_ptr * _size_ptr;
	pd->uiLine = _line;
	pd->pcPointer = (char *)calloc(_count_ptr, _size_ptr);
	pd->_Next = NULL;
	pd->iFree = FALSE;
	pd->$ = ++$;
	
	leack_storage->_Next = pd;
	leack_storage = pd;

	return (void *)(leack_storage->pcPointer);
}

void *_DeRtck_memrealloc(void *_ptr, size_t _size_ptr, const char *_func, const char *_file, unsigned int _line)
{
	char *funcset, *fileset;
	_PDERTCKLEACK pd;

	funcset = (char *)malloc(sizeof(char) * _strnlen_asc(_func, 255));
	_strcpy_asc(funcset, _func);
	fileset = (char *)malloc(sizeof(char) * _strnlen_asc(_file, 255));
	_strcpy_asc(fileset, _file);
	
	pd = (_DERTCKLEACK *)malloc(sizeof(_DERTCKLEACK));
	pd->strFunc = funcset;
	pd->strFile = fileset;
	pd->szTotalsize = _size_ptr;
	pd->uiLine = _line;
	pd->pcPointer = (char *)realloc(_ptr, _size_ptr);
	pd->iFree = FALSE;
	pd->$ = ++$;

	leack_storage->_Next = pd;
	leack_storage = pd;

	return (void *)(leack_storage->pcPointer);
}

void *_DeRtck_memfree(void *ptr, const char *_func, const char *_file, unsigned int _line)
{
	_PDERTCKLEACK leack_last = leack_head->_Next;
	_PDERTCKERR errc_new;
	char *funcset, *fileset;

	if ((int)(ptr) == NULL)
		return;

	for( ; leack_last != NULL; leack_last = leack_last->_Next) {
		if(!_strcmp_asc(leack_last->strFunc, _func) 
			&& (leack_last->pcPointer == (char *)ptr 
			|| leack_last->uiLine == _line)) {
			leack_last->iFree = TRUE;
			free(ptr);
			return;
		} else if (!_strcmp_asc(leack_last->strFunc, _func) 
			&& !(leack_last->pcPointer == (char *)ptr 
			|| leack_last->uiLine == _line)) {
			break;
		}
	}
	
	funcset = (char *)malloc(sizeof(char) * _strnlen_asc(_func, 255));
	_strcpy_asc(funcset, _func);
	fileset = (char *)malloc(sizeof(char) * _strnlen_asc(_file, 255));
	_strcpy_asc(fileset, _file);

	errc_new = (_DERTCKERR *)malloc(sizeof(_DERTCKERR));
	errc_new->ddPointer = ptr;
	errc_new->dwPointer = leack_last->pcPointer;
	errc_new->szTotalsize = leack_last->szTotalsize;
	errc_new->uiLine = _line;
	errc_new->_Func = funcset;
	errc_new->_File = fileset;
	errc_new->$ = leack_last->$;
	
	errck_storage->_Next = errc_new;
	errck_storage = errc_new;
}

void _DeRtck_print_nfree()
{
	_PDERTCKLEACK leack_last = leack_head->_Next;

	for(; leack_last; leack_last = leack_last->_Next) {
		if( leack_last->iFree == FALSE ) {
			printf("---------------------------------------------\n");
			printf("Address : %s\nLine : %d\nFunction name : %s\nCount : %d\nSize : [%d]\nVirtual Address : %#08x\n", 
				leack_last->strFile, leack_last->uiLine, 
				leack_last->strFunc, leack_last->$, leack_last->szTotalsize, leack_last->pcPointer);
		}
	}
}

void _DeRtck_print_all()
{
	_PDERTCKLEACK leack_last = leack_head->_Next;

	for(; leack_last; leack_last = leack_last->_Next) {
		printf("---------------------------------------------\n");
		printf("Address : %s\nLine : %d\nFunction name : %s\nCount : %d\nSize : [%d]\nVirtual Address : %#08x\n", 
			leack_last->strFile, leack_last->uiLine, 
			leack_last->strFunc, leack_last->$, leack_last->szTotalsize, leack_last->pcPointer);
	}
}

void _DeRtck_print_error()
{
	_PDERTCKERR error_last = errck_head->_Next;

	for(; error_last; error_last = error_last->_Next) {
		printf("---------------------------------------------\n");
		printf("Address : %s\nLine : %d\nFunction name : %s\nCount : %d\nSize : [%d]\nVirtual Address : %#08x\n", 
			error_last->_File, error_last->uiLine, 
			error_last->_Func, error_last->$, error_last->ddPointer, error_last->szTotalsize, error_last->dwPointer);
	}
}

#ifdef _ROLLRATKRNL_

void _SetDebugWithStart()
{
	lgdt[1].BreakPointException = TRUE;

}

#endif

#include "leak.h"