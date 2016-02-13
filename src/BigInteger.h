/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   BigInteger.h

Purpose:

   RollRat Library

Author:

   12-01-2015:   HyunJun Jeong, Creation

***/

#ifndef _BIGINTEGER_9bf1541fdf7efd41b7b39543fd870ac4_
#define _BIGINTEGER_9bf1541fdf7efd41b7b39543fd870ac4_

#include "WString.h"
#include <algorithm>

namespace Utility {

	class BigInteger
	{
		char *m_ptr;
		size_t m_length;
		bool sign;

	public:

		BigInteger()
			: m_ptr(nullptr)
			, m_length(0)
			, sign(false)
		{
		}

		~BigInteger()
		{
			if ( m_ptr != nullptr )
				delete[] m_ptr;
		}

		void Add(const char * s)
		{
			char *k = _strdup(s);
			InternalAddition(_strrev(k));
			delete[] k;
		}

		void Sub(const char * s)
		{
			char *k = _strdup(s);
			InternalSubtract(_strrev(k));
			delete[] k;
		}

		void Mul(const char * s)
		{
			char *k = _strdup(s);
			InternalMultiple(_strrev(k));
			delete[] k;
		}

		void Div(const char * s)
		{
			InternalDivide((char *)s);
		}

		char* get() const
		{
			return m_ptr;
		}

	private:

		/*
			logic

			integer
			for i < len(a1)
				tmp = tmp + a1
				tmp + 1 = tmp / 10
				tmp = tmp % 10
			end for

			char
			for i < len(a1)
				tmp = tmp + a1 + carry
				carry = tmp / 10
				tmp = (tmp % 10) | '0'
			end for
		*/
		void InternalAddition(char* a1)
		{
			size_t srclen = strlen(a1);
			char* tmp = CheckPtr(srclen);

			if (!m_length || (m_length == 1 && *m_ptr == '0'))
			{
				memcpy(tmp, _strrev(a1), srclen + 1);
				delete[] m_ptr;
				m_ptr = tmp;
				m_length = srclen;
				return;
			}

			if ( sign )
			{
				sign = 1;
				InternalSubtract(a1);
				sign = 0;
				return;
			}

			int carry = 0;
			char *ptr = tmp;
			char *mm_ptr = m_ptr;

			_strrev(m_ptr);

			for ( ; *a1 && *m_ptr; a1++, m_ptr++)
			{
				int k = (*a1 & 0xf) + (*m_ptr & 0xf) + carry;
				carry = k / 10;
				k %= 10;
				*ptr++ = k + '0';
			}

			if ( *a1 )
			{
				for ( ; *a1 ; a1++)
				{
					int k = (*a1 & 0xf) + carry;
					carry = k / 10;
					k %= 10;
					*ptr++ = k + '0';
				}
			}
			else if ( *m_ptr )
			{
				for ( ; *m_ptr ; m_ptr++)
				{
					int k = (*m_ptr & 0xf) + carry;
					carry = k / 10;
					k %= 10;
					*ptr++ = k + '0';
				}
			}
			
			if (carry)
			{
				*ptr++ = carry + '0';
			}

			*ptr = 0;
			_strrev(tmp);
			delete[] mm_ptr;
			m_ptr = tmp;
			m_length = ptr - tmp;
			Trim();
		}
		

		/*
			logic

			integer
			for i < len(a1)
				tmp = tmp - a1
				if tmp less than 0
					tmp + 1 = (tmp + 1) - 1
					tmp = tmp + 10
				end if
			end for
		*/
		void InternalSubtract(char* a1)
		{
			size_t srclen = strlen(a1);
			char* tmp = CheckPtr(srclen);

			if (!m_length || (m_length == 1 && *m_ptr == '0'))
			{
				memcpy(tmp, _strrev(a1), srclen + 1);
				delete[] m_ptr;
				m_ptr = tmp;
				m_length = srclen;
				sign = true;
				return;
			}
			
			if ( sign )
			{
				sign = 0;
				InternalAddition(a1);
				sign = 1;
				return;
			}

			int carry = 0;
			char *ptr = tmp;
			char *mm_ptr = m_ptr;
			
			_strrev(m_ptr);

			for ( ; *a1 && *m_ptr; a1++, m_ptr++ )
			{
				int k = (*m_ptr & 0xf) - (*a1 & 0xf) - carry;
				carry = k < 0;

				if (k >= 0)
					*ptr++ = '0' + k;
				else
					*ptr++ = '9' + k + 1;
			}

			if ( *a1 )
			{
				carry = 1;
				for ( ; *a1 ; a1++ )
				{
					int k =  (*a1 & 0xf) - carry;
					carry = k < 0;

					if (k >= 0)
						*ptr++ = '0' + k;
					else
						*ptr++ = '9' + k + 1;
				}
				sign = true;
			}
			else if ( *m_ptr )
			{
				for ( ; *m_ptr ; m_ptr++ )
				{
					int n = (*m_ptr & 0xf);
					int k = n - carry;
					carry = k < 0;

					if (k >= 0)
						*ptr++ = '0' + k;
					else
						*ptr++ = '9' + k + 1;
				}
			}
			else if ( carry )
			{
				*(ptr - 1) = (*--a1 & 0xf) - (*--m_ptr & 0xf) + '0';
			}

			if ( carry )
			{
				sign = true;
			}

			*ptr = 0;
			_strrev(tmp);
			delete[] mm_ptr;
			m_ptr = tmp;
			m_length = ptr - tmp;
			Trim();
		}

