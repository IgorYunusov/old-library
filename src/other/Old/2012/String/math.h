/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_MATH_
#define _ROLLRAT_MATH_

#include "rutil.h"
#include "regex.hpp"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

	_CCC_B_TEMPLATE_CS
	template<typename _NT_MATH>
		class MATH{
		public:
			MATH();
			~MATH();
			void _Set(_NT_MATH,_NT_MATH);
			_NT_MATH _Get_Operator();
			_NT_MATH Add(_NT_MATH, _NT_MATH);
			_NT_MATH Sub(_NT_MATH, _NT_MATH);
			_NT_MATH Mul(_NT_MATH, _NT_MATH);
			_NT_MATH Div(_NT_MATH, _NT_MATH);
			_NT_MATH Sqrt(_NT_MATH);
			_NT_MATH Square(_NT_MATH, int);
			_NT_MATH Reci(_NT_MATH);
			_NT_MATH Fact(int);
			_NT_MATH NI(_NT_MATH);
			_NT_MATH IN(_NT_MATH);
			_NT_MATH Sin(_NT_MATH);
			_NT_MATH Cos(_NT_MATH);
			_NT_MATH Tan(_NT_MATH);
			_NT_MATH Log(_NT_MATH);
			_NT_MATH Permutation(int,int);
			_NT_MATH Combination(int,int);

		private:
			_NT_MATH _Operand;
			_NT_MATH _Operator;

		};

		#define max(a,b)            (((a) > (b)) ? (a) : (b))
		#define min(a,b)            (((a) < (b)) ? (a) : (b))
		#define inc(a)				((a) + 1)
		#define des(a)				((a) - 1)
		#define abs(num)			( num > 0 ? num : ( num * -1 ))
		#define Mov(a,b)			((a) % (b))

		#define E					2.71828182845904523536
		#define PI					3.14159265358979323846
		#define RATIO				0.01745329251994329576923690768489

		#define Tf(x)				Div(Square(Operand, x),		Fact(x))
		#define Tff(x, y, z)		Div(Square(Operand, x) * y,	Fact(z))

		//<-- 2013-02-20 Extra Set

		#define SIN_30	0.50000000000000000000000000000000
		#define SIN_60  0.86602540378443864676372317075294
		#define SIN_90	1.00000000000000000000000000000000
		#define COS_30  0.86602540378443864676372317075294
		#define COS_60	0.50000000000000000000000000000000
		#define COS_90	0.00000000000000000000000000000000
		#define TAN_30	0.57735026918962576450914878050196
		#define TAN_60	1.7320508075688772935274463415059

		//-->

		template<class _NT_MATH> inline
		MATH<_NT_MATH>::MATH()
		{
			_Operand = 0; 
			_Operator = 0;
		}

		template<class _NT_MATH> inline
		MATH<_NT_MATH>::~MATH()
		{	}

		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::_Get_Operator()
		{ 
			return _Operator; 
		}
		template<class _NT_MATH> inline
		void MATH<_NT_MATH>::_Set(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			_Operand = Operand; 
			_Operator = Operator; 
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Add(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand + Operator; 
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Sub(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand - Operator; 
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Mul(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand * Operator;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Div(_NT_MATH Operand,_NT_MATH Operator)
		{ 
			return Operand / Operator;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Reci(_NT_MATH Operand)
		{ 
			return 1 / Operand;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Sqrt(_NT_MATH Operand)
		{ 
			_NT_MATH Next, Temp;
			Next = 0.5 * (1 + (Operand / 1));
			for(;;)
			{
				Temp = Next;
				Next = 0.5 * (Next + (Operand / Next));
				if(Temp - Next < 0.005 || Temp - Next < - 0.005)
				break;
			}
			return Next;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Square(_NT_MATH Operand,int SquareSet)
		{ 
			_NT_MATH Buffer = 1;
			while(SquareSet-- > 0) 
			{
				Buffer *= Operand;
			}
			return Buffer;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Fact(int Operand)
		{ 
			_NT_MATH i; 
			if(Operand >= 2)
			{
				i = Operand * Fact(Operand - 1);
			}else{
				i=1; 
			}
			return i;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::NI(_NT_MATH Operand)
		{ 
			return 1 + Tf(1) + Tf(2) + Tf(3) +
				Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) + Tf(9) + Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) 
				+ Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20);	
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::IN(_NT_MATH Operand)
		{ 
			return Tf(1) + Tf(2) + Tf(3) + Tf(4) + Tf(5) + Tf(6) + Tf(7) + Tf(8) +
				Tf(9) + Tf(10) + Tf(11) + Tf(12) + Tf(13) + Tf(14) + Tf(15) + Tf(16) + Tf(17) + Tf(18) + Tf(19) + Tf(20);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Sin(_NT_MATH Operand)
		{ 
			Operand *= RATIO;
			return Operand - Tf(3) + Tf(5) - Tf(7) + Tf(9) - Tf(11);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Cos(_NT_MATH Operand)
		{
			Operand *= RATIO;
			return 1 - Tf(2) + Tf(4) - Tf(6) + Tf(8) - Tf(10);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Tan(_NT_MATH Operand)
		{ 
			Operand *= RATIO;
			return Tff(1,1,1) + Tff(2,3,3) + Tff(16,5,5) + Tff(272,7,7) + Tff(7936,9,9) + Tff(353792,11,11);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Log(_NT_MATH Operand)
		{ 
			return Div(IN(Operand),2.30258);
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Permutation(int Operand, int Operator)
		{
			_NT_MATH i;
			i = Operand;
			while(i-- > Operator)
			{
				Operand *= i;
			}
			return Operand;
		}
		template<class _NT_MATH> inline
		_NT_MATH MATH<_NT_MATH>::Combination(int Operand,int Operator)
		{
			return Permutation(Operand,Operator)
				/
				Fact(Operator);
		}//2012-10-27 Check.h<by rollrat>

		
	template<class _Ty, 
			class _Pointer = _Ty*, 
			class _Reference = _Ty&>
		struct _X_MATH_EX
		{ // File struct
		STR_PUBLICQ
		typedef _Ty Value_Type;
		typedef _Pointer Pointer;
		typedef _Reference Reference;
		};

	_CCC_B_TEMPLATE_CS
	template<class _Ty>
		class MATH_EX
			: public _X_MATH_EX<_Ty>, 
			public MATH<_Ty>
		{
			typedef MATH_EX<_Ty> _MyT;
			typedef typename _X_MATH_EX<_Ty>::Value_Type _MyVT;
			typedef typename _X_MATH_EX<_Ty>::Reference _MyRE;
			typedef typename _X_MATH_EX<_Ty>::Pointer _MyPI;
			typedef MATH<_Ty>	_MyTH;
		public:

			struct _point{_Ty x; _Ty y;};
			struct _triangle{_Ty w1; _Ty w2; _Ty w3; _Ty area;};
			struct function{_Ty x; _Ty y; _Ty z;};

			function Equation_Substitution(char* equation, char* variable, _Ty* variables)
				{
					
				}

		};

_X_LIB_END
/*COMMON Lib End
*/

#endif

#endif