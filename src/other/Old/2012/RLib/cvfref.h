/*=================================================

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

=================================================*/

#pragma once
#ifndef _cvf_ref
#define _cvf_ref_

#include "zfrmy.h"

#if defined(_EZ_SUCCESS)
_Z_LIB_BEGIN
	
/*
			CVF CHECKER
	(Computer Valriable Found)
								*/
#define _CVF_CHECK(x)

#define _CVF_STANDARD		_CVF_CHECK("cvf;version 0.16-bet") // Bet check
#define _CVF_IRREGULAR		_CVF_STANDARD						_CVF_CHECK("cvf;extender 0.1-bet")
#define _CVF_COMEUP			_CVF_CHECK("cvf;version 0.16-aleph") // Aleph check
#define _CVF_DETAIL			_CVF_IRREGULAR				_CVF_CHECK("cvf;version;check;debug")

#define _CVF_CHECK_PTR		_CVF_CHECK("debug;ptr") // pointer check
#define _CVF_ERRORNO		_CVF_CHECK("debug;ern") // error no check


_Z_LIB_END
#endif
#endif
/*
 *	The rollrat z_library
 *  Updated : 2013-06
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0015****/

/*
 *	Special Library 'The Complex'
 *	Lastest Updated : 2013-06-15
 *	C/C++ syntax of the total complex made ​​possible by mobilizing header.
 *	If you understand all this, you C/C++ will have 
 *	completed all of the grammar.
L1_H*/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_z_Library_btype*/