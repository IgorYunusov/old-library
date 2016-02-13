/***********************************************************************
 *
 * FILE NAME : kernel32.h - RollRat OS Entry Point and kernel kit
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

#ifndef _RKERNEL_
#define _RKERNEL_

#pragma pack( push, 1 )		// byte padding for kernel output

// Make Number Method
#define _Make_Number(x)					x
#define _Make_Number_type(x, type)		( *( type * ) (x) )
#define _Make_Number_volitale(x, type)	( *( volatile type * ) (x) )

#ifdef _DRIVER_MODE	// [ _DRIVER_MODE
#undef _Make_Number
#define _Make_Number(x)					( *( volatile long * ) (x) )
#else	// >- !_DRIVER_MODE
#endif	// ] <- _DRIVER_MODE

#ifdef _UNICODE		// [ _UNICODE
#define _USING_UNICODE			_Make_Number(1)
#define _CHAR_SET				wchar_t
#else	// >- !_UNICODE
#define _USING_UNICODE			_Make_Number(0)
#define _CHAR_SET				char
#endif	// ] <- _UNICODE

typedef _CHAR_SET	TCCHAR, *PTCCHAR;

#define _Logic_Copy(x, t)			((x) << (t)) | (x)
//#define _Logic_Copy_Time1(x)		_Logic_Copy(x,  1)
//#define _Logic_Copy_Time2(x)		_Logic_Copy(x,  2)
//#define _Logic_Copy_Time4(x)		_Logic_Copy(x,  4)
#define _Logic_Cpy8(x)				_Logic_Copy(x,  8)
#define _Logic_Cpy16(x)				_Logic_Copy(x, 16)
#ifndef _X86		// [ !_X86
#define _Logic_Cpy32(x)				_Logic_Copy(x, 32)
#endif	// ] <- !_X86

// Recommendation in embedded programming
#define _Swap_Xor(x, y)				(x) ^= (y), (y) ^= (x), (x) ^= (y);
#define _Swap_Xor_tmp(x, y)			(x) ^= (y) ^= (x) ^= (y);

		// arithmetic shift
#ifndef _SAFE_INT	// [ !_SAFE_INT
#define _Rotate_Left(x, r, n)		(((x) << (r)) | ((b) >> ((n)-(r))))
#define _Rotate_Right(x, r, n)		(((x) >> (r)) | ((b) << ((n)-(r))))
#define _Rotate_Left32(x, r)		_Rotate_Left(x, r, 32)
#define _Rotate_Right32(x, r)		_Rotate_Right(x, r, 32)
#define _ROTATE_USING
#else	// >- _SAFE_INT
#ifdef _ROTATE_USING	// [ _ROTATE_USING
#error _SAFE_INT is set, so you will not be able to perform the rotate operation.
#endif	// ] <- _ROTATE_USING
#endif	// ] <- _SAFE_INT

		// bit switch
#define _Switch_Bit(p)				(1 << ((p) - 1))

		// get/set/release bit using position with origin
#define _Bit_Get(b, r)				((b) & _Switch_Bit(r))
#define _Bit_Set(b, r)				(_Bit_Get(b, r) & _Switch_Bit(r))
#define _Bit_Rel(b, r)				(_Bit_Set(b, r) ^ _Switch_Bit(r))

		// get bit using position
#define _Bit_Get_s(b, r)			(_Bit_Get(b, r) >> (r))

// from to linux kernel.h
#define offset_of(st, m)	((size_t)(&((st *)0)->m))
#define container_of(ptr, type, member) \
	((type *)((char *)ptr - offset_of(type, member)))
#ifdef __cplusplus
#define _typeof(x)			decltype (x)
#endif

#undef near
#undef far
#define near
#define far

#define _In_
#define _Out_

#define _In_ptr_		// reference
#define _Out_prt_


		// classification accr-to-the number of bits
typedef unsigned long			u32;
typedef unsigned long long		u64;
typedef long					l32;
typedef long long				l64;
typedef long double				ld;
typedef unsigned short			u8;
typedef short					s8;

typedef unsigned long			DWORD;
typedef unsigned short			WORD;
typedef unsigned char			BYTE;
typedef int						BOOL;
typedef BOOL					*PBOOL;
typedef BYTE					*PBYTE;
typedef DWORD					*PDWORD;
typedef WORD					*PWORD;

typedef unsigned int			size_t;

typedef char					CHAR, *PCHAR;

#define TRUE		1
#define FALSE		0

//////////////////////////////////////////////////
//		KERNEL METHOD
/////////////////////////////////////////////////

void _internel_print_string(int x, int y, const PCHAR str, size_t length);
BOOL _internel_initialize_kernel64_area(void);
BOOL _internel_check_memory();
void _internel_copy_kernel_image();

typedef struct _video_memory_out {
	BYTE character;
	BYTE attribute;
}	kernel_vmo, *pkernel_vmo;

typedef struct _page_table_entry {

	// Case ( PML4T, PDPTE )
	//		 1 bit : P, RW, US, PWT, PCD, A
	//		 3 bit : Reserved
	//		 3 bit : Avail
	//		20 bit : Base Address
	// Case ( PDE )
	//		 1 bit : P, RW, US, PWT, PCD, A, B, 1, G
	//		 3 bit : Avail
	//		 1 bit : PAT
	//		 8 bit : Avail
	//		11 bit : Base Address
	DWORD dwATB_LBA;		// Attribute and Lower Base Address

	//		 8 bit : Upper Base Address
	//		12 bit : Reserved
	//		11 bit : Avail
	//		 1 bit : EXB
	DWORD dwUBA_EXB;		// Upper Base Address and EXB Field
}	PML4TENTRY, PDPTENTRY, PDENTRY, PTENTRY;

// attribute field for lower 32bit
#define PAGE_FLAGS_P        0x00000001  // Present
#define PAGE_FLAGS_RW       0x00000002  // Read/Write
#define PAGE_FLAGS_US       0x00000004  // User/Supervisor( default setting is supervisor )
#define PAGE_FLAGS_PWT      0x00000008  // Page Level Write-through
#define PAGE_FLAGS_PCD      0x00000010  // Page Level Cache Disable
#define PAGE_FLAGS_A        0x00000020  // Accessed
#define PAGE_FLAGS_D        0x00000040  // Dirty
#define PAGE_FLAGS_PS       0x00000080  // Page Size
#define PAGE_FLAGS_G        0x00000100  // Global
#define PAGE_FLAGS_PAT      0x00001000  // Page Attribute Table Index
#define PAGE_FLAGS_DEFAULT	(PAGE_FLAGS_P | PAGE_FLAGS_RW)

// attribute field for higher 32bit
#define PAGE_FLAGS_EXB		0x80000000 // Execute Disable bit

#define PAGE_TABLESIZE		0x1000
#define PAGE_MAXENTRYCOUNT	512
#define PAGE_DEFAULTSIZE	0x200000

void _internel_initialize_pagetables();
void _internel_page_set_entrydata( _In_ptr_ PTENTRY* pstEntry, DWORD dwUpperBaseAddress,
		DWORD dwLowerBaseAddress, DWORD dwLowerFlags, DWORD dwUpperFlags );

extern void _internel_read_cpuid( DWORD dwEAX, DWORD* pdwEAX, DWORD* pdwEBX, DWORD* pdwECX, DWORD* pdwEDX );
extern void _internel_switch_and_excuate64bit_kernel(void);

#define DYNAMICMEMORY_START_ADDRESS     ( ( TASK_STACKPOOLADDRESS + 0x1fffff ) & \
                                          0xffe00000 )

#pragma pack( pop )


#endif