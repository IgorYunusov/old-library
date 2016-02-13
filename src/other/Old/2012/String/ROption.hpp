/*******************************************************************\
 *																   *
 *				ROption.hpp -- rollrat Option.					   *
 *																   *
 *																   *
 *			Copyright (c) rollrat. All rights reserved.			   *
 *																   *
\*******************************************************************/

#pragma once
#ifndef _ROLLRAT_OPTION_
#define _ROLLRAT_OPTION_

typedef enum ENU_COMPILEOPTION_COMS
{
	None			= 0x0000,
	Task			= 0x0001,
	Hardcording		= 0x0002,
} COMPILEOPTION, *PTR_COMPILEOPTION ;

typedef enum ENU_COMPILEOPTION_TAKES
{
	LL = 1,
	LR = 2,
	RL = 3,
	RR = 4
} COMPILEOPTION_TAKE, *PTR_COMPILEOPTION_TAKE ;

typedef struct TAD_OPTIONHEADER_COMS
{
	COMPILEOPTION		CPL;
	COMPILEOPTION_TAKE	CPLT;
} OPTIONHEADER, *PTR_OPTIONHEADER ;

#endif