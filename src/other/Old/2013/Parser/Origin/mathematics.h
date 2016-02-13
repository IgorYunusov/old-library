/*
            ROLLRAT MATHEMATICS PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _MATHEMATICS_
#define _MATHEMATICS_
#pragma once

#define MathZero		(0L)

#define THROW_OVERFLOWMAP			1L
#define THROW_OVERRAP				2L

// MATRIX

#define THROW_NOT_MATCHED			3L



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

#define MUTARE32GETBIT(x, m)	(x & (1 << m)) >> m
#define CAMBIAR32SETBIX(x, c)	x << c

#define True		1
#define False		0

#define _NOUSED

typedef unsigned int			uint_t;
typedef unsigned long int		uint32_t;
typedef unsigned long long int	uint64_t;


		// METAPROGRAMMING
#ifdef _WIN32
#define T_UINT template<uint32_t _Val>
#define T_UINT2 template<uint32_t _Val1, uint32_t _Val2>
#define UINT	uint32_t
#else
#define T_UINT template<uint64_t _Val>
#define T_UINT2 template<uint64_t _Val1, uint64_t _Val2>
#define UINT	uint64_t
#endif

// COMPILER UNROLLING

		// FACTORIAL
T_UINT class Factorial
	{
public:
	static const UINT value = (_Val * Factorial<_Val - 1>::value);
	};
template<>
class Factorial<1> // with zero
	{
public:
	static const UINT value = 1;
	};


		// PERMUTATION
T_UINT2 class Permutation
	{
public:
	static const UINT value = (_Val1 * Permutation<_Val1 - 1, _Val2 - 1>::value);
	};
T_UINT class Permutation<_Val, 0>
	{
public:
	static const UINT value = 1;
	};


		// COMBINATION
T_UINT2 class Combination
	{
public:
	static const UINT value = (Permutation<_Val1, _Val2>::value / Factorial<_Val2>::value);
	};


		// COMBINATION WITH REPETITION
T_UINT2 class Repetition
	{
public:
	static const UINT value = (_Val1 * Permutation<_Val1, _Val2 - 1>::value);
	};
T_UINT class Repetition<_Val, 0>
	{
public:
	static const UINT value = 1;
	};


		// LOOP UNROLLING
template<UINT _Val, typename _Func>
class Unrolling
	{
public:
	static inline void Do(_Func _Function)
		{
		Unrolling<_Val - 1, _Func>::Do(_Function);
		_Function();
		}
	};
template<typename _Func>
class Unrolling<-1, _Func>
	{
public:
	static inline void Do(_Func _Function)
		{
		}
	};

// Vector Type

template<typename _Type>
class Scalar
	{
public:
	_Type x, y, z;
	};

template<typename _Type, typename _Angle = double>
class Vector
	: public Scalar<_Type>
	{
public:
	_Angle x, y;
	};

template<typename _Type>
class Quaternion
	{
public:
	_Type i, j, k;
	};

#endif