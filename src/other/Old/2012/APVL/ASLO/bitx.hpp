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

#ifndef __bitx
#define __bitx

#include "aslo.hpp"

#define True		1
#define False		0

//
//	ASLO BITX BIT CLASS
//
template<class _Tx = unsigned short> class
	_Aslo_Bit
	{ // Aslo Bit
	_Tx bits : 1;
public:
	ONLY_WRITE void operator=(_Tx t)
		{ // write bit
			bits = t;
		}
	_Tx operator*()
		{ // get bit
			return bits;
		}
	ONLY_READ _Tx operator()(int i)
		{ // get bit after bit shift
			return bits << i;
		}
	void operator&(_Tx t)
		{ // and logic
			bits &= t;
		}
	void operator|(_Tx t)
		{ // or logic
			bits &= t;
		}
	void operator^(_Tx t)
		{ // xor logic
			bits ^= t;
		}
	void operator~()
		{ // not logic
			bits = ~bits;
		}
	};

//
//	ASLO BITX BYTE CLASS
//
template<class _Tx = unsigned short> class
	_Aslo_Byte
	{ // Aslo Byte
	_Aslo_Bit<> bits[8];
public:
	ONLY_WRITE void operator=(_Tx t)
		{ // write byte
			for(int i = 0; i < 8; i++)
				bits[i] = (t & (1 << i)) >> i;
		}
	_Tx operator*()
		{ // get byte
			_Tx x = 0;
			for(int i = 0; i < 8; i++)
				x |= *bits[i] << i;
			return x;
		}
	ONLY_READ _Tx operator()(int i)
		{ // get bit
			return *bits[i];
		}
	void operator<<(int i)
		{ // shift and rotate
			_Tx xty = 0;
			for(int xt = 0; xt < i; xt++)
			{
				xty = *bits[7];
				for(int i = 0; i < 7; i++)
					bits[i + 1] = *bits[i];
				bits[0] = xty;
			}
		}
	void operator>>(int i)
		{ // shift and rotate
			_Tx xty = 0;
			for(int xt = 0; xt < i; xt++)
			{
				xty = *bits[0];
				for(int i = 7; i < 7; i++)
					bits[i - 1] = *bits[i];
				bits[7] = xty;
			}
		}
	void operator~()
		{ // not logic
			for(int i = 0; i < 8; i++) 
				~bits[i];
		}
	void operator&&(_Tx t)
		{ // and logic
			for(int i = 0; i < 8; i++) 
				bits[i] & t;
		}
	void operator||(_Tx t)
		{ // or logic
			for(int i = 0; i < 8; i++) 
				bits[i] | t;
		}
	void operator<(_Tx t)
		{ // xor logic
			for(int i = 0; i < 8; i++)
				bits[i] ^ t;
		}
	void operator&(_Tx t)
		{ // and logic expand
			for(int i = 0; i < 8; i++) 
				bits[i] & (t & (1 << i)) >> i;
		}
	void operator|(_Tx t)
		{ // or logic expand
			for(int i = 0; i < 8; i++) 
				bits[i] | (t & (1 << i)) >> i;
		}
	void operator^(_Tx t)
		{ // xor logic expand
			for(int i = 0; i < 8; i++) 
				bits[i] ^ (t & (1 << i)) >> i;
		}
	template<class _Ty>
		void operator&(_Aslo_Byte<_Ty> t)
			{ // and logic expand
				for(int i = 0; i < 8; i++)
					bits[i] & (t(i) & (1 << i)) >> i;
			}
	template<class _Ty>
		void operator|(_Aslo_Byte<_Ty> t)
			{ // or logic expand
				for(int i = 0; i < 8; i++)
					bits[i] | (t(i)  & (1 << i)) >> i;
			}
	template<class _Ty>
		void operator^(_Aslo_Byte<_Ty> t)
			{ // xor logic expand
				for(int i = 0; i < 8; i++)
					bits[i] ^ (t(i)  & (1 << i)) >> i;
			}
	};

typedef _Aslo_Byte<char> Char;

#endif