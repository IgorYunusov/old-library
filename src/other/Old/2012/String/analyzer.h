/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_CUTILITYEX_
#define _ROLLRAT_CUTILITYEX_

#include "rutil.h"
#if defined(_EX_SUCCESS)

_X_LIB_BEGIN

	template<class _Ty> 
		class _custom_analyzer
		{
		public:

			void Add(_Ty item)
				{
				AddVector(item);
				}

		private:

			void CreateNewVectorSystem()
				{
				items = new _Ty[0];
				flkhost = 0;
				}

			void AddVector(_Ty item)
				{
				Growup();
				items[flkhost] = item;
				}

			void Growup()
				{
				_Ty buf = new _Ty[++flkhost];
				for(unsigned long long n = 0; n < flkhost; n++)buf[n] = items[n];
				items = buf;
				}

		private:


			unsigned long long flkhost;

			_Ty* items;

		};

_X_LIB_END


#endif

#endif