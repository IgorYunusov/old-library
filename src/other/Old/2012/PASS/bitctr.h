/***********************************************************************

	RollRat Software BITCTR Algorithm
	Bit Control

	Copyright (c) rollrat. 2013. All rights reserved.

***********************************************************************/

#pragma once

#ifndef __ARRCTR4
#define __ARRCTR4

typedef unsigned u;
typedef unsigned char uChar, BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;

#define _B1(x) x
#define _B2(x) x << 4
#define _B3(x) x << 8
#define _B4(x) x << 12
#define _B5(x) x << 16
#define _B6(x) x << 20
#define _B7(x) x << 24
#define _B8(x) x << 28
#define _B9(x) x << 32
#define _B10(x) x << 36
#define _B11(x) x << 40
#define _B12(x) x << 44
#define _B13(x) x << 48
#define _B14(x) x << 52
#define _B15(x) x << 56
#define _B16(x) x << 60

#define _D1(x) x << 2
#define _D2(x) x << 4
#define _D3(x) x << 6
#define _D4(x) x << 8
#define _D5(x) x << 10
#define _D6(x) x << 12
#define _D7(x) x << 14
#define _D8(x) x << 16
#define _D9(x) x << 18

/*
		MAKE BITS
*/
#define MAKEBINARY(_0, _1, _2, _3) _0 << 3 | _1 << 2 | _2 << 1 | _3
#define MAKEHEX(_x0, _x1, _x2, _x3, _x4, _x5, _x6, _x7) \
	_x7 | _x6 << 4 | _x5 << 8 | _x4 << 12 |\
	_x3 << 16 | _x2 << 20 | _x1 << 24 | _x0 << 28
#define MAKEWORD(x, y)	((BYTE)x | _B3((WORD)y))
#define MAKEDWORD(x, y) ((WORD)x | _B5((DWORD)y))

/*
		GET BITS
*/
#define _E_C(_x, x) (_x & (0xf << (_D1(x)))) // get bit w pos
#define _E(_x, x) (_E_C(_x, x) >> (_D1(x)))	// get bit
#define _E_BP(_x, x) ((_x) & ((0xff) << (_D1(x) + 1))) // get byte w pos
#define _E_B(_x, x) ((_E_BP(_x, x)) >> (_D1(x) + 1)) // get byte
#define _LBYTE(_x) ((uChar)_x) // get pos 0xff
#define _HBYTE(_x) ((WORD)_x >> 8 & 0xff) // get pos 0xff00
#define _E_WP(_x, x) (_x & (0xffff << (_D2(x)))) // get word w pos
#define _E_W(_x, x) (_E_WP(_x, x) >> (_D2(x))) // get word
#define _LWORD(_x) ((WORD)_x) // get pos 0xffff
#define _HWORD(_x) ((u int)_x >> 16 & 0xffff) // get pos 0xffff0000
#define _E_DP(_x, x) (_x & (0xffffffff << (_D3(x)))) // get dword w pos
#define _E_D(_x, x) (_E_D(_x, x) >> (_D3(x))) // get dword

/*
		EXCHANGE BITS
*/
#define _EX_C(_x, x, y) ((_x ^ (_E_C(_x, x)) ^ (_E_C(_x, y))) \
		| ((_E(_x, x) << y) | (_E(_x, y) << x))) // exc bit
#define _EX_B(_x, x, y) (_x ^ (_E_BP(_x, x)) ^ (_E_BP(_x, y)) \
		| ((_E_B(_x, x) << (_D1(y) + 1)) | \
		((_E_B(_x, y) << (_D1(x) + 1))))) // exc byte
#define _EX_BC(_x, x, y) (_x ^ ((_x & (0xff << (x << 2 + 1)))) \
	^ ((_x & (0xff << (y << 2 + 1)))) | ((((_x & (0xff << (x \
	<< 2 + 1))) >> (x << 2 + 1)) << (y << 2 + 1)) | ((((_x & \
	(0xff << (x << 2 + 1))) >> (x << 2 + 1)) << (x << 2 + 1)))))

/*
		SET BITS
*/
#define _S_P(_x, x, y) (_x ^ x | y)

