
#include "tasm.h"

#include <string.h>

_DATA _data_e[0xFF] = 
{
	{"and", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"or", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"xor", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"add", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"adc", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"sub", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"sbb", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"mul", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"div", FLAG_REG, FLAG_DATA, 0, 0},
	{"cmp", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"shl", FLAG_REG, FLAG_DATA, 0, 0}, 
	{"shr", FLAG_REG, FLAG_DATA, 0, 0}, 

	{"and", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"or", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"xor", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"add", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"adc", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"sub", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"sbb", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"mul", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"div", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"cmp", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"shl", FLAG_REG, FLAG_ADDR, 0, 0}, 
	{"shr", FLAG_REG, FLAG_ADDR, 0, 0}, 

	{"and", FLAG_REG, FLAG_REG, 0, 0}, 
	{"or", FLAG_REG, FLAG_REG, 0, 0}, 
	{"xor", FLAG_REG, FLAG_REG, 0, 0}, 
	{"add", FLAG_REG, FLAG_REG, 0, 0}, 
	{"adc", FLAG_REG, FLAG_REG, 0, 0}, 
	{"sub", FLAG_REG, FLAG_REG, 0, 0}, 
	{"sbb", FLAG_REG, FLAG_REG, 0, 0}, 
	{"mul", FLAG_REG, FLAG_REG, 0, 0}, 
	{"div", FLAG_REG, FLAG_REG, 0, 0}, 
	{"cmp", FLAG_REG, FLAG_REG, 0, 0}, 
	{"shl", FLAG_REG, FLAG_REG, 0, 0}, 
	{"shr", FLAG_REG, FLAG_REG, 0, 0}, 

	// push <operator>
	// pop <operator>
	{"push", FLAG_REG, 0, EAX, 0},
	{"push", FLAG_REG, 0, ECX, 0},
	{"push", FLAG_REG, 0, EDX, 0},
	{"push", FLAG_REG, 0, EBX, 0},
	{"push", FLAG_REG, 0, ESP, 0},
	{"push", FLAG_REG, 0, EBP, 0},
	{"push", FLAG_REG, 0, ESI, 0},
	{"push", FLAG_REG, 0, EDI, 0},
	{"pop", FLAG_REG, 0, EAX, 0},
	{"pop", FLAG_REG, 0, ECX, 0},
	{"pop", FLAG_REG, 0, EDX, 0},
	{"pop", FLAG_REG, 0, EBX, 0},
	{"pop", FLAG_REG, 0, ESP, 0},
	{"pop", FLAG_REG, 0, EBP, 0},
	{"pop", FLAG_REG, 0, ESI, 0},
	{"pop", FLAG_REG, 0, EDI, 0},
	{"push", FLAG_ADDR, 0, 0, 0},

	// inc
	{"inc", FLAG_REG, 0, EAX, 0},
	{"inc", FLAG_REG, 0, ECX, 0},
	{"inc", FLAG_REG, 0, EDX, 0},
	{"inc", FLAG_REG, 0, EBX, 0},
	{"inc", FLAG_REG, 0, ESP, 0},
	{"inc", FLAG_REG, 0, EBP, 0},
	{"inc", FLAG_REG, 0, ESI, 0},
	{"inc", FLAG_REG, 0, EDI, 0},
	{"dec", FLAG_REG, 0, EAX, 0},
	{"dec", FLAG_REG, 0, ECX, 0},
	{"dec", FLAG_REG, 0, EDX, 0},
	{"dec", FLAG_REG, 0, EBX, 0},
	{"dec", FLAG_REG, 0, ESP, 0},
	{"dec", FLAG_REG, 0, EBP, 0},
	{"dec", FLAG_REG, 0, ESI, 0},
	{"dec", FLAG_REG, 0, EDI, 0},

	// mov
	{"mov", FLAG_REG, FLAG_ADDR, EAX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, ECX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EDX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EBX, 0},
	{"mov", FLAG_REG, FLAG_ADDR, ESP, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EBP, 0},
	{"mov", FLAG_REG, FLAG_ADDR, ESI, 0},
	{"mov", FLAG_REG, FLAG_ADDR, EDI, 0},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EAX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, ECX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EDX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EBX},
	{"mov", FLAG_ADDR, FLAG_REG, 0, ESP},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EBP},
	{"mov", FLAG_ADDR, FLAG_REG, 0, ESI},
	{"mov", FLAG_ADDR, FLAG_REG, 0, EDI},
	{"mov", FLAG_REG, FLAG_REG, EAX, EAX},
	{"mov", FLAG_REG, FLAG_REG, ECX, ECX},
	{"mov", FLAG_REG, FLAG_REG, EDX, EDX},
	{"mov", FLAG_REG, FLAG_REG, EBX, EBX},
	{"mov", FLAG_REG, FLAG_REG, ESP, ESP},
	{"mov", FLAG_REG, FLAG_REG, EBP, EBP},
	{"mov", FLAG_REG, FLAG_REG, ESI, ESI},
	{"mov", FLAG_REG, FLAG_REG, EDI, EDI},

	// jump
	{"jo", FLAG_ADDR, 0, 0, 0},
	{"jno", FLAG_ADDR, 0, 0, 0},
	{"jb", FLAG_ADDR, 0, 0, 0},
	{"jnb", FLAG_ADDR, 0, 0, 0},
	{"jz", FLAG_ADDR, 0, 0, 0},
	{"jnz", FLAG_ADDR, 0, 0, 0},
	{"jbe", FLAG_ADDR, 0, 0, 0},
	{"ja", FLAG_ADDR, 0, 0, 0},
	{"js", FLAG_ADDR, 0, 0, 0},
	{"jnx", FLAG_ADDR, 0, 0, 0},
	{"jp", FLAG_ADDR, 0, 0, 0},
	{"jnp", FLAG_ADDR, 0, 0, 0},
	{"jl", FLAG_ADDR, 0, 0, 0},
	{"jnl", FLAG_ADDR, 0, 0, 0},
	{"jle", FLAG_ADDR, 0, 0, 0},
	{"jnle", FLAG_ADDR, 0, 0, 0},
	{"jmp", FLAG_ADDR, 0, 0, 0},

	{"call", FLAG_ADDR, 0, 0, 0},
	{"ret", 0, 0, 0, 0},

	{"lea", 0, 0, 0, 0},
	
	{"std", 0, 0, 0, 0},// http://bab2min.tistory.com/245
	{"cld", 0, 0, 0, 0},
	{"lodsd", 0, 0, 0, 0},
	{"stosd", 0, 0, 0, 0},

	{"pushf", FLAG_ADDR, 0, 0, 0},
	{"pusha", 0, 0, 0, 0},
	{"popf", FLAG_ADDR, 0, 0, 0},
	{"popa", 0, 0, 0, 0},

	{"nop", 0, 0, 0, 0},
	{"INT3", 0, 0, 0, 0},

};

