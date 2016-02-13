// rollrat sector class
#pragma once
#ifndef __SECTOR_
#define __SECTOR_
#include "rutil.h"
#if defined(_EX_SUCCESS)

_X_LIB_BEGIN
	
	template<class _Ty, 
			class _Pointer = _Ty*, 
			class _Reference = _Ty&>
		struct Custom_Pointer_STR
		{ // File struct
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Pointer Pointer;
		typedef _Reference Reference;
		};

	template<class _Ty>
	class _X_Sector_EX
		: public Custom_Pointer_STR<_Ty>
	{
		typedef _X_Sector_EX<_Ty> _MyT;
		typedef typename Custom_Pointer_STR<_Ty>::Value_Type _MyVT;
		typedef typename Custom_Pointer_STR<_Ty>::Reference _MyRE;
		typedef typename Custom_Pointer_STR<_Ty>::Pointer _MyPI;
	public:

		explicit _X_Sector_EX()
			{
			}

		~_X_Sector_EX()
			{
			}

	private:

		_MyT* Irector;

	};

_X_LIB_END

#endif
#endif

/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

// Operation Version : 1.00