/*************************************************************

	ROLLRAT Project

										Calculator	V 1.1

*************************************************************/

#ifndef _modCal_
#define _modCal_

#include "xtree.h"

template<class variable_type = double> struct
	basis
	{
public:
	variable_type _data;
	int _operator;
	char *_t;
	int _t_size;
	};

#define OPERATOR_NUMBER		1
#define OPERATOR_VARIABLE	2
#define OPERATOR_OPERATOR	3
#define OPERATOR_FUNCTION	4

template<class variable_type = double, 
	typename ch = char> class
	equation
	{
	};

template<class variable_type = double> class
	equation<variable_type, char>
	{
	variable_type *_sic;
	tree<basis<variable_type>> _tree;
public:
	equation(char * _str)
		: _sic(_str) 
		{
		}

private:
	void var()
		{
		exp()
		}
	void exp()
		{
		factor()
		}
	void factor()
		{
		if(*_sic == '(')
			{
			basis<variable_type> t;
			_sic++;
			t._operator = 0;
			_tree.go_right(t);
			var();
			if (*_sic == ')')
				_sic++;
			}
		else if(('0' <= *_sic) && (*_sic <= '9'))
			{
			int _tmp = 0, _tmp_int = 0, _float_c = 0;
			double _under = 0.0f;
			bool float_t = false;
			basis<variable_type> t;
			t._operator = OPERATOR_NUMBER;
			while(true)
				{
				if (('0' <= *_sic) && (*_sic <= '9'))
					{
					_tmp *= 10;
					_tmp += *_sic - '0';
					_sic++;
					_float_c++;
					}
				else if(*_sic == '.')
					{
					_float_c = 0;
					_sic++;
					_tmp_int = _tmp;
					_tmp = 0;
					float_t = true;
					}
				else
					break;
				}
			if(!float_t)
				t._data = (variable_type)(_tmp);
			else
				{
				for(int i = 0; i < _float_c; i++)
					{
					_under /= 10;
					_under += _tmp % 10;
					_tmp /= 10;
					}
				t._data = (variable_type)((double)_tmp_int + _under);
				}
			_tree.set(t);
			}
		}
	};

#endif