/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   DateTime.cpp

Purpose:

   RollRat Library

Author:

   10-24-2015:   HyunJun Jeong, Creation

***/

#include "DateTime.h"

namespace Utility {
	
	static const int _date_366[] = 
		{0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};
	static const int _date_365[] = 
		{0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

	// Short Length is 3
	static const wchar_t *_month_eng[] =
		{ L"January", L"February", L"March", L"April", L"May", L"June",
		  L"July", L"August", L"September", L"October", L"November", L"December" };

	static const wchar_t *_week_eng[] = 
		{ L"Sunday", L"Monday", L"Tuesday", L"Wednesday", L"Thursday", L"Friday", L"Saturday" };
	static const wchar_t *_week_kor[] = 
		{ L"일", L"월", L"화", L"수", L"목", L"금", L"토" };
	static const wchar_t *_week_kor_post[] = 
		{ L"일요일", L"월요일", L"화요일", L"수요일", L"목요일", L"금요일", L"토요일" };

	const int* DateTime::days366 = _date_366;
	const int* DateTime::days365 = _date_365;

	const wchar_t** DateTime::monthsEng = _month_eng;

	const wchar_t** DateTime::weeksEng = _week_eng;
	const wchar_t** DateTime::weeksKorFull = _week_kor_post;
	const wchar_t** DateTime::weeksKorShort = _week_kor;

	const wchar_t* DateTime::meridiemEngFirst = L"A.M.";
	const wchar_t* DateTime::meridiemEngLast = L"P.M.";
	const wchar_t* DateTime::meridiemEngFirstShort = L"AM";
	const wchar_t* DateTime::meridiemEngLastShort = L"PM";

	const wchar_t* DateTime::meridiemKorFirst = L"오전";
	const wchar_t* DateTime::meridiemKorLast = L"오후";

}