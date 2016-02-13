/*
 *
 *			ROLLRAT SOFTWARE
 *			SINCE : 2009 - 2012
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#if !defined(_Number_) /* !(_Number_)    */

#include "rlimit.h"
#include "rmathlib.h"

#define _Number_

#define Null		0

#define True		1
#define False		0

#define BC
#define FAR
#define NEAR
#define HC
#define KOPE
#define OPPE
#define POINT
#define POINT_RESET

#define KOKE_RET	KOPE		FAR		return
#define OPPE_RET	OPPE		FAR		return
#define KOKE_RET_N	KOPE		NEAR	return
#define OPPE_RET_N	OPPE		NEAR	return

#define RAPLE_RETURN
#define COPLE_RETURN

#define RECURSIVE_FUNCTION
#define GENENAL_RECURSIVE_FUNCTION
#define GENENAL_FUNCTION
#define REVERSE_FUNCTION

#define ORTHOGONAL_COORDINATES_SYSTEM

#define POLAR_COORDINATES
#define POLAR_COORDINATES_SYSTEM	POLAR_COORDINATES


#define LIMIT_
#define LIMIT_ZERO
#define LIMIT_LIMIT
#define LIMIT_DIFFERENTIAL

#define DIFFERENTIAL
#define REVERSE_DIFFERENTIAL		REVERSE_FUNCTION DIFFERENTIAL
#define INTEGRAL
#define DIFFERENTIAL_COEFFICIENT
#define INTEGRATING_FACTOR
#define REVERSE_INTEGRAL			REVERSE_FUNCTION

#define SMALLEST					ORTHOGONAL_COORDINATES_SYSTEM
#define GREATEST					ORTHOGONAL_COORDINATES_SYSTEM

#define EQUATION

#define EQUATION_DIFFERENTIAL		DIFFERENTIAL					EQUATION
#define EQUATION_POLAR_COORDINATES									EQUATION

#if !defined(_Typedef_STD_)
#define _Typedef_STD_
#define UNI				unsigned
typedef						int				BOOL		;
typedef UNI					int				UINT		;
typedef UNI					long			DWORD		;
typedef UNI					char			BYTE		;
typedef UNI					short			WORD		;
typedef UNI					long			ULONG		;
//typedef UNI					float			UFLOAT		;
typedef UNI					short			USHORT		;
typedef						char	*		PCHAR		;
typedef						int		*		PINT		;
typedef	UNI					int		*		UPINT		;
typedef						double			DKORK		;
//typedef	UNI					double			UDKORK		;
typedef long				double			LDKORK		;
#endif

#define brk					break

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define inc(a)				((a) + 1)
#define dei(a)				((a) - 1)
#define abs(num)			( num > 0 ? num : ( num * -1 ))
#define LDAdd(a,b)			((long double)(a) + (long double)(b))
#define LDSub(a,b)			((long double)(a) - (long double)(b))
#define LDDiv(a,b)			((long double)(a) / (long double)(b))
#define LDMul(a,b)			((long double)(a) * (long double)(b))
#define Add(a,b)			((a) + (b))
#define Sub(a,b)			((a) - (b))
#define Div(a,b)			((a) / (b))
#define Mul(a,b)			((a) * (b))
#define Mov(a,b)			((a) % (b))

#define E					2.71828182845904523536
#define PI					3.14159265358979323846
#define RATIO				0.01745329251994329576923690768489

#define Tf(x)				Div(SQUARE(Operand, x),		FACT(x))
#define Tff(x, y, z)		Div(SQUARE(Operand, x) * y,	FACT(z))

GENENAL_FUNCTION
DWORD
AddFunc
( 
	DWORD Operator, 
	DWORD Operand 
	)
{
	KOKE_RET RAPLE_RETURN Operator + Operand;
}

GENENAL_FUNCTION
DWORD
SubFunc
( 
	DWORD Operator, 
	DWORD Operand 
	)
{
	KOKE_RET RAPLE_RETURN Operator - Operand;
}

GENENAL_FUNCTION
DWORD
DivFunc
( 
	DWORD Operator,
	DWORD Operand 
	)
{
	KOKE_RET RAPLE_RETURN Operator / Operand;
}

GENENAL_FUNCTION
DWORD
MulFunc
( 
	DWORD Operator, 
	DWORD Operand 
	)
{
	KOKE_RET RAPLE_RETURN Operator * Operand;
}

