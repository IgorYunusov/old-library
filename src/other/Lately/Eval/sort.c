/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   sort.c - [Private]

Project:

   RollRat Eval
   
Abstract:

   Sorting Algorithm, String Algorithm

------
   AUTHOR: HyunJun Jeong  2015-01-29

***************************************************************************/

#include <memory.h>
#include "sort.h"
#include "rocket.h"

#include <stdlib.h>

#define _LEAK_TEST
#include "leak.h"

/*
	@����: �� ���ڿ��� ���մϴ�.
	@ptr [IN] : �м��� ���ڿ��� ������
	-
	@return: 0, 1
*/
BOOL EvalCompareString(const char *s1, const char *s2, size_t size)
{
	if (s1 == s2)
		return TRUE;

	while ( size >= 16 )
	{
		if( *(DWORD *)s1 != *(DWORD *)s2 )
			return FALSE;
		if( *(DWORD *)(s1 + 4) != *(DWORD *)(s2 + 4) )
			return FALSE;
		if( *(DWORD *)(s1 + 8) != *(DWORD *)(s2 + 8) )
			return FALSE;
		if( *(DWORD *)(s1 + 12) != *(DWORD *)(s2 + 12) )
			return FALSE;
		s1 += 16;
		s2 += 16;
		size -= 16;
	}

	while ( size >= 4 )
	{
		if( *(DWORD *)s1 != *(DWORD *)s2 )
			break;
		s1 += 4;
		s2 += 4;
		size -= 4;
	}

	if(size == 3) {
		if ( *s1 != *s2 )
			return FALSE;
		size--;
	}
	if(size == 2) {
		if( *(DWORD *)s1 != *(DWORD *)s2 )
			return FALSE;
		size -= 2;
	} else if (size == 1) {
		if( *s1 != *s2 )
			return FALSE;
	}

	return size <= 0;
}

/*
	@����: ������ ũ���� �� �迭�� ���� ġȯ�մϴ�.
	@ptr [IN] : ���ڿ��� �迭
	-
*/
static void EvalInternalSortSwaping(char *a1, char *a2, size_t size)
{
	if ( a1 != a2 ) {

		//char *stmp = (char *)malloc(size);
		//memcpy(stmp, a2, size);
		//memcpy(a2, a1, size);
		//memcpy(a1, stmp, size);

		for(; size; size--, a1++, a2++) {
			char s = *a1;
			*a1 = *a2;
			*a2 = s;
		}
	}
}

#define PUSH
#define POP

/*
	@����: Qucik���� �˰������� �����մϴ�. �� ����� Bubble���ĺ��� �����ϴ�.
	@ptr [IN] : ���ڿ��� �迭
	-
*/
void EvalQuickSort(void *ptr, size_t n_array, size_t size, int (*compare)(const void *, const void *))
{
#if defined(_DEBUG) || defined(DEBUG)
	char *left, *right, *middle;
	char *ltm, *rtm;
	char *stack[16];
	int stkptr, lft, rgt;

	left = (char *)ptr;
	right = (char *)ptr + size * (n_array - 1);
	stkptr = 0;

	PUSH stack[stkptr++] = right;
	PUSH stack[stkptr++] = left;

	while ( stkptr ) {
		POP ltm = left = stack[lft = --stkptr];
		POP rtm = right = stack[rgt = --stkptr];

		// ū ������ �� ���� �̿�
		if(rtm - ltm + 1 > 100) {

			middle = (((rtm - ltm) / size + 1) / 2) * size + ltm;

			if(compare(ltm, middle) > 0) {
				EvalInternalSortSwaping(ltm, middle, size);
			}
			if(compare(ltm, rtm) > 0) {
				EvalInternalSortSwaping(ltm, rtm, size);
			}
			if(compare(middle, rtm) > 0) {
				EvalInternalSortSwaping(middle, rtm, size);
			}

			//
			// ��ġ r-1
			//
			right = rtm -= size;

			//
			// middle�� r-1�� ġȯ
			//
			EvalInternalSortSwaping(middle, rtm, size);

			//
			// ������ �̿��Ͽ� ����
			//
			while (1) {
				while (compare(ltm = ltm + size, middle) < 0)
					;
				while (compare(rtm = rtm - size, middle) > 0)
					;
				if (ltm >= rtm)
					break;

				EvalInternalSortSwaping(ltm, rtm, size);
			}

			rtm = right;

			EvalInternalSortSwaping(ltm, rtm, size);

			PUSH stack[stkptr++] = rtm;
			PUSH stack[stkptr++] = ltm + size;
			PUSH stack[stkptr++] = ltm - size;
			PUSH stack[stkptr++] = ltm;
		} else {
			while(rtm > ltm) {
				middle = ltm;
				ltm += size;
				while (ltm <= rtm) {
					if (compare(ltm, rtm) > 0)
						middle = ltm;
					ltm += size;
				}

				EvalInternalSortSwaping(middle, rtm, size);

				rtm -= size;
			}
		}
	}
#else
	qsort(ptr, n_array, size, compare);
#endif
}

/*
	@����: Insert���� �˰������� �����մϴ�.
	@ptr [IN] : ���ڿ��� �迭
	-
*/
void EvalInsertSort(void *ptr, size_t n_array, size_t size, int (*compare)(const void *, const void *))
{
	char *ix=0, *jx=0;

	while (ix > jx) {

	}
}

/*
	@����: Bubble���� �˰������� �����մϴ�.
	@ptr [IN] : ���ڿ��� �迭
	-
*/
void EvalBubbleSort(void *ptr, size_t n_arry, size_t size, int (*compare)(const void *, const void *))
{
	size_t i, j;


}

int EvalInternalCompareString(const void *s1, const void *s2)
{
	return _strcmp_asc((char *)s1, (char *)s2);
}