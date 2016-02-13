/*
 *	Rollrat Api
 *
 *	Function Gropup
 */

#if !defined(_R_API_MATH_)
#define _R_API_MATH_

#include "Type.h"

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define inc(a)				((a) + 1)
#define dei(a)				((a) - 1)
#define abs(num)			(num > 0 ? num : ( num * -1 ))
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
	return NEXT;
}

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
	return Operand * Operand;
}

LDKORK
RECI
(
	LDKORK Operand
	)
{
	return Div(1, Operand);
}

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
	return i;
}

LDKORK
NI
(
	LDKORK Operand
	)
{
	return 1 + Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5) + Tf(6) + 
		Tf(7) + Tf(8) + Tf(9) + Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) + Tf(15) + 
		Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20);
}

LDKORK
IN
(
	LDKORK Operand
	)
{
	return Tf(1) - Tf(2) + Tf(3) - Tf(4) + Tf(5) - Tf(6) + Tf(7) - Tf(8) + Tf(9) - Tf(10) +
		Tf(11) - Tf(12) + Tf(13) - Tf(14) + Tf(15) - Tf(16) + Tf(17) - Tf(18) + Tf(19) - Tf(20);
}

LDKORK
SIN
(
	LDKORK Operand
	)
{
	Operand *= RATIO;
	return Operand - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11);
}

LDKORK
COS
(
	LDKORK Operand
	)
{
	Operand *= RATIO;
	return 1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10);
}

LDKORK
TAN
(
	LDKORK Operand
	)
{
	Operand *= RATIO;
	return Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9) + Tff(353792,11,11);
}

LDKORK
LOG
(
	LDKORK Operand
	)
{
	return Div(IN(Operand),2.30258);
}

LDKORK
SOLVER_QUADRATIC_D
(
	LDKORK a,
	LDKORK b,
	LDKORK c
	)
{
	return SQUARE(b,1) - 4 * b * c;
}

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
		return (-1 * b + SQRT(SOLVER_QUADRATIC_D(a,b,c))) / (2 * a);
	}else if (Type){
		return (-1 * b - SQRT(SOLVER_QUADRATIC_D(a,b,c))) / (2 * a);
	}else{
		return (0);
	}
}


#endif