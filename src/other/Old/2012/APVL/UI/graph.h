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


#ifndef __APVL_GRAPH
#define __APVL_GRAPH

#ifdef  __cplusplus
#define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
#else
#define _ADDRESSOF(v)   ( &(v) )
#endif

#define UIGraphMemberSet	static
typedef unsigned long long	UIGraphHandle;

#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )
#define va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

#define UIGraph_Error					0x7000000F

typedef unsigned short UIGraphVersion;
typedef unsigned long UIGraphLVersion;

// Must Cast Before !!
#define UIGraphVersionCheck( vs1, vs2 ) \
	(UIGraphLVersion)(vs1) << 4 | (UIGraphVersion)(vs2)


// Rollrat Unlimited Intervene Graph Library 1.0
// [ FIRST I ]

#define FIUI_Version	UIGraphVersionCheck( 0x00, 0x01 )

#define FI_UIGraphVersionCheckSuccess	0x80000002

typedef unsigned long FI_UIGraphRequest;
typedef struct _tag_REQUEST_edc
{ // request
	FI_UIGraphRequest		HighMessage;
	FI_UIGraphRequest		LowMessage;
} FIUIG_Request,	*PFIUIG_Request;




#endif