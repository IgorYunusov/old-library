// rollrat sector class
#pragma once
#ifndef __SECTOR_
#define __SECTOR_
#include "rutil.h"
#if defined(_EX_SUCCESS)

_X_LIB_BEGIN

	template<class _Ty>
	class _X_Sector_EX
	{
		typedef _X_Sector_EX<_Ty> _MyT;

	public:

		explicit _X_Sector_EX()
			{

			}

		~_X_Sector_EX()
			{

			}


	private:

		_Ty* memset;

	};

_X_LIB_END

#endif
#endif

/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

// Operation Version : 1.00