		void InternalMultiple(char* a)
		{
			if (!m_length || (m_length == 1 && *m_ptr == '0'))
				return;

			char* _dup = _strdup(_strrev(m_ptr));
			size_t len = m_length;

			delete[] m_ptr;
			m_length = 0;
			m_ptr = nullptr;

			size_t alen = strlen(a);

			for (int i = 0; i < alen; i++)
				InternalMultipleCh(_dup, len, a[i], i);

			delete[] _dup;
			Trim();
		}

		void InternalMultipleCh(char* sm_ptr, size_t sm_len, char a, int z)
		{
			char* ptr = sm_ptr;
			char* tmp = new char[sm_len + z + 2];
			char* ttr = tmp + z;
			int carry = 0;
			
			for ( ; *ptr; ptr++)
			{
				int k = carry + (*ptr & 0xf) * (a & 0xf);
				*ttr++ = (k % 10) + '0';
				carry = k / 10;
			}

			if ( carry )
				*ttr++ = (carry % 10) + '0';
			*ttr = 0;
			
			while ( z-- )
				tmp[z] = '0';

			InternalAddition(tmp);
			delete[] tmp;
		}

		/*
			logic

			if dividend > divisor
				loop
					shift divisor by len - len(a)
					subtract shifted
			else if dividend = divisor
				set 1
			else
				fill zero
			end if
		*/
		void InternalDivide(char * a)
		{
			size_t len = strlen(a);

			if ( len == 1 && *a == '0' )
				throw("คว");

			if ( m_length < len )
				ForcePut("0");

			char* buf = new char[m_length];
			size_t blen = 0;
			char* ptr = m_ptr;
			size_t prevlen = m_length;

			for ( size_t posValid = len - 1; posValid < m_length; )
			{
				bool skip = false;
				
				if (InternalCompare(a) < 0)
					break;

				if ( m_ptr[posValid] >= *a )
				{
					char tch = m_ptr[posValid + 1];
					m_ptr[posValid + 1] = 0;
					bool k = strcmp(m_ptr, a) >= 0;
					m_ptr[posValid + 1] = tch;
					if (k == true)
						goto S;
				}

				if ( posValid >= m_length  )
					break;
				posValid++;
				buf[blen++] = 0;
				skip = true;
			S:
				char* lefts = new char[posValid + len];
				memcpy(lefts, m_ptr, posValid + len - 1);
				lefts[posValid + len - 1] = 0;

				// test multiple
				const char* bt[] = { "2", "3", "4", "5", "6", "7", "8", "9" };
				int i = 2;
				for ( ; i < 10; i++)
				{
					BigInteger bi;
					bi.Add(a);
					bi.Mul(bt[i-2]);
					if ( bi.InternalCompare(lefts) >= 0 )
						break;
				}

				BigInteger result;
				result.Add(a);
				if ( i >= 3 )
					result.Mul(bt[i-3]);
				char* subt_ex10 = new char[m_length - posValid + skip + len];
				memcpy(subt_ex10, result.m_ptr, result.m_length);
				int puts = m_length - posValid - len + 1;
				if ( puts > 0 )
				while ( puts-- )
					subt_ex10[result.m_length + puts] = '0';
				subt_ex10[m_length - posValid + skip + len - 1] = 0;

				// subtract shifted
				InternalSubtract(_strrev(subt_ex10));

				delete[] lefts;
				delete[] subt_ex10;

				buf[blen++] = i - 1;

				if ( prevlen > m_length )
				{
					posValid = len - 1;
					prevlen = m_length;
					buf[blen++] = 0;
				}
			}

			size_t bpl = blen;
			char* tmp = new char[blen + 1];
			while ( --blen )
				tmp[blen] = buf[blen] + '0';
			*tmp = *buf + '0';
			tmp[bpl] = 0;
			delete[] m_ptr;
			delete[] buf;
			m_length = bpl - 1;
			m_ptr = tmp;
		}

		/*void InternalRemainder(char * a)
		{

		}*/

		int InternalCompare(char * a)
		{
			size_t len = strlen(a);

			if ( len > m_length )
				return -1;
			else if ( len < m_length ) 
				return 1;

			return strcmp(m_ptr, a);
		}

		char* CheckPtr(size_t len = 0)
		{
			len = std::max(len, m_length);

			char* ptr = new char[len + 2];
			memset(ptr, 0, len + 2);
			return ptr;
		}

		void ForcePut(const char* s)
		{
			delete[] m_ptr;
			m_length = strlen(s);
			m_ptr = _strdup(s);
		}

		// Nomarlize number
		void Trim()
		{
			if ( m_length > 1 )
			{
				char* starts = m_ptr;
				char* last = m_ptr + m_length - 1;

				while (*starts == '0' && starts != last)
					starts++;

				if ( starts != m_ptr )
				{
					m_length = m_length - ( starts - m_ptr ) + (starts == last);
					char* tmp = new char[m_length + 1];
					memcpy(tmp, starts, m_length + 1);
					delete[] m_ptr;
					m_ptr = tmp;
				}
			}
		}

		void Clear()
		{
			if (m_ptr != nullptr)
				delete[] m_ptr;
			m_length = 0;
			m_ptr = nullptr;
		}

	};

}

#endif