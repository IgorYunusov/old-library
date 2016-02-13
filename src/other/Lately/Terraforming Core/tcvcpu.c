#include "tcvcpu.h"


// RAM AREA
/////////////////////////////////////////////////////////////////////////////////////////


tcv_ram tcv_ram_init()
{
	tcv_ram ram;

	/* open and close access right set.
	*/
	ram.access = TCV_RAM_ACCESS_NONE;

	return ram;
}


void tcv_ram_request_open(tcv_ram *tr, tcv_cpu_status *tcs)
{
	tcv_clock_increse(&tcs->tcp);
	tr->access = TCV_RAM_ACCESS_REQUEST_OPEN;
}


void tcv_ram_request_close(tcv_ram *tr, tcv_cpu_status *tcs)
{
	tcv_clock_increse(&tcs->tcp);
	tr->access = TCV_RAM_ACCESS_NONE;
}


void tcv_ram_request_read_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs)
{
	tcv_ram_request_open(tr, tcs);

	if( tr->access == TCV_RAM_ACCESS_REQUEST_OPEN ) {
		if( !(tr->memory[tcb->bus_data].flag 
			& TCV_RAM_FLAG_NO_READ) ) {
			tr->access = TCV_RAM_ACCESS_READ_ACCEPT;		// read accept.
			return;
		}
	}
	
	tcv_ram_request_close(tr, tcs);
}


void tcv_ram_request_write_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs)
{
	tcv_ram_request_open(tr, tcs);

	if( tr->access == TCV_RAM_ACCESS_REQUEST_OPEN ) {
		if( !(tr->memory[tcb->bus_data].flag 
			& TCV_RAM_FLAG_READ_ONLY) ) {
			tr->access = TCV_RAM_ACCESS_WRITE_ACCEPT;		// write accept.
			return;
		}
	}
	
	tcv_ram_request_close(tr, tcs);
}


void tcv_ram_read_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs, u32 *value)
{
	tcv_clock_increse(&tcs->tcp);

	if( (*tr).access == TCV_RAM_ACCESS_READ_ACCEPT ) {
		*value = tr->memory[tcb->bus_data].cell;
	}

	tcv_ram_request_close(tr, tcs);
}


void tcv_ram_write_memory(tcv_ram *tr, tcv_cpu_bus *tcb, tcv_cpu_status *tcs, u32 value)
{
	tcv_clock_increse(&tcs->tcp);

	if( tr->access == TCV_RAM_ACCESS_WRITE_ACCEPT ) {
		tr->memory[tcb->bus_data].cell = value;
	}

	tcv_ram_request_close(tr, tcs);
}




// CPU AREA
/////////////////////////////////////////////////////////////////////////////////////////


tcv_clock_pulse tcv_clock_init()
{
	tcv_clock_pulse tcp_new;

	/* tcp'hz is not operted in tcvcpu. 
	*/
	tcp_new.hz = TCV_CLOCK_PULSE_UNSIZED_HZ;
	tcp_new.count = 0;

	return tcp_new;
}


void tcv_cpu_init(tcv_cpu_status *tcs)
{
	tcs->tcp = tcv_clock_init();
	tcs->tcc.last_cache_addr = 0;

	tcs->tcr.eax = 0;
	tcs->tcr.ecx = 0;
	tcs->tcr.edx = 0;
	tcs->tcr.ebx = 0;
	tcs->tcr.esp = 0;
	tcs->tcr.ebp = 0;
	tcs->tcr.esi = 0;
	tcs->tcr.edi = 0;
	tcs->tcr.eip = 0;
	tcs->tcr.efl = 0;
}


void tcv_clock_increse(tcv_clock_pulse *tcp)
{
	tcp->count += 1;
}


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


void tcv_cpu_write_memory(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr, u32 value)
{
	tcv_cpu_bus tcb;
	
	tcv_clock_increse(&tcs->tcp);

	tcb.bus_data = addr;

	tcv_ram_request_write_memory(tr, &tcb, tcs);
	tcv_ram_write_memory(tr, &tcb, tcs, value);
}


void tcv_cpu_caching(tcv_cpu_status *tcs, tcv_ram *tr, u32 addr, u8 size)
{
	u8 v;

	tcv_clock_increse(&tcs->tcp);

	if (size > TCV_MAX_CACHE_SIZE)
		return;

	for(v = 0; v < size; v++) {
		u32 value;

		value = tcv_cpu_read_memory(tcs, tr, addr + v);

		tcs->tcc.cache[v] = value;
	}
}


void tcv_cpu_program_counter(tcv_cpu_status *tcs)
{
	; // none
}


void tcv_cpu_control_unit(tcv_cpu_status *tcs)
{
	byte b1, b2, b3, b4;
	
	tcv_clock_increse(&tcs->tcp);

	b1 = ((byte *)(tcs->tcc.cache))[tcs->tcr.ebp];
	b1 = ((byte *)(tcs->tcc.cache))[tcs->tcr.ebp+1];
	b1 = ((byte *)(tcs->tcc.cache))[tcs->tcr.ebp+2];
	b1 = ((byte *)(tcs->tcc.cache))[tcs->tcr.ebp+3];

	tcs->tcr.ebp += 4;
}