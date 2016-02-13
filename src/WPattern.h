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
	//	���ڿ� �������� ���ڿ��� �����մϴ�.
	//
	class WPattern
	{
	public:
		/*
		
			�����

			escape: '\' �� ���� ������ ������ ���ڷ� ��޵Ǿ�
			���Ͽϼ���ҿ� ���Եȴ�.
			���ĺ� �� r, n, b�� ���� \r, \n, \b�� ����Ѵ�.

			����ó������ �Ű澲�� �ʾ����� �˾Ƽ� ó���Ұ�

			Ƚ�� ����: �� ������ ���� �� �տ� �־���Ѵ�.
			{} �Ǵ� ����: word�� ���� �˾Ƽ� ��½�Ų��.
			{1}: �� ���� ����Ѵ�. ��, �� �ٸ� ��µȴ�.
			{<name>-val}: name�� val�� �ɶ����� ����Ѵ�.
			 �̴� �ִ� 256�� ������ ����Ѵ�.

			[word]|[word=>num] : ���� Ű����. �⺻ ������ 0���� �����Ѵ�.
			1. ��������: [1]�� [1+]�� ���� ���� �ϳ��� �� ��쿣 �� 
			���ں��� ������ ���۵ȴ�. �� �������� 1���� ���۵ȴ�.
			[1+2]��� ������ 2�� ������Ű�� ����Ѵ�.
			Ư�� [a]�� a��� ���ڸ� ������Ų��. a������ b
			2. ���ҹ���: [1-]�� 1���� ������ ���ҽ�Ű�� �����Ѵ�.
			[1-2]�� 2�� ���ҽ�Ű�� �����Ѵ�. ���ڵ� ������� ����.
			3. ��������: �⺻ ������ 10���� �̴�.
			[1+o]�� 8���� [1+b]�� 2���� [1+x]�� 16������ ���� ����Ѵ�.
			4. ��¹���: [123=>1]�� ���� Ű����� 123�� �ݺ��Ͽ�
			����Ѵ�. ó���� 1���� ������ 123123���� 2���� ��½�Ų��.
			�̴� ���鵵 �����Ͽ� ����Ѵ�.

			(num,l/r,g) : ���� ����Ű����
			num�� �� ����, l/r �� �ϳ��� �����ϴµ� l�� �������� ���߰�,
			r�� ���������� �����. g�� ��Ÿ �������� ������ �ȴ�.

			<name> : '('�� '['���� <s1>[1]�� ���� ������
			Ƚ�� ������ ������ �ش�.

		*/
		struct _a
		{
			 // 0: str 1: ���� ���� 2: ���� ���ڿ� 3: ���� ���� 4 : ���� ������
			int type;

			// ���� Ű���忡�� ���
			int sz;   // ����ũ��
			int sVal;
			int radix;

			// ���� ����
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