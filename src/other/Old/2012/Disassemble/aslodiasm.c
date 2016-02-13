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

// ASLO DISASM

#include "aslodiasm.h"

#define case4(x)	case x: case (x+1): case (x+2): case (x+3):
#define case8(x)	case4(x) case4(x+4)

#define _2		unsigned short
#define _4		unsigned int
#define _8		unsigned long

#define no_return	void

_8 swap_endian(_8 codec)
{
	return ((codec & 0xff) << 24) | ((codec & 0xff00) << 16) 
		| ((codec & 0xff0000) << 8) | (codec & 0xff000000);
}

_2 get_2(_8 codec, int pos)
{
	return (codec & (0xff << (pos * 8))) >> (pos * 8);
}

char *__m_set_decline(_8 codec, char *ret)
{
	_8 dec = swap_endian(codec);

	return ret;
}