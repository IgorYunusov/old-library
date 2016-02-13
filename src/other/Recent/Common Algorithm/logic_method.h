/*************************************************************************
  
   RollRat Software Common Parser Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: logic.h
                         Abstract: Logic expression solver
                         Creation: 2015-03-10
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _LOGIC_c948da428ed90827ec113072f75b421f_
#define _LOGIC_c948da428ed90827ec113072f75b421f_

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "rocket.h"

class logic_method 
{
	const char *ptr;
	std::string temp;
	std::vector<char> variable_vec;
	std::vector<bool> bool_vec;

public:

	void add_variable(char variable_name, bool bo = false)
	{
		for (char ptr : variable_vec)
			if (ptr == variable_name)
				return;
		variable_vec.push_back(variable_name);
		bool_vec.push_back(bo);
	}

	bool get_value(const char *str)
	{
		ptr = str;
		return var();
	}

	void view_value_table(const char *str)
	{
		using namespace std;

		cout << "--Logic Expression Table--" << endl
			<< "Exp: " << str << endl;
		
		stringstream sst;
		stringstream bar;

		sst << "|   ";
		bar << "+---";
		for (char ptr : variable_vec) {
			sst << ptr << "   |   ";
			bar <<       "----+---";
		}
		bar << "--------+";
		sst << "Value   |";
		
		cout << bar.str() << endl;
		cout << sst.str() << endl;
		cout << bar.str() << endl;

		int maximum = bool_vec.size();
		int maximum_binary = 1;
		for (int i = 0; i < maximum; i++)
			maximum_binary <<= 1;
		maximum_binary -= 1;

		for(int j = 0; j <= maximum_binary; j++)
		{
			bool_vec.clear();

			cout << "|   ";
			for (int k = maximum - 1; k >= 0; k--) 
			{
				bool_vec.push_back((j&(1 << k)) >> k);

				cout << ((j&(1 << k)) >> k) << "   |   ";
			}

			cout << "  " << get_value(str) << "     |" << endl;
		}
		cout << bar.str() << endl;
	}

	void view_value_table_file(const char *str, std::string address)
	{
		using namespace std;

		ofstream ost(address);

		if (ost.fail())
			return;

		ost << "--Logic Expression Table--" << endl
			<< "Exp: " << str << endl;
		
		stringstream sst;
		stringstream bar;

		sst << "|   ";
		bar << "+---";
		for (char ptr : variable_vec) {
			sst << ptr << "   |   ";
			bar <<       "----+---";
		}
		bar << "--------+";
		sst << "Value   |";
		
		ost << bar.str() << endl;
		ost << sst.str() << endl;
		ost << bar.str() << endl;

		int maximum = bool_vec.size();
		int maximum_binary = 1;
		for (int i = 0; i < maximum; i++)
			maximum_binary <<= 1;
		maximum_binary -= 1;

		for(int j = 0; j <= maximum_binary; j++)
		{
			bool_vec.clear();

			ost << "|   ";
			for (int k = maximum - 1; k >= 0; k--) 
			{
				bool_vec.push_back((j&(1 << k)) >> k);

				ost << ((j&(1 << k)) >> k) << "   |   ";
			}

			ost << "  " << get_value(str) << "     |" << endl;
		}
		ost << bar.str() << endl;

		ost.close();
	}

private:

	bool inverse()
	{
		if (*ptr == '\'')
		{
			ptr++;
			return true;
		}
		return false;
	}

	bool var()
	{
		bool result = multiple();
		result ^= inverse();
		while (*ptr == '+' || *ptr == '@' || *ptr == '|')		// Or, Xor
		{
			if (*ptr == '+' || *ptr == '|') {
				ptr++;
				bool temp = multiple();
				temp ^= inverse();
				result |= temp;
			} else {
				ptr++;
				bool temp = multiple();
				temp ^= inverse();
				result ^= temp;
			}
		}
		return result;
	}

	bool multiple()
	{
		bool result = factor();
		result ^= inverse();
		while (*ptr == '*' || *ptr == '&')		// And
		{
			ptr++;
		INSIDE:
			bool temp = factor();
			temp ^= inverse();
			result &= temp;
		}
		if (_isalpha(*ptr) || *ptr == '(')		// »ý·«µÈ °ö
			goto INSIDE;
		return result;
	}

	bool factor()
	{
		bool result = false;
		if(*ptr == '(')
		{
			ptr++;
			result = var();
			if(*ptr == ')')
			{
				ptr++;
				result ^= inverse();
				return result;
			}
		} else if (_isalpha(*ptr)) {
			size_t count = 0;
			for (; count < variable_vec.size(); count++)
				if (variable_vec[count] == *ptr) {
					ptr++;
					return bool_vec[count];
				}
		}
		return result;
	}

};


#endif