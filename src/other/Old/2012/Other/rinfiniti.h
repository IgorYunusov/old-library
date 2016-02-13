/*
 *
 *			ROLLRAT SOFTWARE SUBROUTINE
 *			SINCE : 2009 - 2012
 *
 *			Version: 0.2.0.3
 *
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#pragma once
#if !defined(__R_API_INF__)
#define __R_API_INF__
#define INF_F 0
#define INF_H 1
#define INF_I 0xFF
#define INF_O 0xFFFF
#define INF_K 0xFFFFFFFF
#define INF_L 0xFFFFFFFFFFFF
#define INF_J 0xFFFFFFFFFFFFFFFF
#define	int_size		(sizeof	(int)			)
#define long_size		(sizeof	(long)			)
#define double_size		(sizeof	(double)		)
#define ldouble_size	(sizeof	(long double)	)
#define inf_set(__infiniti) ( \
	sizeof(__infiniti) > int_size ? ( \
	sizeof(__infiniti) > double_size ? 0xffff : __infiniti) : __infiniti )
#define inf_get_type(__infiniti) ( \
	sizeof(__infiniti) > int_size ? ( \
	sizeof(__infiniti) > long_size ? ( \
	sizeof(__infiniti) > double_size ? ( \
	sizeof(__infiniti) > ldouble_size ? 5 : 4 ) : 3 ) : 2 ) : 1)
#define Only_Long_Double(__infiniti) ( \
	sizeof(__infiniti) <  ldouble_size ? 0 : 1)
#define tf(_f) ( _f = 0 ? 1 : 0 )
#define abs(num) ( num > 0 ? num : ( num * -1 ))

long double ld_inf(long double fNumber)
{
	if (fNumber > 0)
		return 0;
	else if (fNumber = 0)
		return 0x123FFF654AAA;
	else
		return tf(fNumber);
}



#endif