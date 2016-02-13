/*************************************************************************
 *
 *					  ROLLRAT SOFTWARE LIBRARY
 *						INTER METHOD
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _INTER_METHOD_
#define _INTER_METHOD_

#include "string.h"
#include "tree.h"
#include "urray.h"
#include "serve_method.h"
#include <hash_map>
#include <vector>
#include <stack>
#include <string>
#include <Windows.h>

template<typename _Ty> struct
	_Variable0
	{
	typedef typename String<_Ty> _Mystr;
	_Variable0() {}
	_Variable0(_Mystr& _o, _Mystr& _r) : _Origin(_o), _Replace(_r) {}
	_Mystr  _Origin;
	_Mystr  _Replace;
	};

template<typename _Ty = char, class _Tx = _Variable0<_Ty>> class
	variable
	{
	typedef typename String<_Ty> _Mystr;
	typedef typename std::hash_map<size_t, _Tx> _Myhm;
	_Myhm _map;
public:

	inline void put(_Mystr& _origin, _Mystr& _replace)
		{
		_map.insert(_Myhm::value_type(_origin.make_hash(), *new _Tx(_origin, _replace)));
		}

	inline _Tx& get(_Mystr& _origin)
		{
		auto find = _map.find(_origin.make_hash());
		if(find != _map.end())
			return find->second;
		}

	};

urray<String<>> _intercode_generator(tree<String<>> tree)
	{
	//variable<> var;
	std::stack<String<>> stk;
	std::stack<String<>> stt;
	urray<String<>> code;
	int count = 0;
	bool pref = false;
	postorder_travel([&](String<> str)
		{
		if(**str == '+' || **str == '/' || **str == '-' || **str == '*' || **str == '^'
			|| **str == '&' || **str == '|' || **str == '%')
			{
			//std::string t;
			String<> rvalue, stk_v;
			rvalue.Append("t");
			rvalue.Append(count);
			stk_v.Append("t");
			stk_v.Append(count);
			rvalue.Append("=");
			if(pref)
				{
				if(!stk.empty())
					{
					rvalue.Append(stk.top());
					stk.pop();
					rvalue.Append(*str);
					rvalue.Append(stt.top());
					stt.pop();
					stt.push(stk_v);
					}
				else
					{
					rvalue.Append(stt.top());
					rvalue.Append(*str);
					stt.pop();
					rvalue.Append(stt.top());
					stt.pop();
					stt.push(stk_v);
					}
				}
			else
				{
				String<> pre = stk.top();
				stk.pop();
				rvalue.Append(stk.top());
				rvalue.Append(*str);
				rvalue.Append(pre);
				stk.pop();
				stt.push(stk_v);
				}
			code.Add(rvalue);
			count += 1;
			pref = true;
			}
		else
			{
			String<> rvalue, stk_v;
			rvalue.Append("t");
			rvalue.Append(count);
			stk_v.Append("t");
			stk_v.Append(count);
			stk.push(stk_v);
			rvalue.Append("=");
			rvalue.Append(str);
			code.Add(rvalue);
			count += 1;
			pref = false;
			}
		}
		, tree.travel());
	return code;
	}
 
std::vector<std::string> _intercode_generator(tree<std::string> tree)
	{
	//variable<ch> var;
	std::stack<std::string> stk;
	std::stack<std::string> stt;
	std::vector<std::string> code;
	int count = 0;
	bool pref = false;
	postorder_travel([&](std::string str)
		{
		char ch = str[0];
		if(ch == '+' || ch == '/' || ch == '-' || ch == '*' || ch == '^'
			|| ch == '&' || ch == '|' || ch == '%')
			{
			//std::string t;
			std::string rvalue, stk_v;
			rvalue.push_back('t');
			rvalue.append(std::to_string(count));
			stk_v.push_back('t');
			stk_v.append(std::to_string(count));
			rvalue.push_back('=');
			if(pref)
				{
				if(!stk.empty())
					{
					rvalue.append(stk.top());
					stk.pop();
					rvalue.push_back(ch);
					rvalue.append(stt.top());
					stt.pop();
					stt.push(stk_v);
					}
				else
					{
					rvalue.append(stt.top());
					rvalue.push_back(ch);
					stt.pop();
					rvalue.append(stt.top());
					stt.pop();
					stt.push(stk_v);
					}
				}
			else
				{
				std::string pre = stk.top();
				stk.pop();
				rvalue.append(stk.top());
				rvalue.push_back(ch);
				rvalue.append(pre);
				stk.pop();
				stt.push(stk_v);
				}
			code.push_back(rvalue);
			count += 1;
			pref = true;
			}
		else
			{
			std::string rvalue, stk_v;
			rvalue.push_back('t');
			rvalue.append(std::to_string(count));
			stk_v.push_back('t');
			stk_v.append(std::to_string(count));
			stk.push(stk_v);
			rvalue.push_back('=');
			rvalue.append(str);
			code.push_back(rvalue);
			count += 1;
			pref = false;
			}
		}
		, tree.travel());
	return code;
	}

		// INTERCODE GENERATOR for linked_rvalue
std::vector<std::string> _intercode_generator2(tree<std::string> tree)
	{
	std::stack<std::string> var;	// º¯¼ö
	std::vector<std::string> code;
	int count = 0;
	bool pref = false;
	postorder_travel([&](std::string str)
		{
		if(::strchr("+-*/&^|%<>!~", str[0]))
			{
			std::string rvalue("$t" + std::to_string(count) + "=");
			if (!var.empty())
				{
				std::string temp = var.top();
				var.pop();
				if (!var.empty())
					{
					rvalue.append(var.top()+str+temp);
					var.pop();
					code.push_back(rvalue);
					var.push("$t" + std::to_string(count));
					}
				else 
					goto _LABEL_ERROR;
				}
			else
		_LABEL_ERROR:
				MessageBox(0, TEXT("Input value is incorrect. Please enter a valid expression."), TEXT("Compiler Method V1.5, _intercode_generator2"), MB_OK | MB_ICONERROR);
			}
		else
			{
			std::string rvalue("$t" + std::to_string(count) + "=" + str);
			var.push("$t" + std::to_string(count));
			code.push_back(rvalue);
			}
		count += 1;
		}
		, tree.travel());
	return code;
	}

		// INTERCODE GENERATOR for linked_rvalue with optimize
