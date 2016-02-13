/*--------------------------------------------------------------------

		AIM Library
		(Another Imaginary Management)

		Copyright (c) Kuroko_decs. 2013. All rights reserved.

--------------------------------------------------------------------*/

#pragma once

#ifndef _AIM_LIB_CORE
#define _AIM_LIB_CORE

#define Far			// Appropriate Distance
#define Near

#define TOKEN		// List token

// Bool
#define TRUE		1
#define FALSE		0

#define STRUCTURE				struct			// simply..
#define ENUMERATE				enum
#define TEMPLATE				template
#define CLASS					class

#define ref

#define Target_c					// target sign

typedef unsigned long			size;

// Check List Korean Sign, Non stop step
#ifndef _CRT_CHECK_LISTKORSIGN_NONSTOP
#define _CCLN_001
#endif /* _CRT_CHECK_LISTKORSIGN_NONSTOP End */

#if defined(_CRT_UNENABLE_FORCEINLINE)
#if !defined(_CRT_UNENABLE_FORCEINLINE_THEN_USE_INLINE)
#define FORCEINLINE
#else /* !_CRT_UNENABLE_FORCEINLINE_THEN_USE_INLINE */
#define FORCEINLINE		inline
#endif /* _CRT_UNENABLE_FORCEINLINE_THEN_USE_INLINE End */
#else /* !_CRT_UNENABLE_FORCEINLINE */
#define FORCEINLINE		__forceinline
#endif /* _CRT_UNENABLE_FORCEINLINE End */

#if (1600 <= _MSC_VER)
#define CPP_0X_FLAG
#endif /* _MSC_VER End >= 1700 */

#if _WIN64
#define _CCLN_006	1
#endif /* _WIN64 End */

#if !defined(_CRT_CHECK_NOALGORITHM) && !defined(_CRT_CHECK_CONTROL_CLONE)
#define CALL_BY_NAL_CORE
#include "Algorithm.h"
#else /* !_CRT_CHECK_NOALGORITHM */
#define _CCLN_007
#endif /* _CRT_CHECK_NOALGORITHM End */

#if !defined(_CRT_CHECK_NOUTILITY)
#include "ExUtil.h"
#else /* !_CRT_CHECK_CONTROL_CLONE */
#define _EXU_NOUSE
#endif /* _CRT_CHECK_CONTROL_CLONE End */

#if !defined(_CRT_CHECK_CONTROL_NOERROR)
#include "AIM Error.h"
#else /* !_CRT_CHECK_CONTROL_NOERROR */
#define _CCLN_002
#endif /* _CRT_CHECK_CONTROL_NOERROR End */

#if !defined(_CRT_CHECK_CONTROL_CLONE) && !defined(_CRT_CHECK_NOALGORITHM)
#include "AIM Clone.h"
#else /* !_CRT_CHECK_CONTROL_CLONE */
#define _CCLN_003
#endif /* _CRT_CHECK_CONTROL_CLONE End */

#if !defined(_CRT_CHECK_EXARRAY)
#include "exArray.h"
#else /* !_CRT_CHECK_EXARRAY */
#define _CCLN_008
#endif /* _CRT_CHECK_EXARRAY End */

#if defined(_CRT_CHECK_NOALGORITHM) && !defined(_CRT_CHECK_CONTROL_CLONE)
#error CAN'T USE CLONE LIBRARY !
#endif

#if !defined(_CRT_CHECK_CONTROL_NOERROR)
// S : 1bit, V : 6bit, OC : 5bit, O : 8bit 
#define MAKE_ERROR(S, V, OC, O)		S << 19 | V << 13 | OC << 8 | O
// Extraction Error Code
#define GET_ERROR_SUBJECT(S)	S	>>	19
#define GET_ERROR_VARIABLE(V)	V	&	0x7E600 >> 13
#define GET_ERROR_OBJECTC(OC)	OC	&	0x01F00 >> 8
#define GET_ERROR_OBJECT(O)		O	&	0x000FF
#else /* _CRT_CHECK_CONTROL_NOERROR Else */
#define MAKE_ERROR(S, V, OC, O)		0
#define GET_ERROR_SUBJECT(S)		0
#define GET_ERROR_VARIABLE(V)		0
#define GET_ERROR_OBJECTC(OC)		0
#define GET_ERROR_OBJECT(O)			0
#endif /* _CRT_CHECK_CONTROL_NOERROR End */

