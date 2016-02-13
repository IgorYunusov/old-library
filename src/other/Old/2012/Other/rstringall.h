/*
 *
 *			ROLLRAT SOFTWARE SUBROUTINE
 *			SINCE : 2009 - 2012
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

#pragma once
#if !defined(_r_type_str_)
#define _r_type_str_
#include "rRetype.h"
#include "rstdset.h"
__char GetCharOnePrev _k __const __charp tCharText __m __const __char fCharText k_
_j
	__int i __put 0 __re
	__whi _k tCharText _m i __inc m_ k_
	_j
		__if _k tCharText _m i m_ __same fCharText  k_
		_j
			__ret tCharText _m __dev i m_ __re
		j_ 
	j_ 
j_
__char GetCharOneNext _k __const __charp tCharText __m __const __char fCharText k_
_j
	__int i = 0 __re
	__whi _k tCharText _m i __inc m_ k_
	_j
		__if _k tCharText _m i m_ __same fCharText  k_
		_j
			__ret tCharText _m __inc i m_ __re
		j_
	j_
j_
#endif