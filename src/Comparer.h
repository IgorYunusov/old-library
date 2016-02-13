#if 0

/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Comparer.h

Purpose:

   RollRat Library

Author:

   11-06-2015:   HyunJun Jeong, Creation

***/

#ifndef _COMPARER_9bf1541fdf7efd41b7b39543fd870ac4_
#define _COMPARER_9bf1541fdf7efd41b7b39543fd870ac4_

namespace Utility {


	template<typename type>
	class ComparerBase
	{
		type *m_ptr;

	public:

		ComparerBase(type *ptr)
			: m_ptr(ptr)
		{
		}

	};

	template<typename type>
	class NormalComparer
	{


	};

}

#endif

#endif