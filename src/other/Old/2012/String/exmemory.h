/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_MEMORY_
#define _ROLLRAT_MEMORY_

#include "rutil.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

	_CCC_C_TEMPLATE_CS
	template<class _Ty, 
			class _Pointer = _Ty*,
			class _Reference = _Ty&>
	struct _X_Memory_TD
		{
		STR_PUBLICQ
		typedef _Pointer Pointer;
		typedef _Ty Value_Type;
		typedef _Reference Reference;
		};

	_CCC_C_TEMPLATE_CS
	template<class _Ty>	// point type
	class _X_Memory_EX 
		: public _X_Base<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>
		{
		typedef _X_Memory_EX<_Ty> _MyT;
		typedef _X_COMMON<_Ty, _Ty, _Ty*> _MyC;
		typedef typename _X_Base<_Ty>::Value_Type _MyVT;
		typedef typename _X_Base<_Ty>::Arrays _MyAY;
		typedef typename _X_Base<_Ty>::UnPointer _MyUP;
		typedef typename _X_Base<_Ty>::Pointer _MyPI;

		public:



		};

_X_LIB_END
/*COMMON Lib End
*/

#endif

#endif