GENENAL_FUNCTION
DWORD
MovFunc
( 
	DWORD Operator, 
	DWORD Operand 
	)
{
	OPPE_RET RAPLE_RETURN Operator - (Operator / Operand) * Operand;
}

RECURSIVE_FUNCTION
LDKORK
SQRT
(
	LDKORK Operand
	)
{
	LDKORK NEXT, TEMP;
	NEXT = 0.5 * (1 + (Operand / 1));
	for(;;)
	{
		TEMP = NEXT;
		NEXT = 0.5 * (NEXT + (Operand / NEXT));
		if(TEMP - NEXT < 0.005 || TEMP - NEXT < - 0.005)
			brk;
	}
	KOKE_RET COPLE_RETURN NEXT;
}

RECURSIVE_FUNCTION
LDKORK
SQUARE
(
	LDKORK Operand,
	DWORD  Operator
	)
{
	while( Operator-- > 0 )
	{
		Operand *= Operand;
	}
	OPPE_RET RAPLE_RETURN Operand * Operand;
}

RECURSIVE_FUNCTION
LDKORK
RECI
(
	LDKORK Operand
	)
{
	OPPE_RET RAPLE_RETURN Div(1, Operand);
}

RECURSIVE_FUNCTION
LDKORK
FACT
(
	UINT Operand
	)
{
	LDKORK i;
	if(Operand >= 2)
	{
		i = Operand * FACT(Operand-1);
	}else{
		i=1;
	}
	KOKE_RET RAPLE_RETURN i;
}

RECURSIVE_FUNCTION
LDKORK
NI
(
	LDKORK Operand
	)
{
	OPPE_RET RAPLE_RETURN 1 + Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) + Tf(9) + Tf(10) +
		Tf(11) + Tf(12) + Tf(13) + Tf(14) + Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20);
}

RECURSIVE_FUNCTION
LDKORK
IN
(
	LDKORK Operand
	)
{
	OPPE_RET RAPLE_RETURN Tf(1) - Tf(2) + Tf(3) - Tf(4) + Tf(5) - Tf(6) + Tf(7) - Tf(8) + Tf(9) - Tf(10) +
		Tf(11) - Tf(12) + Tf(13) - Tf(14) + Tf(15) - Tf(16) + Tf(17) - Tf(18) + Tf(19) - Tf(20);
}

RECURSIVE_FUNCTION
LDKORK
SIN
(
	LDKORK Operand
	)
{
	Operand *= RATIO;
	OPPE_RET RAPLE_RETURN Operand - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11);
}

RECURSIVE_FUNCTION
LDKORK
COS
(
	LDKORK Operand
	)
{
	Operand *= RATIO;
	OPPE_RET RAPLE_RETURN 1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10);
}

RECURSIVE_FUNCTION
LDKORK
TAN
(
	LDKORK Operand
	)
{
	Operand *= RATIO;
	OPPE_RET RAPLE_RETURN Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9) + Tff(353792,11,11);
}

RECURSIVE_FUNCTION
LDKORK
LOG
(
	LDKORK Operand
	)
{
	OPPE_RET RAPLE_RETURN Div(IN(Operand),2.30258);
}

GENENAL_FUNCTION
LDKORK
SOLVER_QUADRATIC_D
(
	LDKORK a,
	LDKORK b,
	LDKORK c
	)
{
	OPPE_RET RAPLE_RETURN SQUARE(b,1) - 4 * b * c;
}

GENENAL_FUNCTION
LDKORK
SOLVER_QUADRATIC_FORMULA
(
	LDKORK a,
	LDKORK b,
	LDKORK c,
	UINT Type
	)
{
	if (Type == 0){
		OPPE_RET RAPLE_RETURN (-1 * b + SQRT(SOLVER_QUADRATIC_D(a,b,c))) / (2 * a);
	}else if (Type){
		OPPE_RET RAPLE_RETURN (-1 * b - SQRT(SOLVER_QUADRATIC_D(a,b,c))) / (2 * a);
	}else{
		OPPE_RET RAPLE_RETURN (0);
	}
}

#define sin					SIN
#define cos					COS
#define tan					TAN
#define sqrt				SQRT
#define in					IN
#define reci				RECI
#define log					LOG
#define fact				FACT

#define SOLVER_FIRST_FORMULA(g,f)	EQUATION	SOLVER_QUADRATIC_FORMULA(g,f,0,0)

#endif /* !(_Number_)    */