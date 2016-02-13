/*************************************************************************
 *
 * FILE NAME : tcbfield.h - Terraforming Core Bit Field List
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

#ifndef _TCBFIELD_		// [ !_TCBFIELD_
#define _TCBFIELD_

#define MAKE_TCBF(bit, table)		TCBF##table##_##bit

typedef union _bitfield_tmp {
	struct _inside_bits4 {
		unsigned short bit0 : 1;
		unsigned short bit1 : 1;
		unsigned short bit2 : 1;
		unsigned short bit3 : 1;
	} bits;
	unsigned short value;
}	TCBF1_4, *PTCBF1_4;

typedef union _bitfield_tmp0 {
	struct _inside_bits8 {
		unsigned short bit0 : 1;
		unsigned short bit1 : 1;
		unsigned short bit2 : 1;
		unsigned short bit3 : 1;
		unsigned short bit4 : 1;
		unsigned short bit5 : 1;
		unsigned short bit6 : 1;
		unsigned short bit7 : 1;
	} bits;
	unsigned short value;
}	TCBF1_8, *PTCBF1_8;

typedef union _bitfield_tmp1 {
	struct _inside_bits8 {
		unsigned short bit0 : 4;
		unsigned short bit1 : 4;
	} bits;
	unsigned short value;
}	TCBF4_8, *PTCBF4_8;

typedef union _bitfield_tmp2 {
	struct _inside_bits16 {
		unsigned short bit0	 : 1;
		unsigned short bit1	 : 1;
		unsigned short bit2	 : 1;
		unsigned short bit3	 : 1;
		unsigned short bit4	 : 1;
		unsigned short bit5	 : 1;
		unsigned short bit6	 : 1;
		unsigned short bit7	 : 1;
		unsigned short bit8	 : 1;
		unsigned short bit9	 : 1;
		unsigned short bit10 : 1;
		unsigned short bit11 : 1;
		unsigned short bit12 : 1;
		unsigned short bit13 : 1;
		unsigned short bit14 : 1;
		unsigned short bit15 : 1;
	} bits;
	unsigned short value;
}	TCBF1_16, *PTCBF1_16;

typedef union _bitfield_tmp3 {
	struct _inside_bits16 {
		unsigned short bit0 : 4;
		unsigned short bit1 : 4;
		unsigned short bit2 : 4;
		unsigned short bit3 : 4;
	} bits;
	unsigned short value;
}	TCBF4_16, *PTCBF4_16;

typedef union _bitfield_tmp4 {
	struct _inside_bits16 {
		unsigned short bit0 : 8;
		unsigned short bit1 : 8;
	} bits;
	unsigned short value;
}	TCBF8_16, *PTCBF8_16;

typedef union _bitfield_tmp5 {
	struct _inside_bits32 {
		unsigned int bit0  : 1;
		unsigned int bit1  : 1;
		unsigned int bit2  : 1;
		unsigned int bit3  : 1;
		unsigned int bit4  : 1;
		unsigned int bit5  : 1;
		unsigned int bit6  : 1;
		unsigned int bit7  : 1;
		unsigned int bit8  : 1;
		unsigned int bit9  : 1;
		unsigned int bit10 : 1;
		unsigned int bit11 : 1;
		unsigned int bit12 : 1;
		unsigned int bit13 : 1;
		unsigned int bit14 : 1;
		unsigned int bit15 : 1;
		unsigned int bit16 : 1;
		unsigned int bit17 : 1;
		unsigned int bit18 : 1;
		unsigned int bit19 : 1;
		unsigned int bit20 : 1;
		unsigned int bit21 : 1;
		unsigned int bit22 : 1;
		unsigned int bit23 : 1;
		unsigned int bit24 : 1;
		unsigned int bit25 : 1;
		unsigned int bit26 : 1;
		unsigned int bit27 : 1;
		unsigned int bit28 : 1;
		unsigned int bit29 : 1;
		unsigned int bit30 : 1;
		unsigned int bit31 : 1;
	} bits;
	unsigned int value;
}	TCBF1_32, *PTCBF1_32;

typedef union _bitfield_tmp6 {
	struct _inside_bits32 {
		unsigned int bit0 : 4;
		unsigned int bit1 : 4;
		unsigned int bit2 : 4;
		unsigned int bit3 : 4;
		unsigned int bit4 : 4;
		unsigned int bit5 : 4;
		unsigned int bit6 : 4;
		unsigned int bit7 : 4;
	} bits;
	unsigned int value;
}	TCBF4_32, *PTCBF4_32;

typedef union _bitfield_tmp7 {
	struct _inside_bits32 {
		unsigned int bit0 : 8;
		unsigned int bit1 : 8;
		unsigned int bit2 : 8;
		unsigned int bit3 : 8;
	} bits;
	unsigned int value;
}	TCBF8_32, *PTCBF8_32;

typedef union _bitfield_tmp8 {
	struct _inside_bits32 {
		unsigned int bit0 : 16;
		unsigned int bit1 : 16;
	} bits;
	unsigned int value;
}	TCBF16_32, *PTCBF16_32;

#endif // ] <- _TCBFIELD_