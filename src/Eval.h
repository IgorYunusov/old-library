/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Eval.h

Purpose:

   RollRat Library

Author:

   10-31-2015:   HyunJun Jeong, Creation

***/

#ifndef _EVAL_9bf1541fdf7efd41b7b39543fd870ac4_
#define _EVAL_9bf1541fdf7efd41b7b39543fd870ac4_

#define _USE_MATH_DEFINES
#include <math.h>

#include "WString.h"
#include "WStringBuilder.h"
#include "List.h"

#define radian 0.01745329251994329576923690768489 // 57.295779513082320876798154814105

namespace Utility {
	
	class Eval // Arithmetic
	{
		const wchar_t *ptr;
		List<char> variable;
		List<double> values;

		char *variable_release;
		double *values_release;

	public:

		void add_variable(char variable, double dou)
		{
			this->variable.Append(variable);
			this->values.Append(dou);
		}

		double get_value(const wchar_t *ptr)
		{
			this->ptr = ptr;
			variable_release = variable.ToArray();
			values_release = values.ToArray();
			return plus_minus();
		}

		double get_value(const WString& refer)
		{
			return get_value(refer.Reference());
		}

	private:
		
		double plus_minus()
		{
			double result = multiple_divide();
			while(*ptr == L'+' || *ptr == L'-')
				if(*ptr == L'+') {
					ptr++;
					result += multiple_divide();
				} else if(*ptr == L'-') {
					ptr++;
					result -= multiple_divide();
				}
			return result;
		}
		
		double multiple_divide()
		{
			double result = carrot();
			while(*ptr == L'*' || *ptr == L'/')
				if(*ptr == L'*') {
					ptr++;
				INSIDE:
					result *= carrot();
				} else if(*ptr == L'/') {
					ptr++;
					result /= carrot();
				}
			if (iswalpha(*ptr) || *ptr == L'(')
				goto INSIDE;
			return result;
		}
		
		double carrot()
		{
			double result = factor();
			if(*ptr == L'^')
			{
				ptr++;
				result = pow(result, factor());
			}
			return result;
		}
		
		double factor()
		{
		    double result = 0;
		    if (*ptr == L'(') {
		        ptr++;
		        result = plus_minus();
		        if (*ptr == L')') {
		            ptr++;
		            return result;
		        }
			} else if (*ptr == L'|') {
		        ptr++;
		        result = plus_minus();
		        if (*ptr == L'|') {
		            ptr++;
		            return abs(result);
		        }
		    } else if((L'0' <= *ptr) && (*ptr<= L'9') || *ptr == L'-') {
				double ret = 1.0f, minus = 1;
				unsigned int left = 0;
				unsigned long long right = 0;

				if (*ptr == L'-') {
					minus = -1;
					ptr++;
				}
				else if (*ptr == L'+') {
					ptr++;
				}

				while (iswdigit(*ptr)) {
					left = left * 10 + *ptr - L'0';
					ptr++;
				}

				if (*ptr == L'.')
				{
					ptr++;
					while (iswdigit(*ptr)) {
						ret /= 10;
						right = right * 10 + *ptr - L'0';
						ptr++;
					}
				}

				ret = (double)left + right * ret;
				result = ret * minus;
				return result;
			} else if (iswalpha(*ptr)) { // 변수는 한 자리로 취급
				const wchar_t *tmp = ptr;			
				for (; iswalpha(*tmp); tmp++)
					;
				if (*tmp == L'(') {
					WStringBuilder wsb(6);
					
					for (; iswalpha(*ptr); ptr++)
						wsb.Append( *ptr);
					
					WString sst_str;
					sst_str.Clone(wsb.ToString());
					if (*ptr == L'(') {
						ptr++;
						if (sst_str == L"sin") {
							result = sin(plus_minus() * radian);
						} else if (sst_str == L"cos") {
							result = cos(plus_minus() * radian);
						} else if (sst_str == L"tan") {
							result = tan(plus_minus() * radian);
						} else if (sst_str == L"exp") {
							result = exp(plus_minus());
						} else if (sst_str == L"cot") {
							result = 1 / tan(plus_minus() * radian);
						} else if (sst_str == L"csc") {
							result = 1 / sin(plus_minus() * radian);
						} else if (sst_str == L"sec") {
							result = 1 / cos(plus_minus() * radian);
						} else if (sst_str == L"ln" || sst_str == L"log") {
							result = log(plus_minus());
						} else if (sst_str == L"log10") {
							result = log10(plus_minus());
						}
						
						if(*ptr == L')') {
							ptr++;
							return result;
						}
					}
				}
				size_t count = 0;
				for (; count < variable.Size(); count++)
					if (variable_release[count] == *ptr) {
						ptr++;
						return values_release[count];
					}
		    }
		}
	
	};

}

#endif