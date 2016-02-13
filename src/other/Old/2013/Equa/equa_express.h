/*************************************************************************
 *
 *                              ROLLRAT PAPERS
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _EQUA_EXPRESS_
#define _EQUA_EXPRESS_

template<class _Arg,
	class _Result,
	class _Fn = _Result (*)(_Arg)>
	class fuction_adapter
	{
public:
	typedef _Arg argument_type;
	typedef _Result result_type;

	explicit fuction_adapter(_Fn _Left)
		: _Pfun(_Left)
		{	// construct from pointer
		}

	_Result operator()(_Arg _Left) const
		{	// call function with operand
		return (_Pfun(_Left));
		}

protected:
	_Fn _Pfun;	// the function pointer
	};

#include <stack>

/*********************************************

			시그니쳐 결합방식

	8									0
	+---+---+---+---+---+---+---+---+---+
	| K | H | H | H | H | S | S | S | S |
	+---+---+---+---+---+---+---+---+---+

	S : 부모 시그니쳐
	H : 자식 시그니쳐
	K : 1 := 음수 0 := 양수

**********************************************/

#define Make_Signature(H, S)	(((H & 0xf) << 4) | (S & 0xf))
#define Get_H(T)				((T & (0xf << 4)) >> 4)
#define Get_S(T)				(T & 0xf)

typedef enum /*class*/ _noname_enum_0145
{
	normal = 1,			// 상수
	specific,			// 미리정의된함수
	//exponential,		// 지수형
	commonlogarithm,	// 상용로그형
	differential,		// 미분계수형
	variable,			// 변수
	reverse,			// 역수
	error,				// 오차형
	series,				// 급수
	limit,				// 극한
}	SIGNATURE;

typedef enum /*class*/ _noname_enum_1565
{
	sine = 1,				// 삼각함수
	cosine,
	tangent,
	cosecant,
	secant,
	cotangent,
	arcsine,				// 역삼각함수
	arccosine,
	arctangent,
	arccosecant,
	arcsecant,
	arccotangent,
	hyperbolicsine,			// 쌍곡선함수
	hyperboliccosine,
	hyperbolictangent,
	hyperboliccosecant,
	hyperbolicsecant,
	hyperboliccotangent,
	hyperbolicarcsine,		// 역쌍곡선함수
	hyperbolicarccosine,
	hyperbolicarctangent,
	hyperbolicarccosecant,
	hyperbolicarcsecant,
	hyperbolicarccotangent,
	naturallogarithm,		// 자연로그
	commonexponential,		// 익스포넨셜
}	SPECIFIC_SIGNATURE;

