/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   WSearch.h

Purpose:

   RollRat Library

Author:

   11-14-2015:   HyunJun Jeong, Creation

***/

#ifndef _WSEARCH_9bf1541fdf7efd41b7b39543fd870ac4_
#define _WSEARCH_9bf1541fdf7efd41b7b39543fd870ac4_

#include "WString.h"
#include "PreHelper.h"

namespace Utility {
	
	//
	//	WSearch의 옵션을 나타냅니다. (enum class x)
	//
	typedef enum _wsearch_op_
	{
		PerfectMatch = 1, // 문장이 완전히 일치하는 지의 여부를 가져옵니다.
		PartialMatch = 2, // 부분적인 검색을 허용할지의 여부를 설정합니다.
		AcceptError = 4,  // 오차를 설정하여 검색할 것인지의 여부를 가져옵니다.
		                  // 이는 PerfectMatch와 PartialMatch를 포함합니다.
	}	WSearchOption;

	//
	//	AcceptError의 세부 설정 사항입니다.
	//	이 설정이 중복된 경우 모든 설정이 중첩되어 계산됩니다.
	//
	typedef enum _wsearch_accept_sense_
	{
		/*
			오탈자를 검색할지의 여부를 설정합니다.
			
			Src를 Wost라 설정하면
			다음 경우가 일부 일치의 확률로 표기됩니다.
			Wost : 100 %
			West :   0 %
			Wst  :  75 %
			Wttt :   0 %
			tttt :   0 %
			t    :  25 %
			Ws   :  50 %
		*/
		TypoOmit = 1,

		/*
			반복된 문자를 맞추어 검색할지의 여부를 설정합니다.
			
			이 설정은 모든 중복된 문자를 한 문자로 치환하여 검색합니다.
			Src가 EEEWWWSSSNNN라면 EWSN을 검색하는 것과 같으며,
			Dest또한 그러합니다.

			중첩되어 사용되지 않은 옵션이라면 0 %와 100 %중 하나가 출력됩니다.
		*/
		RepeatTest = 2,

		/*
			짝 맞춤을 적용하여 검색할지의 여부를 설정합니다.
			(TypoOmit와 중첩되어 사용됩니다.)

			Src를 Wost라 설정하면
			다음 경우가 입부 일치의 확률로 표기됩니다.
			Wost : 100 %
			West :  75 %
			Wst  :  75 %
			Wttt :   0 % -
			tttt :   0 % - RepeatTest와 같이 사용될경우 각각 50 %, 25 %
			t    :  25 %
			Ws   :  50 %
		*/
		PairMatch = 4,

		/*
			첫 문자가 일치하지 않으면 검색을 종료합니다.
		*/
		XFirst = 8,

		/*
			문자열의 길이가 일치하지 않으면 검색을 종료합니다.
		*/
		XLength = 16,

	}	WSearchAcceptDetailOption;
	
	_Create_Enum_Or_Def_(WSearchOption)
	_Create_Enum_Or_Def_(WSearchAcceptDetailOption)

	//
	//	문자열 검색 서비스를 제공합니다.
	//
	template<typename ptype = double>
	class WSearchBase
	{
		WSearchOption wso;
		WSearchAcceptDetailOption wsado;

	public:

		typedef ReadOnlyArray<WString *> WSearchArray;
		typedef ReadOnlyArray<ptype>     WSearchResult;

		WSearchBase(const WSearchArray& wsa, 
			WSearchOption wso = WSearchOption::AcceptError, 
			WSearchAcceptDetailOption wsado = WSearchAcceptDetailOption::PairMatch 
											| WSearchAcceptDetailOption::RepeatTest)
			: m_array(wsa)
			, wso(wso)
			, wsado(wsado)
		{
		}

		WSearchResult Search(const WString& wstr)
		{
		}

	private:

		WSearchResult CheckPerfectOnly(const WString& wstr)
		{
			ptype *p_result = new ptype[m_array.Size()];
			size_t count = 0;

			m_array.Each([] (const WString& refer)
			{
				p_result[count++] = (wstr == refer);
			}
			);

			return WSearchResult(p_result, count);
		}

		const WSearchArray m_array;

	};

}

#endif