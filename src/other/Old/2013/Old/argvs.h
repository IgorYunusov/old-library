/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef __argvs_apvl
#define __argvs_apvl

#include "memory.h"

#ifdef  __cplusplus
#define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
#else
#define _ADDRESSOF(v)   ( &(v) )
#endif

typedef char *va_list;

#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define va_start(ap, v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
#define va_arg(ap, t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

#endif