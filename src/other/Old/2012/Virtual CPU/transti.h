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

#ifndef __TRANSTI		// with parts of aslo
#define __TRANSTI

// transti.hpp

#define True		1
#define False		0

template<class _Tx = unsigned short> class
	_Aslo_Bit
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

#define Transti		_Aslo_Bit<>

#endif