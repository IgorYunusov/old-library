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
		//	����/����/���鹮�� �� ���� ��ġ�մϴ�.
		//
		IsCharacter,
		IsNumberic,
		IsWhiteSpace,
		IsDot, // \n�� ������ �� ���� ���ڿ� ��ġ

		//
		//	���� �������� ( [0-9] )���� ��Ÿ���� ������ ����ŵ�ϴ�.
		//
		IsScopeValueOf,

		//
		//	���� �������� ����
		//
		IsScopeNormal,
		IsScopeDifferenceOf, // ������
		IsScopeDeepOf, // ������

		//
		//	�������� ������ ��ġ�մϴ�.
		//
		IsLogicOr, // (...|...|...)

		//
		//	ó���� ���� ��Ÿ���� ���ڿ� ��ġ�մϴ�. �̴� ���� �߰��� �� �� �����ϴ�.
		//
		IsStart,
		IsEnd,

		//
		//	�ݺ������ ��ġ�մϴ�.
		//
		IsIterateAsterrisk,
		IsIterateQuestion,
		IsIteratePlug,
		IsIterateTime, // { ~~ }
		IsIterateTimeScope, // { ~~, ~~ }

	} flag_type;




	/**
		Ŭ���� ���:
			���� ����ǥ���� �м� Ŭ����
	
		���ø� �䱸����:
			&( char * ) �Ǵ� ���� ����
	**/
	template<class _Ty>
	class Regex
	{
		// const char *���� *�� ���۷����� ����� ����
		typedef typename remove_pointer<_Ty>::value_type value_type;
		typedef typename remove_pointer<_Ty>::value_type* pointer;

		pointer _Ptr;

	public:
	
		Regex(const pointer _ptr)
			: _Ptr(_ptr)
		{
			// ���� �м� ����
			parse_syntax();
		}

	private:

		void parse_syntax()
		{
		}

	};

	
	/**
		Ŭ���� ���:
			Regex Node for Regex Provider
	
		���ø� �䱸����:
			Regex�� ����
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