#if defined(_CRT_CHECK_LISTKORSIGN_USEVIRTUALVARIABLE)
#define _CCLN_004
#else /* !_CRT_CHECK_LISTKORSIGN_USEVIRTUALVARIABLE */
#if !defined(_CRT_CHECK_NOUSEOF_VIRTUALVARIABLE)
#define _USE_VV			TRUE
#else /* !_CRT_CHECK_NOUSEOF_VIRTUALVARIABLE */
#define _USE_VV			FALSE
#endif /* _CRT_CHECK_NOUSEOF_VIRTUALVARIABLE End */
#endif /* _CRT_CHECK_LISTKORSIGN_USEVIRTUALVARIABLE End */

#if defined(_CRT_CHECK_USE_DEBUG_ERRORSIGN)
#define _CCLN_004
#endif /* _CRT_CHECK_USE_DEBUG_ERRORSIGN End */

#ifdef __cplusplus
extern "C" {
#endif

//===================================================================
//	BOOL													 <=130803
//===================================================================
#if !defined(_CRT_NOUSEOF_ENUM_FORBOOL)
typedef ENUMERATE _ENU_BOOLEAN{
	True = 1,
	False = 0,
}	BOOL;
#else
typedef int BOOL;
#endif

//===================================================================
//	HANDLE													 <=130803
//===================================================================
typedef STRUCTURE _SERVICING_HANDLE{
	unsigned int handle;
	BOOL parent;			// if parent is existed
	unsigned int hParent;	// parent Handle
}	HANDLE, *HANDLE_PTR;

//===================================================================
//	HANDLER													 <=130803
//===================================================================
typedef STRUCTURE _PORTING_HANDLE{
	HANDLE host;
	void *PORTING_Thing;
	size sizeofPorting;
}	HANDLER, *HANDLER_PTR;

//===================================================================
//	POINT													 <=130803
//===================================================================
typedef STRUCTURE _PICTUREING_POSITION{
	int x, y;
}	POINT, *LPPOINT;

//===================================================================
//	POSITION												 <=130803
//===================================================================
typedef STRUCTURE _DIRECTERING_POSITION{
	int x, y, z;
}	POSITION, *LPPOSITION;

//===================================================================
//	POSITION												 <=130803
//===================================================================
typedef STRUCTURE _SERVICING_EVENT{
	HANDLE hEvent;
	HANDLER pTs;
}	EVENT, *LPEVENT;

#ifndef _CRT_CHECK_MIKOTO_CLONE
#define _CCLN_005
#else /* !_CRT_CHECK_MIKOTO_CLONE */
#define _CCLN_005	1L
#endif /* _CRT_CHECK_MIKOTO_CLONE End */

#ifndef _CRT_CHECK_VIRTUAL_SPACE
#define _CCLN_006
#endif  /* _CRT_CHECK_VIRTUAL_SPACE End */

#if defined(CPP_0X_FLAG)
#define NULL		nullptr
#else
#define NULL		0
#endif

FORCEINLINE
Far
void 
InitPos(
	ref LPPOSITION pPos
	);

FORCEINLINE
Far
void
InitPoint(
	ref LPPOINT pPoint
	);

FORCEINLINE 
Near
void 
InitHandle(
	ref HANDLE_PTR hHandle
	);

FORCEINLINE
Far
void
InitEvent(
	ref LPEVENT evEvnet
	);

FORCEINLINE
Far
void
InitHandler(
	ref HANDLER_PTR hHandler
	);

//===================================================================
//	HANDLE SIGN												 <=130804
//===================================================================
typedef ENUMERATE _ENU_HANDLE_SIGN{
	Equal	=	0,
	Parent  =	1,
	Child	=	2,
	Nothing =	3,
}	HSIGN;

FORCEINLINE
Near
HSIGN
InquiryHandle(
	Target_c const HANDLE hLeft,
	const HANDLE hRight
	);

FORCEINLINE
Near
void
SetHandle(
	HSIGN hsSigh,
	Target_c ref HANDLE_PTR hLeft,
	ref HANDLE_PTR hRight
	);

FORCEINLINE
Near
void
SetHandleParent(
	Target_c ref HANDLE_PTR hLeft,
	ref HANDLE_PTR hRight
	);

FORCEINLINE
Near
void
SetHandleChild(
	Target_c ref HANDLE_PTR hLeft,
	ref HANDLE_PTR hRight
	);

#ifdef __cplusplus
}
#endif

//===================================================================
//	LIST NODE												 <=130805
//===================================================================
TEMPLATE<class _Are> 
CLASS _CLS_LIST_NODE{
	_Are data;
	_CLS_LIST_NODE* _next;
	_CLS_LIST_NODE* _prev;
	};



#endif