/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY [Private]
 *						META PROGRAMMING TOOL
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *[INSIDE METHOD]
 *************************************************************************/

#ifndef _META_PRO_
#define _META_PRO_

// STL과의 모호성을 방지하기 위함
#ifndef _RSL
#define _RSL_BEGIN namespace rsl{
#define _RSL		rsl :: 
#define _RSL_END  }
#endif

_RSL_BEGIN

// xstddef method

// _If< [조건] , [틀릴시] , [맞을시] >::type
template<bool, class _Ty1, class _Ty2> struct _If{typedef _Ty2 type;};
template<class _Ty1, class _Ty2> struct _If<true, _Ty1, _Ty2>{typedef _Ty1 type;};


// xtr1common method
template<class _Ty, _Ty _Val>
	struct integral_constant
	{
	static const _Ty value = _Val;

	typedef _Ty value_type;
	typedef integral_constant<_Ty, _Val> type;

	operator value_type() const
		{	// return stored value
		return (value);
		}
	};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;
template<bool>						struct _Cat_base : false_type {};
template<>							struct _Cat_base<true>: true_type {};
template<class _Ty1, class _Ty2>	struct is_same : false_type{};
template<class _Ty1>				struct is_same<_Ty1, _Ty1> : true_type{};
template<class _Ty>					struct remove_const {typedef _Ty type;};
template<class _Ty>					struct remove_const<const _Ty> {typedef _Ty type;};
template<class _Ty>					struct remove_const<const _Ty[]> {typedef _Ty type[];};
template<class _Ty, unsigned int _Nx> struct remove_const<const _Ty[_Nx]> {typedef _Ty type[_Nx];};
template<class _Ty>					struct remove_volatile {typedef _Ty type;};
template<class _Ty>					struct remove_volatile<volatile _Ty> {typedef _Ty type;};
template<class _Ty>					struct remove_volatile<volatile _Ty[]> {typedef _Ty type[];};
template<class _Ty, unsigned int _Nx> struct remove_volatile<volatile _Ty[_Nx]>{typedef _Ty type[_Nx];};
template<class _Ty>					struct _Is_integral : false_type {};
template<>							struct _Is_integral<bool> : true_type {};
template<>							struct _Is_integral<char> : true_type {};
template<>							struct _Is_integral<unsigned char> : true_type {};
template<>							struct _Is_integral<signed char> : true_type {};
template<>							struct _Is_integral<unsigned short> : true_type {};
template<>							struct _Is_integral<signed short> : true_type {};
template<>							struct _Is_integral<unsigned int> : true_type {};
template<>							struct _Is_integral<signed int> : true_type {};
template<>							struct _Is_integral<unsigned long> : true_type {};
template<>							struct _Is_integral<signed long> : true_type {};
template<bool _Test, class _Ty = void> struct enable_if {};
template<class _Ty>					struct enable_if<true, _Ty> { typedef _Ty type;};
template<class _Ty>					struct remove_reference {typedef _Ty type;};
template<class _Ty>					struct remove_reference<_Ty&> {typedef _Ty type;};
template<class _Ty>					struct remove_reference<_Ty&&> {typedef _Ty type;};
template<class _Ty>	struct remove_cv{typedef typename remove_const<typename remove_volatile<_Ty>::type>::type type;};

#define _META_STL_OPERATION_CLASS_SET(name, operation)\
	template<class _Ty = void>\
		struct name\
		{\
		_Ty operator()(const _Ty& _Left, const _Ty& _Right) const\
			{\
			return (_Left operation _Right);\
			}\
		};

#define _META_STL_OPERATION_CLASS_C11(name, operation)\
	template<>\
		struct name<void>\
		{\
		template<class _Ty1,\
			class _Ty2>\
			auto operator()(_Ty1&& _Left, _Ty2&& _Right) const\
			-> decltype(static_cast<_Ty1&&>(_Left)\
				operation static_cast<_Ty2&&>(_Right))\
			{\
			return (static_cast<_Ty1&&>(_Left)\
				operation static_cast<_Ty2&&>(_Right));\
			}\
		};

