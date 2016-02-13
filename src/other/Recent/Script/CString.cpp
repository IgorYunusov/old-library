/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   CString.cpp

Project:

	RollRat Script Parser - String Class

------
   AUTHOR: HyunJun Jeong  2015-08-13

***************************************************************************/

#include <stdio.h>
#include <assert.h>
#include <type_traits>
#include <algorithm>
#include <ctype.h>
#include <cmath>
#include <stdlib.h>

#include "CString.h"

CString::CString()
	: m_length(0)
	, m_ptr(nullptr)
{
	//std::alignment_of<CString>::value == 4;
}

CString::CString(const char *ptr)
	: m_length(strlen(ptr))
{
	m_ptr = new char[m_length + 1];
	strcpy_s(m_ptr, m_length+1, ptr);
}

CString::CString(const char *ptr, size_t len)
	: m_length(len)
{
	m_ptr = new char[m_length + 1];
	strncpy_s(m_ptr, m_length + 1, ptr, m_length);
}

CString::CString(int num)
{
	char buffer[65];
	_itoa_s(num, buffer, 10);
	InitializationString((const char *)buffer);
}

CString::CString(long int num)
{
	char buffer[65];
	_ltoa_s(num, buffer, 10);
	InitializationString((const char *)buffer);
}

CString::CString(long long int num)
{
	char buffer[65];
	sprintf_s(buffer, "%lld", num, 65);
	InitializationString((const char *)buffer);
}

CString::CString(unsigned int num)
{
	char buffer[65];
	sprintf_s(buffer, "%u", num, 65);
	InitializationString((const char *)buffer);
}

CString::CString(unsigned long long int num)
{
	char buffer[65];
	sprintf_s(buffer, "%llu", num, 65);
	InitializationString((const char *)buffer);
}

CString::CString(float num)
{
	char buffer[65];
	sprintf_s(buffer, "%f", num, 65);
	InitializationString((const char *)buffer);
}

CString::CString(double num)
{
	char buffer[65];
	sprintf_s(buffer, "%lf", num, 65);
	InitializationString((const char *)buffer);
}

CString::CString(long double num)
{
	char buffer[65];
	sprintf_s(buffer, "%llf", num, 65);
	InitializationString((const char *)buffer);
}

void CString::InitializationString(const char *str)
{
	m_length = strlen(str);
	m_ptr = new char[m_length + 1];
	strncpy_s(m_ptr, m_length + 1, str, m_length);
}

CString::~CString()
{
	if (m_ptr) {
		delete[] m_ptr;
		m_ptr = nullptr;
	}
}

size_t CString::Length() const
{
	return m_length;
}

void CString::Append(const char ch)
{
	size_t newSize = 1 + m_length;
	char *tmptr;

	assert(newSize > 0);

	tmptr = new char[newSize + 1];

	if (m_length > 0)
		strcpy_s(tmptr, m_length + 1, m_ptr);
	*(tmptr + m_length) = ch;
	*(tmptr + m_length + 1) = '\0';

	if (m_ptr)
		delete[] m_ptr;

	m_ptr = tmptr;
	m_length = newSize;
}

void CString::Append(const char *chs)
{
	Append(chs, strlen(chs));
}

void CString::Append(const char *chs, size_t len)
{
	if (len < 1)
		return;

	size_t newSize = len + m_length;
	char *tmptr;

	assert(newSize > 0);

	tmptr = new char[newSize + 1];

	if (m_length > 0)
		strcpy_s(tmptr, m_length + 1, m_ptr);
	strncpy_s(tmptr + m_length, len+1, chs, len);

	if (m_ptr)
		delete[] m_ptr;

	m_ptr = tmptr;
	m_length = newSize;
}

void CString::Append(const CString& refer)
{
	Append(refer.m_ptr, refer.m_length);
}

bool CString::Equal(const char *str) const
{
	assert(m_ptr || str);
	return !strcmp(m_ptr, str);
}