template<typename _T, typename _sign = unsigned short /*int*/> class
	_equa_express
	{
public:
	typedef typename struct _equa_express<_T> _MyStruct;

	_equa_express()
		: _Mul_Ptr(nullptr), _Add_Ptr(nullptr), _Coff_Ptr(nullptr), _Expr_Ptr(nullptr)
		{
		}

	_T& operator*()
		{
		return _Value;
		}

	_sign operator()() const
		{
		return _Signagture;
		}

	void operator()(_sign sign)
		{
		_Signagture = sign;
		}

#define CLASS_NEXT_OPERATOR(Wa)	\
		void (_##Wa)(_MyStruct * Ta)\
			{ /*Set*/ \
				_##Wa##_Ptr = Ta; \
			}\
		void (_##Wa)(_MyStruct * Ta, _T _Val)\
			{ /*Set*/ \
				_##Wa##_Ptr = Ta; \
				_##Wa##_Ptr->_Value = _Val; \
			}\
		_MyStruct*& (_##Wa)()\
			{ /*Get*/ \
				return _##Wa##_Ptr; \
			}

	CLASS_NEXT_OPERATOR(Mul)
	CLASS_NEXT_OPERATOR(Add)
	CLASS_NEXT_OPERATOR(Coff)
	CLASS_NEXT_OPERATOR(Expr)

	_MyStruct *_Mul_Ptr, *_Add_Ptr, *_Coff_Ptr, *_Expr_Ptr;
	_T _Value;
	_sign _Signagture;
	};

#undef _STD
#define _STD		::std::

template<typename _Unit = unsigned long long/*= __int64*/> class
	nonlinear_equation
	{
public:
	typedef class _equa_express<_Unit> _Equa;

	_STD stack<_Equa *> _deep;

	_Equa *_Head, *_Current;

	nonlinear_equation()
		: _Head(_Allocate()), _Current(_Head)
		{
		}

	explicit nonlinear_equation(const char * equstr)
		: _Head(_Allocate()), _Current(_Head)
		{
		__string2equation(equstr);
		}

private:
	
	_Equa* _Allocate()
		{
		return new _Equa;
		}

	bool perpect_match(const char * s1, const char * s2)
		{
		while( *s1++ == *s2++ )
			if (*s2 == 0 && *s2 == 0)
				return true;
		return false;
		}

	void get_specific(char ** ref, const char *target)
		{
		const char *t = target, *o = target;
		while (('a' <= *t && *t <= 'z') || ('A' <= *t && *t <= 'Z'))
			(*ref)[t - o] = *t, target++, t++;
		}

	void __string2equation(const char * cstr)
		{
		const char * chr = cstr;

		while ( *chr )
			{
			// 변수 확인
			if (('a' <= *chr && *chr <= 'z') || ('A' <= *chr && *chr <= 'Z'))
				{
				// 한 글자 이상은 변수가 아니다.
				if ((('a' <= *(chr + 1) && *(chr + 1) <= 'z') || ('A' <= *(chr + 1) && *(chr + 1) <= 'Z')))
					goto NOT_VARIABLE;
				(*_Current)._Add(_Allocate(), *chr);
				*(*_Current) = *chr;
				(*_Current)(Make_Signature(0, variable));
				chr++;
				continue;
			NOT_VARIABLE:
				char *temp = new char[6];
				for (int i = 0; i < 6; i++)
					temp[i] = 0;
				get_specific(&temp, chr);
				(*_Current)._Add(_Allocate());
				_deep.push(_Current);
				_Current = (*_Current)._Add();
				if(perpect_match(temp, "sin"))			(*_Current)(Make_Signature(sine, specific));
				else if(perpect_match(temp, "cos"))		(*_Current)(Make_Signature(cosine, specific));
				else if(perpect_match(temp, "tan"))		(*_Current)(Make_Signature(tangent, specific));
				else if(perpect_match(temp, "csc"))		(*_Current)(Make_Signature(cosecant, specific));
				else if(perpect_match(temp, "sec"))		(*_Current)(Make_Signature(secant, specific));
				else if(perpect_match(temp, "cot"))		(*_Current)(Make_Signature(cotangent, specific));
				else if(perpect_match(temp, "asin"))	(*_Current)(Make_Signature(arcsine, specific));
				else if(perpect_match(temp, "acos"))	(*_Current)(Make_Signature(arccosine, specific));
				else if(perpect_match(temp, "atan"))	(*_Current)(Make_Signature(arctangent, specific));
				else if(perpect_match(temp, "acsc"))	(*_Current)(Make_Signature(arccosecant, specific));
				else if(perpect_match(temp, "asec"))	(*_Current)(Make_Signature(arcsecant, specific));
				else if(perpect_match(temp, "acot"))	(*_Current)(Make_Signature(arccotangent, specific));
				else if(perpect_match(temp, "sinh"))	(*_Current)(Make_Signature(hyperbolicsine, specific));
				else if(perpect_match(temp, "cosh"))	(*_Current)(Make_Signature(hyperboliccosine, specific));
				else if(perpect_match(temp, "tanh"))	(*_Current)(Make_Signature(hyperbolictangent, specific));
				else if(perpect_match(temp, "csch"))	(*_Current)(Make_Signature(hyperboliccosecant, specific));
				else if(perpect_match(temp, "sech"))	(*_Current)(Make_Signature(hyperbolicsecant, specific));
				else if(perpect_match(temp, "coth"))	(*_Current)(Make_Signature(hyperboliccotangent, specific));
				else if(perpect_match(temp, "asinh"))	(*_Current)(Make_Signature(hyperbolicarcsine, specific));
				else if(perpect_match(temp, "acosh"))	(*_Current)(Make_Signature(hyperbolicarccosine, specific));
				else if(perpect_match(temp, "atanh"))	(*_Current)(Make_Signature(hyperbolicarctangent, specific));
				else if(perpect_match(temp, "acsch"))	(*_Current)(Make_Signature(hyperbolicarccosecant, specific));
				else if(perpect_match(temp, "asech"))	(*_Current)(Make_Signature(hyperbolicarcsecant, specific));
				else if(perpect_match(temp, "acoth"))	(*_Current)(Make_Signature(hyperbolicarccotangent, specific));
				else if(perpect_match(temp, "log"))		(*_Current)(Make_Signature(0, commonlogarithm));
				else if(perpect_match(temp, "exp"))		(*_Current)(Make_Signature(commonexponential, specific));
				else if(perpect_match(temp, "ln"))		(*_Current)(Make_Signature(naturallogarithm, specific));
				}
			else
				{
				switch(*chr)
					{
				case '^':	// Carrot
					(*_Current)._Coff(_Allocate());
					_deep.push(_Current);
					_Current = (*_Current)._Coff();
					chr++;
					continue;
					}
				}
			}
		}

	};

#endif