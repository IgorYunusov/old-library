
	// *** high Fex Library

	// COPYRIGHT ROLLRAT SOFTWARE 2013
	// ALL RIGHT RESERVED

#ifndef HIGHFEX

#include <Windows.h>

typedef struct _tag_HIGHfex
{
#ifndef _HIGHFEX_MACRO_DISUSED_LOADING
	void _setup_x(unsigned short i);
#endif
	unsigned short low1;
	unsigned short low2;
	unsigned long high;
	HANDLE	hHandle;
}	HIGHFEX, *PHIGHFEX;

void HIGHFEX::_setup_x(unsigned short i)
{
	low1 = i;
	low2 = i;
	high = i << 4 | i;
}

void start_highfex(PHIGHFEX x_)
{
#ifndef _HIGHFEX_MACRO_DISUSED_LOADING
	x_->_setup_x(0);
#endif

}
#endif