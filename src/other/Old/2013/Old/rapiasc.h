/*
 *
 *			ROLLRAT SOFTWARE SUBROUTINE
 *			SINCE : 2009 - 2012
 *
 *			Version: 1.2.1.5
 *
 *
 *			Copyright (c) ROLLRAT. All Rights Reserved.
 *
 *
 ***************************************************************************/

// Version : C_1-5-2-3
#pragma once
#if !defined(__R_API_ASCII__)
#define __R_API_ASCII__
#include "runicode.h"
#include "rRetype.h"
UINT GetCharValue(__const __char * pCharText) // Return to char(0) (line) value.
{
	__const __char * O = pCharText __re // __const = const, __char = char, __re = ;
	__whi(*O++){  }						// NULL = 0x00 = 0 = FALSE
	__ret (O - pCharText - 1)__re		// __ret = return
}
UINT GetCharSetValue(__const CHAR rCharText, __const BYTE gCharText) // Return to char(0) ~ gCharText (line) value.
{
	__int i = 0 __re
	__int max = GetCharValue(rCharText) __re // strlen
	__for(__nofor i++) // __nofor = ;;
	{
		__if(rCharText[i] == gCharText){		// __if = if
			__brk 
		}__ifelse(i = max){					// __ifelse = else if
			__brk 							// __brk = break;
		}
	}
	__ret i + 1 __re
}
UINT GetCharGotValue(__const CHAR rCharText, __const BYTE gCharText) // Return to rCharText ~ char(last) (line) value.
{
	__int i = 0 __re
	__int value = 0 __re
	__for(__nofor i++)						// __for = for
	{
		__if(rCharText[i] == gCharText){
			__for(value=i __nofor value++)
			{
				__if(rCharText[value] == '\0')
					__goto _out_ __re		// __goto = goto
			}
		}__ifelse(rCharText[i] == '\0'){
			__brk 
		}
	}
_out_: __re
	__ret i __re
}
UINT GetCharSetGotValue(__const CHAR rCharText, __const BYTE gCharText, __const BYTE fCharText) // Return to gCharText ~ fCharText (line) value.
{
	__int i = 0 __re
	__int value = 0 __re
	__for(__nofor i++)
	{
		__if(rCharText[i] == gCharText){
			__for(value=i __nofor value++)
			{
				__if(rCharText[value] == fCharText){
					__goto _out_ __re
				}__ifelse(rCharText[value] == '\0'){
					value = 0 __re
					__goto _out_ __re
				}
			}
		}__ifelse(rCharText[i] == '\0'){
			__brk 
		}
	}
_out_: __re
	__ret i __re
}
VOID GetCharAsciiCode(__const CHAR tCharText,CHAR fCharText) // English, Number to change Hex.
{
	__int i = 0 __re
	__int f = 0 __re
	__int c = 0 __re
	i = GetCharValue(tCharText) __re
	__for(__re f<=i __re f++)
	{
		__swt(tCharText[f])
		{
			__case('a'): // 0x61 
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '1' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('b'): // 0x62
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '2' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('c'): // 0x63
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('d'): // 0x64
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('e'): // 0x65
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('f'): // 0x66
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = 'f' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('g'): // 0x67
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('h'): // 0x68
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '8' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('i'): // 0x69
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = '9' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('j'): // 0x6A
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = 'A' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('k'): // 0x6B
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = 'B' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('l'): // 0x6C
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = 'C' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('m'): // 0x6D
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = 'D' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('n'): // 0x6E
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = 'E' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('o'): // 0x6F
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = 'F' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('p'): // 0x70
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('q'): // 0x71
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '1' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('r'): // 0x72
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '2' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('s'): // 0x73
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('t'): // 0x74
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('u'): // 0x75
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('v'): // 0x76
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('w'): // 0x77
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('x'): // 0x78
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '8' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('y'): // 0x79
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = '9' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('z'): // 0x7A
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = 'A' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('\0'):
				fCharText[c] = '\0' __re
				__brk

		}
		__swt(tCharText[f])
		{
			__case('A'): // 0x41
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '1' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('B'): // 0x42
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '2' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('C'): // 0x43
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('D'): // 0x44
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('E'): // 0x45
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('F'): // 0x46
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = 'f' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('G'): // 0x47
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('H'): // 0x48
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '8' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('I'): // 0x49
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = '9' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('J'): // 0x4A
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = 'A' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('K'): // 0x4B
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = 'B' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('L'): // 0x4C
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = 'C' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('M'): // 0x4D
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = 'D' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('N'): // 0x4E
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = 'E' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('O'): // 0x4F
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = 'F' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('P'): // 0x50
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('Q'): // 0x51
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '1' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('R'): // 0x52
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '2' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('S'): // 0x53
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('T'): // 0x54
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('U'): // 0x55
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('V'): // 0x56
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('W'): // 0x57
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('X'): // 0x58
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '8' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('Y'): // 0x59
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = '9' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('Z'): // 0x5A
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = 'A' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('\0'):
				fCharText[c] = '\0' __re
				__brk

		}
		__swt(tCharText[f])
		{
			__case('0'): // 0x30
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('1'): // 0x31
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '1' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('2'): // 0x32
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '2' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('3'): // 0x33
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('4'): // 0x34
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '4' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('5'): // 0x35
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '5' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('6'): // 0x36
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '6' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('7'): // 0x37
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '7' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('8'): // 0x38
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '8' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
			__case('9'): // 0x30
				fCharText[c] = '0' __re
				c++ __re
				fCharText[c] = 'x' __re
				c++ __re
				fCharText[c] = '3' __re
				c++ __re
				fCharText[c] = '9' __re
				c++ __re
				fCharText[c] = ' ' __re
				c++ __re
				__brk
		}

	}
}

#endif