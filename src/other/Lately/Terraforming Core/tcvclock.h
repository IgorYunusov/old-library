/*************************************************************************
 *
 * FILE NAME : tcvclock.h - Terraforming Core Virtual Clock Pulse
 *
 * RollRat Terraforming Core
 *
 *
 * CREATION : 2014.12.11
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

/*
	The RollRat Terraforming Core Native Source
 */

#ifndef _TCVCLOCK_		// [ !_TCVCLOCK_
#define _TCVCLOCK_

#include "tctype.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

typedef struct _tcv_temp_clock_pulse {
	u8		hz;
	u32		count;
}	tcv_clock_pulse;

#define TCV_CLOCK_PULSE_UNSIZED_HZ			0xff
	
#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // ] <- _TCVCLOCK_