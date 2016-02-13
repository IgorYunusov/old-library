/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   DateTime.h ( DateTime + TimeSpan )

Purpose:

   RollRat Library

Author:

   10-24-2015:   HyunJun Jeong, Creation

***/

#ifndef _DATETIME_9bf1541fdf7efd41b7b39543fd870ac4_
#define _DATETIME_9bf1541fdf7efd41b7b39543fd870ac4_

#include <chrono>
#include <stdint.h>
#include <Windows.h>

#include "WStringBuilder.h"

namespace Utility {

#   define __timeSecond			1
#   define __timeMinute			(__timeSecond * 60)
#   define __timeHour			(__timeMinute * 60)
#   define __timeDay            (__timeHour * 24)
#   define __timeYear366        (__timeDay * 366)
#   define __timeYear365        (__timeDay * 3650

#   define __timeInvSecond		(1.0f / __timeSecond)
#   define __timsInvMinute		(1.0f / __timeMinute)
#   define __timeInvHour		(1.0f / __timeHour)
#   define __timeInvDay     	(1.0f / __timeDay)
#   define __timeInvYear366 	(1.0f / __timeYear366)
#   define __timeInvYear365 	(1.0f / __timeYear365)

#   define __DaysYear           365
#   define __Days4Years			(__DaysYear * 4 + 1)
#   define __Days100Years		(__Days4Years * 25 - 1)
#   define __Days400Years		(__Days100Years * 4 + 1)

	//
	//	��¥�� �ð��� ����� �� �ִ� �˰����� �����մϴ�. ( �⺻ ���� : �� )
	//
	class DateTime
	{
		static const int *days366;
		static const int *days365;

		static const wchar_t **monthsEng;

		static const wchar_t **weeksEng;
		static const wchar_t **weeksKorShort; // short
		static const wchar_t **weeksKorFull;

		static const wchar_t *meridiemEngFirst;
		static const wchar_t *meridiemEngLast;
		static const wchar_t *meridiemEngFirstShort;
		static const wchar_t *meridiemEngLastShort;

		static const wchar_t *meridiemKorFirst;
		static const wchar_t *meridiemKorLast;

		uint64_t m_seconds;

	public:

		DateTime()
			: DateTime(___GetNowTm())
		{
		}
		
		DateTime(uint64_t time) // second
			: m_seconds(time)
		{
		}

		DateTime(FILETIME ft)
			: DateTime(___FileTime(ft))
		{
		}

		DateTime(SYSTEMTIME st)
			: DateTime(___SystemTime(st))
		{
		}
		
		DateTime(const struct tm tm)
			: DateTime(tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec)
		{
		}

		DateTime(int year, int month, int day)
			: m_seconds( GetSecondsFromDate( year, month, day ) )
		{
		}

		DateTime(int year, int month, int day, int hour, int minute, int second)
			: m_seconds( GetSecondsFromDate( year, month, day    ) +
			           GetSecondsFromTime( hour, minute, second)   )
		{
		}
		
		int Days()
		{ return m_seconds / __timeDay; }
		int Hours()
		{ return (uint64_t(m_seconds / __timeHour)) % 24; }
		int Minutes()
		{ return (uint64_t(m_seconds / __timeMinute)) % 60; }
		int Seconds()
		{ return (uint64_t(m_seconds / __timeSecond)) % 60; }
		int Year()
		{ return GetDatePart(0); }
		int DayOfYear()
		{ return GetDatePart(1); }
		int Month()
		{ return GetDatePart(2); }
		int Day()
		{ return GetDatePart(3); }
		int DayOfWeek()
		{ return (uint64_t((m_seconds & ~(uint64_t((3 << 63)))) / __timeDay + 1)) % 7; }
		bool Morning()
		{ return Hours() < 12; }
		bool Afternoon()
		{ return !Morning(); }

		DateTime Subtract(const DateTime& dest)
		{
			if (dest.m_seconds > this->m_seconds)
				return DateTime(dest.m_seconds - this->m_seconds - 1);
			else
				return DateTime(this->m_seconds - dest.m_seconds - 1);
		}
		DateTime Add(const DateTime& dest)
		{
			return DateTime(this->m_seconds + dest.m_seconds);
		}

