/*************************************************************************
 *
 * FILE NAME : defines.h - Terraforming Core
 *
 * RollRat Terraforming Core
 *
 *
 * CREATION : 2014.12.05
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _TERRAFORMING_DEFINES_
#define _TERRAFORMING_DEFINES_

#define VOLATILE		volatile

// TC unit
typedef VOLATILE int			INT, *INT_PTR;
typedef VOLATILE unsigned int	UINT, *UINT_PTR;
typedef VOLATILE char			CHAR, *PCHAR;

#define MAKE_UINT(_numberic)	( *( ( UINT_PTR ) _numberic) )
#define MAKE_INT(_numberic)		( *( ( INT_PTR  ) _numberic) )
#define MAKE_TYPE(_type, _target) ( *( ( _type ) _target) )

typedef VOLATILE unsigned char SBCS, BYTE;
typedef VOLATILE unsigned short MBCS, WORD;
typedef VOLATILE unsigned long DWORD;	// LLP64 Only

typedef VOLATILE int			BOOL;

#ifndef TRUE
#define TRUE					0
#else
#undef TRUE
#define TRUE					0
#endif

#ifndef FALSE
#define FALSE					1
#else
#undef FALSE
#define FALSE					1
#endif

#define MAKE_CHARSET(sbcs_u, sbcs_l) ( ((sbcs_u&4) << 4) | (sbcs_l&4) )


#endif