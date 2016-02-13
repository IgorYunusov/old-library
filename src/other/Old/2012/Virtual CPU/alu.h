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

#ifndef __ALU
#define __ALU

#include "bitWord.h"
#include "eflag.h"

typedef unsigned int ALU_BIT;

/*--------------------------------------------------------------------------------------------

		Arithmetic and Logic Unit

--------------------------------------------------------------------------------------------*/

class _32bitALU 
	{ // 32 bit ALU
	EFLAGS eFlags;
	ALU_BIT LastCacheAddress;
	Transti *Lolc;

	Transti **MemoryArea;
public:

	void MemSet(Transti**& memarea)
		{
			MemoryArea = memarea;
		}

	void New()
		{
			eFlags = EFLAGS_LOCK;
		}

	void And(Transti *X, Transti *Y)
		{ // And Logic
			Transti *buxa = Mutare32_s(0);
			for(int f = 0; f < 32; f++)
				buxa[f] = transAnd(X[f], Y[f]);
			Lolc = buxa;
		}

	void Or(Transti *X, Transti *Y)
		{ // Or Logic
			Transti *buxa = Mutare32_s(0);
			for(int f = 0; f < 32; f++)
				buxa[f] = transOr(X[f], Y[f]);
			Lolc = buxa;
		}

	void Not(Transti *X)
		{ // Not Logic
			Transti *buxa = Mutare32_s(0);
			for(int f = 0; f < 32; f++)
				buxa[f] = transVer(X[f]);
			Lolc = buxa;
		}

	void Xor(Transti *X, Transti *Y)
		{ // Xor Logic
			Transti *buxa = Mutare32_s(0);
			for(int f = 0; f < 32; f++)
				buxa[f] = excuXor(X[f], Y[f]);
			Lolc = buxa;
		}

	void Add(Transti *X, Transti *Y)
		{ // Add
			Transti *buxa = Mutare32_s(0);
			Transti Carry;
			Carry = 0;
			for(int f = 0; f < 32; f++)
			{
				buxa[f] = HalfAddBit(X[f], Y[f], Carry);
				Carry = GetCarry(X[f], Y[f], Carry);
			}
			if(*Carry == True)
				eFlags |= EFLAGS_OVERFLOW;
			Lolc = buxa;
		}

	};

#endif
