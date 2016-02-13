/*******************************************************************\
 *ranal.h -- rollrat syntax analysis library.					   *
 *																   *
 *Purpose :														   *
 *		This library was created to parse the [RollRatParser].	   *
 *		Duty and for other purposes, if you want, you need to	   *
 *		modify the library in some you can.						   *
 *																   *
 *Dealing :														   *
 *		C++ Language, RollRatParser								   *
 *																   *
 *Available :													   *
 *		CompilerParser, Syntax analyzer							   *
 *																   *
 *			Copyright (c) rollrat. All rights reserved.			   *
 *																   *
\*******************************************************************/

#pragma once
#ifndef _ROLLRAT_ANAL_
#define _ROLLRAT_ANAL_

#include <conio.h>
#include <string.h>

#if !defined(_UNICODE) || !defined(UNICODE)
#define Uni char;
#define CLO (char*)
#else
#define Uni unsigned char
#define CLO (unsigned char*)
#endif

#define ERR_SendOut 0x80076FF // the send buffer is overlapping in processing.

namespace rts
{
	namespace String
	{
		// Analyzer Tools
		#define CCTextTEMP template<class LEF>
		CCTextTEMP class CCTextR
		{
		public: // Entry Value
			CCTextR(LEF*);
			CCTextR(LEF*, LEF*);

		public: // basically Value
			int GetLenthFromStr() const;
			LEF* GetStr() const;
	
		public: // Static Value
			static void Release(LEF*);
	
		private: // Private Value
			int e_Lenth;
			LEF* e_str;
	
		public: // Tools
			int IsCompare(LEF* str_1, LEF* str_2);
			int IsEqual(LEF* str_1, LEF* str_2);
			int GetLenth(LEF* str);
			int IsLenthByOp(LEF* str, char op);
			LEF* Strstr(LEF* str_1, LEF* str_2);
			LEF* Strtok(LEF* strToken, const LEF* strDelimit);
			LEF* GetStrFromPos(LEF* str, int pos_x, int pos_y);
			LEF* Split(const LEF* rCharText, const char fSplit, int Arrange);
			LEF* Split(const LEF* str_1, const LEF* Split, int Arrange);
			LEF* CopyStr(LEF* str_1, const LEF* str_2);
			LEF* CopyStr(LEF* str_1, const LEF* str_2, int count);
			LEF* Replace(LEF* str, LEF* Target, LEF* Changes);
			LEF* ReplaceAll(LEF* str, LEF* Target, LEF* Changes);
			LEF* ReplaceAll(LEF* str, LEF* Target, LEF* Changes, int Value);
			LEF* RTrim(LEF* str);
			LEF* LTrim(LEF* str);
			LEF* Trim(LEF* str);
			int IsSpace(int c_ch);
			int FirstPosCH(LEF* str, char fpch);
			LEF* BackStr(LEF* str, const char ch);
			LEF* ForwardStr(LEF* str, const char ch);
			char BackCH(LEF* str, const char ch);
			char ForwardCH(LEF* str, const char ch);
			int CountCH(LEF* str, const char ch);
			LEF* MidStr(LEF* str, const char ch_1, const char ch_2);
			int MidLenth(LEF* str, const char ch_1, const char ch_2);
		};
		CCTextTEMP CCTextR<LEF>::CCTextR(LEF* str)
		{
			int i = 0;
			e_str = str;
			while( str[i] ) { i++; }
			e_Lenth = i;
		}
		CCTextTEMP CCTextR<LEF>::CCTextR(LEF* str, LEF* lenth)
		{
			e_str = str;
			e_Lenth = lenth;
		}
		CCTextTEMP int CCTextR<LEF>::GetLenthFromStr() const
		{
			return e_Lenth;
		}
		CCTextTEMP LEF* CCTextR<LEF>::GetStr() const
		{
			return e_str;
		}
		CCTextTEMP inline void CCTextR<LEF>::Release(LEF* re_str)
		{
			if(re_str != 0) delete [] re_str;
		}
		CCTextTEMP int CCTextR<LEF>::IsCompare(LEF* str_1, LEF* str_2)
		{
			if(str_1 == str_2)
				return 1;
			else
				return 0;
		}
		CCTextTEMP int CCTextR<LEF>::IsEqual(LEF* str_1, LEF* str_2)
		{
			int i = 0;
			while(str_1[i])
			{
				if (str_1[i] != str_2[i])
					return 0;
				i++;
			}
			return 1;
		}
		CCTextTEMP int CCTextR<LEF>::GetLenth(LEF* str)
		{
			int i = 0;
			while( str[i] ) { i++; }
			return i;
		}
		CCTextTEMP int CCTextR<LEF>::IsLenthByOp(LEF* str, char op)
		{
			int i = 0, f = 0;
			while( str[f] )
			{
				if ( str[f] == op )
					i++;
				f++;
			}
			return i;
		}
		CCTextTEMP LEF* CCTextR<LEF>::Split(const LEF* rCharText, const char fSplit, int Arrange)
		{
			int i=0, f=0, Split=0;
			char Buf[10][1000];
			while(rCharText[f])
			{
				if(rCharText[f] == fSplit)
				{
					Buf[Split][++i] = 0;
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
				Buf[Split][++i] = 0;
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
		}
		CCTextTEMP LEF* CCTextR<LEF>::Split(const LEF* str_1, const LEF* Split, int Arrange)
		{
			static char * Buf;
			Buf = new char[4096];
			char * token = 0;
			int i = 0;
			token = Strtok(str_1, Split);
			if(!Arrange)
				return token;
			if(token)
				while(token = Strtok(0, Split))
				{
					if (i++ == Arrange - 1)
						return token;
				}
			return 0;
		}
		CCTextTEMP LEF* CCTextR<LEF>::Strstr(LEF* str_1, LEF* str_2)
		{// http://www.jbox.dk/sanos/source/lib/string.c.html
			LEF* cp = (LEF) str_1;
			LEF* s1, s2;
			if (!*str_2) 
				return (LEF) str_1;
			while (*cp)
			{
				s1 = cp;
				s2 = (LEF) str_2;
				while (*s1 && *s2 && !(*s1 - *s2)) s1++, s2++;
				if (!*s2) return cp;
				cp++;
			}
			return 0;
		}
		CCTextTEMP LEF* CCTextR<LEF>::Strtok(LEF* strToken, const LEF* strDelimit)
		{// MS-SRC ( whitout _TOKEN )
			char *str;
			const char *ctrl = strDelimit;
			unsigned char map[32];
			int count;
			for (count = 0; count < 32; count++)map[count] = 0;
			do {map[*ctrl >> 3] |= (1 << (*ctrl & 7));} while (*ctrl++);
			if (strToken)str = strToken;
			while ( (map[*str >> 3] & (1 << (*str & 7))) && *str )str++;
			strToken = str;
			for ( ; *str ; str++ )
			        if ( map[*str >> 3] & (1 << (*str & 7)) ) {
			                *str++ = 0;break;}
			if ( strToken == str )return 0;
			else return strToken;
		}
		CCTextTEMP LEF* CCTextR<LEF>::GetStrFromPos(LEF* str, int pos_x, int pos_y)
		{
			LEF* * buf = new LEF[pos_y - pos_x + 2];
			int i = 0, f = 0;
			while( str[i] )
			{
				if (pos_x <= i <= pos_y)
				{
					buf[f++] = str[i];
				}
				i++;
			}
			buf[f] = '\0';
			return buf;
		}
		CCTextTEMP LEF* CCTextR<LEF>::CopyStr(LEF* str_1, const LEF* str_2)
		{
			int i = 0;
			while (str_2[i] != 0)
			{
				str_1[i] = str_2[i];
				i++;
			}
			str_1[i] = 0;
			return &str_1[0];
		}
		CCTextTEMP LEF* CCTextR<LEF>::CopyStr(LEF* str_1, const LEF* str_2, int count)
		{
			int i = 0;
			while (str_2[i] != 0 && i < count)
			{
				str_1[i] = str_2[i++];
			}
			while(i < count)
			{
				str_1[i++] = 0;
			}
			return &str_1[0];
		}
		CCTextTEMP LEF* CCTextR<LEF>::Replace(LEF* str, LEF* Target, LEF* Changes)
		{
			static char * buffer;
			buffer = new char[4096];
			LEF* ch = "";
			if (!(ch = Strstr(str, Target)))
				return str;
			CopyStr(buffer, str, ch-str);  
			buffer[ch-str] = 0;
			sprintf(buffer + (ch-str), "%s%s", Changes, ch + strlen(Target));
			return buffer;
		}
		CCTextTEMP LEF* CCTextR<LEF>::ReplaceAll(LEF* str, LEF* Target, LEF* Changes)
		{
			static char * returns;
			static char * buffer[1];
			int f=0xFFFF;
			returns = new char[4096];
			buffer[0] = new char[4096];
			buffer[1] = new char[4096];
			while(f)
			{
				CopyStr(returns, buffer[0]);
				if (f == 0xFFFF)
					buffer[0] = Replace(str, Target, Changes);
				else
					buffer[0] = Replace(buffer[0], Target, Changes);
				
				if(IsEqual(buffer[0], returns))
				{
					return returns;
				}
				f--;
			}
			CopyStr(returns, buffer[0]);
			return returns;
		}
		CCTextTEMP LEF* CCTextR<LEF>::ReplaceAll(LEF* str, LEF* Target, LEF* Changes, int Value)
		{
			static char * returns;
			static char * buffer[1];
			int f=Value;
			returns = new char[4096];
			buffer[0] = new char[4096];
			buffer[1] = new char[4096];
			while(f)
			{
				CopyStr(returns, buffer[0]);
				if (f == Value)
					buffer[0] = Replace(str, Target, Changes);
				else
					buffer[0] = Replace(buffer[0], Target, Changes);

				f--;
			}
			CopyStr(returns, buffer[0]);
			return returns;
		}
		CCTextTEMP int CCTextR<LEF>::FirstPosCH(LEF* str, char fpch)
		{
			int i = 0;
			while( str[i] )
			{
				if (str[i] == fpch)
					return i;
			}
			return 0;
		}
		CCTextTEMP LEF* CCTextR<LEF>::RTrim(LEF* str)
		{
			char t[4096];
			LEF* end;
			CopyStr(t, str);
			end = t + GetLenth(t) - 1;
			while (end != t && IsSpace(*end))
				end--;
			*(end + 1) = 0;
			str = t;
			return str;
		}
		CCTextTEMP LEF* CCTextR<LEF>::LTrim(LEF* str)
		{
			char* begin;
			begin = str;
			while (*begin != 0) {
			  if (IsSpace(*begin))
				  begin++;
			  else {
			    str = begin;
			    break;
			  }
			}
			return str;
		}
		CCTextTEMP LEF* CCTextR<LEF>::Trim(LEF* str)
		{
			return RTrim(LTrim(str));
		}
		CCTextTEMP int CCTextR<LEF>::IsSpace(int c_ch)
		{
			switch(c_ch)
			{
			case '\n':
			case '\v':
			case '\f':
			case '\t':
			case '\r':
			case  ' ':
				return 1;
			}
			return 0;
		}
		CCTextTEMP LEF* CCTextR<LEF>::BackStr(LEF* str, const char ch)
		{
			int i = 0;
			LEF * buf = new LEF[GetLenth(str)];
			i = GetLenth(str);
			while(i)
				buf[i--] = '\0';
			i = 0;
			while(str[i])
			{
				if(str[i] == ch)
					return buf;
				buf[i] = str[i];
				i++;
			}
			return buf;
		}
		CCTextTEMP LEF* CCTextR<LEF>::ForwardStr(LEF* str, const char ch)
		{
			int i = 0, f = 0, comp = 0;
			LEF * buf = new LEF[GetLenth(str)];
			i = GetLenth(str);
			while(i)
				buf[i--] = '\0';
			i = 0;
			while(str[i])
			{
				if(str[i] == ch && comp != 1)
				{
					i++;
					comp = 1;
					continue;
				}
				if(comp == 1)
				{
					buf[f++] = str[i];
				}
				i++;
			}
			return buf;
		}
		CCTextTEMP char CCTextR<LEF>::BackCH(LEF* str, const char ch)
		{
			int i = 0;
			static char buf;
			buf = 0;
			while(str[i])
			{
				if (str[i] == ch)
					break;
				buf = str[i];
				i++;
			}
			return buf;
		}
		CCTextTEMP char CCTextR<LEF>::ForwardCH(LEF* str, const char ch)
		{
			int i = 0;
			while(str[i])
			{
				if( str[i] == ch )
					return str[++i];
				i++;
			}
			return 0;
		}
		CCTextTEMP int CCTextR<LEF>::CountCH(LEF* str, const char ch)
		{
			int i = 0, f = 0;
			while(str[i++])
				if(str[i] == ch)
					f++;
			return f;
		}
		CCTextTEMP LEF* CCTextR<LEF>::MidStr(LEF* str, const char ch_1, const char ch_2)
		{
			return BackStr(ForwardStr(str, ch_1), ch_2);
		}
		CCTextTEMP int CCTextR<LEF>::MidLenth(LEF* str, const char ch_1, const char ch_2)
		{
			return GetLenth(MidStr(str, ch_1, ch_2));
		}
	}
	namespace Analyzer
	{
		using namespace String;
		#define CCAnalyzerT template<class ALZ, class LEF>
		#define CCAnalyzerF template<class ALZ>
		#define CCTextTEMP	template<class LEF>
		#undef RCHAR
		#pragma push_macro( "RCHAR" )
		#define RCHAR( _ch ) (ALZ*)(_ch)
		CCAnalyzerF class CCMatch
		{
		public:
			CCMatch(const ALZ *);
			
		public:
			void SetText(ALZ*);
			ALZ * Match();
			void NextMatch();
			int IsMatch();

		public:
			ALZ * WhatMatch(const char rchar, ALZ * pattern);

		private:
			ALZ * pattern;
			ALZ * pattern_buf;
			int patternLen;
			ALZ * Text;
			int TextLen;

		private:
			int bufmon_c;
			ALZ * bufmon;

		private:
			int MatchCount;

		};
		CCAnalyzerF CCMatch<ALZ>::CCMatch(const ALZ * patterns)
		{
			CCTextR<ALZ> S(RCHAR(patterns));
			pattern = RCHAR(patterns);
			patternLen = S.GetLenth(RCHAR(patterns));
		}
		CCAnalyzerF void CCMatch<ALZ>::SetText(ALZ * str)
		{
			CCTextR<ALZ> S((ALZ*)str);
			TextLen = S.GetLenth((ALZ*)str);
			Text = str;
		}
		CCAnalyzerF int CCMatch<ALZ>::IsMatch()
		{
			if (MatchCount)
				return 0;
			return 1;
		}
		CCAnalyzerF ALZ * CCMatch<ALZ>::Match()
		{
			int i = 0;
			CCTextR<ALZ> Ref(CLO"");
			bufmon = new ALZ[4096];
			bufmon_c = 0;
			ZeroMemory(bufmon, sizeof(bufmon));
			while( pattern[i] )
			{
				switch(pattern[i])
				{
				case RCHAR('['):
					bufmon = WhatMatch(pattern[i], Ref.MidStr(pattern, '[', ']'));
					break;
				case RCHAR('('):
					bufmon = WhatMatch(pattern[i], Ref.MidStr(pattern, '(', ')'));
					break;
				default:
					break;
				}
				i++;
			}
			return bufmon;
		}
		CCAnalyzerF void CCMatch<ALZ>::NextMatch()
		{

		}
		CCAnalyzerF ALZ * CCMatch<ALZ>::WhatMatch(const char rchar, ALZ * pattern)
		{
			CCTextR<ALZ> Ref(CLO"");
			switch(rchar)
			{
			case RCHAR('['):
				int c_chr_indexbuf = 
					Ref.GetLenth(pattern);
				int c_chr_minuxbuf =
					Ref.CountCH(pattern, '-');
				int c_chr_overlap =
					Ref.CountCH(pattern, '[');
				if (c_chr_overlap > 0)
					return CLO ERR_SendOut;

				int whi_for_i = 0;
				int whi_for_f_chartbuffer = 0;

				if (c_chr_minuxbuf == 0)
				{
					while(whi_for_i <= c_chr_indexbuf)
					{
						while(whi_for_f_chartbuffer <= TextLen)
						{
							if(pattern[whi_for_i] == Text[whi_for_f_chartbuffer])
							{
								bufmon[bufmon_c++] = Text[whi_for_f_chartbuffer];
							}
							whi_for_f_chartbuffer++;
						}
						whi_for_i++;
						whi_for_f_chartbuffer = 0;
					}
					break;
				}
			}
			return this->bufmon;
		}
		#undef RCHAR
		#pragma pop_macro("RCHAR")
	}
}

#if !defined(_UNICODE) || !defined(UNICODE)
typedef rts::Analyzer::CCMatch<char> Matcher;
typedef rts::String::CCTextR<char>	String;
#else
typedef rts::Analyzer::CCMatch<Uni> Matcher;
typedef rts::String::CCTextR<Uni>	StringT;
#endif

#endif