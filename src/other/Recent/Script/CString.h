/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   CString.h

Project:

	RollRat Script Parser - String Class

------
   AUTHOR: HyunJun Jeong  2015-08-13

***************************************************************************/

#ifndef _CSTRING_efac098ccb24d690335d7bc3f5ba0a65_
#define _CSTRING_efac098ccb24d690335d7bc3f5ba0a65_

#include <vector>

class CString {
public:
	CString();
	CString(const char *);
	CString(const char *, size_t);
	CString(int);
	CString(long);
	CString(long long);
	CString(unsigned);
	CString(unsigned long long);
	CString(float);
	CString(double);
	CString(long double);
	~CString();

	size_t Length() const;

	void Append(const char);
	void Append(const char *);
	void Append(const char *, size_t);
	void Append(const CString&);
	bool Equal(const char *) const;
	bool Equal(const char *, size_t) const;
	bool Equal(const CString&) const;
	bool Contains(const char *) const;
	bool Contains(const char *, size_t) const;
	bool Contains(const CString&) const;

	char *operator*();
	bool operator==(const char *) const;
	bool operator==(const CString&) const;
	bool operator!=(const char *) const;
	bool operator!=(const CString&) const;

	char& operator[](int);
	char operator[](int) const;

	CString Substring(size_t);
	CString Substring(size_t, size_t);

	CString LTrim();
	CString RTrim();
	CString TrimEnd();
	CString TrimStart();
	CString Trim();

	CString LSet(size_t);
	CString RSet(size_t);

	CString Left(size_t);
	CString Mid(size_t, size_t);
	CString Right(size_t);

	size_t Len(const char *);
	size_t Len(const CString&);

	bool StartsWith(const char *);
	bool StartsWith(const CString&);
	bool EndsWith(const char *);
	bool EndsWith(const CString&);

	CString PadLeft(size_t);
	CString PadLeft(size_t, char);
	CString PadRight(size_t);
	CString PadRight(size_t, char);

	CString ToLower();
	CString ToUpper();

	std::vector<CString *> Split(const char *);
	std::vector<CString *> Split(const char *, size_t);
	std::vector<CString *> Split(const CString&);
	std::vector<CString *> Split(const CString&, size_t);

	CString Replace(const char *, const char *);
	CString Replace(const char *, const char *, size_t);
	CString Replace(const CString&, const CString&);
	CString Replace(const CString&, const CString&, size_t);
	
	bool IsNumberic() const;
	bool IsInteger() const;

	int ToInteger();
	double ToDouble();

private:

	// Implement Helper
	void AdjustPreCharacter(const char const **, char);
	void AdjustPostCharacter(const char const **, char);
	void AdjustPreWithScope(const char const **, char, char);
	void AdjustPostWithScope(const char const **, char, char);
	void AdjustBracketCharacter(const char const **, char, char);
	template<typename _Func>
	size_t AdjustPreFindFunction(const char const **, _Func *);
	template<typename _Func>
	size_t AdjustPostFindFunction(const char const **, _Func *);
	template<typename _Func>
	size_t AdjustPreSkipFunction(const char const **, _Func *);
	template<typename _Func>
	size_t AdjustPostSkipFunction(const char const **, _Func *);
	void AdjustLeftTrim(const char const **);
	void AdjustRightTrim(char **);
	void AdjustLastPointer(const char const **);

	char *DropLeft(const char *, size_t);
	char *DropRight(const char *, size_t);
	char *DropMid(const char *, size_t, size_t);
	char *DropLSet(const char *, size_t, char);
	char *DropRSet(const char *, size_t, char);
	size_t DropContainsLength(const char *, const char *);
	bool DropStartsWith(const char *, const char *);
	bool DropEndsWith(const char *, const char *);

	char *ToArray();

	void InitializationString(const char *);

private:

	//bool non_sizeable;
	size_t m_length;
	mutable char *m_ptr;
};

#endif