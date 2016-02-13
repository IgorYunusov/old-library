/*******************************************************************\
 *																   *
 *				RString.hpp -- rollrat String.					   *
 *																   *
 *																   *
 *			Copyright (c) rollrat. All rights reserved.			   *
 *																   *
\*******************************************************************/

/***********************************************************

		 _____    __  __   ______           __
		/  __ |___\ \ \ \ /  __  | __   _ __\ \__
		| |_| | _ \ | | | | |__| |/  \_| |/___  _/
		|  __/ (_)| | | | |  _  / |(_)  |   | |
		| |  \ ___/ |_| |_| | \ \ \____/    | |
		\_/ \_\    \__\\__\_/  \_\          \_\

		RollRatSoftware-PrivateProgrammingLab

	Copyright (c) rollrat. 2009-2013 All rights reserved.


************************************************************/

#pragma once
#ifndef _ROLLRAT_STR_
#define _ROLLRAT_STR_

#include <string.h>
#include "RTypes.h"
#include <stdio.h>

inline int IsSpace(int c_ch)
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

/****************************************
 * RChar class							*
 ***************************************/
class RChar
{
public:

	/* Input Output */
	RChar();
    RChar( char c );
    RChar( short rc );
    RChar( int rc );
    RChar( uchar c );
    RChar( ushort rc );
    RChar( uint rc );
    RChar( const RChar& c );
	RChar( uchar c, uchar ch );
	RChar( char c, char ch );
	RChar( const RChar& c, const RChar& ch );

	/* Return */
	uchar Get() const { return RCHAR(bup); };

	/* Operator Overlaps */
	friend inline bool operator==( char ch, RChar c );
	friend inline bool operator==( RChar c, char ch );
	friend inline bool operator==( RChar c, RChar ch );
	friend inline bool operator!=( char c, RChar ch );
	friend inline bool operator!=( RChar c, char ch );
	friend inline bool operator!=( RChar c, RChar ch );
	friend inline bool operator>=( char c, RChar ch );
	friend inline bool operator>=( RChar c, char ch );
	friend inline bool operator>=( RChar c, RChar ch );
	friend inline bool operator<=( char c, RChar ch );
	friend inline bool operator<=( RChar c, char ch );
	friend inline bool operator<=( RChar c, RChar ch );
	friend inline bool operator>( char c, RChar ch );
	friend inline bool operator>( RChar c, char ch );
	friend inline bool operator>( RChar c, RChar ch );
	friend inline bool operator<( char c, RChar ch );
	friend inline bool operator<( RChar c, char ch );
	friend inline bool operator<( RChar c, RChar ch );
	friend inline RChar operator>>( RChar ch, int sh_b );
	friend inline RChar operator<<( RChar ch, int sh_b );

	/* Functions */
	bool IsNull() const;
	bool IsSpace() const;
	bool IsEnglish() const;
	bool IsNumberic() const;

private:
	uchar bup;
};

inline RChar::RChar(){ bup = 0; }
inline RChar::RChar( char c ){ bup = RCHAR(c); }
inline RChar::RChar( short c ){ bup = RCHAR(c); }
inline RChar::RChar( int c ){ bup = RCHAR(c); }
inline RChar::RChar( uchar c ){ bup = RCHAR(c); }
inline RChar::RChar( ushort c ){ bup = LGet(c); }
inline RChar::RChar( uint c ){ bup = LGet(c); }
inline RChar::RChar( const RChar& c ){ bup = RCHAR(c.bup); }
inline RChar::RChar( uchar c, uchar ch ){ bup = UCow( c,ch ); }
inline RChar::RChar( char c, char ch ){ bup = LCow( c,ch ); }
inline RChar::RChar( const RChar& c, const RChar& ch ){ bup = UCow( c.bup, ch.bup ); }

