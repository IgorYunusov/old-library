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

#pragma once

#ifndef __VCEFFLINK
#define __VCEFFLINK

#include "vceffmem.h"

#ifndef __onlyc
template<class _Ty>
struct _tag_VCEFF_linked_list
{
	struct _tag_VCEFF_linked_list *Next;
	struct _tag_VCEFF_linked_list *Prev;
	_Ty Data;
};
#else	// Don't Used this.
struct _tag_VCEFF_linked_list
{
	struct _tag_VCEFF_linked_list *Next;
	struct _tag_VCEFF_linked_list *Prev;
	int _d_type;
	void *Data;
};
#endif


#endif