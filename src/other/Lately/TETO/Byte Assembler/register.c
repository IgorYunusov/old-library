#include "tasm_def.h"
#include "register.h"

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