// enum을 사용하여도 무방함
#define _META_TEMPLATE_CLASS_SINGLE_UP(type, name, operation, _max)\
	template<type _Val> \
		struct name\
		{\
			static const type value = (_Val operation name<_Val + 1> ::value);\
		};\
	template<>\
		struct name<_max>\
		{\
			static const type value = 1;\
		};

#define _META_TEMPLATE_CLASS_SINGLE_DOWN(type, name, operation)\
	template<type _Val> \
		struct name\
		{\
			static const type value = (_Val operation name<_Val - 1> ::value);\
		};\
	template<>\
		struct name<1>\
		{\
			static const type value = 1;\
		};

#define _META_TEMPLATE_CLASS_SINGLE(type, name, body)\
	template<type _Val> \
		struct name\
		{\
			static const type value = (body);\
		};\
	template<>\
		struct name<1>\
		{\
			static const type value = 1;\
		};

#define _META_TEMPLATE_CLASS_DOUBLE_DOWN(type, name, operation)\
	template<type _Val1, type _Val2> \
		struct name\
		{\
			static const type value = (_Val1 operation name<_Val1 - 1, _Val2 - 1 > ::value);\
		};\
	template<type _Val1>\
		struct name<_Val1, 0>\
		{\
			static const type value = 1;\
		};

#define _META_TEMPLATE_CLASS_DOUBLE(type, name, body)\
	template<type _Val1, type _Val2> \
		struct name\
		{\
		public:\
			static const type value = (body);\
		};\
	template<type _Val1>\
		struct name<_Val1, 0>\
		{\
		public:\
			static const type value = 1;\
		};

_META_STL_OPERATION_CLASS_SET(plus, +)
_META_STL_OPERATION_CLASS_SET(minus, -)
_META_STL_OPERATION_CLASS_SET(multiplies, *)
_META_STL_OPERATION_CLASS_SET(equal_to, ==)
_META_STL_OPERATION_CLASS_SET(nequal_to, !=)
_META_STL_OPERATION_CLASS_SET(less, <)
_META_STL_OPERATION_CLASS_SET(less_equal, <=)

_META_STL_OPERATION_CLASS_C11(plus, +)
_META_STL_OPERATION_CLASS_C11(minus, -)
_META_STL_OPERATION_CLASS_C11(multiplies, *)
_META_STL_OPERATION_CLASS_C11(equal_to, ==)
_META_STL_OPERATION_CLASS_C11(nequal_to, !=)
_META_STL_OPERATION_CLASS_C11(less, <)
_META_STL_OPERATION_CLASS_C11(less_equal, <=)

_META_TEMPLATE_CLASS_SINGLE_DOWN(unsigned int, factorial, *)
_META_TEMPLATE_CLASS_DOUBLE_DOWN(unsigned int, permutation, *)
_META_TEMPLATE_CLASS_SINGLE(unsigned int, combination, (permutation<_Val1, _Val2>::value / factorial<_Val2>::value))
_META_TEMPLATE_CLASS_DOUBLE(unsigned int, repetition, (_Val1 * permutation<_Val1, _Val2 - 1>::value))

template<unsigned int _Val, typename _Func>
	struct loop_unrolling
	{
	static inline void Do(_Func _Function)
		{
		loop_unrolling<_Val - 1, _Func>::Do(_Function);
		_Function();
		}
	};

template<typename _Func>
	struct loop_unrolling < -1, _Func >
	{
	static inline void Do(_Func _Function)
		{
		}
	};

template<class _Ty,
	size_t _Size> inline
	_Ty *begin(_Ty (&_left)[_Size])
	{
	return (_left);
	}

template<class _Ty,
	size_t _Size> inline
	_Ty *end(_Ty (&_left)[_Size])
	{
	return (_left + _Size);
	}

_RSL_END

#endif