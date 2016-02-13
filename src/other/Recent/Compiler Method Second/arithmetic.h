/*************************************************************************
  
   RollRat Software Common Parser Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: arithmetic.h
                         Abstract: Formula expression solver
                         Creation: 2015-03-11
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _ARITHMETIC_26e816805c2eb54063da29d3d21a3641_
#define _ARITHMETIC_26e816805c2eb54063da29d3d21a3641_

#define _USE_MATH_DEFINES
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <cmath>
#include <stack>
#include "rocket.h"

#define radian 0.01745329251994329576923690768489 // 57.295779513082320876798154814105

// RollRat Eval - sscanft.c ���Ͽ��� ������

static void _internal_get_ll(char const const * *src, long long *target)
{
	const char *s = *src;
	long long minus = 1;
	unsigned long long left = 0;
	
	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		left = left * 10 + *s - '0';
		s++;
	}

	*src = s;
	*target = (double)left * minus;
}

static void _internal_sscanft_get_double(char const const * *src, double *target)
{
	const char *s = *src;
	double ret = 1.0f, minus = 1;
	unsigned int left = 0;
	unsigned long long right = 0;
	
	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		left = left * 10 + *s - '0';
		s++;
	}

	if( *s == '.' )
	{
		s++;
		while( _isdigit(*s) ) {
			ret /= 10;
			right = right * 10 + *s - '0';
			s++;
		}
	}

	ret = (double)left + right * ret;
	*src = s;
	*target = ret * minus;
}

static void _internal_sscanft_get_ldouble(char const const * *src, long double *target)
{
	const char *s = *src;
	long double ret = 1.0f, minus = 1;
	unsigned int left = 0;
	unsigned long long right = 0;
	
	if( *s == '-' ) {
		minus = -1;
		s++;
	} else if ( *s == '+' ) {
		s++;
	}

	while( _isdigit(*s) ) {
		left = left * 10 + *s - '0';
		s++;
	}

	if( *s == '.' )
	{
		s++;
		while( _isdigit(*s) ) {
			ret /= 10;
			right = right * 10 + *s - '0';
			s++;
		}
	}

	ret = (double)left + right * ret;
	*src = s;
	*target = ret * minus;
}

class arithmetic_method
{
	const char *ptr;
	std::string temp;
	std::vector<char> variable_vec;
	std::vector<double> double_vec;

public:

	void add_variable(char variable_name, double bo = 0.0)
	{
		for (char ptr : variable_vec)
			if (ptr == variable_name)
				return;
		variable_vec.push_back(variable_name);
		double_vec.push_back(bo);
	}

	double get_value(const char *str)
	{
		ptr = str;
		return plus_minus();
	}

private:

	double plus_minus()
	{
		double result = multiple_divide();
		while(*ptr == '+' || *ptr == '-')
			if(*ptr == '+') {
				ptr++;
				result += multiple_divide();
			} else if(*ptr == '-') {
				ptr++;
				result -= multiple_divide();
			}
		return result;
	}

	double multiple_divide()
	{
		double result = carrot();
		while(*ptr == '*' || *ptr == '/')
			if(*ptr == '*') {
				ptr++;
			INSIDE:
				result *= carrot();
			} else if(*ptr == '/') {
				ptr++;
				result /= carrot();
			}
		if (_isalpha(*ptr) || *ptr == '(')		// ������ ��
			goto INSIDE;
		return result;
	}

	double carrot()
	{
		double result = factor();
		if(*ptr == '^')
		{
			ptr++;
			result = pow(result, factor());
		}
		return result;
	}

	double factor()
	{
	    double result = 0;
	    if (*ptr == '(') {
	        ptr++;
	        result = plus_minus();
	        if (*ptr == ')') {
	            ptr++;
	            return result;
	        }
		} else if (*ptr == '|') {
	        ptr++;
	        result = plus_minus();
	        if (*ptr == '|') {
	            ptr++;
	            return abs(result);
	        }
	    } else if(('0' <= *ptr) && (*ptr<= '9') || *ptr == '-') {
			/*bool minus = false;
			if (*ptr == '-')
				ptr++, minus = true;
	        while(true)
	            if('0' <= *ptr && *ptr<= '9')  {
	                result *= 10;
	                result += *ptr - '0';
	                ptr++;
	            } else {
	                break;
				}
			if (minus == true)
				return -result;
	        return result;*/
			_internal_sscanft_get_double(&ptr, &result);
			return result;
		} else if (_isalpha(*ptr)) { // ������ �� �ڸ��� ���
			const char *tmp = ptr;			
			for (; _isalpha(*tmp); tmp++)
				;
			if (*tmp == '(') {
				std::stringstream sst;

				for (; _isalpha(*ptr); ptr++)
					sst << *ptr;

				std::string sst_str = sst.str();
				if (*ptr == '(') {
					ptr++;
					if (sst_str == "sin") {
						result = sin(plus_minus() * radian);
					} else if (sst_str == "cos") {
						result = cos(plus_minus() * radian);
					} else if (sst_str == "tan") {
						result = tan(plus_minus() * radian);
					} else if (sst_str == "exp") {
						result = exp(plus_minus());
					} else if (sst_str == "cot") {
						result = tan((M_PI_2 - plus_minus()) * radian);
					} else if (sst_str == "csc") {
						result = sin((M_PI_2 - plus_minus()) * radian);
					} else if (sst_str == "sec") {
						result = cos((M_PI_2 - plus_minus()) * radian);
					} else if (sst_str == "ln" || sst_str == "log") {
						result = log(plus_minus());
					} else if (sst_str == "log10") {
						result = log10(plus_minus());
					}

					if(*ptr == ')') {
						ptr++;
						return result;
					}
				}
			}
			size_t count = 0;
			for (; count < variable_vec.size(); count++)
				if (variable_vec[count] == *ptr) {
					ptr++;
					return double_vec[count];
				}
	    }
	}

};

