/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2014. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************
 *																*
 * FILE NAME : getra_apvl.h                                     *
 * CREATION  : 2014.12.19                                       *
 * MADEBY    : Jeong HyunJun(Nickname : rollrat)                *
 * E-MAIL    : rollrat@naver.com                                *
 *                                                              *
 * (C) Copyright 2014 .rollrat. All Rights Reserved             *
 *                                                              *
 ****************************************************************/

#ifndef _GETRA_APVL_
#define _GETRA_APVL_

#ifndef BIG_ENDIAN
#define CONVERT_TO_LITTLE_ENDIAN(x) ((0x000000ff & x) << 24 | (0x0000ff00 & x) << 8 | (0x00ff0000 & x) >> 8 | (0xff000000 & x) >> 24)
#else
#define CONVERT_TO_LITTLE_ENDIAN(x) x
#endif

typedef unsigned long int _ETRA_ULONG, *_ETRA_PULONG;

#define _Rotate_Left(x, r, n, t)		((t)((x) << (r)) | (t)((x) >> ((n)-(r))))
#define _Rotate_Right(x, r, n, t)		((t)((x) >> (r)) | (t)((x) << ((n)-(r))))

#define ROR_UL(x, r)					_Rotate_Right(x, r, 32, _ETRA_ULONG)
#define ROL_UL(x, r)					_Rotate_Left(x, r, 32, _ETRA_ULONG)
#define ROR_ULL(x, r)					_Rotate_Right(x, r, 64, unsigned long long)
#define ROL_ULL(x, r)					_Rotate_Left(x, r, 64, unsigned long long)

typedef unsigned long long int _ETRA_ULONGLONG, *_ETRA_ULONGLONG;

#ifdef __cplusplus
extern "C" {
#endif



#ifdef __cplusplus
}
#endif

#endif