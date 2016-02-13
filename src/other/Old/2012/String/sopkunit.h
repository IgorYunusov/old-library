/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_VECTOR_
#define _ROLLRAT_VECTOR_
#include "rutil.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

	#define Public public:
	#define Private private:
	#define Protected protected:
	typedef void Sub;
	#define StartSub	{
	#define EndSub		}
	#define ByVal		const
	#define ByRef
	#define OnlySub		const{
	#define StartSub	{
	
	#define Dim private:

	template<class _Ty,
		class _Vector = _Ty, 
		class _Pointer = _Ty *,
		class _Reference = _Ty&,
		typename object>
	class identifier_pointer
		: public _X_TYPE<_Ty>, 
		public _X_COMMON<_Ty, _Ty, _Ty*>,
		public _X_Type_Ex<_Ty>
		{
		typedef _X_Mem_Controller_Container<_Ty> _MyT;
		#ifndef _USELESS_OF_COMMON
		typedef _X_COMMON<_Ty, _Ty, _Pointer> _MyC;
		#else
		typedef _X_UCOMMON<_Ty, _Ty, _Pointer> _MyC;
		#endif
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_Ty>::Arrays _MyAY;
		typedef typename _Reference _MyUP;
		typedef typename _Pointer _MyPI;
		typedef typename _X_Type_Ex<_Ty> _MyDef;
		typedef object Function;

			Public Sub SetFirstScopeOfIdentifierPointerSizeOfThis(ByVal _MyVT firstscopeset)StartSub
				firstscopesetterbuffer = firstscopeset;
			EndSub

			Public Sub SetSecondScopeOfIdentifierPointerSizeOfThis(ByVal _MyVT secondscopeset)StartSub
				secondscopesetterbuffer = secondscopeset;
			EndSub

			Public Sub SetLastScopeOfIdentifierPointerSizeOfThis(ByVal _MyVT lastscopeset)StartSub
				lastscopesetterbuffer = lastscopeset;
			EndSub

			Public Function GetFinalScopeOfThis()OnlySub
				return firstscopesetterbuffer + secondscopesetterbuffer + lastscopesetterbuffer;
			EndSub

			Dim _MyVT firstscopesetterbuffer;
			Dim _MyVT secondscopesetterbuffer;
			Dim _MyVT lastscopesetterbuffer;

		};

_X_LIB_END

#endif

#endif