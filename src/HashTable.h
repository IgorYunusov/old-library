/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   HashTable.h

Purpose:

   RollRat Library

Author:

   11-26-2015:   HyunJun Jeong, Creation

***/

#ifndef _HASHTABLE_9bf1541fdf7efd41b7b39543fd870ac4_
#define _HASHTABLE_9bf1541fdf7efd41b7b39543fd870ac4_

#include "WString.h"
#include "List.h"

namespace Utility {
	
	template<typename data_type, typename key_type, size_t capacity>
	class HashTable
	{
		struct HashNode
		{
			data_type data;
			key_type  key;

			HashNode(const data_type& dt, const key_type& kt)
				: data(dt), key(kt)
			{
			}

		};

		List<HashNode *>   m_list[capacity];

	public:
		
		void Append(const data_type& data, const key_type& key, size_t hash)
		{
			m_list[hash % capacity].Append(new HashNode(data, key));
		}

		data_type Get(const key_type& key, size_t hash)
		{
			data_type dt = data_type();

			m_list[hash % capacity].EachBreak([&] (const HashNode* hn) -> bool
			{
				if (hn->key == key)
				{
					dt = hn->data;
					return true;
				}
				return false;
			});

			return dt;
		}

	};
	
	template<typename data_type, size_t capacity>
	class HashTable<data_type, WString, capacity>
	{
		struct HashNode
		{
			data_type data;
			WString  key;

			HashNode(const data_type& dt, const WString& kt)
				: data(dt), key(kt)
			{
			}

		};

		List<HashNode *>   m_list[capacity];

	public:
		
		void Append(const data_type& data, const WString& key)
		{
			m_list[key.Hash() % capacity].Append(new HashNode(data, key));
		}

		data_type Get(const WString& key)
		{
			data_type dt = data_type();

			m_list[key.Hash() % capacity].EachBreak([&] (const HashNode* hn) -> bool
			{
				if (hn->key == key)
				{
					dt = hn->data;
					return true;
				}
				return false;
			});

			return dt;
		}

	};
}

#endif