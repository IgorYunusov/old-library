/*************************************************************************
 *
 * FILE NAME : elc.h - Extbutax Lithium Carbide Project
 *
 * RollRat Compiler x4 Language Invention Compiler 
 *
 *
 * CREATION : 2014.12.23
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _ELC_
#define _ELC_

#include "cpp_begin.h"

#define _Array(t)						t*

#ifdef _DRIVER_MODE	// [ _DRIVER_MODE
#undef _Make_Number
#define _Make_Number(x)					( *( volatile long * ) (x) )
#else	// >- !_DRIVER_MODE
#endif	// ] <- _DRIVER_MODE

#ifdef _UNICODE		// [ _UNICODE
#define _USING_UNICODE			_Make_Number(1)
#define _CHAR_SET				wchar_t
#else	// >- !_UNICODE
#define _USING_UNICODE			_Make_Number(0)
#define _CHAR_SET				char
#endif	// ] <- _UNICODE

typedef _CHAR_SET	TCCHAR, *PTCCHAR;

#include "bitcon.h"

// from to linux kernel.h
#define offset_of(st, m)	((size_t)(&((st *)0)->m))
#define container_of(ptr, type, member) \
	((type *)((char *)ptr - offset_of(type, member)))
#ifdef __cplusplus
#define _typeof(x)			decltype (x)
#define _cpp
#endif

#undef near
#undef far
#define near
#define far

#define _In_
#define _Out_

#define _In_ptr_		// reference
#define _Out_prt_

		// classification accr-to-the number of bits
#include "type.h"

#ifdef __GNUC__
#define USING_COMPILER	1
#define COMPILER_NAME	"GCC"
#elif defined(_MSC_VER)
#define USING_COMPILER	2
#define COMPILER_NAME	"Microsoft"
#elif defined(__INTEL_COMPILER)
#define USING_COMPILER	3
#define COMPILER_NAME	"Intel"
#elif defined(__Turbo-c___)
#define USING_COMPILER	4
#define COMPILER_NAME	"Turbo -C"

#endif

/********************************************************************
 *
 *		ELC Data Type Declaration
 *
 ********************************************************************/

typedef unsigned long  SHA_ULONG, *SHA_PULONG;
typedef unsigned char SHA_BYTE, *SHA_PBYTE;

#pragma pack( push, 1 )		// byte padding for kernel output

//
// @ SHA 256 Only way encryption
// @ Context Structure
//
typedef struct _sha256_context {
	SHA_ULONG outdexs[8];
	SHA_BYTE buffer[64];
	SHA_ULONG residue, inces;
}	SHA256_CONTEXT, *PSHA256_CONTEXT;

#pragma pack( pop )

void SHA256(const SHA_BYTE *target, SHA_ULONG len, SHA_BYTE *source);

//
// @ Master Cluster
// @ The contents of this cluster is a basic support functions of C4LiC.
//
typedef struct _master_cluster {
	int length; // size of cluster
}	MASTER_CLUSTER, *PMASTER_CLUSTER;

// make cluster
#define BEGIN_CLUSTER(name) typedef struct name {
#define END_CLUSTER(name) } name, P##name;

#pragma pack( push, 1 )		// byte padding for kernel output

//
// @ Attribute
// @ Language invention basic attribute structure
//
typedef struct _attribute {
	
	/* Basic Syntax Setup */
	BOOL ifextVariableSyntax;
	BOOL ifextJumpSyntax;
	BOOL ifMultiline;

	/* Visual String Setup */
	int isVisualString; // language string type
	DWORD CustomVisualString;
	CHAR * Custom2VisualString;
	
	/* Entry Point Setup */
	int setupEntry;
	BOOL ifextEntryPoint;
	CHAR * epSetup; // entry point setup function text ptr
	
	/* Include Library Setup */
	BOOL ifincLib;
	int incLibSize;
	_Array(CHAR *) txLib;
	
	/* Linker */
	DWORD opLinker; // link option

	/* Compiler */
	DWORD ifextopCompiler;
	PCHAR opCompiler; // Delimiter: ' ' , the space

	// Using Extended Attribute
	BOOL ifextExtendAttribute;

}	Attribute, *PAttribute;

#pragma pack( pop )

#define ELSYNTAX_BEGINELC		".BEGIN_ELC"
#define ELSYNTAX_ENDELC			".END_ELC"

BEGIN_CLUSTER(_xelc1_)
	// Variable Cluster

	DWORD dwOption;
	DWORD makeAep; // Aep[Correlation of files]

	DWORD onlyOption; // Set run at specific cpu or environment
	
	// check vitality of cluster
	BOOL vitality;

	int clustersize;

	Attribute * incluster;
END_CLUSTER(XELC1)

#pragma pack( push, 1 )		// byte padding for kernel output

//
// @ ELC Error Chip Option
// @ Error chip option
//
typedef enum _error_chip_option_ {
	errorCommon=1,
	errorLinktoline,
	errorNotStandard,
	errorWarning,
	errorImplicit,
	errorGrammar,
}	ECOption;

//
// @ ELC Error Chip
// @ Error chip
//
typedef struct _error_chip_ {
	DWORD dwErrorCode;
	CHAR * msgError; // ELC Error Format
	int length;
	ECOption errorType;
}	ErrorChip, *PErrorChip;

//
// @ ELC Make error
// @ Make error structure
//
typedef struct _error_ {

	/* inter error */ // using{ .Use[InterError] }
	BOOL opUsingInterError;

	_Array(ErrorChip) errors;
	int length;

	/* how to check error */
	DWORD responsiv_element;

}	 Error, *PError;

#pragma pack( pop )

#define ELSYNTAX_BEGINERROR		".BEGIN_ERROR"
#define ELSYNTAX_ENDERROR		".END_ERROR"

BEGIN_CLUSTER(_xelc2_)
	// Cluster for Error
	
	DWORD dwOption;
	DWORD makeAep; // Aep[Correlation of files]

	DWORD onlyOption; // Set run at specific cpu or environment
	
	// check vitality of cluster
	BOOL vitality;

	int clustersize;

	Error * incluster;
END_CLUSTER(XELC2)

#pragma pack( push, 1 )		// byte padding for kernel output

#define _and(x, y)		(x && y)
#define _or(x, y)		(x || y
#define __and(x, y, z)		((x && y) && z)
#define __or(x, y, z)		((x || y) || z)

#define zeroset(dst, size)		memset(dst, 0, size)

#include "cpp_end.h"

#endif