std::vector<std::string> _optimize_intercode_generator2(tree<std::string> tree)
	{
	std::stack<std::string> var;
	std::vector<std::string> tdup1, tdup2, code;
	int count = 0;
	bool pref = false;
	
	auto is_number=[](std::string cptr)->bool
		{
		for (const char *ptr = cptr.c_str(); 
			('0' <= *ptr && *ptr <= '9') || *ptr == '.'; ptr++)
			if(!*(ptr+1))
				return true;
		return false;
		};

	postorder_travel([&](std::string str)
		{
		if(::strchr("+-*/&^|%<>!~", str[0]))
			{
			std::string rvalue("$t" + std::to_string(count) + "_=");
			if (!var.empty())
				{
				bool second_number = is_number(var.top());
				std::string temp = var.top();
				var.pop();
				if (!var.empty()) {
					if(is_number(var.top()) && second_number) {
						long long v1 = std::stoll(temp), v2 = std::stoll(var.top()), v3=0.0f;
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
							goto JUST_EXCUATE;
						}
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
		_LABEL_ERROR:
				MessageBox(0, TEXT("Input value is incorrect. Please enter a valid expression."), TEXT("Compiler Method V1.5, _optimize_intercode_generator2"), MB_OK | MB_ICONERROR);
			}
		else
			if(is_number(str))
				var.push(str);
			else {
				bool t = false;
				for(int i = 0; i < tdup1.size(); i++)
					if(tdup2[i] == str) {
						var.push(tdup1[i]);
						t = true;
						break;
					}
				if(!t) {
					std::string rvalue("$t" + std::to_string(count) + "_=" + str);
					var.push("$t" + std::to_string(count) + "_");
					tdup1.push_back(var.top());
					tdup2.push_back(str);
					code.push_back(rvalue);
					count += 1;
				}
			}
		}
		, tree.travel());
	if (code.empty())
		code.push_back(var.top());
	return code;
	}

#endif