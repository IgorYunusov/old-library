/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Regex.h

Purpose:

   RollRat Library

Author:

   12-12-2015:   HyunJun Jeong, Creation

***/

#ifndef _REGEX_9bf1541fdf7efd41b7b39543fd870ac4_
#define _REGEX_9bf1541fdf7efd41b7b39543fd870ac4_

#include "WStringBuilder.h"
#include "List.h"

#include <functional>
#include <stack>

#define BUFFER_SIZE_OF		(00255)
#define STACK_SIZE_OF		(65535)

namespace Utility {
	
	typedef enum class _regex_symbol {
		Alnum = 0,
		Alpha = 1,
		Boundary = 2,
		Space = 3, // space and tab
		//Upper = 4,
		Unicode = 4,
		Lower = 5,
		Punct = 6,
		Word = 7,
		Digit = 8,
		XDigit = 9,
		Tab = 10,		// \t
		Return = 11,	// \r
		LineFeed = 12,	// \n
		Control = 13,
		Graph = 14,
		Print = 15,
		ODigit = 16,
	//  Boundary = 17, // \b
	}	RegexSymbol;

	typedef enum class _regex_type {
		None = 0,
		AnyOne = 1, // 모든 글자
		Character = 2,
		String = 3,
		Symbol = 4, // escape
		BackJmp = 5, //no
		FrontJmp = 6,
		Goto = 7, //no
		GroupOr = 8,
		// (~|~|~)
		GroupAnd = 9,
		// (~(~)~)
		GroupNan = 10, // (?<=), (?=), (?:)
		ClassChar = 11, // []
		Capture = 12,
	}	RegexType;

	typedef enum class _regex_jmp { // loop
		PassWhatever = 0, // *
		PassOneMore = 1, // +
		PassTobeorNot = 2, // ?
		PassConditional = 3, // {}, {,}
		// _Ix2 == _Ix3 : Count _Ix2
		// _Ix2 & _Ix3=0 : Count more equal _Ix2
		// _Ix2 & _Ix3 : Count more euqal _Ix2 less equal _Ix3
	}	RegexJump;

	typedef enum class _regex_quantifier {
		Greedy = 1, // ex) .* or .*+
		Lazy = 2, // ex) .*?
	}	RegexQuantifier;

	typedef enum class _regex_option {
		None = 0,
		Multiline = 1,
	}	RegexOption;

	class RegexNode
	{
	public:

		int _Identifier;

		RegexType       _RegType;
		RegexJump       _RegJmp;
		RegexQuantifier _RegQuan;

		class RegexSymbolT
		{
		public:

			RegexSymbol _Symbol;
			bool _Not;
			int _Value;

		};

		RegexSymbolT* _RegSym;

		int _Index1; // goto, jmp index
		int _Index2; // {(~),~}
		int _Index3; // {~,(~)}

		// no capture group
		// inverse class char (carrot)
		bool _Not;

		WString* _String;
		wchar_t  _Char;

		class RegexClass
		{
		public:
			
			List< std::pair<wchar_t, wchar_t> > _Scope;
			List< RegexSymbolT* > _Symbol;
			List< wchar_t > _Characters;

		}* _RegClass;

		bool IsNonTerminal() const
		{
			if ( _RegType == RegexType::AnyOne    ||
				 _RegType == RegexType::Character ||
				 _RegType == RegexType::String    ||
				 _RegType == RegexType::Symbol     )
				 return true;
			return false;
		}

		bool IsJump() const // IsLoop
		{
			if ( _RegType == RegexType::BackJmp  ||
				 _RegType == RegexType::FrontJmp ||
				 _RegType == RegexType::Goto      )
				 return true;
			return false;
		}

		bool IsGroup() const
		{
			if ( _RegType == RegexType::GroupOr   ||
				 _RegType == RegexType::GroupAnd  ||
			//   _RegType == RegexType::ClassChar || 
				 _RegType == RegexType::Capture    )
				 return true;
			return false;
		}

