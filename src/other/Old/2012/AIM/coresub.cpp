/*--------------------------------------------------------------------

		AIM Library
		(Another Imaginary Management)

		Copyright (c) Kuroko_decs. 2013. All rights reserved.

--------------------------------------------------------------------*/

#include "AIM Core.h"

FORCEINLINE
void 
InitPos(
	ref LPPOSITION pPos
	)
{ // init position
	pPos->x = 0;
	pPos->y = 0;
	pPos->z = 0;
	return;
}

FORCEINLINE
void
InitPoint(
	ref LPPOINT pPoint
	)
{ // init point
	pPoint->x = 0;
	pPoint->y = 0;
	return;
}

FORCEINLINE 
void 
InitHandle(
	ref HANDLE_PTR hHandle
	)
{ // inint Handle
	hHandle->handle = 0;
	hHandle->hParent = 0;
#ifndef _CRT_NOUSEOF_ENUM_FORBOOL
	hHandle->parent = BOOL::False;
#else
	hHandle->parent = 0;
#endif
	return;
}

FORCEINLINE
void
InitEvent(
	ref LPEVENT evEvent
	)
{ // init event
	InitHandle(&evEvent->hEvent);
	InitHandle(&evEvent->pTs.host);
	evEvent->pTs.PORTING_Thing = 0;
	evEvent->pTs.sizeofPorting = 0;
}

FORCEINLINE
void
InitHandler(
	ref HANDLER_PTR hHandler
	)
{ // init handler
	InitHandle(&(hHandler->host));
	hHandler->PORTING_Thing = 0;
	hHandler->sizeofPorting = 0;
	return;
}

FORCEINLINE
HSIGN
InquiryHandle(
	const HANDLE hLeft,
	const HANDLE hRight
	)
{ // inquiry hadnle
	if(hLeft.handle == hRight.handle)
		return HSIGN::Equal;
	else if(hLeft.parent)
		if(hLeft.hParent == hRight.handle)
			return HSIGN::Child;
		else
			return HSIGN::Nothing;
	else
		if(hRight.parent)
			if(hLeft.handle == hRight.hParent)
				return HSIGN::Parent;
			else
				return HSIGN::Nothing;
		else
			return HSIGN::Nothing;
}

FORCEINLINE
void
SetHandle(
	HSIGN hsSigh,
	ref HANDLE_PTR hLeft,
	ref HANDLE_PTR hRight
	)
{ // set handle
	switch(hsSigh)
	{
	case HSIGN::Equal:
		hLeft->handle = hRight->handle;
		return;
	case HSIGN::Parent: // right as a parent
		hRight->parent = BOOL::True;
		hRight->hParent = hLeft->handle;
		return;
	case HSIGN::Child: // left as a child
		hLeft->parent = BOOL::True;
		hLeft->hParent = hRight->handle;
		return;
	case HSIGN::Nothing: // only left
		hLeft->parent = BOOL::False;
		hLeft->hParent = (int)NULL;
		return;
	}
}

FORCEINLINE
void
SetHandleParent(
	Target_c ref HANDLE_PTR hLeft,
	ref HANDLE_PTR hRight
	)
{ // set handle parent
	SetHandle(HSIGN::Parent, hLeft, hRight);
	return;
}

FORCEINLINE
void
SetHandleChild(
	Target_c ref HANDLE_PTR hLeft,
	ref HANDLE_PTR hRight
	)
{ // set child parent
	SetHandle(HSIGN::Child, hLeft, hRight);
	return;
}