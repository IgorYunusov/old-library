/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   Structure.h

Project:

	RollRat DB Mmg Structure Header

------
   AUTHOR: HyunJun Jeong  2015-08-27

***************************************************************************/

#ifndef _STRUCTURE_
#define _STRUCTURE_

#include "Type.h"
#include <time.h>

#define IMAGE_QUREY_MAGIC	(WORD)(0x514C)

typedef struct _entry_ {
	WORD Magic;
	time_t CreationStamp;
	time_t LastestStamp;
	DWORD SizeOfAccount;
	WORD IndexStartsOf;
}	QUREY_ENTRY, *PQUREY_ENTRY;

typedef struct _account_ {
	DWORD ClassIdentifier;
	// 기본 정보
	DWORD IdentifierNumber;
	CHAR *Name;

}	QUREY_ACCOUNT, *PQUREY_ACCOUNT;

#endif