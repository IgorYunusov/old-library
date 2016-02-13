/*
 *	Rollrat Api
 *
 *	Function Gropup
 */

#ifndef _R_API_CHAR_
#define _R_API_CHAR_

#include "Api_IO.h"
#include "Type.h"

/*	This Function is R_Char Function. 
 *	So i can give a impormation.
 */
PLCON _nbuf Split(OCHAR rCharText, OCNST fSplit, DWORD Arrange)
{
	DWORD i=0, f=0, Split=0;
	AREA CHAR Buf[10][1000];
	while(rCharText[f])
	{
		//Note:
		//	Copy_ x_rCharText include_ x_fSplit
		//
		if(rCharText[f] == fSplit)
		{
			//Note:
			//	Next_ y_Buf[ _..x- ][ ... ] inc_ y_i
			//
			Buf[Split][++i] = '\0';

			//Note:
			//	Check_ y_Split inc_ y_Split
			//
			Split++;

			//Note:
			//	Check_ y_Buf[ ... ][ reset this part ]
			//
			i = 0;
		}

		//Note:
		//	Check_ x_fSplit _exemption
		//
		if(rCharText[f] != fSplit)
		{
			//Note:
			//	Check_ Normal
			//
			Buf[Split][i] = rCharText[f];
		}
		else
		{
			//Note:
			//	Delete_ y_Buf[ ... ][ _..x- ] dec_ y_i
			//
			Buf[Split][--i] = rCharText[f];
		}
		i++;
		f++;
	}
	return Buf[Arrange];
}

void _buf Replace(OCHAR rCharText,OCNST fC,OCNST hC)
{
	DWORD i=0;
	while(rCharText[i])
	{
		if(rCharText[i] == fC)
		{
			rCharText[i] = hC;
		}
		i++;
	}
}

void _buf PrevChar(PLCON rCharText, OCNST fC, PLCON Buf_Char)
{
	DWORD i=0;
	while(rCharText[i] != fC)
	{
		if (rCharText[i] == '\0')
		{
			Buf_Char = "";
		}
		else
		{
			Buf_Char[i] = rCharText[i];
			i++;
		}
	}
	Buf_Char[++i] = '\0';
}

void _buf _noerror NextChar(PLCON rCharText, OCNST fC, PLCON Buf_Char)
{
	DWORD i=0,f=0;
	while(rCharText[i] != fC){ i++; }
	i++;
	while(rCharText[i])
	{
		Buf_Char[f] = rCharText[i];
		i++;
		f++;
	}
	Buf_Char[++i] = '\0';
}

void _buf _noerror MiddleChar(PLCON rCharText, OCNST fC, OCNST hC, PLCON Buf_Char)
{
	//Note:
	//	If fC and hC is the same, please use the Split.
	//
	DWORD i=0,f=0;
	while(rCharText[i] != fC){ i++; }
	i++;
	while(rCharText[i] != hC)
	{
		Buf_Char[f] = rCharText[i];
		i++;
		f++;
	}
	Buf_Char[++i] = '\0';
}

void _fbuf _noerror PutChar(PLCON rCharText, PLCON fCharText, OCNST fC)
{
	DWORD i=0,f=0,z=0,h=0,p=0;
	CHAR Buf[1000] = {0,};
	while(rCharText[i] != fC){ i++; }
	z = i--;
	while(rCharText[z])
	{
		Buf[h] = rCharText[z];
		h++;
		z++;
	}
	while(rCharText[z])
	{
		Buf[h] = rCharText[z];
		z++;
		h++;
	}
	while(fCharText[f])
	{
		rCharText[i] = fCharText[f];
		i++;
		f++;
	}
	while(Buf[++p])
	{
		rCharText[i] = Buf[p];
		i++;
	}
}

//
//	Fail Algorithm.
//
DWORD _noerror FindWord(PLCON rCharText, PLCON fCharWord)
{
	DWORD i=0,fCharLenth=0,Totalf=0;
	while(fCharWord[Totalf]){ Totalf++; }
	while(rCharText[i])
	{
		if(rCharText[i] == rCharText[fCharLenth])
		{
			fCharLenth++;
		}
		i++;
	}
	if (fCharLenth == Totalf)
	{
		return i;
	}
	else
	{
		return fCharLenth;
	}
}

PLCON strcpy(PLCON dest, OCNST *str)
{
	PLCON pdest = dest;
	while(*str)
	{
		*dest++ = *str++;
	}
	*dest = '\0';
	return pdest;
}

#endif