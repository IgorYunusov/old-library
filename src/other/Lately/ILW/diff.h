/*************************************************************************
 *
 * FILE NAME : diff.h - Differential with symbols
 *
 * Interactive Legibility Works
 *
 *
 * CREATION : 2014.11.18
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#ifndef _DIFF_
#define _DIFF_

#include "ilw.h"
#include <vector>
#include <stack>
#include <string>

namespace ILW {
	
	namespace Calculate {

#define ilw_isdigit( ch )		::isdigit( ch )
#define ilw_isspace( ch )		::isspace( ch )
#define ilw_isalpha( ch )		::isalpha( ch )

			// template Differential Calculator class
		class differential {
		public:

			typedef differential CType;
			typedef	char _Diffch, *_Diffptr;
			typedef _REF wstring	_Diff_type;

			_Diff_type temp;

			differential(_Diff_type& diff_target) 
				: temp(diff_target) {
			}

		private:

			_Diffptr FunctionList[] = {
				0,
				"cos",
				"sin",
				"tan",
				"sec",
				"csc",
				"cot",
				"log",
				"log10",
				"ln",
				"exp",
				"cosh",
				"sinh",
				"tanh"
			};

			int GetSingleObjectBy(_Diffptr g, const _Diffch t, const _Diffch u) {
				int count = 0;
				while(*(g++))
					if(*g == t)
						count++;
					else if(*g == u)
						if(--count == 0)
							return ++count;
			}

			template<class _Ty, size_t _size> size_t array_size(_Ty (&x)[_size]) {
				return _size;
			}

			int Matching(_Diffptr fn, _Diffptr list[], size_t size) {
				//size_t max = array_size(list);
			}

			_Diffptr GetFunction(_Diffptr fn) {
				_Diffptr fn_temp = fn;
				while (ilw_isalpha(*fn_temp++) && *fn_temp)
					;
				fn_temp--;
				while (ilw_isdigit(*fn_temp++) && *fn_temp)
					;
				fn_temp--;
				
				int func;
				if (!(func = Matching(fn, FunctionList, fn_temp - fn + 1)))
					return nullptr;

			}
		};

	}

}

#endif