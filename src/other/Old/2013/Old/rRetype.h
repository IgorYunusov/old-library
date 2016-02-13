/*	
 *
 *			rollrat software < r R e t y p e >  Header
 *		
 *			Copyright (c) 2012. rollrat. All right reserved.
 *
 *		
 ***************************************************************************/

// Version : C_0-3-0-9
#pragma once
#if !defined(_r_type_)
#define _r_type_
#if !defined(NULL)
#define NULL 0
#endif
#define __typedef				typedef
#define __re					;
__typedef   void	__void			__re
__typedef	char	__char			__re
__typedef	char *	__charp			__re
__typedef	int		__int			__re
__typedef	float	__float			__re
__typedef	double	__double		__re
__typedef	long	__long			__re
__typedef	short	__short			__re
#define __unid		unsigned
#define	__swt		switch
#define __case		case
#define __for		for
#define __nofor		;;
#define __if		if
#define __else		else
#define __ifelse	else if
#define __whi		while
#define __type		typedef
__typedef	long float	__lfloat	__re
__typedef	long double __ldouble	__re
#define __brk		break			__re
#define __loop		while(true)
#define __cont		continue		__re
#define __goto		goto
#define __size		sizeof
#define __struct	struct
#define __static	static
#define __ret		return
#define __retz		return 0		__re
#define __retn		return			__re
#define __pas       __pascal
#define __cde       __cdecl
#define __const		const
#define __archi		__type __struct
#if !defined(_r_retype_def_mjk_)
#define _r_retype_def_mjk_
#define _m		[
#define m_		]
#define __nm	 _m m_
#define _j		{
#define j_		}
#define __nj	_j j_
#define _k		(
#define k_		)
#define __nk	_k k_
#define __same	==
#define __put	=
#define __inc	++
#define __dev	--
#define __m		,
#endif
#if !defined(_r_retype_def_)
#define _r_retype_def_
#define VOID		__void
typedef				int			BOOL;
typedef unsigned	int			UINT;
typedef unsigned	long		DWORD;
typedef unsigned	char		BYTE;
typedef unsigned	short		WORD;
#define UNI			unsigned
typedef UNI			long		ULONG;
typedef UNI			float		UFLOAT;
typedef UNI			short		USHORT;
typedef				char*		PCHAR;
typedef				int*		PINT;
typedef	UNI			int*		PINT;
typedef				double		DKORK;
typedef UNI			double		UDKORK;
typedef long		double		LDKORK;
#define CHAR char *
#endif
#endif