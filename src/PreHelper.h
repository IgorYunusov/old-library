/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   PreHelper.h

Purpose:

   RollRat Library

Author:

   10-08-2015:   HyunJun Jeong, Creation

***/

#ifndef _PREHELPER_9bf1541fdf7efd41b7b39543fd870ac4_
#define _PREHELPER_9bf1541fdf7efd41b7b39543fd870ac4_

#define _Create_Enum_Or_(type) \
	type operator|(type x, type y)\
	{\
		return static_cast<type> \
			 ( static_cast<int> (x) | static_cast<int> (y) );\
	}\
	type operator|=(type& x, type y)\
	{\
		return x = x | y;\
	}\
	type operator^(type x, type y)\
	{\
		return static_cast<type> \
			(~((~(static_cast<int> (x))) & static_cast<int> (y)));\
	}

#define _Create_Enum_Or_Def_(type) \
	type operator|(type, type);\
	type operator|=(type&, type);\
	type operator^(type, type);

#define STRUCTURE_SIZE_OF(ptr)		sizeof(ptr)/sizeof(ptr[0])

#endif