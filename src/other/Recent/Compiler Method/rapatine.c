/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   rapatine.c

Project:

   The Random Pattern Tuning Machine

------
   AUTHOR: HyunJun Jeong  2015-06-04

***************************************************************************/

#include <malloc.h>

// Standard size type.
typedef unsigned int SIZE_TYPE;

typedef unsigned long int FEATURE_TYPE;
typedef unsigned int AUTHORITY_TYPE;

typedef int  ACHIEVE;

#define IN
#define OUT


/*++

Description:

	The struture of item linked list.

--*/
typedef struct _strdef_4800b23fa1dcb92f9edaaaefdffce70d_ {

	struct _strdef_4800b23fa1dcb92f9edaaaefdffce70d_ *_Next;
	struct _strdef_4800b23fa1dcb92f9edaaaefdffce70d_ *_Prev;

	//
	//	char pointer is the same as the general pointer.
	//
	char *_Data;

}	LAPA_LLIST, *PLAPA_LLIST;



/*++

Description:

	The struture of item shunt of circle algrotihm.

--*/
typedef struct _strdef_9b6ddeba5b33e577c07c35d8505c6072_ {
	
	//
	//	Siblings
	//
	struct _strdef_9b6ddeba5b33e577c07c35d8505c6072_ *_Next;
	struct _strdef_9b6ddeba5b33e577c07c35d8505c6072_ *_Prev;

	//
	//	This variable is expressed to shorten the 
	//	local characteristics of the data.
	//
	FEATURE_TYPE _Characterisitc;

	//
	//	Storage information
	//
	PLAPA_LLIST _Storage;
	PLAPA_LLIST _StorageLast;
	SIZE_TYPE _Length;

}	LAPA_CIRCLE, *PLAPA_CIRCLE;



/*++

Description:

	The administrator of circle or column manager.

--*/
typedef struct _strdef_1d0258c2440a8d19e716292b231e3190_ {

	//
	//	Access right level arbitration.
	//
	AUTHORITY_TYPE _Authority;
	
	PLAPA_CIRCLE *_Circle;
	PLAPA_CIRCLE *_CricleLast;
	SIZE_TYPE _NumberOfCircle;

}	LAPA_CIRCLE_ADMIN, *PLAPA_CIRCLE_ADMIN;



ACHIEVE
LapaListAllocate(
	OUT PLAPA_LLIST *Target
	)
/*++

Description:

	This function safe allocate Lapa  Linked list structure. 
	And initialize pointing pointers.

Arguments:

	Target - Target pointer of allocated pointer variable.

Return Value:

--*/
{
	ACHIEVE ach;
	LAPA_LLIST *pointer = (LAPA_LLIST *)malloc(sizeof(LAPA_LLIST));

	if ( ach = pointer > 0 ) {
		pointer->_Next = 0;
		pointer->_Prev = 0;

		*Target = pointer;
	}

	return ach;
}



ACHIEVE
LapaListSwapData(
	IN OUT PLAPA_LLIST s1,
	IN OUT PLAPA_LLIST s2
	)
/*++

Description:

	This function swap data of target Linked list.

Arguments:

Return Value:

--*/
{
	ACHIEVE ach;
	char *s = s1->_Data;

	s1->_Data = s2->_Data;
	s2->_Data = s;

	return ach = 1;
}



ACHIEVE
LapaCircleAllocate(
	OUT PLAPA_CIRCLE *Target
	)
/*++

Description:

	This function safe allocate Lapa Circle structure. 
	And initialize pointing pointers.

Arguments:

	Target - Target pointer of allocated pointer variable.

Return Value:

--*/
{
	ACHIEVE ach;
	LAPA_CIRCLE *pointer = (LAPA_CIRCLE *)malloc(sizeof(LAPA_CIRCLE));
	
	if ( ach = (pointer > 0) ) {
		pointer->_Next = 0;
		pointer->_Prev = 0;
		pointer->_Length = 0;
		pointer->_Storage = 0;
		pointer->_StorageLast = 0;

		*Target = pointer;
	}

	return ach;
}



ACHIEVE
LapaCirclePushbackList(
	IN PLAPA_LLIST  List,
	IN OUT PLAPA_CIRCLE *Target
	)
/*++

Description:

	Inserts an element at the end of the list.

Arguments:

	List - Element to insert

	Target - Target pointer of circle.

Return Value:

	Whether inserts success

--*/
{
	ACHIEVE ach;
	PLAPA_CIRCLE pointer = *Target;
	LAPA_CIRCLE *LastStorage = pointer->_StorageLast;

	if ( ach = (LastStorage == 0) ) {

		LastStorage->_Next = List;
		List->_Prev = LastStorage;

		pointer->_StorageLast = List;
		pointer->_Length++;

		if ( pointer->_Storage == 0 ) {

			pointer->_Storage = LastStorage;

		}
	}

	return ach;
}



ACHIEVE
LapaFindCircleInCircle(
	IN PLAPA_CIRCLE Circle,
	IN FEATURE_TYPE Feature,
	OUT PLAPA_CIRCLE *Target
	)
/*++

Description:

	This function finds the unit circle to 
	compare the characteristics of the circle.

	Features, going to search, must have been normalized.

Arguments:

	Circle - Enter a pointer to the circle want to search.

	Feature - Normalized features.

	Target - Target pointer of finding pointer variable.

Return Value:

	Whether searching success

--*/
{
	ACHIEVE ach;
	PLAPA_CIRCLE RecusiveVar = Circle;

	ach = 0;

	if ( RecusiveVar > 0 ) {

		for ( ; RecusiveVar ; ) {

			if ( RecusiveVar->_Characterisitc == Feature ) {
				*Target = RecusiveVar;
				ach = 1;
				break;
			}

			RecusiveVar = RecusiveVar->_Next;
		}

	}

	return ach;
}