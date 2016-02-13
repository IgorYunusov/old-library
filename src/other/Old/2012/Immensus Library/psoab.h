/****************************************************************
 *																*
 *																*
 *			ROLLRAT AUTO PERSONA VERBOTER LIBROFEX				*
 *																*
 *																*
 *		COPYRIGHT (c) rollrat. 2013. ALL RIGHTS RESERVED.		*
 *																*
 *																*
 ****************************************************************/

#ifndef __portableseditionemoutaponiabreak // Portable Seditionem Out Aponia Break
#define __portableseditionemoutaponiabreak

/*************************************************************

	RollRat 4 Fundamental Arithmetic Operations Calculator

	Extended Backus-Naur Form(EBNF)

	:MODULE
		<exp> -> <term> { <addop> <term> }
		<addop> -> + | - | * | /
		<term> -> <factor> { <mulop> <factor> }
		<term> -> <factor> { <divop> <factor> }
		<mulop> -> * | <divop> -> /
		<factor> -> ( <exp> ) | num | char

	:SAFE
		$ <exp> | <exp> | <exp> | ... | <exp>

*************************************************************/

#define unfinished_unicode_template		char

int RY_ConvertHexDigit(const char val)
{
	if((val <= '9') && (val >= '0'))
		return (val - '0');
	if((val >= 'a') && (val <= 'f'))
		return ((val - 'a') + 10);
	if((val < 'A') || (val > 'F'))
		return -1;
	return ((val - 'A') + 10);
}

template<class _UTF = unfinished_unicode_template> class
	_4faoc
{ // 4 Fundamental Arithmetic Operations Calculator
	_UTF gb_token;
	const _UTF *ptr;
public:

	// basic module

	int factor()
	{
		int temp;
		if(gb_token == '(') 
		{
			match('(');
			temp = exp();
			match(')'); 
		}
		else if(('0' <= gb_token) && (gb_token <= '9')) 
		{
			forward();
			temp = getint();
			gb_token = getnextchar(); 
		}
		return temp;
	}

	int exp()
	{
		int temp = term();
		while((gb_token == '+') || (gb_token == '-'))
			if(gb_token == '+') 
			{
				match('+');
				temp += term();
			}
			else if(gb_token == '-')
			{
				match('-');
				temp -= term(); 
			}
		return temp;
	}

	int term()
	{
		int temp = factor();
		while(gb_token == '*' || gb_token == '/') 
		{
			switch(gb_token)
			{
			case '*':
				match('*');
				temp *= factor();
				break;
			case '/':
				match('/');
				temp /= factor();
				break;
			} 
		}
		return temp;
	}

public:

	// match module

	void charset(const char *st)
	{
		ptr = st;
		gb_token = getnextchar();
	}

	void match(_UTF e)
	{
		if(gb_token == e)
			gb_token = getnextchar();
	}

	void forward()
	{
		ptr--;
	}

	_UTF getnextchar()
	{
		ptr++;
		return *(ptr - 1);
	}

	int getint()
	{
		char temp = getnextchar();
		int tp = 0;
		while(true) 
		{
			if('0' <= temp && temp <= '9') 
			{
				tp *= 10;
				tp += RY_ConvertHexDigit(temp);
				temp = getnextchar(); 
			} 
			else 
			{
				forward();
				break;
			}
		}
		return tp;
	}

};

#endif