#define _P1(x)		(x & 0x000000000000000f)
#define _P2(x)		(x & 0x00000000000000f0)
#define _P3(x)		(x & 0x0000000000000f00)
#define _P4(x)		(x & 0x000000000000f000)
#define _P5(x)		(x & 0x00000000000f0000)
#define _P6(x)		(x & 0x0000000000f00000)
#define _P7(x)		(x & 0x000000000f000000)
#define _P8(x)		(x & 0x00000000f0000000)
#define _P9(x)		(x & 0x0000000f00000000)
#define _P10(x)		(x & 0x000000f000000000)
#define _P11(x)		(x & 0x00000f0000000000)
#define _P12(x)		(x & 0x0000f00000000000)
#define _P13(x)		(x & 0x000f000000000000)
#define _P14(x)		(x & 0x00f0000000000000)
#define _P15(x)		(x & 0x0f00000000000000)
#define _P16(x)		(x & 0xf000000000000000)

#define _PE1(x)		(x & 0x0000000000000001)
#define _PE2(x)		(x & 0x0000000000000002)
#define _PE3(x)		(x & 0x0000000000000004)
#define _PE4(x)		(x & 0x0000000000000008)
#define _PE5(x)		(x & 0x0000000000000010)
#define _PE6(x)		(x & 0x0000000000000020)
#define _PE7(x)		(x & 0x0000000000000040)
#define _PE8(x)		(x & 0x0000000000000080)
#define _PE9(x)		(x & 0x0000000000000100)
#define _PE10(x)	(x & 0x0000000000000200)
#define _PE11(x)	(x & 0x0000000000000400)
#define _PE12(x)	(x & 0x0000000000000800)
#define _PE13(x)	(x & 0x0000000000001000)
#define _PE14(x)	(x & 0x0000000000002000)
#define _PE15(x)	(x & 0x0000000000004000)
#define _PE16(x)	(x & 0x0000000000008000)
#define _PE17(x)	(x & 0x0000000000010000)
#define _PE18(x)	(x & 0x0000000000020000)
#define _PE19(x)	(x & 0x0000000000040000)
#define _PE20(x)	(x & 0x0000000000080000)
#define _PE21(x)	(x & 0x0000000000100000)
#define _PE22(x)	(x & 0x0000000000200000)
#define _PE23(x)	(x & 0x0000000000400000)
#define _PE24(x)	(x & 0x0000000000800000)
#define _PE25(x)	(x & 0x0000000001000000)
#define _PE26(x)	(x & 0x0000000002000000)
#define _PE27(x)	(x & 0x0000000004000000)
#define _PE28(x)	(x & 0x0000000008000000)
#define _PE29(x)	(x & 0x0000000010000000)
#define _PE30(x)	(x & 0x0000000020000000)
#define _PE31(x)	(x & 0x0000000040000000)
#define _PE32(x)	(x & 0x0000000080000000)
#define _PE33(x)	(x & 0x0000000100000000)
#define _PE34(x)	(x & 0x0000000200000000)
#define _PE35(x)	(x & 0x0000000400000000)
#define _PE36(x)	(x & 0x0000000800000000)
#define _PE37(x)	(x & 0x0000001000000000)
#define _PE38(x)	(x & 0x0000002000000000)
#define _PE39(x)	(x & 0x0000004000000000)
#define _PE40(x)	(x & 0x0000008000000000)
#define _PE41(x)	(x & 0x0000010000000000)
#define _PE42(x)	(x & 0x0000020000000000)
#define _PE43(x)	(x & 0x0000040000000000)
#define _PE44(x)	(x & 0x0000080000000000)
#define _PE45(x)	(x & 0x0000100000000000)
#define _PE46(x)	(x & 0x0000200000000000)
#define _PE47(x)	(x & 0x0000400000000000)
#define _PE48(x)	(x & 0x0000800000000000)
#define _PE49(x)	(x & 0x0001000000000000)
#define _PE50(x)	(x & 0x0002000000000000)
#define _PE51(x)	(x & 0x0004000000000000)
#define _PE52(x)	(x & 0x0008000000000000)
#define _PE53(x)	(x & 0x0010000000000000)
#define _PE54(x)	(x & 0x0020000000000000)
#define _PE55(x)	(x & 0x0040000000000000)
#define _PE56(x)	(x & 0x0080000000000000)
#define _PE57(x)	(x & 0x0100000000000000)
#define _PE58(x)	(x & 0x0200000000000000)
#define _PE59(x)	(x & 0x0400000000000000)
#define _PE60(x)	(x & 0x0800000000000000)
#define _PE61(x)	(x & 0x1000000000000000)
#define _PE62(x)	(x & 0x2000000000000000)
#define _PE63(x)	(x & 0x4000000000000000)
#define _PE64(x)	(x & 0x8000000000000000)

