/***

   RollRat Software Project.
   Copyright (C) 2015. rollrat. All Rights Reserved.

File name:
   
   WPattern.h

Purpose:

   RollRat Library

Author:

   11-18-2015:   HyunJun Jeong, Creation

***/

#ifndef _WPATTERN_9bf1541fdf7efd41b7b39543fd870ac4_
#define _WPATTERN_9bf1541fdf7efd41b7b39543fd870ac4_

#include "WStringBuilder.h"
#include "List.h"

namespace Utility {

	//
	//	문자열 패턴으로 문자열을 생성합니다.
	//
	class WPattern
	{
	public:
		/*
		
			사용방법

			escape: '\' 이 문자 다음은 무조건 문자로 취급되어
			패턴완성요소에 삽입된다.
			알파벳 중 r, n, b는 각각 \r, \n, \b를 출력한다.

			오류처리따윈 신경쓰지 않았으니 알아서 처리할것

			횟수 설정: 이 설정은 구문 맨 앞에 있어야한다.
			{} 또는 없음: word에 따라 알아서 출력시킨다.
			{1}: 한 번만 출력한다. 즉, 한 줄만 출력된다.
			{<name>-val}: name이 val가 될때까지 출력한다.
			 이는 최대 256번 까지만 출력한다.

			[word]|[word=>num] : 증감 키워드. 기본 설정은 0부터 시작한다.
			1. 증가문법: [1]나 [1+]와 같이 숫자 하나가 들어간 경우엔 그 
			숫자부터 증가가 시작된다. 이 예제에선 1부터 시작된다.
			[1+2]라는 구문은 2씩 증가시키며 출력한다.
			특히 [a]는 a라는 문자를 증가시킨다. a다음은 b
			2. 감소문법: [1-]는 1부터 시작해 감소시키며 삽입한다.
			[1-2]는 2씩 감소시키며 삽입한다. 문자도 사용방법은 같다.
			3. 진법설정: 기본 설정은 10진수 이다.
			[1+o]는 8진수 [1+b]는 2진수 [1+x]는 16진수로 각각 출력한다.
			4. 출력문법: [123=>1]와 같은 키워드는 123을 반복하여
			출력한다. 처음엔 1개를 다음엔 123123같이 2개를 출력시킨다.
			이는 공백도 포함하여 출력한다.

			(num,l/r,g) : 공백 세팅키워드
			num은 총 길이, l/r 중 하나만 선택하는데 l은 왼쪽으로 맞추고,
			r은 오른쪽으로 맞춘다. g는 여타 문법들을 적으면 된다.

			<name> : '('나 '['전에 <s1>[1]와 같이 적으면
			횟수 설정에 영향을 준다.

		*/
		struct _a
		{
			 // 0: str 1: 증감 숫자 2: 증감 문자열 3: 공백 왼쪽 4 : 공백 오른쪽
			int type;

			// 증감 키워드에서 사용
			int sz;   // 증감크기
			int sVal;
			int radix;

			// 공백 길이
			int len;
			int rl;
			List<struct _a> g;
			WString str;
		};

		const wchar_t *p_ptr;

		List<struct _a> list;
		struct _a *list2array;

		WPattern(const WString& pattern)
			: p_ptr(pattern.Reference())
		{
		}

		WString Get()
		{
			ScanStart();
			return Establish();
		}


	private:

		void ScanStart()
		{
		}

		WString Establish()
		{
		}

	};

}

#endif