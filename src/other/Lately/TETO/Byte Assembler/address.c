#include "tasm_def.h"
#include "address.h"

int get_address_small(const char *_t)
{
	const char *_Ptr = _t;
	int g = 0;
	for (; *_t != ' ' && *_t; _t++)
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
	for (; *_t != ' ' && *_t; _t++)
	{
		g *= 16;
		g += ('0' <= *_Ptr  && *_Ptr  <= '9') ? (*_Ptr  - '0') : (*_Ptr  - 'A' + 0xa);
	}
	return g;
}