/*
		CARRY
*/
#define _CARRY_0(_x, _y) (_PE1(_x & _y))
#define _CARRY_1(_x, _y) (_PE2(_x & _y) | (_CARRY_0(_x, _y) << 1) & _PE1(_x ^ _y))
#define _CARRY_2(_x, _y) (_PE3(_x & _y) | (_CARRY_1(_x, _y) << 1) & _PE2(_x ^ _y))
#define _CARRY_3(_x, _y) (_PE4(_x & _y) | (_CARRY_2(_x, _y) << 1) & _PE3(_x ^ _y))
#define _CARRY_4(_x, _y) (_PE5(_x & _y) | (_CARRY_3(_x, _y) << 1) & _PE4(_x ^ _y))
#define _CARRY_5(_x, _y) (_PE6(_x & _y) | (_CARRY_4(_x, _y) << 1) & _PE5(_x ^ _y))
#define _CARRY_6(_x, _y) (_PE7(_x & _y) | (_CARRY_5(_x, _y) << 1) & _PE6(_x ^ _y))
#define _CARRY_7(_x, _y) (_PE8(_x & _y) | (_CARRY_6(_x, _y) << 1) & _PE7(_x ^ _y))
#define _CARRY_8(_x, _y) (_PE9(_x & _y) | (_CARRY_7(_x, _y) << 1) & _PE8(_x ^ _y))
#define _CARRY_9(_x, _y) (_PE10(_x & _y) | (_CARRY_8(_x, _y) << 1) & _PE9(_x ^ _y))
#define _CARRY_10(_x, _y) (_PE11(_x & _y) | (_CARRY_9(_x, _y) << 1) & _PE10(_x ^ _y))
#define _CARRY_11(_x, _y) (_PE12(_x & _y) | (_CARRY_10(_x, _y) << 1) & _PE11(_x ^ _y))
#define _CARRY_12(_x, _y) (_PE13(_x & _y) | (_CARRY_11(_x, _y) << 1) & _PE12(_x ^ _y))
#define _CARRY_13(_x, _y) (_PE14(_x & _y) | (_CARRY_12(_x, _y) << 1) & _PE13(_x ^ _y))
#define _CARRY_14(_x, _y) (_PE15(_x & _y) | (_CARRY_13(_x, _y) << 1) & _PE14(_x ^ _y))
#define _CARRY_15(_x, _y) (_PE16(_x & _y) | (_CARRY_14(_x, _y) << 1) & _PE15(_x ^ _y))
#define _CARRY_16(_x, _y) (_PE17(_x & _y) | (_CARRY_15(_x, _y) << 1) & _PE16(_x ^ _y))
#define _CARRY_17(_x, _y) (_PE18(_x & _y) | (_CARRY_16(_x, _y) << 1) & _PE17(_x ^ _y))
#define _CARRY_18(_x, _y) (_PE19(_x & _y) | (_CARRY_17(_x, _y) << 1) & _PE18(_x ^ _y))
#define _CARRY_19(_x, _y) (_PE20(_x & _y) | (_CARRY_18(_x, _y) << 1) & _PE19(_x ^ _y))
#define _CARRY_20(_x, _y) (_PE21(_x & _y) | (_CARRY_19(_x, _y) << 1) & _PE20(_x ^ _y))
#define _CARRY_21(_x, _y) (_PE22(_x & _y) | (_CARRY_20(_x, _y) << 1) & _PE21(_x ^ _y))
#define _CARRY_22(_x, _y) (_PE23(_x & _y) | (_CARRY_21(_x, _y) << 1) & _PE22(_x ^ _y))
#define _CARRY_23(_x, _y) (_PE24(_x & _y) | (_CARRY_22(_x, _y) << 1) & _PE23(_x ^ _y))
#define _CARRY_24(_x, _y) (_PE25(_x & _y) | (_CARRY_23(_x, _y) << 1) & _PE24(_x ^ _y))
#define _CARRY_25(_x, _y) (_PE26(_x & _y) | (_CARRY_24(_x, _y) << 1) & _PE25(_x ^ _y))
#define _CARRY_26(_x, _y) (_PE27(_x & _y) | (_CARRY_25(_x, _y) << 1) & _PE26(_x ^ _y))
#define _CARRY_27(_x, _y) (_PE28(_x & _y) | (_CARRY_26(_x, _y) << 1) & _PE27(_x ^ _y))
#define _CARRY_28(_x, _y) (_PE29(_x & _y) | (_CARRY_27(_x, _y) << 1) & _PE28(_x ^ _y))
#define _CARRY_29(_x, _y) (_PE30(_x & _y) | (_CARRY_28(_x, _y) << 1) & _PE29(_x ^ _y))
#define _CARRY_30(_x, _y) (_PE31(_x & _y) | (_CARRY_29(_x, _y) << 1) & _PE30(_x ^ _y))
#define _CARRY_31(_x, _y) (_PE32(_x & _y) | (_CARRY_30(_x, _y) << 1) & _PE31(_x ^ _y))
#define _CARRY_32(_x, _y) (_PE33(_x & _y) | (_CARRY_31(_x, _y) << 1) & _PE32(_x ^ _y))
#define _CARRY_33(_x, _y) (_PE34(_x & _y) | (_CARRY_32(_x, _y) << 1) & _PE33(_x ^ _y))
#define _CARRY_34(_x, _y) (_PE35(_x & _y) | (_CARRY_33(_x, _y) << 1) & _PE34(_x ^ _y))
#define _CARRY_35(_x, _y) (_PE36(_x & _y) | (_CARRY_34(_x, _y) << 1) & _PE35(_x ^ _y))
#define _CARRY_36(_x, _y) (_PE37(_x & _y) | (_CARRY_35(_x, _y) << 1) & _PE36(_x ^ _y))
#define _CARRY_37(_x, _y) (_PE38(_x & _y) | (_CARRY_36(_x, _y) << 1) & _PE37(_x ^ _y))
#define _CARRY_38(_x, _y) (_PE39(_x & _y) | (_CARRY_37(_x, _y) << 1) & _PE38(_x ^ _y))
#define _CARRY_39(_x, _y) (_PE40(_x & _y) | (_CARRY_38(_x, _y) << 1) & _PE39(_x ^ _y))
#define _CARRY_40(_x, _y) (_PE41(_x & _y) | (_CARRY_39(_x, _y) << 1) & _PE40(_x ^ _y))
#define _CARRY_41(_x, _y) (_PE42(_x & _y) | (_CARRY_40(_x, _y) << 1) & _PE41(_x ^ _y))
#define _CARRY_42(_x, _y) (_PE43(_x & _y) | (_CARRY_41(_x, _y) << 1) & _PE42(_x ^ _y))
#define _CARRY_43(_x, _y) (_PE44(_x & _y) | (_CARRY_42(_x, _y) << 1) & _PE43(_x ^ _y))
#define _CARRY_44(_x, _y) (_PE45(_x & _y) | (_CARRY_43(_x, _y) << 1) & _PE44(_x ^ _y))
#define _CARRY_45(_x, _y) (_PE46(_x & _y) | (_CARRY_44(_x, _y) << 1) & _PE45(_x ^ _y))
#define _CARRY_46(_x, _y) (_PE47(_x & _y) | (_CARRY_45(_x, _y) << 1) & _PE46(_x ^ _y))
#define _CARRY_47(_x, _y) (_PE48(_x & _y) | (_CARRY_46(_x, _y) << 1) & _PE47(_x ^ _y))
#define _CARRY_48(_x, _y) (_PE49(_x & _y) | (_CARRY_47(_x, _y) << 1) & _PE48(_x ^ _y))
#define _CARRY_49(_x, _y) (_PE50(_x & _y) | (_CARRY_48(_x, _y) << 1) & _PE49(_x ^ _y))
#define _CARRY_50(_x, _y) (_PE51(_x & _y) | (_CARRY_49(_x, _y) << 1) & _PE50(_x ^ _y))
#define _CARRY_51(_x, _y) (_PE52(_x & _y) | (_CARRY_50(_x, _y) << 1) & _PE51(_x ^ _y))
#define _CARRY_52(_x, _y) (_PE53(_x & _y) | (_CARRY_51(_x, _y) << 1) & _PE52(_x ^ _y))
#define _CARRY_53(_x, _y) (_PE54(_x & _y) | (_CARRY_52(_x, _y) << 1) & _PE53(_x ^ _y))
#define _CARRY_54(_x, _y) (_PE55(_x & _y) | (_CARRY_53(_x, _y) << 1) & _PE54(_x ^ _y))
#define _CARRY_55(_x, _y) (_PE56(_x & _y) | (_CARRY_54(_x, _y) << 1) & _PE55(_x ^ _y))
#define _CARRY_56(_x, _y) (_PE57(_x & _y) | (_CARRY_55(_x, _y) << 1) & _PE56(_x ^ _y))
#define _CARRY_57(_x, _y) (_PE58(_x & _y) | (_CARRY_56(_x, _y) << 1) & _PE57(_x ^ _y))
#define _CARRY_58(_x, _y) (_PE59(_x & _y) | (_CARRY_57(_x, _y) << 1) & _PE58(_x ^ _y))
#define _CARRY_59(_x, _y) (_PE60(_x & _y) | (_CARRY_58(_x, _y) << 1) & _PE59(_x ^ _y))
#define _CARRY_60(_x, _y) (_PE61(_x & _y) | (_CARRY_59(_x, _y) << 1) & _PE60(_x ^ _y))
#define _CARRY_61(_x, _y) (_PE62(_x & _y) | (_CARRY_60(_x, _y) << 1) & _PE61(_x ^ _y))
#define _CARRY_62(_x, _y) (_PE63(_x & _y) | (_CARRY_61(_x, _y) << 1) & _PE62(_x ^ _y))
#define _CARRY_63(_x, _y) (_PE64(_x & _y) | (_CARRY_62(_x, _y) << 1) & _PE63(_x ^ _y))
#define _GET_CARRY(_x, _y) (_CARRY_0(_x, _y) | _CARRY_1(_x, _y) \
	| _CARRY_2(_x, _y) | _CARRY_3(_x, _y) | _CARRY_4(_x, _y) | \
	_CARRY_5(_x, _y) | _CARRY_6(_x, _y) | _CARRY_7(_x, _y) | \
	_CARRY_8(_x, _y) | _CARRY_9(_x, _y) | _CARRY_10(_x, _y) | \
	_CARRY_11(_x, _y) | _CARRY_12(_x, _y) | _CARRY_13(_x, _y) | \
	_CARRY_14(_x, _y) | _CARRY_15(_x, _y) | _CARRY_16(_x, _y) | \
	_CARRY_17(_x, _y) | _CARRY_18(_x, _y) | _CARRY_19(_x, _y) | \
	_CARRY_20(_x, _y) | _CARRY_21(_x, _y) | _CARRY_22(_x, _y) | \
	_CARRY_23(_x, _y) | _CARRY_24(_x, _y) | _CARRY_25(_x, _y) | \
	_CARRY_26(_x, _y) | _CARRY_27(_x, _y) | _CARRY_28(_x, _y) | \
	_CARRY_29(_x, _y) | _CARRY_30(_x, _y) | _CARRY_31(_x, _y) | \
	_CARRY_32(_x, _y) | _CARRY_33(_x, _y) | _CARRY_34(_x, _y) | \
	_CARRY_35(_x, _y) | _CARRY_36(_x, _y) | _CARRY_37(_x, _y) | \
	_CARRY_38(_x, _y) | _CARRY_39(_x, _y) | _CARRY_40(_x, _y) | \
	_CARRY_41(_x, _y) | _CARRY_42(_x, _y) | _CARRY_43(_x, _y) | \
	_CARRY_44(_x, _y) | _CARRY_45(_x, _y) | _CARRY_46(_x, _y) | \
	_CARRY_47(_x, _y) | _CARRY_48(_x, _y) | _CARRY_49(_x, _y) | \
	_CARRY_50(_x, _y) | _CARRY_51(_x, _y) | _CARRY_52(_x, _y) | \
	_CARRY_53(_x, _y) | _CARRY_54(_x, _y) | _CARRY_55(_x, _y) | \
	_CARRY_56(_x, _y) | _CARRY_57(_x, _y) | _CARRY_58(_x, _y) | \
	_CARRY_59(_x, _y) | _CARRY_60(_x, _y) | _CARRY_61(_x, _y) | \
	_CARRY_62(_x, _y) | _CARRY_63(_x, _y))

#endif