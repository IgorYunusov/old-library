/*
 *
 *			ROLLRAT SOFTWARE
 *			SINCE : 2009 - 2012
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#if !defined(_mathlib_) /* !(_mathlib_)  */

#if !defined(_Typedef_STD_)
#define _Typedef_STD_
#define UNI				unsigned
typedef						int				BOOL		;
typedef UNI					int				UINT		;
typedef UNI					long			DWORD		;
typedef UNI					char			BYTE		;
typedef UNI					short			WORD		;
typedef UNI					long			ULONG		;
typedef UNI					short			USHORT		;
typedef						char	*		PCHAR		;
typedef						int		*		PINT		;
typedef	UNI					int		*		UPINT		;
typedef						double			DKORK		;
typedef long				double			LDKORK		;
#endif

LDKORK
MATHLIB_SQUARE
(
	LDKORK	Operand, 
	DWORD	Operator
	)
{
	while(Operator--)
	{
		Operand *= Operand;
	}
	return Operand;
}

DWORD
MATHLIB_PERMUTATION
(
	DWORD	Operand,
	DWORD	Operator
	)
{
	DWORD	i;
	i = Operand;
	while(i-- > Operator)
	{
		Operand *= i;
	}
	return Operand;
}

DWORD
MATHLIB_FACTORIAL
(
	DWORD Operand
	)
{	
	DWORD i;
	if(Operand >= 2)
	{
		i = Operand * MATHLIB_FACTORIAL(Operand-1);
	}else{
		i=1;
	}
	return i;
}

DWORD
MATHLIB_COMBINATION
(
	DWORD Operand,
	DWORD Operator
	)
{
	return MATHLIB_PERMUTATION(Operand,Operator) 
		/ 
		MATHLIB_FACTORIAL(Operator);
}


#endif /* !(_mathlib_)  */