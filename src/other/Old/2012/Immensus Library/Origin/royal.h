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

#ifndef __royal
#define __royal

int RY_ConvertHexDigit(const char val)
{
	if((val <= '9') && (val >= '0'))
		return (val - '0');
	if((val >= 'a') && (val <= 'f'))
		return ((val - 'a') + 10);
	if((val < 'A') || (val > 'f'))
		return -1;
	return ((val - 'A') + 10);
}

#endif