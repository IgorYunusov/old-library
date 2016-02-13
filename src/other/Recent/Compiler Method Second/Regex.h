/*************************************************************************
  
   RollRat Software Common Parser Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: Regex.h
                         Abstract: Regular Expression Class
                         Creation: 2015-03-08
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _REGEX_86f600672d32a7be1dd6cb035ac61577_
#define _REGEX_86f600672d32a7be1dd6cb035ac61577_

#include <string>

namespace CPMC {

	using namespace std;
	
	typedef enum class _flags_0219ed0efc668186e4f9d64a7da6a7aa_ {

		//
		//	문자/숫자/공백문자 한 개와 일치합니다.
		//
		IsCharacter,
		IsNumberic,
		IsWhiteSpace,
		IsDot, // \n을 제외한 한 개의 문자와 일치

		//
		//	범위 지정구문 ( [0-9] )에서 나타내는 범위를 가리킵니다.
		//
		IsScopeValueOf,

		//
		//	범위 지정구문 관련
		//
		IsScopeNormal,
		IsScopeDifferenceOf, // 차집합
		IsScopeDeepOf, // 멱집합

		//
		//	여러가지 구문과 일치합니다.
		//
		IsLogicOr, // (...|...|...)

		//
		//	처음과 끝을 나타내는 문자와 일치합니다. 이는 구문 중간에 올 수 없습니다.
		//
		IsStart,
		IsEnd,

		//
		//	반복연산과 일치합니다.
		//
		IsIterateAsterrisk,
		IsIterateQuestion,
		IsIteratePlug,
		IsIterateTime, // { ~~ }
		IsIterateTimeScope, // { ~~, ~~ }

	} flag_type;




	/**
		클래스 요약:
			범용 정규표현식 분석 클래스
	
		템플릿 요구사항:
			&( char * ) 또는 관련 집합
	**/
	template<class _Ty>
	class Regex
	{
		// const char *에서 *의 레퍼런스를 만들기 위함
		typedef typename remove_pointer<_Ty>::value_type value_type;
		typedef typename remove_pointer<_Ty>::value_type* pointer;

		pointer _Ptr;

	public:
	
		Regex(const pointer _ptr)
			: _Ptr(_ptr)
		{
			// 구문 분석 시작
			parse_syntax();
		}

	private:

		void parse_syntax()
		{
		}

	};

	
	/**
		클래스 요약:
			Regex Node for Regex Provider
	
		템플릿 요구사항:
			Regex와 같음
	**/
	template<class _Ty>
	class RegexNode
	{
		typedef RegexNode<_Ty> this_ptr;
		typedef typename remove_pointer<_Ty>::value_type value_type;
		typedef typename remove_pointer<_Ty>::value_type* pointer;

		typedef void * mutable_type;

		this_ptr *_Next;
		this_ptr *_Prev;
		this_ptr *_JumpLeft;
		this_ptr *_JumpRight;

		typedef typename flag_type flag_type;

		flag_type flag;
		mutable_type data;

	public:

		RegexNode()
			: _Next(this_ptr()), _Prev(this_ptr())
		{
		}

		void connect_next(this_ptr *next, this_ptr *prev = this_ptr())
		{
			_Next = next;
			_Prev = prev;
		}

		void set_flag(flag_type flags)
		{
			flag = flags;
		}

		bool operator()(flag_type flags)
		{
			return flag == flags;
		}

		void set_data(mutable_type mt)
		{
			data = mt;
		}

		bool operator()(mutable_type mt)
		{
			return data == mt;
		}

		bool scope_read(mutable_type mt)
		{
			return ((regex_node_scope_structure<_Ty>)(data))._Left <= mt &&
				mt <= ((regex_node_scope_structure<_Ty>)(data))._Right;
		}
	};

	template<class _Ty>
	struct regex_node_scope_structure {
		_Ty _Left, _Right;
	};
}

#endif