		RegexNode* next;
		RegexNode* group;

		//---------------------------------------------------------------------------
		//
		//   GroupAnd Diagram
		//   Ex) \w(\s(\w\s)+)?123
		//
		//   \w ------ groupand(?) ------ 123 ------ (0)
		//                 \
		//                 \s ------ groupand(+)
		//                               \
		//                               \w ------ \s
		//
		//---------------------------------------------------------------------------
		//
		//   GroupOr Diagram
		//   Ex) \w(a|b|c)+1
		//  
		//   \w ------ groupand(+) ------ groupor ------ groupor ------ 1 ------ (0)
		//                 \                  \              \
		//                  a                  b              c
		//
		//   So, scan next node when groupand.
		//
		//---------------------------------------------------------------------------

	};

	class RegexParser
	{
	public:

		int _I_count = 0;
		int _Or_count = 0;

		std::stack<RegexNode *> stack; // group stack
		std::stack<int> orstack;

		const wchar_t* ptr;

		RegexNode* _Head;
		RegexNode* _Last;

		RegexParser(const wchar_t* ptr)
			: ptr(ptr), _Head(get_alloc()), _Last(_Head) { scan_entry(); }
		
		RegexNode* get_nodes()
			{ return _Head; }

		RegexNode* get_alloc()
			{ RegexNode* node = new RegexNode; node->next = nullptr; node->_Identifier = _I_count++; return node; }

		void create_new()
			{ _Last = _Last->next = get_alloc(); }

		// Regex Scan Core

		wchar_t elem() // no safe
			{ return *ptr++; }
		wchar_t prev() // no safe
			{ return ptr[-1]; }
		wchar_t next() // no safe
			{ return ptr[1]; }
		wchar_t now()
			{ return *ptr; }
		void front()
			{ ptr++; }
		void back()
			{ ptr--; }
		bool end()
			{ return *ptr == 0; }

		bool numeric()
			{ return isdigit(*ptr); }
		bool hex()
			{ return isxdigit(*ptr); }
		bool alnum()
			{ return isalnum(*ptr); }
		bool alpha()
			{ return isalpha(*ptr); }
		bool walnum()
			{ return iswalnum(*ptr); }
		bool upper()
			{ return isupper(*ptr); }
		bool lower()
			{ return islower(*ptr); }

		void push()
			{ stack.push(_Last); _Last = _Last->group = get_alloc(); }
		void pop()
			{ _Last = stack.top(); stack.pop(); }
		
		void scan_entry()
		{
			switch ( elem() )
			{
			case L'^':
				_Last->_RegType = RegexType::None;
				_Last->_Index1 = 1; // Starts With
				create_new();
				break;
				
			default:
				back();
				break;
			}
			
			_Last->_RegType = RegexType::None;
			_Last->_Index1 = 0; // Entry Point
			push();
			scan_core();
		}

		void scan_core()
		{
			switch ( elem() )
			{
			case L'\\':
				scan_terminal();
				break;

			case L'.':
				_Last->_RegType = RegexType::AnyOne;
				break;

			case L'(':
				orstack.push(_Or_count);
				_Or_count = 0;
				_Last->_RegType = RegexType::GroupAnd;
				scan_nan();
				push();
				break;

			case L'|':
				pop();
				_Or_count++;
				_Last->_RegType = RegexType::GroupOr;
				push();
				break;
				
			case L')':
				pop();
				_Or_count = orstack.top();
				orstack.pop();
				break;

			case L'[':
				scan_chclass();
				break;

				// wcschr ...
			case L'*':
			case L'+':
			case L'?':
			case L'{':
				scan_loop();
				break;

			case L'$':
				_Last->_RegType = RegexType::None;
				_Last->_Index1 = 2; // ends With
				return;

			default:
				scan_nonterminal();
				break;

			}

			if ( ! end() )
			{
				create_new();
				scan_core();
			}
		}

