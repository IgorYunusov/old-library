/*************************************************
 *												 *
 *			RollRat Software Library			 *
 *												 *
 *	Copyright (c) rollrat. All rights reserved.  *
 *_______________________________________________*/

#pragma once

#ifndef _PSTR_
#define _PSTR_

#include "pDEFFMY.h"

SIZE strlen(UNICODE *str)	
{
	FIXED UNICODE *t_str = str;
	while( *t_str++ )
		;
	return (t_str - str - 1);
}

BOOL strcpy(UNICODE *str, FIXED UNICODE *target)	
{
	UNICODE *t_str = str;
	while( (*target++ || *t_str++) && *target )
		*t_str = *target;
	//if(strlen(str) == strlen(target))
		return TRUE;
	return FALSE;
	}

BOOL strcmp(UNICODE *str, UNICODE *target)
{
	FIXED UNICODE *_t = str, *_s = target;
	int i, f = strlen(target);
	if(str == target)
		return TRUE;
	for(i = 0; i <= f; i++, _t++, _s++)
		if(*_t != *_s)
			return FALSE;
	return TRUE;	
}

UNICODE *strfill(UNICODE *str, UNICODE target, SIZE times)
{
	UNICODE *_t = str;
	int i;
	for(i = 0; i <= times; i++, _t++)
		*_t = target;
	return TRUE;	
}

HANDLES inside(HANDLES exH, UNICODE *str, UNICODE *conf)
{
	UNICODE *_t = str, *_s;
	int i = 0;
	while(*conf) 
		conf++;
	//_s = str - conf;
	return (HANDLES)(0);
}

#endif
/*
 *	The rollrat x_library
 *  Updated : 2013-05
 *	http://blog.naver.com/rollrat
 *  Copyright (c) 2009-2013 by rollrat. All right reserved.
 *  For more information, refer to the documentation on the license.
V0.1:0012****/

/*
 *	This item, is available free of charge. However, if you change 
 *	yourself, you can bring fatal consequences. This project is 
 *	based on the ethical issues of the information, and began to 
 *	improve the openness of the program. You can use anyone, but 
 *	please observe the clear copyright notice. When you beat this, 
 *	you can go into the legal action.
V0.1_x_Library_btype*/