bool CString::Equal(const char *str, size_t len) const
{
	assert(m_ptr || str);
	if (m_length != len || len < 1)
		return false;
	return !strcmp(m_ptr, str);
}

bool CString::Equal(const CString& cs) const
{
	assert(m_ptr || cs.m_ptr);
	if (cs.m_length != m_length)
		return false;
	return !strcmp(m_ptr, cs.m_ptr);
}

bool CString::Contains(const char *ptr) const
{
	const char *s1, *s2, *_ptr = ptr;
	size_t ret = 0;
	for(; *_ptr; _ptr++) {
		s1 = m_ptr;
		s2 = ptr;
		while(*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2)
			return true;
	}
	return false;
}

bool CString::Contains(const char *ptr, size_t len) const
{
	assert(len <= m_length);
	const char *s1, *s2, *_ptr = ptr;
	size_t ret = 0;
	for(; *_ptr; _ptr++) {
		s1 = m_ptr;
		s2 = ptr;
		while(*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2)
			return true;
	}
	return false;
}

bool CString::Contains(const CString& cs) const
{
	return Contains(cs.m_ptr, cs.m_length);
}

char& CString::operator[](int index)
{
	assert(m_length > index);
	return m_ptr[index];
}

char CString::operator[](int index) const
{
	assert(m_length > index);
	return m_ptr[index];
}

bool CString::operator==(const char *cs) const
{
	return Equal(cs);
}

bool CString::operator==(const CString& cs) const
{
	return Equal(cs);
}

bool CString::operator!=(const char *cs) const
{
	return !Equal(cs);
}

bool CString::operator!=(const CString& cs) const
{
	return !Equal(cs);
}

char *CString::operator*()
{
	return ToArray();
}

//
//	String Private Helper
//
void CString::AdjustPreCharacter(const char const **ptr, char ch)
{
	while ( **ptr != ch )
		*ptr += 1;
}

void CString::AdjustPostCharacter(const char const **ptr, char ch)
{
	while ( **ptr == ch )
		*ptr += 1;
}

void CString::AdjustPreWithScope(const char const **ptr, const char lch, const char rch)
{
	while ( !(**ptr <= lch && rch <= **ptr) )
		*ptr += 1;
}

void CString::AdjustPostWithScope(const char const **ptr, const char lch, const char rch)
{
	while ( **ptr <= lch && rch <= **ptr )
		*ptr += 1;
}

void CString::AdjustBracketCharacter(const char const **ptr, const char ch1, const char ch2)
{
	int i;
	for (i = 0; **ptr != ch2; *ptr += 1)
		if (**ptr == ch1)
			i++;
	for ( ; i > 0; *ptr += 1)
		if (**ptr == ch2)
			i--;
}

template<typename _Func>
size_t CString::AdjustPreFindFunction(const char const **ptr, _Func *func)
{
	const char *p = *ptr, *o = *ptr;
	
	while ( *p ) {
		if(func((int)*p))
			return (*ptr = p) - o;
		p++;
	}
	
	*ptr = p;
	return -1;
}

template<typename _Func>
size_t CString::AdjustPostFindFunction(const char const **ptr, _Func *func)
{
	const char *p = *ptr, *o = *ptr;
	
	while ( *p ) {
		if(func((int)*p))
			return o - (*ptr = p);
		p--;
	}
	
	*ptr = p;
	return -1;
}

template<typename _Func>
size_t CString::AdjustPreSkipFunction(const char const **ptr, _Func *func)
{
	const char *p = *ptr, *o = *ptr;
	
	while ( *p ) {
		if(!func((int)*p))
			return (*ptr = p) - o;
		p++;
	}
	
	*ptr = p;
	return -1;
}

template<typename _Func>
size_t CString::AdjustPostSkipFunction(const char const **ptr, _Func *func)
{
	const char *p = *ptr, *o = *ptr;
	
	while ( *p ) {
		if(!func((int)*p))
			return o - (*ptr = p);
		p--;
	}
	
	*ptr = p;
	return -1;
}

