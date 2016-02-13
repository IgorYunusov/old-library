/*
 *
 *			ROLLRAT SOFTWARE SUBROUTINE
 *			SINCE : 2009 - 2012
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#pragma once
#if !defined(_r_stack_)
#define _r_stack_
#define _r_retype_def_mjk_
#include "rapiasc.h"
#include "rdefine.h"

__archi { 
	UINT boolean;
	__charp	bool_ret;
	__char	STACKT	[ enough_stack_char ];
}	STACK;
VOID StackReset(CHAR CHARG)
{
	UINT i=0;
	__for(;;)
	{
		CHARG[i++] = '\0';
		__if(i == enough_stack_char - 1)
			__brk;
	}
}
STACK * Stack(STACK * Items,UINT Address,CHAR Type)
{
	__static STACK p;
	UINT lenth;
	__if(Type[0] == 'U')
	{
	__if(Address == 0)
		StackReset(p.STACKT);
	p.STACKT[ Address ] = Items;
	__if(Type[1] == 'a')
	{
		__ret p.STACKT[ Address ];
	}
	__ifelse(Type[1] == 'p')
	{
		__ret p.STACKT[ --Address ];
	}
	__ifelse(Type[1] == 'n')
	{
		__ret p.STACKT[ ++Address ];
	}
	__ifelse(Type[1] == 's')
	{
		__ret p.STACKT;
	}
	}
	__ifelse(Type[0] == 'F')
	{
		lenth = GetCharValue(p.STACKT);
		p.STACKT[ --lenth ] = 0;
		__ret p.STACKT;
	}
	__ifelse(Type[0] == 'L')
	{

	}
}
STACK * StackAddress(UINT StackAddress)
{
	__ret StackAddress;
}

STACK * StackItems(__char item)
{
	__ret item;
}

#endif