		// Regex Component Scanner

		void scan_char()
		{
			_Last->_RegType = RegexType::Character;
			_Last->_Char = elem();
		}

		void scan_nonterminal()
		{
			wchar_t  buf[BUFFER_SIZE_OF];
			wchar_t* tpr = buf;

			while ( walnum() )
			{ 
				*tpr++ = elem();
			}

			// check length
			if ( tpr - buf == 1 )
			{
				_Last->_RegType = RegexType::Character;
				_Last->_Char = *tpr;
			}
			else
			{
				_Last->_RegType = RegexType::String;
				_Last->_String = new WString((const wchar_t *)buf, tpr - buf);
			}
		}

		void scan_terminal()
		{
			if ( !alpha() )
			{
				scan_char();
			}
			else
			{
				_Last->_RegType = RegexType::Symbol;
				scan_terminal(*(_Last->_RegSym = new RegexNode::RegexSymbolT));
			}
		}

		void scan_terminal(RegexNode::RegexSymbolT& _Terminal)
		{
			_Terminal._Not = upper();
			
			switch (towlower(elem()))
			{
			case L'w':
				_Terminal._Symbol = RegexSymbol::Word;
				break;

			case L's':
				_Terminal._Symbol  = RegexSymbol::Space;
				break;

			case L'd':
				_Terminal._Symbol  = RegexSymbol::Digit;
				break;

			case L'u':
				_Terminal._Symbol = RegexSymbol::Unicode;
				_Terminal._Value = ((elem() & 15) << 4) + (elem() & 15);
				_Terminal._Value <<= 8;
				_Terminal._Value += ((elem() & 15) << 4) + (elem() & 15);
				break;

			case L'l':
				_Terminal._Symbol = RegexSymbol::Lower;
				break;

			case L'b':
				_Terminal._Symbol = RegexSymbol::Boundary;
				break;

			case L'p':
				_Terminal._Symbol = RegexSymbol::Punct;
				break;

			case L't':
				_Terminal._Symbol = RegexSymbol::Tab;
				break;

			case L'r':
				_Terminal._Symbol = RegexSymbol::Return;
				break;

			case L'n':
				_Terminal._Symbol = RegexSymbol::LineFeed;
				break;

			case L'x':
				_Terminal._Symbol = RegexSymbol::XDigit;
				_Terminal._Value= ((elem() & 15) << 4) + (elem() & 15);
				break;

			case L'g':
				_Terminal._Symbol = RegexSymbol::Graph;
				break;

			case L'o':
				_Terminal._Symbol = RegexSymbol::ODigit;
				break;

			}
		}

		void scan_loop()
		{
			_Last->_RegType = RegexType::FrontJmp;
			_Last->_Index1 = 1 + _Or_count;

			switch ( prev() )
			{
			case L'*':
				_Last->_RegJmp = RegexJump::PassWhatever;
				if ( next() == L'?' )
				{
					_Last->_RegQuan = RegexQuantifier::Lazy;
					front();
				}
				else
				{
					if ( next() == L'+' )
						front();
					_Last->_RegQuan = RegexQuantifier::Greedy;
				}
				break;

			case L'+':
				_Last->_RegJmp = RegexJump::PassOneMore;
				break;

			case L'?':
				_Last->_RegJmp = RegexJump::PassTobeorNot;
				break;

			case L'{':
				_Last->_RegJmp = RegexJump::PassConditional;
				_Last->_Index2 = _Last->_Index3 = 0;

				while ( isspace(now()) ) elem();
				while ( numeric() ) _Last->_Index2 = _Last->_Index2 * 10 + elem() & 15;
				while ( isspace(now()) ) elem();

				if ( now() == L',' )
				{
					while ( isspace(now()) ) elem();
					if ( now() != L'}')
					{
						_Last->_Index3 = 0;
						while ( numeric() ) _Last->_Index3 = _Last->_Index3 * 10 + elem() & 15;
						while ( isspace(now()) ) elem();
					}
					else
					{
						_Last->_Index3 = _Last->_Index2;
					}
				}
				break;
			}
		}

