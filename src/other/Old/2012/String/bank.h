/*-------------------------------------------------

			RollRat Software Library

	Copyright (c) rollrat. All rights reserved.

-------------------------------------------------*/

#pragma once
#ifndef _ROLLRAT_BANK_
#define _ROLLRAT_BANK_

#include <iostream>
#include "rutil.h"

using namespace std;

#if defined(_EX_SUCCESS)


_X_LIB_BEGIN
	
	typedef unsigned long long ullong;

	class _X_Bank
	{
	public:

		_X_Bank(char* bankname)
			: banknamec(bankname), 
			count_deal(0), percent(0), 
			pointc(0), nowmoney(0)
			{
				cout << "Hi, welcome to " << bankname << " bank !!" << endl;
			}

		void SetPointPercent(float percentage)
			{
				percent = percentage;
				cout << "Set Percent Complete !" << endl;
			}

		ullong GetPoint() const
			{
				return pointc;
			}

		void GetPoint()
			{
				cout << "Now Point : " << pointc << endl;
			}

		float GetPointPercent() const
			{
				return percent;
			}

		void SavingMoney(ullong money)
			{
				nowmoney += money;
				pointc += (ullong)(money * (percent / 100));
				cout << "NowMoney : " << nowmoney << endl;
			}

		ullong FindMoney(ullong money)
			{
				if(nowmoney < money)
					throw 0;
				else
				{
					nowmoney -= money;
					cout << "FindMoney Successful : " << money << endl;
				}
			}

		void forcepointsaving(ullong point)
			{
				pointc += point;
			}

		void forcepointchange(ullong point)
			{
				pointc = point;
			}

	private:

		char* banknamec;
		float percent;
		ullong pointc;

		//------------log-------------
		unsigned int count_deal;
		ullong nowmoney;

	};


_X_LIB_END


#endif

#endif