class arithmetic_method_postexpression
{
	const char *ptr;
	std::string temp;
	std::string result;

public:

	const char *get(const char *str)
	{
		ptr = str;
		plus_minus();
		return result.c_str();
	}

private:

	void plus_minus()
	{
		multiple_divide();
		while(*ptr == '+' || *ptr == '-') {
			char tmp = *ptr++;
			multiple_divide();
			result += tmp;
		}
	}

	void multiple_divide()
	{
		carrot();
		while(*ptr == '*' || *ptr == '/')
			if(*ptr == '*') {
				*ptr++;
			INSIDE:
				carrot();
				result += '*';
			} else if(*ptr == '/') {
				*ptr++;
				carrot();
				result += '/';
			}
		if (isalpha(*ptr) || *ptr == '(')
			goto INSIDE;
	}

	void carrot()
	{
		factor();
		if(*ptr == '^')
		{
			char tmp = *ptr++;
			factor();
			result += tmp;
		}
	}

	void factor()
	{
	    if (*ptr == '(') {
	        ptr++;
	        plus_minus();
	        if (*ptr == ')') {
	            ptr++;
	        }
	    } else if(('0' <= *ptr) && (*ptr<= '9') || *ptr == '-' || *ptr == '+') {
			if(*ptr == '-' || *ptr == '+')
				result += *ptr++;
			while( isdigit(*ptr) )
				result += *ptr++;
			if(*ptr == '.') {
				result += *ptr++;
				while( isdigit(*ptr) )
					result += *ptr++;
			}
		} else if (isalpha(*ptr)) {
			const char *tmp = ptr;			
			for (; isalpha(*tmp); tmp++)
				;
			if (*tmp == '(') {
				std::stringstream sst;

				for (; isalpha(*ptr); ptr++)
					sst << *ptr;

				std::string sst_str = sst.str();
				if (*ptr == '(') {
					ptr++;
					result += sst.str() + '(';
					plus_minus();
					if(*ptr == ')') {
						ptr++;
						result += ')';
					}
				}
			} else 
				result += *ptr++;
	    }
	}

};

class arithmetic_method_intercode
{
	const char *ptr;
	std::string temp;
	std::string result;

public:

