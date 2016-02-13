/***********************************************************************

	RollRat Software ARPCLS
	Array Preperation Class

	Copyright (c) rollrat. 2013. All rights reserved.

***********************************************************************/

#pragma once

#ifndef __ARPCLS
#define __ARPCLS

#define ONLY_CPLUSPLUS			// Declared ONLY C++.

#define CHECK_ZERO			0x00
#define CHECK_ALPHABAT		0x01
#define CHECK_BLANK			0x02
#define CHECK_NUMBERIC		0x03
#define CMP_ALL				0x04
#define CMP_SCOPE			0x05		//ex \\x05:[00]>[10];;;
#define CMP_SPLIT			0x06		//ex \\x06:[02];;;
#define MPALINECCS_JUMP		0x08
#define MPENTRYEXC_JUMP		0x09
#define CLEAR_ART			0x0A

__forceinline int softvu(char x, char y)
{							// 대충만든 변환 함수
	int xbs = 0;				// 이 함수가 불안하면 strtol을 사용하십시오.
	if(('0' <= x && x <= '9'))
		xbs = xbs * 16 + (x - '0');
	else if(('a' <= x && x <= 'z'))
		xbs = xbs * 16 + (x - 'W');
	else if(('A' <= x && x <= 'Z'))
		xbs = xbs * 16 + (x - '7');
	if(('0' <= y && y <= '9'))
		xbs = xbs * 16 + (y - '0');
	else if(('a' <= y && y <= 'z'))
		xbs = xbs * 16 + (y - 'W');
	else if(('A' <= y && y <= 'Z'))
		xbs = xbs * 16 + (y - '7');
	return xbs;
}

char * __cdecl strtokc (
	char * string,
	const char * control
	)
{
	char *str;
	const char *ctrl = control;

	unsigned char map[32];
	int count;

	/* Clear control map */
	for (count = 0; count < 32; count++)
		map[count] = 0;

	/* Set bits in delimiter table */
	do {
		map[*ctrl >> 3] |= (1 << (*ctrl & 7));
	} while (*ctrl++);

	/* Initialize str */

	/* If string is NULL, set str to the saved
	* pointer (i.e., continue breaking tokens out of the string
	* from the last strtok call) */
	if (string)
		str = string;

	/* Find beginning of token (skip over leading delimiters). Note that
	* there is no token iff this loop sets str to point to the terminal
	* null (*str == '\0') */
	while ( (map[*str >> 3] & (1 << (*str & 7))) && *str )
		str++;

	string = str;

	/* Find the end of the token. If it is not the end of the string,
	* put a null there. */
	for ( ; *str ; str++ )
		if ( map[*str >> 3] & (1 << (*str & 7)) ) {
			*str++ = '\0';
			break;
		}

		/* Determine if a token has been found. */
		if ( string == str )
			return 0;
		else
			return string;
}

char * ReadCharSplit(char rCharText[],char fSplit[],unsigned int Arrange){
	char * SplitData;
	int i = 0; 
	SplitData = strtokc(rCharText, fSplit);
	while( i != Arrange)
	{
		SplitData = strtokc(0, fSplit);
		i++;
	}
	return SplitData;
}

__forceinline char *split(const char *target, const char *colum, 
						  char **putting, int pos, int for_or_back)
{

}

