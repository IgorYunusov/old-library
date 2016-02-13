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
	//	WSearch�� �ɼ��� ��Ÿ���ϴ�. (enum class x)
	//
	typedef enum _wsearch_op_
	{
		PerfectMatch = 1, // ������ ������ ��ġ�ϴ� ���� ���θ� �����ɴϴ�.
		PartialMatch = 2, // �κ����� �˻��� ��������� ���θ� �����մϴ�.
		AcceptError = 4,  // ������ �����Ͽ� �˻��� �������� ���θ� �����ɴϴ�.
		                  // �̴� PerfectMatch�� PartialMatch�� �����մϴ�.
	}	WSearchOption;

	//
	//	AcceptError�� ���� ���� �����Դϴ�.
	//	�� ������ �ߺ��� ��� ��� ������ ��ø�Ǿ� ���˴ϴ�.
	//
	typedef enum _wsearch_accept_sense_
	{
		/*
			��Ż�ڸ� �˻������� ���θ� �����մϴ�.
			
			Src�� Wost�� �����ϸ�
			���� ��찡 �Ϻ� ��ġ�� Ȯ���� ǥ��˴ϴ�.
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
			�ݺ��� ���ڸ� ���߾� �˻������� ���θ� �����մϴ�.
			
			�� ������ ��� �ߺ��� ���ڸ� �� ���ڷ� ġȯ�Ͽ� �˻��մϴ�.
			Src�� EEEWWWSSSNNN��� EWSN�� �˻��ϴ� �Ͱ� ������,
			Dest���� �׷��մϴ�.

			��ø�Ǿ� ������ ���� �ɼ��̶�� 0 %�� 100 %�� �ϳ��� ��µ˴ϴ�.
		*/
		RepeatTest = 2,

		/*
			¦ ������ �����Ͽ� �˻������� ���θ� �����մϴ�.
			(TypoOmit�� ��ø�Ǿ� ���˴ϴ�.)

			Src�� Wost�� �����ϸ�
			���� ��찡 �Ժ� ��ġ�� Ȯ���� ǥ��˴ϴ�.
			Wost : 100 %
			West :  75 %
			Wst  :  75 %
			Wttt :   0 % -
			tttt :   0 % - RepeatTest�� ���� ���ɰ�� ���� 50 %, 25 %
			t    :  25 %
			Ws   :  50 %
		*/
		PairMatch = 4,

		/*
			ù ���ڰ� ��ġ���� ������ �˻��� �����մϴ�.
		*/
		XFirst = 8,

		/*
			���ڿ��� ���̰� ��ġ���� ������ �˻��� �����մϴ�.
		*/
		XLength = 16,

	}	WSearchAcceptDetailOption;
	
	_Create_Enum_Or_Def_(WSearchOption)
	_Create_Enum_Or_Def_(WSearchAcceptDetailOption)

	//
	//	���ڿ� �˻� ���񽺸� �����մϴ�.
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