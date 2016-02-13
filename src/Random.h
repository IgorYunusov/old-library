/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Random.h

Purpose:

   RollRat Library

Author:

   10-11-2015:   HyunJun Jeong, Creation

***/

#ifndef _RANDOM_9bf1541fdf7efd41b7b39543fd870ac4_
#define _RANDOM_9bf1541fdf7efd41b7b39543fd870ac4_

#include <random>
#include <cmath>
#include <vector>

namespace Utility {

	//
	//	요소들이 중복되지않은 Random vector를 생성합니다.
	//
	class Random
	{
	public:

		using rand_type = unsigned long long;

		Random(
			rand_type lvalue,
			rand_type rvalue
			)
		{
			unsigned long long size = rvalue - lvalue + 1;
			std::random_device rd;
			std::mt19937_64 rnd(rd());
			std::vector<bool> _overlap_check(size);

			for (rand_type i = 0; i < size; i++)
			{
				do {
					rand_type real = rnd() % size + lvalue;
					if (!_overlap_check[real - lvalue])
					{
						m_vec.push_back(real);
						_overlap_check[real - lvalue] = true;
						break;
					}
				} while (true);
			}

		}

		inline rand_type operator[](rand_type index) const
		{
			return m_vec[index];
		}

		rand_type* ToArray()
		{
			rand_type *array = new rand_type[m_vec.size()];
			for (rand_type i = 0; i < m_vec.size(); i++)
				array[i] = m_vec[i];
			return array;
		}

		inline rand_type size() const
		{
			return m_vec.size();
		}

	private:

		std::vector<rand_type> m_vec;


	};

}

#endif