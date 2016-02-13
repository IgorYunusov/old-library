/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   matrix.h - [Private]
   
Abstract:

   Matrix calculation module

------
   AUTHOR: HyunJun Jeong  2015-01-23

***************************************************************************/

#ifndef _LINEAR_
#define _LINEAR_

#include "type.h"

typedef struct _tag_matrix_ {
	void **_Data;
	DWORD width, height;
	OPTION type;
}	INTER_MATRIX, *PINTER_MATRIX;


#define MATRIX_OPTION_I					0x00	// int
#define MATRIX_OPTION_L					0x01	// long
#define MATRIX_OPTION_LL				0x02	// long long
#define MATRIX_OPTION_U					0x04	// unsigned
#define MATRIX_OPTION_S					0x08	// short
#define MATRIX_OPTION_F					0x10	// float
#define MATRIX_OPTION_D					0x20	// double

#endif