void CString::AdjustLeftTrim(const char const **ptr)
{
	AdjustPreSkipFunction(ptr, isspace);
}

void CString::AdjustRightTrim(char **ptr)
{
	const char const **iter = (const char **)ptr;
	AdjustLastPointer(iter);
	AdjustPostSkipFunction(iter, isspace);
	*(*(char **)iter + 1) = 0;
}

void CString::AdjustLastPointer(const char const **ptr)
{
	for (; **ptr; *ptr += 1)
		;
	*ptr -= 1;
}

char *CString::DropLeft(const char *ptr, size_t sz)
{
	char *ret, *p = (char *)ptr;
	ret = (char *)malloc(sizeof(char) * sz + 1);
	memcpy(ret, p, sz);
	ret[sz] = 0;
	return ret;
}

char *CString::DropRight(const char *ptr, size_t sz)
{
	char *ret, *p = (char *)ptr;
	while ( *p++ )
		;
	p -= sz + 1;
	ret = (char *)malloc(sizeof(char) * sz + 1);
	memcpy(ret, p, sz);
	ret[sz] = 0;
	return ret;
}

char *CString::DropMid(const char *ptr, size_t _Left, size_t _Right)
{
	char *ret;
	ret = DropLeft(ptr += _Left, _Right);
	return ret;
}

char *CString::DropLSet(const char *ptr, size_t sz, char pad = ' ')
{
	char *ret, *p = (char *)ptr;
	int i;
	ret = (char *)malloc(sizeof(char) * sz + 1);
	for (i = 0; *p && i < sz; i++, p++)
		ret[i] = *p;
	if (!*p)
		for (; i < sz; i++)
			ret[i] = ' ';
	ret[sz] = 0;
	return ret;
}

char *CString::DropRSet(const char *ptr, size_t sz, char pad = ' ')
{
	char *ret, *p = (char *)ptr;
	int i = sz;
	while ( *p++ )
		;
	ret = (char *)malloc(sizeof(char) * sz + 1);
	p -= 2;
	for (; p != (ptr - 1) && i; i--, p--)
		ret[i-1] = *p;
	if (p == (ptr - 1)) {
		for (; i; i--)
			ret[i] = ' ';
		*ret = ' ';
	}
	ret[sz] = 0;
	return ret;
}