inline bool operator==( char ch, RChar c ){ return RCHAR(ch) == c.bup; }
inline bool operator==( RChar c, char ch ){ return RCHAR(ch) == c.bup; }
inline bool operator==( RChar c, RChar ch ){ return ch.bup == c.bup; }
inline bool operator!=( char ch, RChar c ){ return RCHAR(ch) != c.bup; }
inline bool operator!=( RChar c, char ch ){ return RCHAR(ch) != c.bup; }
inline bool operator!=( RChar c, RChar ch ){ return ch.bup != c.bup; }
inline bool operator>=( char ch, RChar c ){ return RCHAR(ch) >= c.bup; }
inline bool operator>=( RChar c, char ch ){ return RCHAR(ch) <= c.bup; }
inline bool operator>=( RChar c, RChar ch ){ return ch.bup <= c.bup; }
inline bool operator<=( char ch, RChar c ){ return RCHAR(ch) <= c.bup; }
inline bool operator<=( RChar c, char ch ){ return RCHAR(ch) >= c.bup; }
inline bool operator<=( RChar c, RChar ch ){ return ch.bup >= c.bup; }
inline bool operator>( char ch, RChar c ){ return !(RCHAR(ch) >= c.bup); }
inline bool operator>( RChar c, char ch ){ return !(RCHAR(ch) <= c.bup); }
inline bool operator>( RChar c, RChar ch ){ return !(ch.bup <= c.bup); }
inline bool operator<( char ch, RChar c ){ return !(RCHAR(ch) <= c.bup); }
inline bool operator<( RChar c, char ch ){ return !(RCHAR(ch) >= c.bup); }
inline bool operator<( RChar c, RChar ch ){ return !(ch.bup >= c.bup); }
inline RChar operator>>( RChar ch, int sh_b ){ return ch.bup >> sh_b; }
inline RChar operator<<( RChar ch, int sh_b ){ return ch.bup << sh_b; }

inline bool RChar::IsNull() const { return bup == 0x0; }
inline bool RChar::IsSpace() const { switch(bup){case '\n':case '\v':case '\f':case '\t':case '\r':case  ' ':return 1;}return 0;}
inline bool RChar::IsEnglish() const { return 'a' <= bup <= 'z' || 'A' <= bup <= 'Z';}
inline bool RChar::IsNumberic() const { return '0' <= bup <= '9'; }

/****************************************
 * RString Class						*
 ***************************************/
class RString
{
public:

	/* Input Output */
	explicit RString();
    RString( char* c );
    RString( RChar* rc );
	RString( const RString& rc );

	/* Return */
	RChar* Get() const { return buffer; };

	/* Operator Overlaps */
	friend inline bool operator==( char * ch, RString c );
	friend inline bool operator==( RString ch, char * c );
	friend inline bool operator==( RString ch, RString c );
	friend inline bool operator!=( char * ch, RString c );
	friend inline bool operator!=( RString ch, char * c );
	friend inline bool operator!=( RString ch, RString c );
	friend inline bool operator<=( char * ch, RString c ); 
	friend inline bool operator<=( RString ch, char * c );
	friend inline bool operator<=( RString ch, RString c );
	friend inline bool operator>=( char * ch, RString c );
	friend inline bool operator>=( RString ch, char * c );
	friend inline bool operator>=( RString ch, RString c );
	friend inline bool operator<( char * ch, RString c );
	friend inline bool operator<( RString ch, char * c );
	friend inline bool operator<( RString ch, RString c );
	friend inline bool operator>( char * ch, RString c );
	friend inline bool operator>( RString ch, char * c );
	friend inline bool operator>( RString ch, RString c );

	/* Tools */
	int Length();
	RString ReplaceO(RChar* str, RChar* Target);
	RString ReplaceO(RString str, RString Target);
	RString ReplaceO(char * str, char * Target);
	RString ReplaceO(char * str_1, char * str, char * Target);
	RString Replace(RChar* str, RChar* Target);
	RString Replace(RString str, RString Target);
	RString Replace(char * str, char * Target);

