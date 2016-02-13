/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/
#pragma once
#ifndef _ROLLRAT_TEM_
#define _ROLLRAT_TEM_

#include "rutil.h"

#if defined(_EX_SUCCESS)

_X_LIB_BEGIN
	
	template<class _Ts1> inline
		bool Compare(_Ts1 Operation, _Ts1 Operator)
			{ // compare one type
			return Operation == Operator;
			}

	template<class _Ts1, class _Ts2> inline
		bool Compare(_Ts1 Operation, _Ts2 Operator)
			{ // compare two type
			return Operation == Operator;
			}

	template<typename _Tn1> inline
		bool Compare(_Tn1 Operation, _Tn1 Operator)
			{ // compare one type name
			return Operation == Operator;
			}

	template<typename _Tn1, typename _Tn2> inline
		bool Compare(_Tn1 Operation, _Tn2 Operator)
			{ // compare one type name
			return Operation == Operator;
			}

	template<class _Ts1> inline
		bool Deny(_Ts1 Operation, _Ts1 Operator)
			{ // Deny one type
			return Operation != Operator;
			}

	template<class _Ts1, class _Ts2> inline
		bool Deny(_Ts1 Operation, _Ts2 Operator)
			{ // Deny two type
			return Operation != Operator;
			}

	template<typename _Tn1> inline
		bool Deny(_Tn1 Operation, _Tn1 Operator)
			{ // Deny one type name
			return Operation != Operator;
			}

	template<typename _Tn1, typename _Tn2> inline
		bool Deny(_Tn1 Operation, _Tn2 Operator)
			{ // Deny one type name
			return Operation != Operator;
			}

	template<class _Ts1> inline
		bool Contrast_Left(_Ts1 Operation, _Ts1 Operator)
			{ // Contrast_Left one type
			return Operation < Operator;
			}

	template<class _Ts1, class _Ts2> inline
		bool Contrast_Left(_Ts1 Operation, _Ts2 Operator)
			{ // Contrast_Left two type
			return Operation < Operator;
			}

	template<typename _Tn1> inline
		bool Contrast_Left(_Tn1 Operation, _Tn1 Operator)
			{ // Contrast_Left one type name
			return Operation < Operator;
			}

	template<typename _Tn1, typename _Tn2> inline
		bool Contrast_Left(_Tn1 Operation, _Tn2 Operator)
			{ // Contrast_Left one type name
			return Operation < Operator;
			}

	template<class _Ts1> inline
		bool Contrast_Right(_Ts1 Operation, _Ts1 Operator)
			{ // Contrast_Right one type
			return Operation > Operator;
			}

	template<class _Ts1, class _Ts2> inline
		bool Contrast_Right(_Ts1 Operation, _Ts2 Operator)
			{ // Contrast_Right two type
			return Operation > Operator;
			}

	template<typename _Tn1> inline
		bool Contrast_Right(_Tn1 Operation, _Tn1 Operator)
			{ // Contrast_Right one type name
			return Operation > Operator;
			}

	template<typename _Tn1, typename _Tn2> inline
		bool Contrast_Right(_Tn1 Operation, _Tn2 Operator)
			{ // Contrast_Right one type name
			return Operation > Operator;
			}

	template<class _Td> inline
		_Td _adding_x64(_Td Oper, _Td Opert)
			{
			if (((Oper << 8) && Opert) == 0 )
				return ((_Td)((Oper << 8) && Opert));
			return Oper;
			}

	template<class _Td> inline
		_Td _adding_x32(_Td Oper, _Td Opert)
			{
			if (((Oper << 4) && Opert) == 0 )
				return ((_Td)((Oper << 4) && Opert));
			return Oper;
			}

	template<typename _Td> inline
		_Td _adding_x64(_Td Oper, _Td Opert)
			{
			if (((Oper << 8) && Opert) == 0 )
				return ((_Td)((Oper << 8) && Opert));
			return Oper;
			}

	template<typename _Td> inline
		_Td _adding_x32(_Td Oper, _Td Opert)
			{
			if (((Oper << 4) && Opert) == 0 )
				return ((_Td)((Oper << 4) && Opert));
			return Oper;
			}

	template<typename _Tc> inline
		_Tc _xor_ex(_Tc Oper, _Tc Opert)
			{
			return ((!(Oper) || (Opert)) && ((Oper) || !(Opert)));
			}

	template<typename _Tc> inline
		_Tc _carry_ex(_Tc Oper, _Tc Opert, _Tc CIn)
			{
			return ((Oper && Opert) || ((Oper ^ Opert) && CIn));
			}

	template<typename _Tc> inline
		_Tc _add_ex(_Tc Oper, _Tc Opert, _Tc CIn)
			{
			return ((!(Oper ^ Opert) && CIn) || ((Oper ^ Opert) && !(CIn)));
			}

_X_LIB_END

#endif

#endif