// _T		:		분석할 문자열
// _A		:		같이 분석할 경우의 문자열
// _uA		:		분석 문자열 
char *ProcessAll(char *_T, char *_A, char *_uA, unsigned int sizeofthat = 256)
{ // process all line
	char *sArt = new char[sizeofthat];
	bool xpos = false, skip = false;
	int sArt_Set = 0, so_buf = 0, _s = 0, _s_T = 0;
	int sArt_size = 0, sizeofa;
	char trues[] = "True", falses[] = "False";
	const char *_t = _T, *_a = _A, *_u = _uA;
	for(char *s = _T; *s != 0; s++)
		sArt_size++;
	for(int i = 0; i < sizeofthat; i++)
		sArt[i] = 0; while(!xpos)	//	*** Must put \\S
	 if(*_u == '\\')
	   switch (*(_u + 1))
		{
		 case 'S':
		  xpos = true;
		  break;
		default: 
			 break;
	   } else _u++;
	//auto db = [&]									// 람다가 작동을 안함. 망할
	//{so_buf ^= so_buf;so_buf += (*(++_u) - '0') 
	//<< 4;so_buf += *(++_u) - '0';return so_buf;};
	while(xpos){
		if(!skip)
		if(*_u == '\\')
			switch(*(++_u))
			{
			case 'x':
				so_buf += (*(++_u) - '0') << 4;
				so_buf += *(++_u) - '0';
				switch(so_buf)
				{
				case CHECK_ZERO:	// No Operate
					break;
				case CHECK_ALPHABAT:
					for(int i = 0; i <= sArt_size; i++)
						if((('a' <= _t[i] && _t[i] <= 'z') || ('A' <= _t[i] 
							&& _t[i] <= 'Z')) && i == (sArt_size - 1)){
							for(int i = sArt_Set; i <= (sArt_Set + 3); i++)
								sArt[i] = trues[i - sArt_Set];
							sArt_Set += 4; break;}
						else if(!(('a' <= _t[i] && _t[i] <= 'z') || ('A' <= _t[i] && _t[i] <= 'Z'))){
							for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
								sArt[i] = falses[i - sArt_Set];
							sArt_Set += 5; break;}
					break;
				case CHECK_BLANK:
					for(int i = 0; i <= sArt_size; i++)
						if(_t[i] == ' ' && i == (sArt_size - 1)){
							for(int i = sArt_Set; i <= (sArt_Set + 3); i++)
								sArt[i] = trues[i - sArt_Set];
							sArt_Set += 4; break;}
						else if(_t[i] != ' '){
							for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
								sArt[i] = falses[i - sArt_Set];
							sArt_Set += 5; break;}
				case CHECK_NUMBERIC:
					for(int i = 0; i <= sArt_size; i++)
						if((('0' <= _t[i] && _t[i] <= '9') && i == (sArt_size - 1))){
							for(int i = sArt_Set; i <= (sArt_Set + 3); i++)
								sArt[i] = trues[i - sArt_Set];
							sArt_Set += 4; break;}
						else if(!('0' <= _t[i] && _t[i] <= '9')){
							for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
								sArt[i] = falses[i - sArt_Set];
							sArt_Set += 5; break;}
					break;
				case MPALINECCS_JUMP:
					if(*(++_u) == ':'){
						if(*(++_u) == '['){
								so_buf ^= so_buf;
								so_buf = softvu(*(_u + 1), *(_u + 2));
								_u += 2;
							for(int i = 0; i < so_buf; i++) _t++;}
						else {for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
								sArt[i] = falses[i - sArt_Set]; sArt_Set += 5;}
						if(*(++_u) != ']')  {for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
								sArt[i] = falses[i - sArt_Set]; sArt_Set += 5;}} 
					else {for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
						sArt[i] = falses[i - sArt_Set]; sArt_Set += 5;}
					break;
				case MPENTRYEXC_JUMP:
					_t = _T;
					break;
				case CMP_ALL:
					for(int i = 0; i <= sArt_size; i++)
						sArt[i + sArt_Set] = _T[i];
					sArt_Set += sArt_size;
					break;
				case CMP_SCOPE:
					int s, tx;
					if(*(++_u) == ':'){
						if(*(++_u) == '['){
								s = softvu(*(_u + 1), *(_u + 2));
								_u += 2; if(*(++_u) == ']'){
								if(*(++_u) == '>'){
									if(*(++_u) == '['){
										so_buf ^= so_buf;
										tx = softvu(*(_u + 1), *(_u + 2));
										_u += 2;
										for(int i = s; i <= sArt_size; i++){
											if(i == tx) break;
											sArt[i + sArt_Set] = _T[i];}
									}else {for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
								sArt[i] = falses[i - sArt_Set]; sArt_Set += 5; break;}}else {
							for(int i = sArt_Set; i <= (sArt_Set + 4); i++)
						sArt[i] = falses[i -sArt_Set]; sArt_Set += 5; break;}}else {
						for(int i = sArt_Set; i <= (sArt_Set + 4); i++)sArt[i] 
						= falses[i - sArt_Set]; sArt_Set += 5; break;}}else {for
						(int i = sArt_Set; i <= (sArt_Set + 4); i++)sArt[i] = falses[
						i - sArt_Set]; sArt_Set += 5; break;}	}else {for(int i = 
					sArt_Set; i <= (sArt_Set + 4); i++) sArt[i] = falses[i - 
					sArt_Set]; sArt_Set += 5; break;}
					break;
				case CMP_SPLIT:		// 기준 문자열은 _A임
					break;
				case CLEAR_ART:
					for(int i = 0; i <= sArt_size; i++)
						sArt[i] = 0;
					sArt_size = 0;
					break;
				default:	// processing error
					break;
				}
				break;
			case 'E':	// End point and break that
				xpos = false;
				break;
			default: 
			 break;
			}
		else
		{
			_u++;
		}
		else
		{
			_s += 1;
			if(_s_T == _s)
			{
				skip = false;
				_s = 0;
				_s_T = 0;
			}
			_u++;
		}
		so_buf = 0;
	}
	return sArt;
}

// CC-BY-NC-ND
// 이 문서에 허락된 행동은 오직 출처를 남기는 배포 뿐입니다. 
#endif