/*******************************************************************\
 *rsyna.h -- rollrat syntax analysis library.					   *
 *rtools.h -- tools												   *
 *Purpose :														   *
 *		This library was created to parse the [RollRatParser].	   *
 *		Duty and for other purposes, if you want, you need to	   *
 *		modify the library in some you can.						   *
 *																   *
 *Dealing :														   *
 *		C/C++ Language, RollRatParser							   *
 *																   *
 *Available :													   *
 *		CompilerParser, Syntax analyzer							   *
 *																   *
 *			Copyright (c) rollrat. All rights reserved.			   *
 *																   *
\*******************************************************************/

#ifndef __rollrat_csplit

#include "rvsprintf.h"

int 
StringLength
(
	const char* ptr
	)
{
    int i = 0;
	while( ptr[i] ) { i++; }
    return i;
}//rollrat

char 
*
Split
(
	const char *rCharText, 
	const char fSplit, 
	int Arrange
	)
{
	int i=0, f=0, Split=0;
	char Buf[10][1000];
	while(rCharText[f])
	{
		if(rCharText[f] == fSplit)
		{
			Buf[Split][++i] = '\0';
			Split++;
			i = 0;
		}
		if(rCharText[f] != fSplit)
		{
			Buf[Split][i] = rCharText[f];
		}
		else
		{
			Buf[Split][--i] = rCharText[f];
		}
		i++;
		f++;
	}
	if(rCharText[f] == 0)
	{
		Buf[Split][++i] = '\0';
		Split++;
		i = 0;
	}
	if(rCharText[f] != fSplit)
	{
		Buf[Split][i] = rCharText[f];
	}
	else
	{
		Buf[Split][--i] = rCharText[f];
	}
	return Buf[Arrange];
}//rollrat

int
CountChar
(
	const char * rCharText,
	const char fC
	)
{
	int i=0;
	int count=0;
	while(rCharText[i])
	{
		if(rCharText[i] == fC)
		{
			count++;
		}
		i++;
	}
	return count;
}//rollrat

char 
*
strstr
(
	const char *operand, 
	const char *operators
	)
{
	int i;
	if(*operand=='\0'){
		return (char *)operand;
	}else{
		for(;*operand;operand++){
			if(*operand==*operators){
				for(i=1;*(operand+i)==*(operators+i);i++);
				if(i==StringLength(operators))
					return (char *)operand;
			}
		}
		return 0;
	}
}// somewhere of google

char *strncpy(char *dest, const char *src, size_t n)
{
    char *ret = dest;
    int i;

    for(i = 0; i<n ; i++)
    {
        if((*dest++ = *src++) == 0)
        {
            while(++i < n)
            {
                *dest++ = 0;
            }
            return ret;
        }
    }
    return ret;
}// somewhere of google

typedef char *  va_list;

#define _crt_va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
    #define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
    #define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define _crt_va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
   #define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define _crt_va_end(ap)      ( ap = (va_list)0 )

long 
sprintf
(
	char * buf, 
	char * format, 
	...
	)
{
	int ret;
	va_list args;
	_crt_va_start(args, format);
	ret = vsprintf(buf, format, args);
	_crt_va_end(args);
	return ret;
}//rollrat

char *replace(char *st, char *orig, char *repl) 
{
	static char buffer[4096];
	char *ch;
	if (!(ch = strstr(st, orig)))
		return st;
	strncpy(buffer, st, ch-st);  
	buffer[ch-st] = 0;
	sprintf(buffer + (ch-st), "%s%s", repl, ch + StringLength(orig));
	return buffer;
} // http://www.roseindia.net/c-tutorials/c-replace-string.shtml

#endif