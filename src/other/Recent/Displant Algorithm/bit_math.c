/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

 -----
FILE NAME:

   bit_math.c

Project:

   Displant Algorithm

------
   AUTHOR: HyunJun Jeong  2015-05-21

 ***************************************************************************/

#include <intrin.h>
#include <math.h>
#include "bit_math.h"

#define radian	0.0174532925199432957692369076848	// radain * 180
#define ln_10	2.3025850929940456840179914546844

#define _BoolFlag
#define _Input
#define _Output

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;

int fast_ceil_log2(unsigned long x);

_BoolFlag uint8_t _BitScanLeft32(
	_Output uint32_t *index,
	uint32_t mask
	)
{	// Find first set
	
	if (mask & 0xffff)
		if (mask & 0x00ff)
			if (mask & 0x000f)
				*index = mask & 1 + 1;
			else
				*index = (mask >> 4) & 1 + 1;
		else
			if (mask & 0x0f00)
				*index = (mask >> 8) & 1 + 1;
			else
				*index = (mask >> 12) & 1 + 1;
	else if (mask & 0xffff0000)
		if (mask & 0x00ff0000)
			if (mask & 0x000f0000)
				*index = (mask >> 16) & 1 + 1;
			else
				*index = (mask >> 20) & 1 + 1;
		else
			if (mask & 0x0f000000)
				*index = (mask >> 24) & 1 + 1;
			else
				*index = (mask >> 28) & 1 + 1;
	else
		return 0;

	return 1;
}

_BoolFlag uint8_t _BitScanRight32(
	_Output uint32_t *index,
	uint32_t mask
	)
{	// Find last set
	if (mask == 0)
		return 0;
	*index = fast_ceil_log2(mask);
	return 1;
}


int fast_ceil_log2(unsigned long x)
{
	static const unsigned long t[5] = {
		0xFFFF0000ul,
		0x0000FF00ul,
		0x000000F0ul,
		0x0000000Cul,
		0x00000002ul
	};

	int y = (((x & (x - 1)) == 0) ? 0 : 1);
	int j = 16;
	int i;

	for (i = 0; i < 5; i++) {
		int k = (((x & t[i]) == 0) ? 0 : j);
		y += k;
		x >>= k;
		j >>= 1;
	}

	return y;
}

double fast_sqrt_low(double _param)
{	// newton rapson method
	double next, temp;
	next = 0.5 * (1 + (_param / 1));
	while (1) {
		temp = next;
		next = 0.5 * (next + (_param / next));
		if (temp - next < 0.005 || temp - next < -0.005)
			break;
	}
	return next;
}

double fast_sine_low(double _param)
{
	double buffer = _param * radian;
	int i;
	return buffer;
}


