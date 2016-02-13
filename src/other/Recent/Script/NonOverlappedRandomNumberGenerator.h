/*************************************************************************

   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:

   NonOverlappedRandomNumberGenerator.h

Project:

	RollRat Non-Overlapping Random Number Array Generator

------
   AUTHOR: HyunJun Jeong  2015-08-15

***************************************************************************/

#ifndef _NONOVERLAPPED_66f2f2ac5722429e41e69b68ee40dd30_
#define _NONOVERLAPPED_66f2f2ac5722429e41e69b68ee40dd30_

#include <random>
#include <cmath>

class NonOverlappedRandomNumberGenerator {
public:

	typedef unsigned long long rand_type;

	NonOverlappedRandomNumberGenerator(
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

	rand_type operator[](rand_type index) const
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

	rand_type size() const
	{
		return m_vec.size();
	}

private:

	std::vector<rand_type> m_vec;

};

#endif