////
//
//		ROLLRAT SOFTWARE STRING . C
// 
//										//
//////////////////////////////////////////


#define _FAR
typedef void _FAR *va_list;
#define __size(x) ((sizeof(x)+sizeof(int)-1) & ~(sizeof(int)-1))
#define va_start(ap, parmN) ((void)((ap) = (va_list)((char _FAR *)(&parmN)+__size(parmN))))
#define va_arg(ap, type) (*(type _FAR *)(((*(char _FAR *_FAR *)&(ap))+=__size(type))-(__size(type))))
#define va_end(ap)          ((void)0)

#include "rapifunc.h"

void CharReset(char * iCharText)
{
	int i = 0;
	while(iCharText[i++])
	{
		iCharText[i] = '\0';
	}
}
char * Put(const char * fCharText,...)
{
	int i = 0;
	int dText = 0;
	static char iTextChar[100] = {0, };
	static char dTextChar[100] = {0, };
	char * pChar;
	va_list va_arg;
	va_start(va_arg,fCharText);
	while(fCharText[i])
	{
		if(fCharText[i] == '%')
		{
			switch(fCharText[++i]){
				case('a'): /* char point	    */
				case('b'): /* bool			    */
				case('c'): /* char				*/
				case('d'): /* int				*/
					dText = (int)va_arg(va_arg, int);
					pChar = (char*)itoa(dText);
					while( *pChar )
					{
						dTextChar[dText] = *pChar;
						*pChar++;
						dText++;
					}
					dTextChar[dText] = '\0';
					break;
				case('e'): /* escape		    */
				case('f'): /* float				*/
				case('g'):
				case('h'):
				case('i'): /* long			    */
				case('j'):
				case('k'):
				case('l'): /* double			*/
				case('m'):
				case('n'):
				case('o'):
				case('p'):
				case('q'):
				case('r'):
				case('s'): /* string		    */
					pChar = (char*)va_arg(va_arg,char*);
					while( *pChar )
					{
						dTextChar[dText] = *pChar;
						*pChar++;
						dText++;
					}
					dTextChar[dText] = '\0';
					break;
				case('t'): /* type set		    */
				case('u'):
				case('v'):
				case('w'):
				case('x'): /* point				*/
				case('y'):
				case('z'):
				default:
					break;
			}
		}else{
			i++;
		}
	}
	va_end(va_arg);
	return dTextChar;
}