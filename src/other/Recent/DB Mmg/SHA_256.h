/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   SHA_256.h

Project:

	RollRat DB Mmg SHA 256

------
   AUTHOR: HyunJun Jeong  2015-08-27

***************************************************************************/

#ifndef _SHA_256_
#define _SHA_256_

#ifdef __cplusplus
extern "C" {
#endif
	
typedef unsigned long  SHA_ULONG, *SHA_PULONG;
typedef unsigned char SHA_BYTE, *SHA_PBYTE;

void SHA256(const SHA_BYTE *target, SHA_ULONG len, SHA_BYTE *source);

#ifdef __cplusplus
}
#endif

#endif