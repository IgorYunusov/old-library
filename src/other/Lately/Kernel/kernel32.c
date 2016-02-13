/***********************************************************************
 *
 * FILE NAME : kernel32.c - RollRat OS Entry Point and kernel kit
 *
 * RollRat Kernel
 *
 *
 * CREATION : 2014.12.13
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

// This file based on mint64 os kernel.

#include "kernel32.h"
#include "string\string.h"

/*****
	Kernel Entry Point

	Print String
*****/
int Main()
{
    DWORD dwEAX, dwEBX, dwECX, dwEDX;
    char vcVendorString[ 13 ] = { 0, };

	if(FALSE == _internel_check_memory()) {

	}
	if(FALSE == _internel_initialize_kernel64_area()) {

	}
	_internel_initialize_pagetables();
	
    _internel_read_cpuid( 0x00, &dwEAX, &dwEBX, &dwECX, &dwEDX );
    *( DWORD* ) vcVendorString = dwEBX;
    *( ( DWORD* ) vcVendorString + 1 ) = dwEDX;
    *( ( DWORD* ) vcVendorString + 2 ) = dwECX;

	// check supported 64bit
    _internel_read_cpuid( 0x80000001, &dwEAX, &dwEBX, &dwECX, &dwEDX );
	if( !(dwEDX & (1 << 29)) ) {
	}
	_internel_copy_kernel_image();
	_internel_switch_and_excuate64bit_kernel();
}

/*****
	Function : _internel_print_string

	Print String
*****/
void _internel_print_string( int x, int y, const PCHAR str, size_t length )
{
	// _screen set on vmo address
	pkernel_vmo _screen = (kernel_vmo *)0xB8000;
	int c;

	// calculate output address
	_screen += ( y * 80 ) + x;

	for( c = 0; c < length; c++ ) {
		_screen[c].character = str[c];
	}
}

/*****
	Function : _internel_initialize_kernel64_area

	Initialize kernel 64 area
*****/
BOOL _internel_initialize_kernel64_area( void )
{
	PDWORD addr;

	// for 1MB
	addr = (DWORD *)0x100000;

	// for 6MB, by 4bytes
	while( (DWORD)addr < 0x600000 ) {

		*addr = 0;

		// check : input value in address for problem
		if (*addr) {
			return FALSE;
		}

		addr++;
	}

	return TRUE;
}

/*****
	Function : _internel_check_memory

	Check Memory Size,
	since loading os to memory
	OS SIZE MAX : 64MB
*****/
BOOL _internel_check_memory()
{
	PDWORD addr;
	
	// for 1MB
	addr = (DWORD *)0x100000;

	while( (DWORD) addr < 0x4000000 ) {
		
		// put random byte
		*addr = 0x12345678;
		
		// check : input value in address for problem
		if( *addr != 0x12345678 ) {
			return FALSE;
		}

		// check for 1MB
		addr += (0x100000 / 4);
	}

	return TRUE;
}

/*****
	Function : _internel_initialize_pagetables

	Initialize page tables
*****/
void _internel_initialize_pagetables()
{
	PML4TENTRY* pstPML4TEntry;
	PDPTENTRY* pstPDPTEntry;
	PDENTRY* pstPDEntry;
	DWORD dwMappingAddress;
    DWORD dwPageEntryFlags;
	int i;

	// Create PML4 Table
	pstPML4TEntry = (PML4TENTRY*)0x100000;
	_internel_page_set_entrydata(&(pstPML4TEntry[0]), 0x00, 0x101000, PAGE_FLAGS_DEFAULT, 0);

	for (i = 1; i < PAGE_MAXENTRYCOUNT; i++)
		_internel_page_set_entrydata(&(pstPML4TEntry[i]), 0, 0, 0, 0);
	
	// Create Page Direntory Pointer Table
	pstPDPTEntry = (PDPTENTRY*) 0x101000;
	for (i = 0; i < 64; i++)
		_internel_page_set_entrydata(&(pstPDPTEntry[i]), 0, 0x102000 + (i * PAGE_TABLESIZE), PAGE_FLAGS_DEFAULT, 0);

	for (i = 64; i < PAGE_MAXENTRYCOUNT; i++)
		_internel_page_set_entrydata(&(pstPDPTEntry[i]), 0, 0, 0, 0);

	// Create Page Direntory Table
	pstPDEntry = (PDENTRY*)0x102000;
	dwMappingAddress = 0;
	for (i = 0; i < PAGE_MAXENTRYCOUNT * 64; i++) {

        if( i < ( ( DWORD ) DYNAMICMEMORY_START_ADDRESS / PAGE_DEFAULTSIZE ) )
            dwPageEntryFlags = PAGE_FLAGS_DEFAULT | PAGE_FLAGS_PS;
        else
            dwPageEntryFlags = PAGE_FLAGS_DEFAULT | PAGE_FLAGS_PS | PAGE_FLAGS_US;

		_internel_page_set_entrydata(&(pstPDEntry[i]),
			(i * (PAGE_DEFAULTSIZE >> 20)) >> 12, dwMappingAddress, dwPageEntryFlags, 0);
		dwMappingAddress += PAGE_DEFAULTSIZE;
	}
}

void _internel_page_set_entrydata( PTENTRY* pstEntry, DWORD dwUpperBaseAddress,
		DWORD dwLowerBaseAddress, DWORD dwLowerFlags, DWORD dwUpperFlags )
{
	pstEntry->dwATB_LBA = dwLowerBaseAddress | dwLowerFlags;
	pstEntry->dwUBA_EXB = ( dwUpperBaseAddress & 0xFF ) | dwUpperFlags;
}

void _internel_copy_kernel_image()
{
	WORD wKernel32SectorCount, wTotalKernelSectorCount;
	DWORD* pdwSourceAddress, *pdwDestinationAddress;
	int i;

	wTotalKernelSectorCount = *((WORD*)0x7C05);
	wKernel32SectorCount = *((WORD*)0x7C07);

	pdwSourceAddress = (DWORD*)(0x10000 + (wKernel32SectorCount * 512));
	pdwDestinationAddress = (DWORD*)0x200000;

	for (i = 0; i < 512 * (wTotalKernelSectorCount - wKernel32SectorCount) / 4; i++)
	{
		*pdwDestinationAddress = *pdwSourceAddress;
		pdwDestinationAddress++;
		pdwSourceAddress++;
	}
}