	RString Trim();
	RString RTrim();
	RString LTrim();
	RString Split(RChar* str, int Arrange);
	RString Split(char* str, int Arrange);

private:
	RChar* buffer;
};

inline RString::RString(){ buffer = 0; }
inline RString::RString( char* c ){ buffer = RCUST(RChar*, c); }
inline RString::RString( RChar* rc ){ buffer = rc; }
inline RString::RString( const RString& rc ){ buffer = rc.buffer; }

inline bool operator==( char * ch, RString c ){ return RCUST(RChar*, ch) == c.buffer; }
inline bool operator==( RString c, char * ch ){ return RCUST(RChar*, ch) == c.buffer; }
inline bool operator==( RString c, RString ch ){ return ch.buffer == c.buffer; }
inline bool operator!=( char * ch, RString c ){ return RCUST(RChar*, ch) != c.buffer; }
inline bool operator!=( RString c, char * ch ){ return RCUST(RChar*, ch) != c.buffer; }
inline bool operator!=( RString c, RString ch ){ return ch.buffer != c.buffer; }
inline bool operator<=( char * ch, RString c ){ return strlen(ch) <= strlen((char*)c.buffer); }
inline bool operator<=( RString c, char * ch ){ return strlen((char*)c.buffer) <= strlen(ch); }
inline bool operator<=( RString c, RString ch ){ return strlen((char*)c.buffer) <= strlen((char*)ch.buffer); }
inline bool operator>=( char * ch, RString c ){ return strlen(ch) >= strlen((char*)c.buffer); }
inline bool operator>=( RString c, char * ch ){ return strlen((char*)c.buffer) >= strlen(ch); }
inline bool operator>=( RString c, RString ch ){ return strlen((char*)c.buffer) >= strlen((char*)ch.buffer); }
inline bool operator<( char * ch, RString c ){ return !(strlen(ch) <= strlen((char*)c.buffer)); }
inline bool operator<( RString c, char * ch ){ return !(strlen((char*)c.buffer) <= strlen(ch)); }
inline bool operator<( RString c, RString ch ){ return !(strlen((char*)c.buffer) <= strlen((char*)ch.buffer)); }
inline bool operator>( char * ch, RString c ){ return !(strlen(ch) >= strlen((char*)c.buffer)); }
inline bool operator>( RString c, char * ch ){ return !(strlen((char*)c.buffer) >= strlen(ch)); }
inline bool operator>( RString c, RString ch ){ return !(strlen((char*)c.buffer) >= strlen((char*)ch.buffer)); }

