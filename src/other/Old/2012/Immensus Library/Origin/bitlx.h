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

#ifndef _BITLX_
#define _BITLX_

#define MUTARE32GETBIT(x, m)	(x & (1 << m)) >> m
#define CAMBIAR32SETBIX(x, c)	x << c

// Level 1 Field
template<class _Tx = unsigned short> class
	_Immensus_Tlx
	{ // Aslo Bit
	_Tx bits : 1;	// 1 bit field
public:
	void operator=(_Tx t)
		{ // write bit
			bits = t;
		}
	_Tx operator*()
		{ // get bit
			return bits;
		}
	};

// Level 1 Field
template<class _Tx = unsigned short> class
	_ICHet_Tlx
	{ // CHet Bit
	_Tx byte : 8;
public:
	void operator=(_Tx t)
		{ // write byte
			byte = t;
		}
	_Tx operator*()
		{ // get byte
			return byte;
		}
	};

#define L1IMMETX		_Immensus_Tlx<>

// Level 2 Field
template<class _Tx = _Immensus_Tlx<>, class 
	_Tlx = _ICHet_Tlx<>
	> class _IAleph_Field_TX
	{ // Aleph Field
	_Tx *terro;
	unsigned int count;
public:
	_IAleph_Field_TX() : count(0) {}
	void operator+=(_Tx Tx)
		{
		}
	};

#define L2IMMETX		_IAleph_Field_TX<>

#define True		1
#define False		0

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

--------------------------------------------------------------------------------------------*/

namespace L1Field
{
	inline L1IMMETX Buf(L1IMMETX x, L1IMMETX &y) 
	{ // -> buf
		y = *x; 
		return y; 
	}
	inline L1IMMETX And(L1IMMETX x, L1IMMETX y) 
	{ // -> x & y
		L1IMMETX bux; bux = *x;
		if(*x == True) 
			bux = *y;
		if(*bux == True) 
			bux = *x; 
		return bux; 
	}
	inline L1IMMETX Or(L1IMMETX x, L1IMMETX y) 
	{ // -> x | y
		L1IMMETX bux; 
		bux = *x;
		if(*x == False) 
			bux = *y;
		if(*bux == False) 
			bux = *x; 
		return bux; 
	}
	inline L1IMMETX Verbote(L1IMMETX xy) 
	{ // -> x !
		L1IMMETX bux; 
		bux = *xy;
		if(*bux == False) 
			bux = True;
		else bux = False; 
		return bux; 
	}
	inline L1IMMETX Xor(L1IMMETX x, L1IMMETX y) 
	{ // -> x ^ b
		L1IMMETX bux; 
		bux = *x != *y; 
		return bux; 
	}
	inline L1IMMETX Carry(L1IMMETX x, L1IMMETX y, L1IMMETX c) 
	{ // get carry function
		return Or(And(x, y), c); 
	}
	inline L1IMMETX AddBit(L1IMMETX x, L1IMMETX y, L1IMMETX c) 
	{ // get add function
		return Or(Xor(x, y), c); 
	}
}

#endif