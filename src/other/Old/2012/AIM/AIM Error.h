/*--------------------------------------------------------------------

		AIM Library
		(Another Imaginary Management)

		Copyright (c) Kuroko_decs. 2013. All rights reserved.

--------------------------------------------------------------------*/

#pragma once

#ifndef _AIM_LIB_ERROR
#define _AIM_LIB_ERROR

/*********************************************************************

	AIM Library Error List
	
	Note : This header is present for more accurate error checking.

	+--+-----------------+------------+---------------+
	|S |	    V	     |     O.C    |		  O		  |
	+--+-----------------+------------+---------------+
	|19|18|17|16|15|14|13|12|11|10|9|8|7|6|5|4|3|2|1|0|
	+--+-----------------+------------+---------------+
	

	Read Direction.
	<<-----------------------------------------------<<


	<LIST OBJECT INFOMATION>

		S	:  True or False

			0 : Success
			1 : Error
	
		V	: Variable
		
		O.C : Object Complement(Flages, Segment, Serial, ...)

		O	: Object


*********************************************************************/

#define SUBJECT_SUCCESS				0x00000L
#define SUBJECT_ERROR				0x80000L

//		OBJECT COMPLEMENT LIST
#define OC_FLAGS_PARITYZERO			0x00500L	// 101
#define OC_FLAGS_PARITYODD			0x00600L
#define OC_FLAGS_CHECKXOR			0x00700L	// 00700 International Call. Sorry

//
//	Serial Number : 1
//
//	Message : 
//
//	Succeceful!
//
#define ERROR_SUCCECEFUL			0x00000L

//
//	Serial Number : 2
//
//	Message :
//
//	Incorrect Value!
//
#define ERROR_INCORRECT_VALUE		(0x00001L	|	SUBJECT_ERROR)

//
//	Serial Number : 3
//
//	Message :
//
//	Incorrect Pointer!
//
#define ERROR_INCORRECT_POINTER		(0x00002L	|	SUBJECT_ERROR)

//	Tip : In any case, CPU process one command each one clock.

//
//	Serial Number : 4
//
//	Message :
//
//	Check the Corrector!
//
#define ERROR_CHECK_CORRECTOR		(0x00003L	|	SUBJECT_ERROR)

//
//	Serial Number : 5
//
//	Message :
//
//	Unenabled Value!
//
#define ERROR_VALUE_UNENALBE		(0x00004L	|	SUBJECT_ERROR)

//
//	Serial Number : 6
//
//	Message :
//
//	Created Many Array!
//
#define ERROR_CREATE_ARRAY			(0x00005L	|	SUBJECT_ERROR)

//
//	Serial Number : 7
//
//	Message :
//
//	Succeceful Used!
//
#define ERROR_USED					0x00006L

//
//	Serial Number : 8
//
//	Message :
//
//	Template Cast Error!
//
#define ERROR_TEMPLATE_CAST			(0x00007L	|	SUBJECT_ERROR)

#endif