		WString Format(const WString& fmt, bool kor = false)
		{
			WStringBuilder wsb(fmt.Length() << 2);
			WString ref;
			const wchar_t *ptr = fmt.Reference();

			int wh;

			auto countRepeat = [](const wchar_t *t, wchar_t ch)
			{
				const wchar_t *ptr = t;
				for ( ; *ptr == ch; ptr++ )
					;
				return ptr - t;
			};

			// stftime�̶� ���� �����ȴٰ� �����
			for ( ; *ptr; )
			{
				wh = countRepeat(ptr, *ptr);
				switch( *ptr )
				{
				case L'y': // year(�빮�ڴ� ����)
					if (wh <= 2)
						wsb.Append(WString(Year()).Substring(2));
					else if (wh >= 4)
						wsb.Append(Year());
					break;
				case L'M': // month
					if (wh == 1)
						wsb.Append(Month() % 10);
					else if (wh == 2)
						wsb.Append(WString(Month()).PadLeft(2, L'0'));
					else if (wh == 3)
						wsb.Append(kor ? WString::Concat(Month(), L"��") : WString(monthsEng[Month()-1]).Substring(0, 3));
					else if (wh >= 4)
						wsb.Append(kor ? WString::Concat(Month(), L"��") : monthsEng[Month()-1]);
					break;
				case L'd': // day
					if (wh == 1)
						wsb.Append(Day() % 10);
					else if (wh == 2)
						wsb.Append(WString(Day()).PadLeft(2, L'0'));
					else if (wh == 3)
						wsb.Append(kor ? weeksKorShort[DayOfWeek()] : WString(weeksEng[DayOfWeek()]).Substring(0, 3));
					else if (wh >= 4)
						wsb.Append(kor ? weeksKorFull[DayOfWeek()] : weeksEng[DayOfWeek()]);
					break;
				case L'T': // AM/PM
					if (wh == 1)
						wsb.Append(Morning() ? L'A' : L'P');
					else if (wh >= 2)
						wsb.Append(Morning() ? (kor ? meridiemKorFirst : meridiemEngFirst) : (kor ? meridiemKorLast : meridiemEngLast));
					break;
				case L't': // A.M./P.M.
					if (wh == 1)
						wsb.Append(Morning() ? L'A' : L'P');
					else if (wh >= 2)
						wsb.Append(Morning() ? (kor ? meridiemKorFirst : meridiemEngFirstShort) : (kor ? meridiemKorLast : meridiemEngLastShort));
					break;
				case L'h': // 12-hour
					if (wh == 1)
						wsb.Append((Hours() % 12) % 10);
					else if (wh >= 2)
						wsb.Append(WString(Hours() % 12).PadLeft(2, L'0'));
					break;
				case L'H': // 24-hour
					if (wh == 1)
						wsb.Append((Hours()) % 10);
					else if (wh >= 2)
						wsb.Append(WString(Hours()).PadLeft(2, L'0'));
					break;
				case L'm': // minute
					if (wh == 1)
						wsb.Append(Minutes() % 10);
					else if (wh >= 2)
						wsb.Append(WString(Minutes()).PadLeft(2, L'0'));
					break;
				case L's': // second
					if (wh == 1)
						wsb.Append(Seconds() % 10);
					else if (wh >= 2)
						wsb.Append(WString(Seconds()).PadLeft(2, L'0'));
					break;
				default:
					wsb.Append(*ptr++);
					continue;
				}
				ptr += wh;
			}

			return wsb.ToString();
		}

	private:

		struct tm ___GetNowTm()
		{
			struct tm now;
			time_t _time;
			time(&_time);
			localtime_s(&now, &_time);
			return now;
		}

		struct tm ___FileTime(FILETIME ft)
		{
			SYSTEMTIME st;
			FileTimeToSystemTime(&ft, &st);
			return ___SystemTime(st);
		}

		struct tm ___SystemTime(SYSTEMTIME st)
		{
			struct tm ftm;
			memset(&ftm, 0, sizeof(struct tm));
			ftm.tm_mday = st.wDay;
			ftm.tm_mon = st.wMonth - 1;
			ftm.tm_year = st.wYear - 1900;
			ftm.tm_min = st.wMinute;
			ftm.tm_hour = st.wHour;
			ftm.tm_sec = st.wSecond;
			return ftm;
		}