int get_op_code(const  char *cm, int op1, int op2, int op3, int op4)
{
	int i;
	for(i = 0; i < 0xff; i++)
		if (_data_e[i].op1 == op1)
			if (_data_e[i].op2 == op2)
				if (_data_e[i].op3 == op3 || !_data_e[i].op3)
					if (_data_e[i].op4 == op4  || !_data_e[i].op4)
						if (strcmp(_data_e[i].command, cm) == 0)
							return i;
	return (-1);
}

int is_command(const char *cm)
{
	int i;
	for(i = 0; i < 0xff; i++)
		if (strcmp(_data_e[i].command, cm) == 0)
			return 1;
	return 0;
}

int get_register_small(const char* _T)
{
	const char * _Ptr = _T; 
	char _Tmp;
	if (*_Ptr == ' ')
		_Ptr++;
	if (*_Ptr++ != 'e')
		return E_X;
	switch (*(_Ptr + 1))
	{
	case 'x':
		_Tmp = *_Ptr - 'a';
		return (((_Tmp ^ 0x2) + (_Tmp >> 1)) & 
			((_Tmp << 1) | (_Tmp >> 1) | _Tmp)) + EAX;
	case 'p':
		return (~*_Ptr & 1) + 5;
	case 'i':
		return (~*_Ptr & 1) + 7;
	}
	return E_X;
}

int get_register_big(const char* _T)
{
	const char * _Ptr = _T; 
	char _Tmp;
	if (*_Ptr == ' ')
		_Ptr++;
	if (*_Ptr++ != 'E')
		return E_X;
	switch (*(_Ptr + 1))
	{
	case 'X':
		_Tmp = *_Ptr - 'A';
		return (((_Tmp ^ 0x2) + (_Tmp >> 1)) & 
			((_Tmp << 1) | (_Tmp >> 1) | _Tmp)) + EAX;
	case 'P':
		return (~*_Ptr & 1) + 5;
	case 'I':
		return (~*_Ptr & 1) + 7;
	}
	return E_X;
}

int get_address_small(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ','; _Ptr++)
	{
		g *= 16;
		g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr  - '0') : (*_Ptr  - 'a' + 0xa);
	}
	return g;
}

int get_address_big(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0;
	for (; *_Ptr != ' ' && *_Ptr && *_Ptr != ','; _Ptr++)
	{
		g *= 16;
		g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr  - '0') : (*_Ptr  - 'A' + 0xa);
	}
	return g;
}