/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   loop.h

Project:

   风橇 包府 档备

------
   AUTHOR: HyunJun Jeong  2015-07-18

***************************************************************************/

#ifndef _LOOP_
#define _LOOP_

#include "type.h"
#include "varmap.h"

class loop {
	variable _varmap;
public:

	void set_map(variable& varmap)
	{
		_varmap = varmap;
	}

	void create_cx_loop(std::string var_name, int starts, int ends)
	{

	}

};

#endif