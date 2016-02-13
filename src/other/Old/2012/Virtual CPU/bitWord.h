/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *					SPIN OFF PROJECT Vol 1						*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef __BITWORD		// Bit & Status Word
#define __BITWORD

#include "transti.h"

#define MUTARE32GETBIT(x, m)	(x & (1 << m)) >> m
#define CAMBIAR32SETBIX(x, c)	x << c

/*--------------------------------------------------------------------------------------------

		Intel Architecture 16, 32 And 64 BIT REGISTER LIST

--------------------------------------------------------------------------------------------*/

typedef struct REGISTER16 {
	unsigned int ax : 16;	// Accumulator Register
	unsigned int bx : 16;	// Base Register
	unsigned int cx : 16;	// Counter Register
	unsigned int dx : 16;	// Datat Register
	unsigned int si : 16;	// Source Index
	unsigned int di : 16;	// Destination Index
	unsigned int bp : 16;	// Base Pointer
	unsigned int sp : 16;	// Stack Pointer
}	Reg16, *PTR_Reg16;

typedef struct REGISTER32 {
	unsigned int eax;	// Extanded Accumulator Register
	unsigned int ebx;	// Extanded Base Register
	unsigned int ecx;	// Extanded Counter Register
	unsigned int edx;	// Extanded Datat Register
	unsigned int esi;	// Extanded Source Index
	unsigned int edi;	// Extanded Destination Index
	unsigned int ebp;	// Extanded Base Pointer
	unsigned int esp;	// Extanded Stack Pointer
}	Reg32, *PTR_Reg32;

typedef struct SEGMENTREGISTER {
	unsigned int cs : 16;	// Code Segment
	unsigned int ds : 16;	// Data Segment
	unsigned int es : 16;	// Extra Segment
	unsigned int fs : 16;	// ??
	unsigned int gs : 16;	// ??
	unsigned int ss : 16;	// Stack Segment
}	SegReg, *PTR_SegReg;


/*--------------------------------------------------------------------------------------------

		Transformation Function

--------------------------------------------------------------------------------------------*/

Transti *Mutare16(unsigned int t)
{ // :16 -> Transti
	static Transti buxa[16];
	int i;
	for(i = 0; i < 16; i++)
		buxa[i] = MUTARE32GETBIT(t, i);
	return buxa;
}

Transti *Mutare32(unsigned int t)
{ // :32 -> Transti
	static Transti buxa[32];
	int i;
	for(i = 0; i < 32; i++)
		buxa[i] = MUTARE32GETBIT(t, i);
	return buxa;
}

Transti *Mutare16_s(unsigned int t)
{ // :16 -> Transti with Alloc
	Transti *buxa;
	int i;
	buxa = new Transti[16];
	for(i = 0; i < 16; i++)
		buxa[i] = MUTARE32GETBIT(t, i);
	return buxa;
}

Transti *Mutare32_s(unsigned int t)
{ // :32 -> Transti with Alloc
	Transti *buxa;
	int i;
	buxa = new Transti[32];
	for(i = 0; i < 32; i++)
		buxa[i] = MUTARE32GETBIT(t, i);
	return buxa;
}

unsigned int Cambiar16(Transti *buxa)
{ // Transti -> :16
	unsigned int x;
	int i;
	for(i = 0; i < 16; i++)
		x = CAMBIAR32SETBIX(*buxa[i], i);
	return x;
}

unsigned int Cambiar32(Transti *buxa)
{ // Transti -> :32
	unsigned int x;
	int i;
	for(i = 0; i < 32; i++)
		x = CAMBIAR32SETBIX(*buxa[i], i);
	return x;
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

--------------------------------------------------------------------------------------------*/

inline Transti transBuf(Transti x, Transti &y)
{ // -> buf
	y = *x;
	return y;
}

inline Transti transAnd(Transti x, Transti y)
{ // -> x & y
	Transti bux;
	bux = *x;
	if(*x == True)
		bux = *y;
	if(*bux == True)
		bux = *x;
	return bux;
}

inline Transti transOr(Transti x, Transti y)
{ // -> x | y
	Transti bux;
	bux = *x;
	if(*x == False)
		bux = *y;
	if(*bux == False)
		bux = *x;
	return bux;
}

inline Transti transVer(Transti xy)
{ // -> x !
	Transti bux;
	bux = *xy;
	if(*bux == False)
		bux = True;
	else
		bux = False;
	return bux;
}

inline Transti excuXor(Transti x, Transti y)
{ // -> x ^ b
	Transti bux;
	bux = *x != *y;
	return bux;
}

inline Transti GetCarry(Transti x, Transti y, Transti c)
{ // get carry function
	return transOr(transAnd(x, y), c);
}

inline Transti HalfAddBit(Transti x, Transti y, Transti c)
{ // get add function
	return transOr(excuXor(x, y), c);
}


/*--------------------------------------------------------------------------------------------

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

--------------------------------------------------------------------------------------------*/

#endif
