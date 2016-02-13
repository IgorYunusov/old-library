#include "tcvcpu.h"
#include "tcvram.h"

static
tcv_ram tcv_ram_init()
{
	tcv_ram ram;

	/* open and close access right set.
	*/
	ram.access = TCV_RAM_ACCESS_NONE;

	return ram;
}

static
void tcv_ram_request_open(tcv_ram *tr, tcv_cpu_status *tcs)
{
	tcv_clock_increse(&tcs->tcp);
	(*tr).access = TCV_RAM_ACCESS_REQUEST_OPEN;
}

static
void tcv_ram_request_close(tcv_ram *tr, tcv_cpu_status *tcs)
{
	tcv_clock_increse(&tcs->tcp);
	(*tr).access = TCV_RAM_ACCESS_NONE;
}

static
void tcv_ram_request_read_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs)
{
	tcv_ram_request_open(tr, tcs);

	if( (*tr).access == TCV_RAM_ACCESS_REQUEST_OPEN ) {
		if( !((*tr).memory[(*tcb).bus_data].flag 
			& TCV_RAM_FLAG_NO_READ) ) {
			(*tr).access = TCV_RAM_ACCESS_READ_ACCEPT;		// read accept.
			return;
		}
	}
	
	tcv_ram_request_close(tr, tcs);
}

static
void tcv_ram_request_write_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs)
{
	tcv_ram_request_open(tr, tcs);

	if( (*tr).access == TCV_RAM_ACCESS_REQUEST_OPEN ) {
		if( !((*tr).memory[(*tcb).bus_data].flag 
			& TCV_RAM_FLAG_READ_ONLY) ) {
			(*tr).access = TCV_RAM_ACCESS_WRITE_ACCEPT;		// write accept.
			return;
		}
	}
	
	tcv_ram_request_close(tr, tcs);
}

static
void tcv_ram_read_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs, u32 *value)
{
	tcv_clock_increse(&tcs->tcp);

	if( (*tr).access == TCV_RAM_ACCESS_READ_ACCEPT ) {
		*value = (*tr).memory[(*tcb).bus_data].cell;
	}

	tcv_ram_request_close(tr, tcs);
}

static
void tcv_ram_write_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs, u32 value)
{
	tcv_clock_increse(&tcs->tcp);

	if( (*tr).access == TCV_RAM_ACCESS_WRITE_ACCEPT ) {
		(*tr).memory[(*tcb).bus_data].cell = value;
	}

	tcv_ram_request_close(tr, tcs);
}