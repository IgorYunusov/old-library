/*************************************************************************
 *
 * FILE NAME : aghead.c - Auto Generator
 *
 * ROLLRAT SOFTWARE RUNTIME COMPILER(RTC)
 *
 *
 * LANGUAGE : Macro Assembly, C++
 * VERSION  : Microsoft Macro Assembler v12.00.30501.0
 *            ISO/C++ 11-Microsoft C/C++ Optimizer Compiler 18.00.0501
 * CREATION : 2014.11.6
 * MADEBY   : Jeong HyunJun(Nickname : rollrat)
 * E-MAIL   : rollrat@naver.com, rollrat.software@gmail.com
 *
 * (C) Copyright 2014 .rollrat. All Rights Reserved
 *
 **************************************************************************/

#include <Windows.h>
#include <stdio.h>
#include "rasm.h"
#include "aghead.h"

PDEFINE ag_def_init()
{
	PDEFINE def = (PDEFINE) malloc (sizeof(DEFINE));
	def->deftext = 0;
	def->size = 0;
	def->_Next = 0;
	def->serial = 0;
	return def;
}

void ag_def_release(PDEFINE pd)
{
	for (; pd; pd = pd->_Next) {
		free(pd->deftext);
		free(pd->serial);
	}
}

BOOL ag_excuate_filedata(const char *src, const char *dst)
{
	FILE *fsrc, *fdst;
	char temp[256];
	const char *ptr;
	BOOL ans = 0, is_loop = FALSE;
	errno_t err;
	PDEFINE def = ag_def_init(), defp, last;
	int loop_count_s, loop_count_e;

	last = def;

	if ((err = fopen_s(&fsrc, src, "r")) != NULL)
		return FALSE;
	if ((err = fopen_s(&fdst, dst, "w")) != NULL) {
		fclose(fsrc);
		return FALSE;
	}

	//////////////////////////////////////////////////////

	while(fgets(temp, sizeof(temp), fsrc)){
		ptr = temp;
		while _isspace(*ptr)
			ptr++;
		switch(*ptr)
		{
		case '#':
			break;
		case ';':
			{
				char s[256] = { '/', '/' };
				int i = 2;
				ptr++;
				while _isnzero(*ptr)
					s[i++] = *ptr++;
				s[--i] = '\n';
				fputs(s, fdst);
			}
			break;
		case '$':		// variable excuate without define: ex) $add reg, imm8 [256]
			{
				char s[256] = { '{', '\"' };
				int i = 2;
				ptr++;
				while _isspace(*ptr)
					ptr++;
				while _isnspace(*ptr)
					s[i++] = *ptr++;
				s[i++] = '\"';
				s[i++] = ',';
				while _isspace(*ptr)
					ptr++;
				while _isnspace(*ptr)
					s[i++] = toupper(*ptr++);
				s[i++] = ',';
				while _isspace(*ptr)
					ptr++;
				while _isnspace(*ptr)
					s[i++] = toupper(*ptr++);
				s[i++] = ',';
				while _isspace(*ptr)
					ptr++;
				ptr++;
				while _and(_isnspace(*ptr), _isnzero(*ptr))
					s[i++] = toupper(*ptr++);
				s[--i] = '}';
				s[++i] = '\n';
				fputs(s, fdst);
			}
			break;
		case '@': // define c macro, ex) @[serial]%s first %d last
			{
				PDEFINE temp = ag_def_init();
				char *t = (char *) malloc (sizeof(char) * 32);
				char *s = (char *) malloc (sizeof(char) * 256);
				int i_t = 0, i_s = 0;
				ptr++;
				while _isspace(*ptr)
					ptr++;
				if (*ptr == '[')
					ptr++;
				while (*ptr != ']')
					t[i_t++] = *ptr++;
				t[i_t] = 0;
				temp->serial = t;
				ptr++;
				while _isnzero(*ptr)
					s[i_s++] = *ptr++;
				s[i_s] = 0;
				temp->deftext = s;
				last->_Next = temp;
				last = last->_Next;
			}
			break;
		case '[': // [serial]s, 256, serial
			{
				char *t = (char *) malloc (sizeof(char) * 32);
				char *s = (char *) malloc (sizeof(char) * 256);
				const char *_ptr;
				PSPRINTF _VAL = ag_sprintf_init(), last = _VAL;
				int i_t = 0, i_s = 0;
				ptr++;
				if (*ptr == '[')
					ptr++;
				while (*ptr != ']')
					t[i_t++] = *ptr++;
				t[i_t] = 0;
				ptr++;
				for (defp = def->_Next; defp != 0; defp = defp->_Next)
					if (!strcmp(t, defp->serial))
						_ptr = defp->deftext;
				while (*ptr != '\0')
					{
						PSPRINTF ps = ag_sprintf_init();
						char *ts = (char *) malloc (sizeof(char) * 256);
						int i_s = 0;
						while (!(*ptr == ',' && *(ptr-1) != '\\') && *ptr && *ptr != '\n')
							if(*ptr != '\\')
								ts[i_s++] = *ptr++;
							else
								ptr++;
						if(*ptr != '\0')
							ptr++;
						ts[i_s] = 0;
						ps->data = ts;
						last->_Next = ps;
						last = last->_Next;
					}
				zeroset(s, 256);
				agsprintf(s, _ptr, _VAL);
				fputs(s, fdst);
				ag_sprintf_release(_VAL);
			}
			break;
		case '(':
			{
				char num[8];
				int num_c = 0;
				ptr++;
				is_loop = TRUE;
			RE:	while (*ptr != '-' && *ptr)
					num[num_c++] = *ptr;
				num[num_c] = 0;
				num_c = 0;
				if (*ptr == '-')
				{
					loop_count_s = atoi(num);
					goto RE;
				}
				else
					loop_count_e = atoi(num);
			}
			break;
		}
	}

	//////////////////////////////////////////////////////
EXIT:
	ag_def_release(def);
	fclose(fdst);
	fclose(fsrc);

	return ans;
}