int RString::Length()
{
	return strlen((char*)buffer);
}
RString RString::ReplaceO(RChar* str, RChar* Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr((char*)buffer, (char*)str)))
		return (RString)buffer;
	strncpy(buffers, (char*)buffer, ch-(char*)buffer);  
	buffers[ch-(char*)buffer] = 0;
	sprintf(buffers + (ch-(char*)buffer), "%s%s", Target, ch + strlen((char*)str));
	return (RString)buffers;
}
RString RString::ReplaceO(RString str, RString Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr((char*)buffer, (char*)str.buffer)))
		return (RString)buffer;
	strncpy(buffers, (char*)buffer, ch-(char*)buffer);  
	buffers[ch-(char*)buffer] = 0;
	sprintf(buffers + (ch-(char*)buffer), "%s%s", (char*)Target.buffer, ch + strlen((char*)str.buffer));
	return (RString)buffers;
}
RString RString::ReplaceO(char * str, char * Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr((char*)buffer, str)))
		return (RString)buffer;
	strncpy(buffers, (char*)buffer, ch-(char*)buffer);  
	buffers[ch-(char*)buffer] = 0;
	sprintf(buffers + (ch-(char*)buffer), "%s%s", Target, ch + strlen(str));
	return (RString)buffers;
}
RString RString::ReplaceO(char * str_1, char * str, char * Target)
{
	static char * buffers;
	buffers = new char[4096];
	char* ch = "";
	if (!(ch = strstr(str_1, str)))
		return (RString)buffer;
	strncpy(buffers, str_1, ch-str_1);  
	buffers[ch-str_1] = 0;
	sprintf(buffers + (ch-str_1), "%s%s", Target, ch + strlen(str));
	return (RString)buffers;
}
RString RString::Replace(RChar* str, RChar* Target)
{
	static char * returns;
	static char * buffers[1];
	int f=0xFFFF;
	returns = new char[4096];
	buffers[0] = new char[4096];
	buffers[1] = new char[4096];
	while(f)
	{
		strcpy(returns, buffers[0]);
		if (f == 0xFFFF)
			buffers[0] = (char*)ReplaceO((char*)buffer, (char*)str, (char*)Target).buffer;
		else
			buffers[0] = (char*)ReplaceO(buffers[0], (char*)str, (char*)Target).buffer;
		
		if(buffers[0] == returns)
		{
			return (RString)returns;
		}
		f--;
	}
	strcpy(returns, buffers[0]);
	return (RString)returns;
}
RString RString::Replace(RString str, RString Target)
{
	static char * returns;
	static char * buffers[1];
	int f=0xFFFF;
	returns = new char[4096];
	buffers[0] = new char[4096];
	buffers[1] = new char[4096];
	while(f)
	{
		strcpy(returns, buffers[0]);
		if (f == 0xFFFF)
			buffers[0] = (char*)ReplaceO((char*)buffer, (char*)str.buffer, (char*)Target.buffer).buffer;
		else
			buffers[0] = (char*)ReplaceO(buffers[0], (char*)str.buffer, (char*)Target.buffer).buffer;
		
		if(buffers[0] == returns)
		{
			return (RString)returns;
		}
		f--;
	}
	strcpy(returns, buffers[0]);
	return (RString)returns;
}
RString RString::Replace(char * str, char * Target)
{
	static char * returns;
	static char * buffers[1];
	int f=0xFFFF;
	returns = new char[4096];
	buffers[0] = new char[4096];
	buffers[1] = new char[4096];
	while(f)
	{
		strcpy(returns, buffers[0]);
		if (f == 0xFFFF)
			buffers[0] = (char*)ReplaceO((char*)buffer, (char*)str, (char*)Target).buffer;
		else
			buffers[0] = (char*)ReplaceO(buffers[0], (char*)str, (char*)Target).buffer;
		
		if(buffers[0] == returns)
		{
			return (RString)returns;
		}
		f--;
	}
	strcpy(returns, buffers[0]);
	return (RString)returns;
}
RString RString::Trim()
{
	RTrim();
	return LTrim();
}
RString RString::RTrim()
{
	char t[4096];
	char* end;
	strcpy(t, (char*)buffer);
	end = t + strlen(t) - 1;
	while (end != t && IsSpace(*end))
		end--;
	*(end + 1) = 0;
	buffer = (RChar*)t;
	return buffer;
}
RString RString::LTrim()
{
	char* begin;
	begin = (char*)buffer;
	while (*begin != 0) {
		if (IsSpace(*begin))
			begin++;
		else {
			buffer = (RChar*)begin;
			break;
		}
	}
	return buffer;
}
RString RString::Split(RChar* str, int Arrange)
{
	char *tokens = new char[4096];
	int i = 0;
	strcpy(tokens, (char*)buffer);
	tokens = strtok((char*)tokens, (char*)str);
	if(!Arrange) return tokens;
	if(tokens)
		while(tokens = strtok(0, (char*)str))
			if (i++ == Arrange - 1)
				return tokens;
	return ((RString)((RChar*)(0)));
}
RString RString::Split(char * str, int Arrange)
{
	char *tokens = new char[4096];
	int i = 0;
	strcpy(tokens, (char*)buffer);
	tokens = strtok((char*)tokens, str);
	if(!Arrange) return tokens;
	if(tokens)
		while(tokens = strtok(0, (char*)str))
			if (i++ == Arrange - 1)
				return tokens;
	return ((RString)((RChar*)(0)));
}

#endif