size_t CString::DropContainsLength(const char *src, const char *ptr)
{
	const char *s1, *s2, *_ptr = ptr;
	size_t ret = 0;
	for(; *_ptr; _ptr++) {
		s1 = src;
		s2 = ptr;
		while(*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if(!*s2)
			_ptr = s1 - 1, ret++;
	}
	return ret;
}

bool CString::DropStartsWith(const char *src, const char *ptr)
{
	while( *src == *ptr && *src && *ptr )
		src++, ptr++;
	
	if(*ptr)
		return false;
	
	return true;
}

bool CString::DropEndsWith(const char *src, const char *ptr)
{
	const char *p1 = src, *p2 = ptr;
	
	AdjustLastPointer(&p1);
	AdjustLastPointer(&p2);
	
	while ( p2 != ptr && p1 != src ) {
		if (*p1 != *p2)
			return false;
		p1--;
		p2--;
	}
	
	if ( p2 == ptr || p1 == src ) {
		if ( *p1 != *p2 )
			return false;
	}
	
	return true;
}

char *CString::ToArray()
{
	char *ret = new char[m_length + 1];
	strcpy_s(ret, m_length+1, m_ptr);
	return ret;
}

//
//	Methods
//
CString CString::Substring(size_t len)
{
	assert(len <= m_length);
	return *new CString(m_ptr, len);
}

CString CString::Substring(size_t starts, size_t len)
{
	assert(len + starts <= m_length);
	const char *ptr = m_ptr + starts;
	return *new CString(ptr, len);
}

CString CString::LTrim()
{
	const char *ptr = m_ptr;
	AdjustLeftTrim(&ptr);
	return *new CString(ptr);
}

CString CString::RTrim()
{
	char *toarray = ToArray();
	AdjustRightTrim(&toarray);
	return *new CString(toarray);
}

CString CString::TrimStart()
{
	return LTrim();
}

CString CString::TrimEnd()
{
	return RTrim();
}

CString CString::Trim()
{
	return  RTrim().LTrim();
}

CString CString::LSet(size_t len)
{
	return *new CString(DropLSet(m_ptr, len));
}

CString CString::RSet(size_t len)
{
	return *new CString(DropRSet(m_ptr, len));
}

CString CString::Left(size_t len)
{
	return *new CString(DropLeft(m_ptr, len));
}

CString CString::Mid(size_t l, size_t r)
{
	return *new CString(DropMid(m_ptr, l, r));
}

CString CString::Right(size_t len)
{
	return *new CString(DropRight(m_ptr, len));
}

size_t CString::Len(const char *str)
{
	return DropContainsLength(m_ptr, str);
}

size_t CString::Len(const CString& cs)
{
	return DropContainsLength(m_ptr, cs.m_ptr);
}

bool CString::StartsWith(const char *str)
{
	return DropStartsWith(m_ptr, str);
}

bool CString::StartsWith(const CString& cs)
{
	return DropStartsWith(m_ptr, cs.m_ptr);
}

bool CString::EndsWith(const char *str)
{
	return DropEndsWith(m_ptr, str);
}

bool CString::EndsWith(const CString& cs)
{
	return DropEndsWith(m_ptr, cs.m_ptr);
}

CString CString::PadLeft(size_t len)
{
	return LSet(len);
}

CString CString::PadLeft(size_t len, char ch)
{
	return *new CString(DropLSet(m_ptr, len, ch));
}

CString CString::PadRight(size_t len)
{
	return RSet(len);
}

CString CString::PadRight(size_t len, char ch)
{
	return *new CString(DropRSet(m_ptr, len, ch));
}

CString CString::ToLower()
{
	CString *ret = new CString(*this);
	for (int i = 0; i < ret->m_length; i++)
		ret->m_ptr[i] = tolower(ret->m_ptr[i]);
	return *ret;
}

CString CString::ToUpper()
{
	CString *ret = new CString(*this);
	for (int i = 0; i < ret->m_length; i++)
		ret->m_ptr[i] = toupper(ret->m_ptr[i]);
	return *ret;
}

std::vector<CString *> CString::Split(const char *str)
{
	std::vector<CString *> ret;
	const char *ptr = m_ptr;
	const char *s1, *s2, *pre = m_ptr;

	for(; *ptr; ) {
		s1 = ptr;
		s2 = str;
		while(*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2) {
			ret.push_back(new CString(pre, ptr - pre));
			ptr = s1;
			pre = s1;
		} else {
			ptr++;
		}
	}
	
	// include zero length string
	ret.push_back(new CString(pre, ptr - pre));

	return ret;
}

std::vector<CString *> CString::Split(const char *str, size_t max)
{
	std::vector<CString *> ret;
	const char *ptr = m_ptr;
	const char *s1, *s2, *pre = m_ptr;

	for(; *ptr && ret.size() < max; ) {
		s1 = ptr;
		s2 = str;
		while(*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2) {
			ret.push_back(new CString(pre, ptr - pre));
			ptr = s1;
			pre = s1;
		} else {
			ptr++;
		}
	}
	
	if (ret.size() < max)
		ret.push_back(new CString(pre, ptr - pre));

	return ret;
}

std::vector<CString *> CString::Split(const CString& cs)
{
	return Split(cs.m_ptr);
}

std::vector<CString *> CString::Split(const CString& cs, size_t max)
{
	return Split(cs.m_ptr, max);
}

CString CString::Replace(const char *src, const char *dest)
{
	CString *ret = new CString;
	const char *ptr = m_ptr;
	const char *s1, *s2, *pre = m_ptr;

	for(; *ptr; ) {
		s1 = ptr;
		s2 = src;
		while(*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2) {
			if (ptr - pre)
				ret->Append(pre, ptr - pre);
			ret->Append(dest, s2 - src);
			ptr = s1;
			pre = s1;
		} else {
			ptr++;
		}
	}

	if (ptr - pre)
		ret->Append(pre, ptr - pre);
	return *ret;
}

CString CString::Replace(const char *src, const char *dest, size_t max)
{
	CString *ret = new CString;
	const char *ptr = m_ptr;
	const char *s1, *s2, *pre = m_ptr;
	size_t count = 0;

	for(; *ptr; ) {
		s1 = ptr;
		s2 = src;
		while(*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;
		if (!*s2 && count < max) {
			if (ptr - pre)
				ret->Append(pre, ptr - pre);
			ret->Append(dest, s2 - src);
			ptr = s1;
			pre = s1;
			count++;
		} else {
			ptr++;
		}
	}

	if (ptr - pre)
		ret->Append(pre, ptr - pre);
	return *ret;
}

CString CString::Replace(const CString& src, const CString& dest)
{
	return Replace(src.m_ptr, dest.m_ptr);
}

CString CString::Replace(const CString& src, const CString& dest, size_t max)
{
	return Replace(src.m_ptr, dest.m_ptr, max);
}

bool CString::IsNumberic() const
{
	const char *ptr = m_ptr;

	if (*ptr == '-')
		ptr++;
	else if (*ptr == '+')
		ptr++;

	while ( isdigit(*ptr) && *ptr )
		ptr++;

	if ( *ptr == '.' )
	{
		ptr++;

		while ( isdigit(*ptr) && *ptr )
			ptr++;

		if ( *ptr == 'e' || *ptr == 'E' )
		{
			ptr++;
			if ( *ptr == '+' || *ptr == '-' || isdigit(*ptr) )
			{
				ptr++;
				while ( isdigit(*ptr) && *ptr )
					ptr++;
			}
		}
	}

	return !*ptr;
}

bool CString::IsInteger() const
{
	const char *ptr = m_ptr;
	
	if (*ptr == '-')
		ptr++;
	else if (*ptr == '+')
		ptr++;

	while ( isdigit(*ptr) && *ptr )
		ptr++;

	return !*ptr;
}

int CString::ToInteger()
{
	int ret = 0, mark = 1;
	const char *ptr = m_ptr;

	if (*ptr == '-')
		mark = -1, ptr++;
	else if (*ptr == '+')
		ptr++;

	while (*ptr)
		ret = ret * 10 + *ptr++ - '0';

	return ret * mark;
}

double CString::ToDouble()
{
	const char *ptr = m_ptr;
	double _integer = 0.0;
	double _minority = 0.0;
	double _set = 1;
	double mark = 1;
	int index = 0;
	int index_mark = 1;

	if (*ptr == '-')
		mark = -1, ptr++;
	else if(*ptr == '+')
		ptr++;
	
	while (*ptr && *ptr != '.')
		_integer = (_integer * 10) + (*ptr++ & 0xf);

	if (*ptr == '.')
		ptr++;

	while (*ptr && *ptr != 'e' && *ptr != 'E')
		_minority = (_minority * 10) + (*ptr++ & 0xf),
		_set *= 0.1;

	if ( *ptr == 'e' || *ptr == 'E' )
	{
		ptr++;
		if ( *ptr == '+' ) {
			ptr++;
		} else if ( *ptr == '-' ) {
			ptr++;
			index_mark = -1;
		}
		while ( *ptr )
			index = index * 10 + *ptr++ & 0xf;
		index *= index_mark;
	}
	else
		index = 1;
	
	return mark * (_integer + _minority * _set) * ::pow(10, index);
}