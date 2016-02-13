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
#if !defined(__R_STD_SET__)
#define __R_STD_SET__

/* String Set */
#define LastChar '\0'

/* Bool Set */
#define TRUE	1
#define FALSE	0


/* File Set */
#define WriteOnly	"w"
#define WritePlus	"w+"
#define ReadOnly	"r"
#define ReadPlus	"r+"
#define ReadWrite	"rw"

/* JMP	Set */
#define NullWhile	while(  )
#define NullFor		for( ;; )
#define InfLoop		while(1)

/* Others */
#define IncludeC	extern("C")

#endif