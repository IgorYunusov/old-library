/*
 *	Rollrat Api
 *
 *	Function Gropup
 */

#if !defined(_R_API_MD_)
#define _R_API_MD_

#include "Type.h"

#include "Api_Math.h"

#define _FAR
typedef void _FAR *va_list;
#define __size(x)				((sizeof(x)+sizeof(int)-1) & ~(sizeof(int)-1))
#define va_start(ap, parmN)		((void)((ap) = (va_list)((char _FAR *)(&parmN)+__size(parmN))))
#define va_arg(ap, type)		(*(type _FAR *)(((*(char _FAR *_FAR *)&(ap))+=__size(type))-(__size(type))))
#define va_end(ap)				((void)0)

//Average Function
LDKORK Mean(const char * fCharText,...)
{
	int i = 0;
	static LDKORK		L_Putting = 0;
	int					ALL_GAESOO = 0;
	va_list va_arg;
	va_start(va_arg,fCharText);
	while(fCharText[i])
	{
		if(fCharText[i] == '%')
		{
			switch(fCharText[++i]){
				case('a'):
				case('b'):
				case('c'):
				case('d'):
				case('e'):
				case('f'):
					ALL_GAESOO++;
					L_Putting += (float)va_arg(va_arg,float);
					break;
				case('g'):
				case('h'):
				case('i'):
					ALL_GAESOO++;
					L_Putting += (int)va_arg(va_arg,int);
					break;
				case('j'):
				case('k'):
				case('l'):
					ALL_GAESOO++;
					L_Putting += (long)va_arg(va_arg,long);
					break;
				case('m'):
				case('n'):
				case('o'):
					ALL_GAESOO++;
					L_Putting += (LDKORK)va_arg(va_arg,LDKORK);
					break;
				case('p'):
				case('q'):
				case('r'):
				case('s'):
					ALL_GAESOO++;
					L_Putting += (short)va_arg(va_arg,short);
					break;
				case('t'):
				case('u'):
				case('v'):
				case('w'):
				case('x'):
				case('y'):
				case('z'):
				default:
					break;
			}
		}else{
			i++;
		}
	}
	L_Putting = L_Putting / ALL_GAESOO;
	va_end(va_arg);
	return L_Putting;
}



#endif