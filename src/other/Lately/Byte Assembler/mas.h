/*************************************************************************
 *
 *                    TETO. BYTE ASSEMBLER 0.1201.1.1.0
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _MAS_
#define _MAS_

#include "tasm_s.h"

struct _Variable0
	{
	_Variable0() {}
	_Variable0(std::string& _o, std::string& _r) : _Origin(_o), _Replace(_r) {}
	std::string  _Origin;
	std::string  _Replace;
	};

class variable
	{
	std::hash_map<size_t, _Variable0> _map;
public:
	size_t make_hash(const char *_Ptr)
		{
		const char * _tmp = _Ptr;
		int j = 0;
		for(int i = 0; *_tmp; _tmp++)
			j = (j << ((256 | 0x7A64) + i)) + *_tmp;
		return j;
		}

	inline void put(std::string& _origin, std::string& _replace)
		{
		_map.insert(std::hash_map<size_t, _Variable0>::value_type(make_hash(_origin.c_str()), *new _Variable0(_origin, _replace)));
		}

	inline _Variable0& get(std::string& _origin)
		{
		auto find = _map.find(make_hash(_origin.c_str()));
		if(find != _map.end())
			return find->second;
		}
	};

#endif