		void scan_nan()
		{
			_Last->_Not = false;

			if ( now() == L'?' )
			{
				front();

				switch ( elem() )
				{
				case L':':
					_Last->_Not = true;
					break;

				case L'<':

					if ( next() == L'=' )
					{
					}
					else
					{
						_Last->_RegType = RegexType::Capture;
						scan_nonterminal();
						front(); // > 생략
					}
					break;

				case L'=':

					break;
				}
			}
		}

		void scan_chclass()
		{
			if ( now() == L'^' )
			{
				_Last->_Not = true;
				front();
			}
			else
			{
				_Last->_Not = false;
			}

			_Last->_RegClass = new RegexNode::RegexClass;

			while ( now() != L']' )
			{
				switch ( elem() )
				{
				case L'\\':
					if ( !alpha() )
					{
						_Last->_RegClass->_Characters.Append(elem());
					}
					else
					{
						RegexNode::RegexSymbolT *_sym = new RegexNode::RegexSymbolT;
						scan_terminal(*_sym);
						_Last->_RegClass->_Symbol.Append(_sym);
					}
					break;

				default:
					if ( now() == L'-' )
					{
						_Last->_RegClass->_Scope.Append(std::pair<wchar_t, wchar_t>(prev(),next()));
						ptr += 2;
					}
					else
					{
						_Last->_RegClass->_Characters.Append(prev());
					}
					break;
				}
			}
			front();
		}

	};
	
	//class RegexUnit;
	//class RegexCompiler
	//{
	//public:

	//	std::stack<RegexNode*> _gStack; // group stack
	//	RegexNode* _Last;

	//	RegexUnit* _Unit;

	//	RegexCompiler(RegexNode* _node)
	//		: _Last(_node), _Unit(new RegexUnit) { compile(); }

	//	void compile()
	//	{
	//	}

	//};
	
	/*class RegexUnit
	{
		typedef void(RegexUnit::*Func)(int, int);

		Func _func[BUFFER_SIZE_OF];

	public:

		int _StkPtr = 0;
		const wchar_t* _Target;
		bool _State = false;

		RegexUnit()
		{
			_func[0] = &RegexUnit::_Goto;
			_func[1] = &RegexUnit::_JmpBack;
			_func[2] = &RegexUnit::_JmpFront;
			_func[3] = &RegexUnit::_Jmp;
			_func[4] = &RegexUnit::_CmpCh;
			_func[5] = &RegexUnit::_Test0;
			_func[6] = &RegexUnit::_JmpBackIf;
			_func[7] = &RegexUnit::_JmpFrontIf;
			_func[8] = &RegexUnit::_JmpIf;
		}

		inline void _Goto(int i, int)
		{
			_StkPtr = i;
		}
		inline void _JmpBack(int i, int)
		{
			_StkPtr -= i;
		}
		inline void _JmpFront(int i, int)
		{
			_StkPtr += i;
		}
		inline void _Jmp(int i, int)
		{
			_StkPtr = _StkPtr + i;
		}
		inline void _CmpCh(int i, int)
		{
			_State = *_Target == (wchar_t)i;
		}
		inline void _Test0(int, int)
		{
			_State = false;
		}
		inline void _JmpBackIf(int i, int)
		{
			if ( _State ) _JmpBack(i,0); _Test0(0,0);
		}
		inline void _JmpFrontIf(int i, int)
		{
			if ( _State ) _JmpFront(i,0); _Test0(0,0);
		}
		inline void _JmpIf(int i, int)
		{
			if ( _State ) _Jmp(i,0); _Test0(0,0);
		}
			
		struct UnitStackList {
			int _op, _v1, _v2;
		};

		UnitStackList _Stk[STACK_SIZE_OF];

	};*/

}

#endif