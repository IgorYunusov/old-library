/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   Parameter.h

Purpose:

   RollRat Library

Author:

   11-16-2015:   HyunJun Jeong, Creation

***/

#ifndef _PARAMETER_9bf1541fdf7efd41b7b39543fd870ac4_
#define _PARAMETER_9bf1541fdf7efd41b7b39543fd870ac4_

#include "WString.h"

namespace Utility {

	//
	//	�����Լ��� �Ű������� �ս��� ã�� �޼��带 �����մϴ�.
	//
	class Parameter
	{

		static bool Exist(int argc, char *argv[], WString refer)
		{
			for (int i = 1; i < argc; i++)
			{
				if (refer.Equal(argv[i]))
				{
					return true;
				}
			}
			return false;
		}

		static bool Exist(int argc, char *argv[], WString refer[])
		{
			for (int i = 1; i < argc; i++)
			{
				for (int j = 0; j < sizeof(refer); j++)
				{
					if (refer[j].Equal(argv[i]))
					{
						return true;
					}
				}
			}
			return false;
		}

		static WString Get(int argc, char *argv[], WString refer)
		{
			for (int i = 1; i < argc; i++)
			{
				if (refer.Equal(argv[i]))
				{
					return argv[i + 1];
				}
			}
			return L"";
		}

		static bool Exist(int argc, char *argv[], const char *cmp)
		{
			for (int i = 1; i < argc; i++)
			{
				if (!strcmp(cmp, argv[i]))
				{
					return true;
				}
			}
			return false;
		}
		
		static bool Exist(int argc, char *argv[], const char *cmp[])
		{
			for (int i = 1; i < argc; i++)
			{
				for (int j = 0; j < sizeof(cmp) / sizeof(char *); j++)
				{
					if (!strcmp(cmp[j], argv[i]))
					{
						return true;
					}
				}
			}
			return false;
		}
		
		static const char *Get(int argc, char *argv[], const char *cmp)
		{
			for (int i = 1; i < argc; i++)
			{
				if (!strcmp(cmp, argv[i]))
				{
					return argv[i + 1];
				}
			}
			return 0;
		}

	};

}

#endif