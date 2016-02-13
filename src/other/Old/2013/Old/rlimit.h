/*
 *
 *			ROLLRAT SOFTWARE
 *			SINCE : 2009 - 2012
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#if !defined(_LIMIT_) /* !(_LIMIT_)  */
#define _LIMIT_

#define Null		0

#define Computer_Limit			"LIMIT"

#define Limit_Mul				Computer_Limit
#define Limit_Div				Null

#define Vector_

#define Vector_Limit			Vector_
#define Vector_Lim				Vector_
#define Vector_Sover			Vector_

#define LIMIT					"LIM"
#define LIMIT_M					"MLIM"


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

typedef struct{
	LDKORK	Operand;
	LDKORK	Operator;
	BYTE	Oper[10];	
}	Math_Limit;

Math_Limit * Check_Null(LDKORK Operand)
{
	Math_Limit * MATH;
	MATH = Null;
	if (Operand < 0)
	{
		return Null;
	}
	MATH->Operand = Operand;
	return MATH;
}

Math_Limit * Check_Sof(char Operating)
{
	Math_Limit * MATH;
	MATH = Null;
	if (Operating == '+')
	{
		MATH->Oper[0] = '+';
	}
	else if(Operating == '-')
	{
		MATH->Oper[0] = '-';
	}
	else if(Operating == '*')
	{
		MATH->Oper[0] = '*';
	}
	else if(Operating == '/')
	{
		MATH->Oper[0] = '/';
	}
	else
	{
		MATH->Oper[0] = NULL;
	}
	return MATH;
}

PCHAR Limit_Calc_So(Math_Limit * MATH)
{
	switch(MATH->Oper[0]){
	case('+'):
		return LIMIT;
	case('-'):
		return LIMIT_M;
	case('*'):
		return LIMIT;
	case('/'):
		return Null;
		break;
	}
	return "NONE";
}



#endif /* !(_LIMIT_)  */