	std::vector<std::string> get_intercode(const char *str)
	{
		ptr = str;
		plus_minus();
		//return result.c_str();
		if (code.empty())
			code.push_back(var.top());
		return code;
	}

private:

	std::string c2str(char c)
	{
		std::stringstream ss;
		ss << c;
		std::string str;
		ss >> str;
		return str;
	}

	void plus_minus()
	{
		multiple_divide();
		while(*ptr == '+' || *ptr == '-') {
			char tmp = *ptr++;
			multiple_divide();
			put_into_puzzlepannel(c2str(tmp));
		}
	}

	void multiple_divide()
	{
		carrot();
		while(*ptr == '*' || *ptr == '/')
			if(*ptr == '*') {
				*ptr++;
			INSIDE:
				carrot();
				put_into_puzzlepannel(c2str('*'));
			} else if(*ptr == '/') {
				*ptr++;
				carrot();
				put_into_puzzlepannel(c2str('/'));
			}
		if (isalpha(*ptr) || *ptr == '(')
			goto INSIDE;
	}

	void carrot()
	{
		factor();
		if(*ptr == '^')
		{
			char tmp = *ptr++;
			factor();
			put_into_puzzlepannel(c2str(tmp));
		}
	}

	void factor()
	{
	    if (*ptr == '(') {
	        ptr++;
	        plus_minus();
	        if (*ptr == ')') {
	            ptr++;
	        }
	    } else if(('0' <= *ptr) && (*ptr<= '9') /*|| *ptr == '-' || *ptr == '+'*/) {
			//if(*ptr == '-' || *ptr == '+')
			//	result += *ptr++;
			std::stringstream sst;
			while( isdigit(*ptr) )
				sst << *ptr++;
			if(*ptr == '.') {
				sst << *ptr++;
				while( isdigit(*ptr) )
					sst << *ptr++;
			}
			put_into_puzzlepannel(sst.str());
		} else if (isalpha(*ptr)) {
			const char *tmp = ptr;			
			for (; isalpha(*tmp); tmp++)
				;
			if (*tmp == '(') {
				std::stringstream sst;

				for (; isalpha(*ptr); ptr++)
					sst << *ptr;

				std::string sst_str = sst.str();
				if (*ptr == '(') {
					ptr++;
					result += sst.str() + '(';
					plus_minus();
					if(*ptr == ')') {
						ptr++;
						result += ')';
					}
				}
			} else 
				put_into_puzzlepannel( c2str(*ptr++) );
	    }
	}

private:

	std::stack<std::string> var;
	std::vector<std::string> tdup1, tdup2, code;
	int count = 0;

	bool is_number(std::string cptr)
	{
		for (const char *ptr = cptr.c_str(); 
			('0' <= *ptr && *ptr <= '9') || *ptr == '.'; ptr++)
			if(!*(ptr+1))
				return true;
		return false;
	}