		// http://six-oval.googlecode.com/svn/tags/six-oval-1.2.0_src-tag/test/resources/OvalTestContent/5.10/linux/oval-def_time_difference_function.xml
		uint64_t ___FileTimeToTime(FILETIME ft)
		{
			return (uint64_t)((*(uint64_t *)&ft - 0x19DB1DED53E8000) / 10000000);
		}

		uint64_t GetSecondsFromDate(int year, int month, int day)
		{
			const int *days = IsLeap(year) ? days366 : days365;

			return (GetDaysFromYear(year) + days[month - 1] + day - 1) * uint64_t(__timeDay);
		}

		uint64_t GetSecondsFromTime(int hour, int minute, int second)
		{
			return ( uint64_t(hour) * 3600 + uint64_t(minute) * 60 + uint64_t(second) ) *
				 uint64_t(__timeSecond);
		}

		uint64_t GetMonthFromDays(int year, int month)
		{
			const int *days = IsLeap(year) ? days366 : days365;
			return days[month] - days[month - 1];
		}
		
		uint64_t GetDaysFromYear(int year)
		{
			uint64_t y = year - 1;
			return (y * 365) + (y / 4 - y / 100 + y / 400 - 1) + 1;
		}

		uint64_t GetDayFromYear(int year)
		{
			return (GetDaysFromYear(year) + 1) % 7;
		}

		// 0: year
		// 1: day of year
		// 2: month
		// 3: day
		int GetDatePart(int wh)
		{
			// 0001 01 01���� �ϼ� ���
			int n = m_seconds / __timeDay;

			// 0001 01 01���� 400�� ��ü�� �Ⱓ ��� (����)
			int y400 = n / __Days400Years;
			// 400�� ��ü�� �ϼ� ���
			n -= y400 * __Days400Years;
			// 400�� ���� 100�� �Ⱓ ���
			int y100 = n / __Days100Years;
			// ������ 100���� �Ϸ簡 �� ���
			// 100���� 400�⿡�� �̹� ó���Ǿ���
			if (y100 == 4)
				y100 = 3;
			// 100�� �Ⱓ�� �ϼ� ���
			n -= y100 * __Days100Years;

			// 100�� �� 4�� �Ⱓ ���
			int y4 = n / __Days4Years;
			// 4�� �Ⱓ�� �ϼ� ���
			n -= y4 * __Days4Years;

			// 4�� �Ⱓ �� 1�� �Ⱓ ���
			int y1 = n / __DaysYear;
			// ������ �⵵�� �Ϸ簡 �� ���
			// 1���� 4�⿡�� �̹� ó���Ǿ���
			if (y1 == 4)
				y1 = 3;

			// ���� ���� ������ �ɰ����� ������ ���δ� ���ؾ��Ѵ�.
			if (wh == 0)
				return y400 * 400 + y100 * 100 + y4 * 4 + y1 + 1;

			// �ϳ� ������ �ڸ� ���� �� ��
			n -= y1 * __DaysYear;

			if (wh == 1)
				return n + 1;

			// ���� ��� ( ��Ʈ �� ������ IsLeap ȣ�� �ʿ���� )
			bool leap = y1 == 3 && ( y4 != 24 || y100 == 3 );
			const int *days = leap ? days366 : days365;

			// �� �δ��� �ִ� �� �� �� 32�� ���� �ʴ´�.
			int m = (n >> 5) + 1;

			// �ϴ� n�� 1�� �� �� ���� �۴�.
			while ( n >= days[m] )
				m++;

			if (wh == 2)
				return m;

			// m-1���� n���� ���� m�޿� �ش��ϴ� �ϼ��� ���´�.
			// �̴� ������ �ͺ��� 1��ŭ �����Ƿ� 1�� ���Ѵ�
			return n - days[m - 1] + 1;
		}

		// ������ 4�� ���������� 100���� ������ �������� �ʰ�
		// 400���� ������ �������� �ظ� ���Ѵ�.
		bool IsLeap(int year)
		{
			return ((year % 400 == 0) || (year % 100 != 0)) && (year % 4 == 0);
		}

	};

}

#endif