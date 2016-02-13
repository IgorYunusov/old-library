/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_REGEX_
#define _ROLLRAT_REGEX_
#include "rutil.h"
#include "cutilityex.h"

#if defined(_EX_SUCCESS)

/*
COMMON Lib Start*/
_X_LIB_BEGIN

	#define ullong unsigned long long
	#define c_n1( n ) ((unchecked_type)n)

	_CCC_C_TEMPLATE_CS
	template<class _Ty,
			 class _Pointer = _Ty *,
			 class _Reference = _Ty&>
	class regex
		: public _X_TYPE<_Ty>
		{
		typedef typename _X_TYPE<_Ty>::Value_Type _MyVT;
		typedef typename _X_TYPE<_X_TYPE<_Pointer> >::Pointer _MyDPI;
		typedef typename _X_TYPE<_Pointer>::Arrays _MyAY;
		typedef typename _X_TYPE<_Reference>::UnPointer _MyRef;
		typedef typename _X_TYPE<_Pointer>::Pointer _MyPI;
		typedef typename regex<_Ty> _MyT;
		
		public:
			
			explicit regex(const _MyVT patterne)
				: patternex(patterne), length(0)
				{ // entry point
				length = len(patternex)
				}

			void compile(const _MyVT unstories)
				{ // compile all stories
				stories = unstories;
				storieslen = len(unstories);
				}

		private:

			template<typename unchecked_type>
				unchecked_type len(const _MyVT what)
					{ // get length
					unchecked_type n = 0;
					for(; what[n] != 0;);
					return n;
					}

			template<typename unchecked_type>
				void swap(unchecked_type& i, unchecked_type& f)
					{ // swapping
					unchecked_type t = i; i = f; f = t;
					}

			class match_helper
				{
				public: 
					match_helper(ullong messages, ullong keepings, bool es = false)
						: message(message), keeping(keepings), esc(es){ }
					ullong message;
					ullong keeping;
					bool esc;
				};

			template<typename unchecked_type, typename return_type>
				return_type match_element(const unchecked_type element = 0, const
						unchecked_type nextex = 0, const unchecked_type wipe = 0, const unchecked_type prev = 0)
					{ // matching stories
						_MyVT buf;

						for(ullong keeping = 0; keeping != storieslen; keeping++)
						{
							switch(element)
							{
							case c_n1('\\'):
								ex = match_helper(element, keeping);
								return match_element(nextex, wipe);
							case c_n1('w'):
								if (ex.message == '\\'){ex = match_helper(element, keeping, true);}
								if (ex.esc == true){
								if('a' <= stories[keeping] && stories[keeping] <= 'z')return true;
								if('A' <= stories[keeping] && stories[keeping] <= 'Z')return true;
								if('0' <= stories[keeping] && stories[keeping] <= '9')return true;
								if(stories[keeping] == '_')
								return true;}
								ex = match_helper(element, keeping);
							}
						}
					}

			template<typename unchecked_type>
				bool match_elements(const unchecked_type element)
				{return stories[ex.keeping] == element;}

			void realloc(ullong size)
				{
				_MyAY* buf = new _MyAY[size];
				for(ullong f = 0; f <= matchsize; f++)
					buf[f] = Match[f];
				matchsize = size;
				return buf;
				}

		private:

			ullong length;
			ullong storieslen;
			_MyVT patternex;
			_MyVT stories;

			match_helper ex;
			ullong matchsize;
			_MyVT* Match;

		};

_X_LIB_END

#endif

#endif