/*
            ROLLRAT INPUT OUTPUT SYSTEMATIC LANGUAGE PROJECT

             Cpy (c) 14. ALL RIGHTS RESERVED.
   */

#ifndef _PRECOMIPLER_
#define _PRECOMIPLER_

#include <string>

#define PRE_COMPILER_STANDARD_C			1
#define PRE_COMPILER_STANDARD_IOS		2

#define PRE_OPTION_REPLACE				0x000000001
#define PRE_OPTION_SET_UNITY			0x000000002
#define PRE_OPTION_ANOTHER				0x000000004
#define PRE_OPTION_DEFINE				0x000000008
#define PRE_OPTION_CHECK				0x000000010
#define PRE_OPTION_CONDITION			0x000000020
#define PRE_OPTION_COUNTUP				0x000000040
#define PRE_OPTION_COUNTDOWN			0x000000080
#define PRE_OPTION_NOT					0x000000100
#define PRE_OPTION_ERROR				0x000000200

class pre_card_kit_a
	{
public:

	const struct { 
		char ch;
		int command_count;
		struct {
			const char *command;
			int option;
		} command[10];
		int type;
	}	PreOperator[] = {

		// C/C++ Pre Compiler
		{
			'#', 
			9,
			{
				{"define", PRE_OPTION_DEFINE | PRE_OPTION_REPLACE | PRE_OPTION_SET_UNITY},
				{"pragma", PRE_OPTION_ANOTHER | PRE_OPTION_SET_UNITY},
				{"ifndef", PRE_OPTION_NOT | PRE_OPTION_DEFINE | PRE_OPTION_CHECK | PRE_OPTION_CONDITION | PRE_OPTION_COUNTUP},
				{"ifdef", PRE_OPTION_DEFINE | PRE_OPTION_CHECK | PRE_OPTION_CONDITION | PRE_OPTION_COUNTUP},
				{"endif", PRE_OPTION_COUNTUP},
				{"else", PRE_OPTION_NOT},
				{"include", PRE_OPTION_SET_UNITY},
				{"undef", PRE_OPTION_DEFINE | PRE_OPTION_NOT},
				{"error", PRE_OPTION_ERROR}
			},
			PRE_COMPILER_STANDARD_C
		},

		// input.ouput systematic Pre Compiler
		{
			'#', 
			2,
			{
				{"compiler", PRE_OPTION_ANOTHER | PRE_OPTION_SET_UNITY}, 
				{"error", PRE_OPTION_ERROR}
			},
			PRE_COMPILER_STANDARD_IOS
		}
	};

	bool operator()(const char * str)
		{
			
		}

	};

template<class kit = pre_card_kit_a, class _STR = char *>
	class pre_compiler
	{
public:

	};

#endif