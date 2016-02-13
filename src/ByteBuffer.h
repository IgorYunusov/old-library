/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   ByteBuffer.h

Purpose:

   RollRat Library

Author:

   11-26-2015:   HyunJun Jeong, Creation

***/

#ifndef _BYTE_BUFFER_9bf1541fdf7efd41b7b39543fd870ac4_
#define _BYTE_BUFFER_9bf1541fdf7efd41b7b39543fd870ac4_

#include <memory.h>

#include "WString.h"
#include "Array.h"

namespace Utility {
	
	class ByteBuffer
	{
	public:
		typedef unsigned char ByteType;
		typedef ReadOnlyArray<ByteType> ByteArray;

	private:
		ByteType* m_ptr;
		size_t    m_length;
		size_t    m_capacity;

	public:

		ByteBuffer()
			: m_ptr(nullptr)
			, m_length(0)
			, m_capacity(0)
		{
		}

		ByteBuffer(size_t capacity)
			: m_ptr(nullptr)
			, m_length(0)
			, m_capacity(capacity)
		{
			___Ensure(m_capacity);
		}

		~ByteBuffer()
		{
			m_ptr != nullptr ? delete[] m_ptr : 0;
		}

		void Append(ByteType ch)
		{
			if ( m_length == m_capacity )
				___EnsureCopy(m_length + 1);

			 m_ptr[ m_length++ ] = ch;
		}

		void Append(uint16_t b16)
		{
			if ( m_length == m_capacity )
				___EnsureCopy(m_length + 2);

			 m_ptr[ m_length + 0 ] = b16 >> 8;
			 m_ptr[ m_length + 1 ] = b16 & 0xff;

			 m_length += 2;
		}
		
		void Append(uint32_t b32)
		{
			if ( m_length == m_capacity )
				___EnsureCopy(m_length + 4);

			 m_ptr[ m_length + 0 ] = b32 >> 24;
			 m_ptr[ m_length + 1 ] = (b32 >> 16) & 0xff;
			 m_ptr[ m_length + 2 ] = (b32 >> 8) & 0xff;
			 m_ptr[ m_length + 3 ] = b32 & 0xff;

			 m_length += 4;
		}
		
		void Append(uint64_t b64)
		{
			if ( m_length == m_capacity )
				___EnsureCopy(m_length + 8);

			 m_ptr[ m_length + 0 ] = b64 >> 56;
			 m_ptr[ m_length + 1 ] = (b64 >> 48) & 0xff;
			 m_ptr[ m_length + 2 ] = (b64 >> 40) & 0xff;
			 m_ptr[ m_length + 3 ] = (b64 >> 32) & 0xff;
			 m_ptr[ m_length + 4 ] = (b64 >> 24) & 0xff;
			 m_ptr[ m_length + 5 ] = (b64 >> 16) & 0xff;
			 m_ptr[ m_length + 6 ] = (b64 >> 8) & 0xff;
			 m_ptr[ m_length + 7 ] = b64 & 0xff;

			 m_length += 8;
		}

		size_t Length()
		{
			return m_length;
		}
		
		ByteArray ToArray() const
		{
			ByteType *ret = new ByteType[m_length];
			memcpy(ret, m_ptr, m_length);
			return ByteArray(ret, m_length);
		}

		void EnsureMore(size_t size)
		{
			___EnsureCopy(size + m_capacity);
		}

	private:
		
		void ___Append(const ByteType *wstr, size_t len)
		{
			if ( m_length + len > m_capacity )
			{
				___EnsureCopy(m_length + len);
			}
			
			memcpy(m_ptr + m_length, wstr, len);
			m_length += len;
		}

		void ___Ensure(size_t size)
		{
			m_ptr = new ByteType[size];
			m_capacity = size;
		}

		void ___EnsureCopy(size_t size)
		{
			if (size > m_capacity)
			{
				ByteType *tmp = m_ptr;
				___Ensure(size);
				memcpy(m_ptr, tmp, m_length);
				delete[] tmp;
			}
		}

	};

}

#endif