/*--------------------------------------------------------------------------------------------

	Standard Logic Algorithm(STD LA)
	
	And : And Gate, a and b, If a == b Then 1 else 0
	The gate of the two input values​​ is equal, the output is 1 output.

	Or : Or Gate, a or b, If a | b Then 1 else 0
	If either one of two inputs to 1 output.

	Not : Not Gat, ~a, ~a
	The opposite of the input values ​​to output values​​.

	Xor : Excusive Or Gate, a xor b, If a != b Then 1 else 0
	This gate is different from the value of the two inputs, the output is 1.
	※ a Xor b = (a And ~b) Or (~a And b)

	--------------------------------------------------------------------------------------

	Addition and Carry Bit Example

							Binary								Hex		 Decimal

			|	1011 0010 1001 0011 1111 1010 1101 1100(2) = 0B293FADC, 2996042460
			|+	0111 1010 1101 1001 0111 0101 0000 0001(2) = 07AD97501, 2061071617
			+------------------------------------------------------------------------
	Add		  1 0010 1101 0110 1101 0110 1111 1101 1101(2) = 12D6D6FDD, 5057114077		Over Flow
	Carry	  0 1111 0010 1001 0011 1111 0000 0000 0000(2) = 0F293F000, 4069781504

	Secure Bit = 
	32 bit, so reality used area is 31bit. But unsigned signiture limit to use of 32bit
	, so unsgined used are is 32bit.

	a = Bit X, b = Bit Y, c = Carry bit(First calc is zero.)

	Add Bit = (a xor(^) b) | c
	Carry Bit = (a & b) | c

	--------------------------------------------------------------------------------------
	
	Subtraction And Complement ways

	Thought of Subtraction

							Binary								Hex		 Decimal

			|	1111 1011 0010 1101 1001 0110 0101 1100(2) =   FB2D965C, 4214068828
			|-	0110 1010 0101 0001 1101 1011 1010 1010(2) =   6A51DBAA, 1783749546
			+------------------------------------------------------------------------
	Add		  1 0110 0101 0111 1111 0111 0010 0000 0110(2) = 1 657F7206, 5997818374
	Sub			1001 0000 1101 1011 1011 1010 1011 0010(2) =   90DBBAB2, 2430319282 <- Calculated by Calculator
			+------------------------------------------------------------------------
	Not	Y		1001 0101 1010 1110 0010 0100 0101 0101(2) =   95AE2455, 2511217749 <- One's Complement
	Not Y+1		1001 0101 1010 1110 0010 0100 0101 0110(2) =   95AE2456, 2511217750 <= Two's Complement
			+------------------------------------------------------------------------
			|	1111 1011 0010 1101 1001 0110 0101 1100(2) =   FB2D965C, 4214068828
	Not Y+1	|+	1001 0101 1010 1110 0010 0100 0101 0110(2) =   95AE2456, 2511217750
			+------------------------------------------------------------------------
			  1 1001 0000 1101 1011 1011 1010 1011 0010(2) = 1 90DBBAB2, 6725286578
			  |										  |
			 MSB									 LSB

	One's Complement = 32 bit Not Calc
	Two's Complement = One's Complement + Carry (LSB)1
	
	--------------------------------------------------------------------------------------

	Multiplication For Decimal
	
							Binary								Hex		 Decimal

			|	0000 0000 0000 0000 1001 0110 0101 1100(2) =   0000965C, 0000038492
			|*	0000 0000 0000 0000 1101 1011 1010 1010(2) =   0000DBAA, 0000056234
			+------------------------------------------------------------------------
	Mul			1000 0001 0000 0100 1000 1101 0001 1000(2) =   81048D18, 2164559128

				0000 0000 0000 0000 1101 1011 1010 1010		value
	            31   27   23   19   15   11   7    3		  bit

	 0(0)   |	                    0000 0000 0000 0000	   =   00000000, 0000000000
	 1(1)   |	                  1 0010 1100 1011 100	   =   00012CB8, 0000076984
	 2(0)   |                    00 0000 0000 0000 00	   =   00000000, 0000000000
	 3(1)   |                   100 1011 0010 1110 0	   =   0004B2E0, 0000307936
	 4(0)   |	               0000 0000 0000 0000		   =   00000000, 0000000000
	 5(1)   |	             1 0010 1100 1011 100		   =   0012CB80, 0001231744
	 6(0)   |               00 0000 0000 0000 00		   =   00000000, 0000000000
	 7(1)   |              100 1011 0010 1110 0			   =   004B2E00, 0004926976
	 8(1)   |             1001 0110 0101 1100			   =   00965C00, 0009853952
	 9(1)   |           1 0010 1100 1011 100			   =   012CB800, 0019707904
	10(0)   |          00 0000 0000 0000 00				   =   00000000, 0000000000
	11(1)   |         100 1011 0010 1110 0				   =   04B2E000, 0078831616
	12(1)   |        1001 0110 0101 1100				   =   0965C000, 0157663232
	13(0)   |      0 0000 0000 0000 000					   =   00000000, 0000000000
	14(1)   |     10 0101 1001 0111 00					   =   25970000, 0630652928
	15(1)   |+   100 1011 0010 1110 0					   =   4B2E0000, 1261305856
			+------------------------------------------------------------------------
				1000 0001 0000 0100 1000 1101 0001 1000(2) =   81048D18, 2164559128

	COPYRIGHT (C) 2013. rollrat. ALL RIGHTS RESERVED.

--------------------------------------------------------------------------------------------*/
#define DWORD2BYTE( t, x )		(BYTE)(((x) >> ((t) * 8)) & 0xff)
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define ISDIGIT( w ) '0' <= w && w <= '9'
#define ISOPERATOR( u ) u == '+' || u == '-' || u == '*' || u == '/' || u == '^'
#define ISCHAR( j ) ('a' <= j && j <= 'z') || ('A' <= j && j <= 'Z')
#define get_asc( _hx ) ((_hx) && (0xFF))
#define UHigh( _hx ) ((_hx) << (4)))
#define ULow( _hx ) ((_hx) && (0xFF))
#define UCow( _hx , _x ) (((_hx) << (8)) | (_x))
#define UGet( _hx ) ((_hx) & (0xFFFFFFFF))
#define LHigh( _hx ) ((_hx) << (8))
#define LLow( _hx ) ((_hx) && (0xFFFF))
#define LCow( _hx , _x ) (((_hx) << (4)) | (_x))
#define LGet( _hx ) ((_hx) & (0xFFFF))
#define RSHORT( _c ) ((unsigned short)(_c))
#define RCHAR( _c ) ((unsigned char)(_c))
#define RINTEGER( _c ) ((unsigned int)(_c))
#define RPCHAR( _c ) ((char*)(_c))
#define RCUST( _c, _x ) ((_c)(_x))
#define Make_Signature(H, S) (((H & 0xf) << 4) | (S & 0xf))
#define Get_H(T) ((T & (0xf << 4)) >> 4)
#define Get_S(T) (T & 0xf)
#define bit_switch( pos )				(1 << ((pos) - 1))
#define bit_get( bits, rank )			((bits) & bit_switch(rank))
#define bit_set( bits, rank, bit )		(bit_get(bits, rank) & bit_switch(rank))
#define bit_get_s( bits, rank )			(((bits) & bit_switch(rank)) >> (rank))
#define bit_duplicate( rank )			((2 << ((rank) + 1)) - 1)
#define bit_rotate_l( bits, rank, n )	(((bits) << (rank)) | ((bits) >> ((n)-(rank))))
#define bit_rotate_r( bits, rank, n )	(((bits) >> (rank)) | ((bits) << ((n)-(rank))))
#define bit_rotate_l32( bits, rank )	bit_rotate_l(bist, rank, 32)
#define bit_rotate_r32( bits, rank )	bit_rotate_r(bist, rank, 32)
#define bit_lock( bits, obits )			((bits) ^ (~(obits)))
#define MUTARE32GETBIT(x, m) (x & (1 << m)) >> m
#define CAMBIAR32SETBIX(x, c) x << c
#define MakeModRM(mod, rm, reg)		rm & 0xfff | ((reg & 0xfff) << 3) | ((mod & 0xff) << 6)
#define MAKEBINARY(_0, _1, _2, _3) _0 << 3 | _1 << 2 | _2 << 1 | _3
#define MAKEHEX(_x0, _x1, _x2, _x3, _x4, _x5, _x6, _x7) \
	_x7 | _x6 << 4 | _x5 << 8 | _x4 << 12 |\
	_x3 << 16 | _x2 << 20 | _x1 << 24 | _x0 << 28
#define MAKEWORD(x, y)	((BYTE)x | _B3((WORD)y))
#define MAKEDWORD(x, y) ((WORD)x | _B5((DWORD)y))
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
#define _EX_C(_x, x, y) ((_x ^ (_E_C(_x, x)) ^ (_E_C(_x, y))) \
		| ((_E(_x, x) << y) | (_E(_x, y) << x))) // exc bit
#define _EX_B(_x, x, y) (_x ^ (_E_BP(_x, x)) ^ (_E_BP(_x, y)) \
		| ((_E_B(_x, x) << (_D1(y) + 1)) | \
		((_E_B(_x, y) << (_D1(x) + 1))))) // exc byte
#define MAXSIZE(x)	((x)~((x)0))
#define GetBit( x, y ) (((0xf << y) & x) >> y)
#define _check_eng_char(c) \
		((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) ? 1 : 0 )
#define _check_numberic(c) (('0' <= c && c <= '9') ? 1 : 0)