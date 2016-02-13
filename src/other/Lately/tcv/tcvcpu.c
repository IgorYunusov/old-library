#include "tcvcpu.h"

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

static
tcv_clock_pulse tcv_clock_init()
{
	tcv_clock_pulse tcp_new;

	/* tcp'hz is not operted in tcvcpu. 
	*/
	tcp_new.hz = TCV_CLOCK_PULSE_UNSIZED_HZ;
	tcp_new.count = 0;

	return tcp_new;
}

static
void tcv_cpu_init(tcv_cpu_status *tcs)
{
	(*tcs).tcp = tcv_clock_init();
}

static
void tcv_clock_increse(tcv_clock_pulse *tcp)
{
	(*tcp).count += 1;
}

static
u32 tcv_cpu_read_memory(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr)
{
	tcv_cpu_bus tcb;
	u32 value;

	tcv_clock_increse(&tcs->tcp);

	tcb.bus_data = addr;

	tcv_ram_request_read_memory(tr, &tcb, tcs);
	tcv_ram_read_memory(tr, &tcb, tcs, &value);

	return value;
}

static
void tcv_cpu_write_memory(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr, u32 value)
{
	tcv_cpu_bus tcb;
	
	tcv_clock_increse(&tcs->tcp);

	tcb.bus_data = addr;

	tcv_ram_request_write_memory(tr, &tcb, tcs);
	tcv_ram_write_memory(tr, &tcb, tcs, value);
}

static
void tcv_cpu_load_cache(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr, u8 size)
{
	u8 v;

	tcv_clock_increse(&tcs->tcp);

	if (size > TCV_MAX_CACHE_SIZE)
		return;

	for(v = 0; v < size; v++) {
		u32 value;

		value = tcv_cpu_read_memory(tcs, tr, addr + v);

		(*tcs).tcc.cache[v] = value;
	}
}