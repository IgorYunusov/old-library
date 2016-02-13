/*************************************************************************
 *
 * FILE NAME : tcvram.h - Terraforming Core Virtual RAM
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

#ifndef _TCVRAM_		// [ !_TCVRAM_
#define _TCVRAM_

#include "tctype.h"
#include "tcvclock.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#define TCV_RAM_FLAG_READ_ONLY		0x01
#define TCV_RAM_FLAG_NO_READ		0x02

#define TCV_RAM_ACCESS_NONE			0x00
#define TCV_RAM_ACCESS_REQUEST_OPEN	0x01
#define TCV_RAM_ACCESS_READ_ACCEPT	0x02
#define TCV_RAM_ACCESS_WRITE_ACCEPT	0x03


typedef struct _tcv_ram_temp_cell {
	u32		cell;
	u8		flag;
}	tcv_ram_cell;

#ifndef _TCV_RAM_SIZE	// [ !_TCV_RAM_SIZE
#define _TCV_RAM_SIZE	1024*1024
#endif	// ] <- _TCV_RAM_SIZE

typedef struct _tcv_ram_temp_memory {
	tcv_ram_cell	memory[_TCV_RAM_SIZE];
	u8				access;
}	tcv_ram;

tcv_ram tcv_ram_init();
void tcv_ram_request_open(tcv_ram *tr, tcv_cpu_status *tcs);
void tcv_ram_request_close(tcv_ram *tr, tcv_cpu_status *tcs);
void tcv_ram_request_read_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs);
void tcv_ram_request_write_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs);
void tcv_ram_read_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs, u32 *value);
void tcv_ram_write_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs, u32 value);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // ] <- _TCVRAM_