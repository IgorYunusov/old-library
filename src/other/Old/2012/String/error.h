/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_ERROR_
#define _ROLLRAT_ERROR_
#include "rutil.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

	template<class _Ty>
	class Exception
	{
	public:
		Exception(_Ty ex){RuntimeMsg = const_cast<_Ty> (ex);}

	private:
		_Ty RuntimeMsg;
	};


_X_LIB_END

#endif

#endif