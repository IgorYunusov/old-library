#include "rtl.h"

BOOL InStr(wht, target)
	const UNICODE wht;
	const UNICODE_STRING target;
{
	for(; *target; target++)
	{
		if(wht == *target)
		{
			return (TRUE);
		}
	}
	return (FALSE);
}

BOOL InScope(wht, _First, _Last)
	const UNICODE wht;
	UNICODE _First; 
	UNICODE _Last;
{
	return(
		(_First <= wht && wht <= _Last) 
		? (TRUE) : (FALSE));
}