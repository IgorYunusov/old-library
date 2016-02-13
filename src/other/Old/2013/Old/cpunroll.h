/*************************************************************
  
       ROLLRAT LIBRARY TTOMLIER CP_UNROLL

       COPYRIGHT @ ROLLRAT. 2014 ALL RIGHTS RESERVED.

**************************************************************/

#ifndef _CP_UNROLL_
#define _CP_UNROLL_

typedef unsigned int			uint_t;
typedef unsigned long int		uint32_t;
typedef unsigned long long int	uint64_t;


		// METAPROGRAMMING
#ifdef _WIN32
#define T_UINT template<uint32_t _Val>
#define T_UINT2 template<uint32_t _Val1, uint32_t _Val2>
#define UINT	uint32_t
#else
#define T_UINT template<uint64_t _Val>
#define T_UINT2 template<uint64_t _Val1, uint64_t _Val2>
#define UINT	uint64_t
#endif

// COMPILER UNROLLING

		// FACTORIAL
T_UINT class Factorial
	{
public:
	static const UINT value = (_Val * Factorial<_Val - 1>::value);
	};
template<>
class Factorial<1> // with zero
	{
public:
	static const UINT value = 1;
	};


		// PERMUTATION
T_UINT2 class Permutation
	{
public:
	static const UINT value = (_Val1 * Permutation<_Val1 - 1, _Val2 - 1>::value);
	};
T_UINT class Permutation<_Val, 0>
	{
public:
	static const UINT value = 1;
	};


		// COMBINATION
T_UINT2 class Combination
	{
public:
	static const UINT value = (Permutation<_Val1, _Val2>::value / Factorial<_Val2>::value);
	};


		// COMBINATION WITH REPETITION
T_UINT2 class Repetition
	{
public:
	static const UINT value = (_Val1 * Permutation<_Val1, _Val2 - 1>::value);
	};
T_UINT class Repetition<_Val, 0>
	{
public:
	static const UINT value = 1;
	};


		// LOOP UNROLLING
template<UINT _Val, typename _Func>
class Unrolling
	{
public:
	static inline void Do(_Func _Function)
		{
		Unrolling<_Val - 1, _Func>::Do(_Function);
		_Function();
		}
	};
template<typename _Func>
class Unrolling<-1, _Func>
	{
public:
	static inline void Do(_Func _Function)
		{
		}
	};

#endif