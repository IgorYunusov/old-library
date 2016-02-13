/*************************************************************************
 *
 * FILE NAME : tcvcpu.h - Terraforming Core Virtual CPU
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

#ifndef _TCVCPU_		// [ !_TCVCPU_
#define _TCVCPU_

#include "tctype.h"

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */
	
typedef struct _tcv_temp_clock_pulse {
	u8		hz;
	u32		count;
}	tcv_clock_pulse;

#define TCV_CLOCK_PULSE_UNSIZED_HZ			0xff
	
typedef struct _tcv_temp_cpu_bus {
	u32		bus_data;
	u8		access;
}	tcv_cpu_bus;		// externel connection

		// intel cpu style
typedef struct _tcv_temp_cpu_register {
	u32		eax;
	u32		ecx;
	u32		edx;
	u32		ebx;
	u32		esp;
	u32		ebp;
	u32		esi;
	u32		edi;
	u32		eip;
	u32		efl;
}	tcv_cpu_register;

#define TCV_MAX_CACHE_SIZE		1024

typedef struct _tcv_temp_cpu_chache {
	u32		cache[TCV_MAX_CACHE_SIZE];
	u8		last_cache_addr;
}	tcv_cpu_cache;

typedef struct _tcv_temp_cpu_status {
	tcv_clock_pulse tcp;
	tcv_cpu_register tcr;
	tcv_cpu_cache tcc;
}	tcv_cpu_status;

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

void tcv_cpu_access_memory(tcv_cpu_status *tcs);
void tcv_clock_increse(tcv_clock_pulse *tcp);
u32 tcv_cpu_read_memory(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr);
void tcv_cpu_write_memory(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr, u32 value);
void tcv_cpu_load_cache(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr, u8 size);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif // ] <- _TCVCPU_