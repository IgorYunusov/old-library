/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

// Unlimited Intervene

#ifndef __APVL_UI_BINARY
#define __APVL_UI_BINARY

/****************************************************************

					1. Complex Program.

			MUST BE USED IN SECURITY SERVICE

****************************************************************/

#define _APVL_UIBIN_TYPE_16			0xC00	// not get, set
#define _APVL_UIBIN_TYPE_32			0xF00
#define _APVL_UIBIN_TYPE_64			0xA00

#define _APVL_UIBIN_TYPE_BINARY		0x10
#define _APVL_UIBIN_TYPE_OCTAL		0x20
#define _APVL_UIBIN_TYPE_HEX		0x30
#define _APVL_UIBIN_TYPE_DECIMAL	0x40

#define _APVL_UIBIN_TYPE_ONE		0x01	// get, set : byte
#define _APVL_UIBIN_TYPE_TWO		0x02	// shl, shr : bit
#define _APVL_UIBIN_TYPE_FOUR		0x03	// replace : bit
#define _APVL_UIBIN_TYPE_OCT		0x04	// make : bit
#define _APVL_UIBIN_TYPE_HEXA		0x05

#define _APVL_UIBIN_MSG_GET			1	// btype, gbit, pos
#define _APVL_UIBIN_MSG_SET			2	// btype, gbit, pos, rettype
#define _APVL_UIBIN_MSG_SHL			3
#define _APVL_UIBIN_MSG_SHR			4
#define _APVL_UIBIN_MSG_REPLACE		5
#define _APVL_UIBIN_MSG_MAKE		6

