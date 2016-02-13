/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

/*
	          이프로젝트는 rollrat에 의하여 시작되었습니다.
                                                                 */

#pragma once
#ifndef _ROLLRAT_CPU_STRUCTURE_
#define _ROLLRAT_CPU_STRUCTURE_

/*=================================================================
	
	Enum Info : - ENU_LOGIC_OPCODE -

	이 부분에서 cpu의 opcode가 정의됩니다.

=================================================================*/
typedef enum ENU_LOGIC_OPCODE
{
	and		=	0,
	or		=	1,
	not		=	2,
	xor		=	3,
	nand	=	4,
	xnor	=	5,
	nor		=	6,
	add		=	7,
	sub		=	8,
	lshift	=	9,
	rshift	=  10,
#ifndef CPUINFOMATION_ALL_EXPOSEDATA
	mov		=  11,
#endif
};

/*=================================================================
	
	Define Info : The CPU typedef or redefined source.

=================================================================*/
typedef unsigned long long	LOGICCALCULATIONEXPOSEDATA;
typedef unsigned long long	LOGICEXPOSEDATA_ALLUSEDINCPU_INDOOR;
typedef long long			LOGICCALCULATION_SIGNED_INTEGER;
typedef float				LOGIC_SIGNED_IFLOATINGPOINTOBJECT;
typedef bool				LOGICCALCULATIONTRUEORFALSE;

// 연산중 오류가 발생했습니다.
#define LOGICCALCULATIONERROR	(0x8700F)

// 보통 이 정의가 나오면 사용되지않은 변수가 입력되었다는뜻입니다.
#define DISABLEDLOGIC			break;

// 
#define UNLIGHT	false
#define LIGHT	true

/*=================================================================
	
	Class Info : - Logic_X  -

=================================================================*/
class Logic_X
{
public:

	LOGICCALCULATIONEXPOSEDATA 
	CACULATION_LOGICEVENT(
		ENU_LOGIC_OPCODE elo,				// op-code의 변수입니다.
		LOGICCALCULATIONEXPOSEDATA lced_1,	// 기본 입력타입 1
		LOGICCALCULATIONEXPOSEDATA lced_2	// 기본 입력타입 2
		)
	{
		switch( elo )
		{
		case and:
			return lced_1 && lced_2;
		case or:
			return lced_1 || lced_2;
		case not:		DISABLEDLOGIC
		case xor:
			return lced_1 ^ lced_2;
		case nand:
			return !(CACULATION_LOGICEVENT(and, lced_1, lced_2));
		case xnor:
			return !(CACULATION_LOGICEVENT(xor, lced_1, lced_2));
		case nor:
			return !(CACULATION_LOGICEVENT(or, lced_1, lced_2));
		case add:		DISABLEDLOGIC
		case sub:		DISABLEDLOGIC
		case lshift:	DISABLEDLOGIC
		case rshift:	DISABLEDLOGIC
		}
		return LOGICCALCULATIONERROR;
	}

	LOGICCALCULATIONEXPOSEDATA 
	CACULATION_LOGICEVENT(
		ENU_LOGIC_OPCODE elo,				// op-code의 변수입니다.
		LOGICCALCULATIONEXPOSEDATA lced,		// 기본 입력타입
		int shp								// 2번째 연산비트
		)
	{
		switch( elo )
		{
		case and:	DISABLEDLOGIC
		case or:	DISABLEDLOGIC
		case not:	DISABLEDLOGIC
		case xor:	DISABLEDLOGIC
		case nand:	DISABLEDLOGIC
		case xnor:	DISABLEDLOGIC
		case nor:	DISABLEDLOGIC
		case add:	DISABLEDLOGIC
		case sub:	DISABLEDLOGIC
		case lshift:
			return lced << shp;
		case rshift:
			return lced >> shp;
		}
		return LOGICCALCULATIONERROR;
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	AND(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2
		)
	{
		switch( lced_1 )
		{
		case LIGHT:
			if (lced_2 == LIGHT)
				return LIGHT;
		}
		return UNLIGHT;
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	OR(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2
		)
	{
		if (lced_1 == LIGHT)
			return LIGHT;
		if (lced_2 == LIGHT)
			return LIGHT;
		return UNLIGHT;
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	NOT(
		LOGICCALCULATIONTRUEORFALSE lced
		)
	{
		if (lced == LIGHT)
			return UNLIGHT;
		else if (lced == UNLIGHT)
			return LIGHT;
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	XOR(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2
		)
	{
		return OR( 
			AND( NOT( lced_1 ),lced_2 ), 
			AND( lced_1 , NOT( lced_2 ))
			);
	}

	
	inline
	LOGICCALCULATIONTRUEORFALSE
	NAND(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2
		)
	{
		return NOT(
			AND(lced_1, lced_2)
			);
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	NOR(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2
		)
	{
		return NOT(
			OR(lced_1, lced_2)
			);
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	XNOR(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2
		)
	{
		return NOT(
			XOR(lced_1, lced_2)
			);
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	ADD_GET_BOUT(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2,
		LOGICCALCULATIONTRUEORFALSE carry
		)
	{
		//http://rkddlsghk98.blog.me/30159264363
		return 
			XOR(
			XOR(lced_1, lced_2), 
			carry
			) ? LIGHT : UNLIGHT;
	}

	inline
	LOGICCALCULATIONTRUEORFALSE
	ADD_GET_CARRY(
		LOGICCALCULATIONTRUEORFALSE lced_1,
		LOGICCALCULATIONTRUEORFALSE lced_2,
		LOGICCALCULATIONTRUEORFALSE carry
		)
	{
		//http://rkddlsghk98.blog.me/30159264363
		return OR(
			AND(XOR(lced_1, lced_2), carry),
			AND(lced_1, lced_2)
			) ? LIGHT : UNLIGHT;
	}

};

/*=================================================================
	
	Class Info : - ENDECORDER -

=================================================================*/
class ENDECORDER
{
	struct ENCODERSTRUCTURE
	{
		LOGICCALCULATIONEXPOSEDATA IF_START_POS;
		LOGICCALCULATIONEXPOSEDATA THEN_OUTPUT;
	};

public:

	ENDECORDER()
		: size(0)
		{
		}

	void
	NEW_DATA(
		LOGICCALCULATIONEXPOSEDATA IF_START_POS,
		LOGICCALCULATIONEXPOSEDATA THEN_OUTPUT
		)
	{
		ENCODERSTRUCTURE* BUF = new ENCODERSTRUCTURE[size + 1];
		for(int i = 0; size <= i; i++)
			BUF[i] = ENCODERBUFFER[i];
		size++;
		ENCODERBUFFER = BUF;
		ENCODERBUFFER[size].IF_START_POS = IF_START_POS;
		ENCODERBUFFER[size].THEN_OUTPUT = IF_START_POS;
	}

	LOGICCALCULATIONEXPOSEDATA
	GET_DATA(
		LOGICCALCULATIONEXPOSEDATA IF_START_POS
		)
	{
		for(int i = 0; i <= size; i++)
			if(ENCODERBUFFER[i].IF_START_POS == IF_START_POS)
				return ENCODERBUFFER[i].THEN_OUTPUT;
		return LOGICCALCULATIONERROR;
	}

private:

	int size;
	ENCODERSTRUCTURE* ENCODERBUFFER;

};

#endif