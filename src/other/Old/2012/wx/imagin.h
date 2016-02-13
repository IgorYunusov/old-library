/***********************************************************************
 ***********************************************************************
 ***********************************************************************
 *******														 *******
 *******	ROLLRAT SOFTWARE									 *******
 *******														 *******
 *******	IMAGIN												 *******
 *******														 *******
 ***********************************************************************
 *********************************************************************** 
 ***********************************************************************/


//					NATURAL	LAWS

#ifndef _IMAGIN
#define _IMAGIN

#define VELOCITY( Whole_Travel_Range, Time ) Whole_Travel_Range / Time
#define SPEED( Displacement, Time ) Displacement / Time

#define ACCELERATION(v, v0, t)	(v - v0) / t

#define EQUIVALENT_VELOCITY_V( v0, a, t ) v0 + a * t
#define EQUIVALENT_VELOCITY_S( v0, a, t ) v0 * t + a * t * t / 2



#endif

// RollRat Software WX Library
// Copyright (c) rollrat. 2013. ALL RIGHTS RESERVED.