	void put_into_puzzlepannel(std::string str)
	{
        /*

        �߰��ڵ� ������ ù ��° �ܰ�� ���� ó������ ����� ����
        �������� ���� ����, ������ ���� ������ ó���մϴ�.

        */
		if(::strchr("+-*/&^|%<>!~=", str[0]))
			{

            /*

            ����� ���� �� ���ο� ������ ����ϴ�.
            �� �������� ���ο� ������ ���� ���ÿ� ����˴ϴ�.

            */
			std::string rvalue("$t" + std::to_string(count) + "_=");

            /*

            ���ÿ� �ƹ� �͵� ������ �����ڿ��� lvalue�� �������� �ʴ� �� �̹Ƿ� 
            Ʈ�� ������������ ������ ���� �� �Դϴ�.
            �� ��� ����ڰ� ������ �߸��Է��Ͽ��� ���ɼ��� �����ϴ�.

            1. ���ÿ��� 2���� ������ �����ɴϴ�.
            2. �������� ������, ���ʿ� ���� ������ ������� �ֽ��ϴ�.
            3. ���� �������� ������� ���� ������ ���ÿ� �ֽ��ϴ�.
            4. ����, ����ȭ ���� ��Ұ� �����Ѵٸ�, �ش� ��Ҹ� ����ȭ�ϰ�,
               ����ȭ�� ���� ���ÿ� �ֽ��ϴ�.

            */
			if (!var.empty())
				{
				bool second_number = is_number(var.top());
				std::string temp = var.top();
				var.pop();
				if (!var.empty()) {
                    
                    /*

                    number <operator> number�� ������ ��� ������ �����ϹǷ�,
                    ���� �����Ͽ� �߰��ڵ带 ����ȭ�մϴ�.

                    */
					if(is_number(var.top()) && second_number) {
						long long v1 = std::stoll(temp), v2 = std::stoll(var.top()), v3=0;
						switch(*str.c_str()) {
						case '+': v3 = v2 + v1; break;
						case '-': v3 = v2 - v1; break;
						case '*': v3 = v2 * v1; break;
						case '/': v3 = v2 / v1; break;
						case '&': v3 = v2 & v1; break;
						case '^': v3 = v2 ^ v1; break;
						case '|': v3 = v2 | v1; break;
						case '%': v3 = v2 % v1; break;
						default:

                            //
                            //  �˷����� ���� �������� ���
                            //
							goto JUST_EXCUATE;
						}
                        var.pop();
						var.push(std::to_string(v3));
					} else {
			JUST_EXCUATE:
						rvalue.append(var.top()+str+temp);
						var.pop();
						code.push_back(rvalue);
						var.push("$t" + std::to_string(count) + "_");
						count += 1;
						}
				} else 
					goto _LABEL_ERROR;
				}
			else 
                {
		_LABEL_ERROR:
				MessageBox(0, TEXT("Input value is incorrect. Please enter a valid expression."), 
                    TEXT("Compiler Method V1.5, _optimize_intercode_generator2"), MB_OK | MB_ICONERROR);
                exit(0);
                }
			}
		else

            /*

            ó�� ���� ���� �����ϰ�� ����ȭ ��Ұ� ���� �� �����Ƿ�
            �ϴ�, ���ÿ� ������ �Ӵϴ�.

            ���� ���ڰ� �ƴ� ��� ������ ����ϹǷ� �ش� ������ �����ϴ� ������ �����
            �ش� ������ ���ÿ� �ֽ��ϴ�.

            */
			if(is_number(str))
				var.push(str);
			else {
				bool t = false;

                /*

                �ߺ��Ǵ� ������ �ִ��� Ȯ���մϴ�.

                ����, �ߺ��Ǵ� ������ ���� ��� �ش� ������ ���ÿ� �ְ�, �� ������ ����ġ��,
                ���� ��� ���ο� ������ �����ϴ� ������ �����մϴ�.

                */
				for(int i = 0; i < tdup1.size(); i++)
					if(tdup2[i] == str) {

                        //
                        //  ���͸� �����鼭 �ϳ��� �߰ߵȴٸ� �ش� ������ ���� �ʿ䰡 �����Ƿ�
                        //  ���� ������ ���ÿ� �ֽ��ϴ�.
                        //
						var.push(tdup1[i]);
						t = true;
						break;
					}

				if(!t) {

                    /*

                    $t~~_�� ���� ���´� ù ������ $�� ���� �� ó���� ���� ������ �ʴ� ���ڶ� ����� ���̸�,
                    ������ ������ _�� $t�� ������ ���ڸ��� ���� ��� strcmp�� true�� ������ ������ ��찡 ���ܼ� �Դϴ�.
                    ����, �����ڿ� ������ �������� �ʾұ� ������ �������� �ڿ� ���� ���̷�
                    �ش� ����� ����Ͽ����ϴ�.

                    */
					std::string rvalue("$t" + std::to_string(count) + "_=" + str);

                    //
                    //  ���ڿ� ���������� ������ ���ÿ� �ֽ��ϴ�.
                    //
					var.push("$t" + std::to_string(count) + "_");

                    //
                    //  ������ �ߺ��� Ȯ���ϱ� ���� tdup1�� ����
                    //
					tdup1.push_back(var.top());
					tdup2.push_back(str);

					code.push_back(rvalue);
					count += 1;
				}
            }
	}

};


#endif