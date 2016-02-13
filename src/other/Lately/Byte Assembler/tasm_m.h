/*************************************************************************
 *
 *                    TETO. BYTE ASSEMBLER 0.1201.1.1.0
 *								
 *                           (C) Copyright 2014
 *                                  rollrat
 *                           All Rights Reserved
 *
 *************************************************************************/

#ifndef _TASM_MODM_
#define _TASM_MODM_

#include "tasm_s.h"

std::vector<BYTE> assemble(std::string str, option options)
{
	std::vector<BYTE> _ret;
	variable var;
	// 좌측 공백제거
	str = ltrim(str);

	const char *_Ptr = str.c_str();

	switch(*_Ptr)
	{
	case ':':
		// Directive Check
		// Goto Check
		;
	case ';':
		break;
	default:
		std::vector<std::string> tmp = Split((char *)_Ptr, " ");
		if(is_command(tmp[0].c_str()) == 1)
			{
			if (tmp.size() == 1)
				goto size1;
			const char *tmp1 = tmp[1].c_str();
			if (tmp.size() == 2)
				goto size2;
			int reg1, type1=0, addr1;
			if (reg1 = get_register_small(tmp1))
				type1 = FLAG_REG;
			if (reg1 == E_X && ((options & TASM_OPTION_CAPITAL) == 0))
				if (reg1 = get_register_big(tmp1))
					type1 = FLAG_REG;
			if(type1 == FLAG_NONE)
				if (ISDIGIT(*tmp1))
					if (addr1 = get_address_small(tmp1))
						type1 = FLAG_ADDR;
			///////////////////////////////////////////////
			const char *tmp2 = tmp[2].c_str();
			int reg2, type2=0, addr2, reg_tmp;
			if (reg2 = get_register_small(tmp2))
				type2 = FLAG_REG;
			if (reg2 == E_X && ((options & TASM_OPTION_CAPITAL) == 0))
				if (reg2 = get_register_big(tmp2))
					type2 = FLAG_REG;
			if(type2 == FLAG_NONE)
				if (ISDIGIT(*tmp2))
					if (addr2 = get_address_small(tmp2))
						type2 = FLAG_ADDR;
			reg_tmp = reg2;
			////////////////////////////////////////////////
			if (type1 == FLAG_REG && type2 == FLAG_REG)
				reg2 = reg1;
			_ret.push_back(get_op_code(tmp[0].c_str(), type1, type2, reg1, reg2));
			if (type1 == FLAG_REG)
				_ret.push_back(reg1);
			else if (type1 == FLAG_ADDR)
				PushDWord(addr1, _ret);
			if (type2 == FLAG_REG)
				if(strcmp(tmp1, "mov") != 0)
					_ret.push_back(reg_tmp);
			else if (type2 == FLAG_ADDR)
				PushDWord(addr2, _ret);
			break;
		size1:
			_ret.push_back(get_op_code(tmp[0].c_str(), 0, 0, 0, 0));
			break;
		size2:
			if (reg1 = get_register_small(tmp1))
				type1 = FLAG_REG;
			if (reg1 == E_X && ((options & TASM_OPTION_CAPITAL) == 0))
				if (reg1 = get_register_big(tmp1))
					type1 = FLAG_REG;
			if(type1 == FLAG_NONE)
				if (ISDIGIT(*tmp1))
					if (addr1 = get_address_small(tmp1))
						type1 = FLAG_ADDR;
			_ret.push_back(get_op_code(tmp[0].c_str(), type1, 0, reg1, 0));
			};
	}
	return _ret;
}

std::vector<BYTE> assemble(std::vector<std::string> strs, option options)
{
	std::vector<BYTE> _ret;
	//variable<> var;
	for(auto& str : strs)
	{
		for (auto& ret : assemble(str, options))
			_ret.push_back(ret);
	}

	return _ret;
}
#endif