// gbit : 총합비트, gn : 비트자릿수, sh : 쉬프트수
#define __udt_served(type, btype, msg, a1, a2, a3, a4, b1, b2, b3, b4, gbit, gn, pos, sh, rettype) \
	type == _APVL_UIBIN_TYPE_16 ?\
			msg == _APVL_UIBIN_MSG_GET ? \
				btype == _APVL_UIBIN_TYPE_ONE ? \
					(gbit & (0xf << (pos << 2))) \
				: btype == _APVL_UIBIN_TYPE_TWO ? \
					(gbit & (0xff << (pos << (2 + 1)))) \
				: btype == _APVL_UIBIN_TYPE_FOUR ? \
					(gbit & (0xffff << (pos << 4))) \
				: btype == _APVL_UIBIN_TYPE_OCT ? \
					(gbit & (0xffffffff << (pos << 8))) \
				: btype == _APVL_UIBIN_TYPE_HEXA ? \
					(gbit & (0xffffffffffffffff << (pos << 16))) \
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SET ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: btype == _APVL_UIBIN_TYPE_TWO ?\
					((gbit ^ (gbit & (0xff << (pos << 2 + 1)))) | (rettype << (pos << 2 + 1)))\
				: btype == _APVL_UIBIN_TYPE_FOUR ?\
					((gbit ^ (gbit & (0xffff << (pos << 4)))) | (rettype << (pos << 4)))\
				: btype == _APVL_UIBIN_TYPE_OCT ?\
					((gbit ^ (gbit & (0xffffffff << (pos << 8)))) | (rettype << (pos << 8)))\
				: btype == _APVL_UIBIN_TYPE_HEXA ?\
					((gbit ^ (gbit & (0xffffffffffffffff  << (pos << 16)))) | (rettype << (pos << 16)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SHL ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SHR ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			\
			\
			\
			\
			\
			msg == _APVL_UIBIN_MSG_REPLACE ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_MAKE ?\
				btype == _APVL_UIBIN_TYPE_HEX ?\
					((a1 << 12) | (a2 << 8) | (a3 << 4 )| (a4))\
				: btype == _APVL_UIBIN_TYPE_BINARY ?\
					((a1 << 3) | (a2 << 2) | (a3 << 1)| (a4))\
				: btype == _APVL_UIBIN_TYPE_OCTAL ?\
					((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4))\
				: btype == _APVL_UIBIN_TYPE_DECIMAL ?\
					((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4))\
				: 0\
			: 0\
	: type == _APVL_UIBIN_TYPE_32 ?\
			msg == _APVL_UIBIN_MSG_GET ? \
				btype == _APVL_UIBIN_TYPE_ONE ? \
					(gbit & (0xf << (pos << 2))) \
				: btype == _APVL_UIBIN_TYPE_TWO ? \
					(gbit & (0xff << (pos << (2 + 1)))) \
				: btype == _APVL_UIBIN_TYPE_FOUR ? \
					(gbit & (0xffff << (pos << 4))) \
				: btype == _APVL_UIBIN_TYPE_OCT ? \
					(gbit & (0xffffffff << (pos << 8))) \
				: btype == _APVL_UIBIN_TYPE_HEXA ? \
					(gbit & (0xffffffffffffffff << (pos << 16))) \
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SET ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: btype == _APVL_UIBIN_TYPE_TWO ?\
					((gbit ^ (gbit & (0xff << (pos << 2 + 1)))) | (rettype << (pos << 2 + 1)))\
				: btype == _APVL_UIBIN_TYPE_FOUR ?\
					((gbit ^ (gbit & (0xffff << (pos << 4)))) | (rettype << (pos << 4)))\
				: btype == _APVL_UIBIN_TYPE_OCT ?\
					((gbit ^ (gbit & (0xffffffff << (pos << 8)))) | (rettype << (pos << 8)))\
				: btype == _APVL_UIBIN_TYPE_HEXA ?\
					((gbit ^ (gbit & (0xffffffffffffffff  << (pos << 16)))) | (rettype << (pos << 16)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SHL ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SHR ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			\
			\
			\
			\
			\
			msg == _APVL_UIBIN_MSG_REPLACE ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_MAKE ?\
				btype == _APVL_UIBIN_TYPE_HEX ?\
					((a1 << 12) | (a2 << 8) | (a3 << 4 )| (a4))\
				: btype == _APVL_UIBIN_TYPE_BINARY ?\
					((a1 << 3) | (a2 << 2) | (a3 << 1)| (a4))\
				: btype == _APVL_UIBIN_TYPE_OCTAL ?\
					((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4))\
				: btype == _APVL_UIBIN_TYPE_DECIMAL ?\
					((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4))\
				: 0\
			: 0\
	: type == _APVL_UIBIN_TYPE_64 ?\
			msg == _APVL_UIBIN_MSG_GET ? \
				btype == _APVL_UIBIN_TYPE_ONE ? \
					(gbit & (0xf << (pos << 2))) \
				: btype == _APVL_UIBIN_TYPE_TWO ? \
					(gbit & (0xff << (pos << (2 + 1)))) \
				: btype == _APVL_UIBIN_TYPE_FOUR ? \
					(gbit & (0xffff << (pos << 4))) \
				: btype == _APVL_UIBIN_TYPE_OCT ? \
					(gbit & (0xffffffff << (pos << 8))) \
				: btype == _APVL_UIBIN_TYPE_HEXA ? \
					(gbit & (0xffffffffffffffff << (pos << 16))) \
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SET ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: btype == _APVL_UIBIN_TYPE_TWO ?\
					((gbit ^ (gbit & (0xff << (pos << 2 + 1)))) | (rettype << (pos << 2 + 1)))\
				: btype == _APVL_UIBIN_TYPE_FOUR ?\
					((gbit ^ (gbit & (0xffff << (pos << 4)))) | (rettype << (pos << 4)))\
				: btype == _APVL_UIBIN_TYPE_OCT ?\
					((gbit ^ (gbit & (0xffffffff << (pos << 8)))) | (rettype << (pos << 8)))\
				: btype == _APVL_UIBIN_TYPE_HEXA ?\
					((gbit ^ (gbit & (0xffffffffffffffff  << (pos << 16)))) | (rettype << (pos << 16)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SHL ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_SHR ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			\
			\
			\
			\
			\
			msg == _APVL_UIBIN_MSG_REPLACE ?\
				btype == _APVL_UIBIN_TYPE_ONE ?\
					((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2)))\
				: 0\
			:\
			msg == _APVL_UIBIN_MSG_MAKE ?\
				btype == _APVL_UIBIN_TYPE_HEX ?\
					((a1 << 12) | (a2 << 8) | (a3 << 4 )| (a4))\
				: btype == _APVL_UIBIN_TYPE_BINARY ?\
					((a1 << 3) | (a2 << 2) | (a3 << 1)| (a4))\
				: btype == _APVL_UIBIN_TYPE_OCTAL ?\
					((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4))\
				: btype == _APVL_UIBIN_TYPE_DECIMAL ?\
					((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4))\
				: 0\
			: 0\
	: 0

//(_x & (0xff << (x << 2 + 1)))


#define __udt_s(type, btype, msg, a1, a2, a3, a4, b1, b2, b3, b4, gbit, gn, pos, sh, rettype) \
	type == _APVL_UIBIN_TYPE_16 ? msg == _APVL_UIBIN_MSG_GET ? btype == _APVL_UIBIN_TYPE_ONE ? (gbit \
	& (0xf << (pos << 2))) : btype == _APVL_UIBIN_TYPE_TWO ? (gbit & (0xff << (pos << (2 + 1)))) : btype \
	== _APVL_UIBIN_TYPE_FOUR ? (gbit & (0xffff << (pos << 4))) : btype == _APVL_UIBIN_TYPE_OCT ? (gbit \
	& (0xffffffff << (pos << 8))) : btype == _APVL_UIBIN_TYPE_HEXA ? (gbit & (0xffffffffffffffff << (pos \
	<< 16))) : 0 : msg == _APVL_UIBIN_MSG_SET ? btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << \
	(pos << 2)))) | (rettype << (pos << 2))) : btype == _APVL_UIBIN_TYPE_TWO ? ((gbit ^ (gbit & (0xff << \
	(pos << 2 + 1)))) | (rettype << (pos << 2 + 1))) : btype == _APVL_UIBIN_TYPE_FOUR ? ((gbit ^ (gbit & \
	(0xffff << (pos << 4)))) | (rettype << (pos << 4))) : btype == _APVL_UIBIN_TYPE_OCT ? ((gbit ^ (gbit \
	& (0xffffffff << (pos << 8)))) | (rettype << (pos << 8))) : btype == _APVL_UIBIN_TYPE_HEXA ? ((gbit ^\
	(gbit & (0xffffffffffffffff  << (pos << 16)))) | (rettype << (pos << 16))) : 0 : msg == \
	_APVL_UIBIN_MSG_SHL ? btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << (pos << 2)))) | \
	(rettype << (pos << 2))) : 0 : msg == _APVL_UIBIN_MSG_SHR ? btype == _APVL_UIBIN_TYPE_ONE ? ((gbit \
	^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2))) : 0 : msg == _APVL_UIBIN_MSG_REPLACE ? \
	btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2))) : 0\
	: msg == _APVL_UIBIN_MSG_MAKE ? btype == _APVL_UIBIN_TYPE_HEX ? ((a1 << 12) | (a2 << 8) | (a3 << 4 )| \
	(a4)) : btype == _APVL_UIBIN_TYPE_BINARY ? ((a1 << 3) | (a2 << 2) | (a3 << 1)| (a4)) : btype == \
	_APVL_UIBIN_TYPE_OCTAL ? ((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4)) : btype == _APVL_UIBIN_TYPE_DECIMAL \
	? ((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4)) : 0 : 0 : type == _APVL_UIBIN_TYPE_32 ? msg == \
	_APVL_UIBIN_MSG_GET ? btype == _APVL_UIBIN_TYPE_ONE ? (gbit & (0xf << (pos << 2))) : btype == \
	_APVL_UIBIN_TYPE_TWO ? (gbit & (0xff << (pos << (2 + 1)))) : btype == _APVL_UIBIN_TYPE_FOUR ? (gbit & \
	(0xffff << (pos << 4))) : btype == _APVL_UIBIN_TYPE_OCT ? (gbit & (0xffffffff << (pos << 8))) : btype \
	== _APVL_UIBIN_TYPE_HEXA ? (gbit & (0xffffffffffffffff << (pos << 16))) : 0 : msg == _APVL_UIBIN_MSG_SET \
	? btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2))) : \
	btype == _APVL_UIBIN_TYPE_TWO ? ((gbit ^ (gbit & (0xff << (pos << 2 + 1)))) | (rettype << (pos << 2 + 1)))\
	: btype == _APVL_UIBIN_TYPE_FOUR ? ((gbit ^ (gbit & (0xffff << (pos << 4)))) | (rettype << (pos << 4))) \
	: btype == _APVL_UIBIN_TYPE_OCT ? ((gbit ^ (gbit & (0xffffffff << (pos << 8)))) | (rettype << (pos << 8))) \
	: btype == _APVL_UIBIN_TYPE_HEXA ? ((gbit ^ (gbit & (0xffffffffffffffff  << (pos << 16)))) | (rettype << \
	(pos << 16))) : 0 : msg == _APVL_UIBIN_MSG_SHL ? btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << \
	(pos << 2)))) | (rettype << (pos << 2))) : 0 : msg == _APVL_UIBIN_MSG_SHR ? btype == _APVL_UIBIN_TYPE_ONE \
	? ((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2))) : 0 : msg == _APVL_UIBIN_MSG_REPLACE ? \
	btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2))) : 0 : msg \
	== _APVL_UIBIN_MSG_MAKE ? btype == _APVL_UIBIN_TYPE_HEX ? ((a1 << 12) | (a2 << 8) | (a3 << 4 )| (a4)) : btype \
	== _APVL_UIBIN_TYPE_BINARY ? ((a1 << 3) | (a2 << 2) | (a3 << 1)| (a4)) : btype == _APVL_UIBIN_TYPE_OCTAL ? \
	((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4)) : btype == _APVL_UIBIN_TYPE_DECIMAL ? ((a1 << 8) | (a2 << 4) \
	| (a3 << 2)| (a4)) : 0 : 0 : type == _APVL_UIBIN_TYPE_64 ? msg == _APVL_UIBIN_MSG_GET ? btype == \
	_APVL_UIBIN_TYPE_ONE ? (gbit & (0xf << (pos << 2))) : btype == _APVL_UIBIN_TYPE_TWO ? (gbit & (0xff << \
	(pos << (2 + 1)))) : btype == _APVL_UIBIN_TYPE_FOUR ? (gbit & (0xffff << (pos << 4))) : btype == \
	_APVL_UIBIN_TYPE_OCT ? (gbit & (0xffffffff << (pos << 8))) : btype == _APVL_UIBIN_TYPE_HEXA ? (gbit & \
	(0xffffffffffffffff << (pos << 16))) : 0 : msg == _APVL_UIBIN_MSG_SET ? btype == _APVL_UIBIN_TYPE_ONE ? \
	((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2))) : btype == _APVL_UIBIN_TYPE_TWO ? ((gbit \
	^ (gbit & (0xff << (pos << 2 + 1)))) | (rettype << (pos << 2 + 1))) : btype == _APVL_UIBIN_TYPE_FOUR ? \
	((gbit ^ (gbit & (0xffff << (pos << 4)))) | (rettype << (pos << 4))) : btype == _APVL_UIBIN_TYPE_OCT ? \
	((gbit ^ (gbit & (0xffffffff << (pos << 8)))) | (rettype << (pos << 8))) : btype == _APVL_UIBIN_TYPE_HEXA \
	? ((gbit ^ (gbit & (0xffffffffffffffff  << (pos << 16)))) | (rettype << (pos << 16))) : 0 : msg == \
	_APVL_UIBIN_MSG_SHL ? btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << \
	(pos << 2))) : 0 : msg == _APVL_UIBIN_MSG_SHR ? btype == _APVL_UIBIN_TYPE_ONE ? ((gbit ^ (gbit & (0xf << \
	(pos << 2)))) | (rettype << (pos << 2))) : 0 : msg == _APVL_UIBIN_MSG_REPLACE ? btype == _APVL_UIBIN_TYPE_ONE\
	? ((gbit ^ (gbit & (0xf << (pos << 2)))) | (rettype << (pos << 2))) : 0 : msg == _APVL_UIBIN_MSG_MAKE ? \
	btype == _APVL_UIBIN_TYPE_HEX ? ((a1 << 12) | (a2 << 8) | (a3 << 4 )| (a4)) : btype == _APVL_UIBIN_TYPE_BINARY\
	? ((a1 << 3) | (a2 << 2) | (a3 << 1)| (a4)) : btype == _APVL_UIBIN_TYPE_OCTAL ? ((a1 << 8) | (a2 << 4) | \
	(a3 << 2)| (a4)) : btype == _APVL_UIBIN_TYPE_DECIMAL ? ((a1 << 8) | (a2 << 4) | (a3 << 2)| (a4)) : 0 : 0 : 0

int served(int type, int msg, int b1, int b2, int b3, int b4, int a1, 
		   int a2, int a3, int a4, int gbit, int gn, int pos, int sh, int rettype)
{
	return 0;
}

// UDT TABLE
#define GetBitWithPos(_b, x) (_b & (0xf << (x << 2)))
#define SetBitWithPos(gbit, pos, rettype) (gbit ^ ((gbit << (pos << 2)) & 0xf << (pos << 2)))

#define _GET_C(_x, x) (_x & (0xf << (x << 2)))
#define _SET_C(_x, x, y) ((_x ^ _GET_C(_x, x)) | (y << (x << 2)))

#define _GET_Cs(_x, x) (_x & (0xff << (x << 2 + 1)))
#define _SET_Cs(_x, x, y) ((_x ^ (_x & (0xff << (x << 2 + 1)))) | (y << (x << 2 + 1)))

#define _DTOH(_x)

#define _XGT(x)  __udt_s(_APVL_UIBIN_TYPE_16, _APVL_UIBIN_TYPE_ONE, _APVL_UIBIN_MSG_SET, 0,0,0,0,0,0,0,0,x,0,3,0,x)

#endif

