/*************************************************************
  
       ROLLRAT FLOW-CHART

       COPYRIGHT @ ROLLRAT. 2014 ALL RIGHTS RESERVED.

**************************************************************/

#ifndef _FLOW_CHART_
#define _FLOW_CHART_

#include "tree.h"

typedef enum class symbol{
	process = 0,
	terminal,
	decision,
	preparation,
	preprocess,
	input_output,
}	FLOW_CHART_SYMBOL;

template<class _CH = char> class
	flowchart
	{

	typedef struct _flow_struct {
		_flow_struct(_CH variable_type, _CH * condition, int type)
			: variable_type(variable_type), condition(condition), type(type)
			{
			}
		explicit _flow_struct(_CH variable_type, _CH * condition)
			: _flow_struct(variable_type, condition, symbol::process)
			{
			}
		explicit _flow_struct()
			: _flow_struct(0, nullptr)
			{
			}
		_CH variable_type;
		_CH * condition;
		symbol type;
		int time;
		tree<struct _flow_struct*>::_MyN* point;
	}	FLOW_STRUCTURE, *PFLOW_STRUCTURE;

	tree<PFLOW_STRUCTURE> flow_tree;

	int l;
public:

	flowchart()
		: l(0)
		{
		}

	void put(_CH ch, const _CH * what, symbol type = symbol::process)
		{
		FLOW_STRUCTURE * flow_ptr = new PFLOW_STRUCTURE;
		auto cocoro = [&](){return l++; };
		switch (type)
			{
		case symbol::process:
			flow_ptr->condition = what;
			flow_ptr->time = cocoro;
			flow_ptr->type = type;
			break;
			}
		}

	};

#endif
