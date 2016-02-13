/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   algorithm.c

Project:

   Paper Project

------
   AUTHOR: HyunJun Jeong  2015-04-25

***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <conio.h>
#include "algorithm.h"


// 기본 함수 인자 형식 : int array[], int size

/***
	swap:
	두 포인터의 값을 서로 바꿉니다.
***/
void swap(char *left, char *right)
{
	char *tmp = (char *)*left;
	*left = *right;
	*right = tmp;
}

/***
	sort_selection:
	선택 정렬 알고리즘
***/
void sort_selection(int array[], int size)
{
	int i, j;
	int min;

	//
	//	모든 실험에서 대체적으로 낮은 처리속도를 보이는
	//	알고리즘이다. 효율성이 매우 떨어진다.
	//
	for(i = 0; i < size - 1; i++) {

		//
		//	최소값의 초기설정 오프셋이다.
		//	이 값은 요소배열에 제일 앞에 높이게 된다.
		//
		min = i;

		//
		//	배열을 순회하며 min보다 낮은 배열이 없는지 검사한다. 
		//	만약 그러한 배열 요소가 있다면 min을 그것으로 덮어씌운다.
		//
		for (j = i + 1; j < size; j++) {

			//
			//	최솟값 발견 조건
			//
			if (array[j] < array[min])
				min = j;
		}
		swap(&(array[min]), &(array[i]));
	}

	/*
		너무 느리니 천 개이상의 크기를 가진 배열에선 절대로 적합하지 아니함
	*/
}

/***
	sort_insertion:
	삽입 정렬 알고리즘
***/
void sort_insertion(int array[], int size)
{
	int i, j, t;

	//
	//	순행배열에서 가장 빠른 속도를 보이는
	//	알고리즘이다.
	//
	for (i = 1; i < size; i++) {
		t = array[i];
		j = i;

		//
		//	임시값이 삽입될 위치를 현재 처음부터 오프셋까지
		//	찾아서 j에 넣는다.
		//
		while(array[j-1] > t && j > 0) {

			//
			//	배열 요소를 한 칸씩 뒤로 옮김
			//
			array[j] = array[j - 1];
			j--;
		}
		array[j] = t;
	}
}

/***
	sort_bubble:
	거품 정렬 알고리즘
***/
void sort_bubble(int array[], int size)
{
	int i, j, thres;
	
	//
	//	순행배열에서 삽입정렬 다음으로 빠른 속도를 
	//	보이는 알고리즘으로 배열이 배열되었는지 
	//	확인하는 용도로 적합함
	//
	for (i = 0; i < size - 1; i++) {
		thres = 1;
		for (j = 1; j < size - i; j++)
			if (array[j] < array[j - 1]) {
				swap(&(array[j]), &(array[j - 1]));
				thres = 0;
			}
		if (thres) return;
	}
}

/***
	sort_shell:
	쉘 정렬 알고리즘
***/
void sort_shell(int array[], int size)
{
	int i, j, h, temp, lens;

	//
	//	모든 조건에서 중간정도의 처리 
	//	속도를 가지는 알고리즘이다.
	//
	for (h = 1; h < size; h = 3 * h + 1)
		;	// Robert Sedgewick's Recurrence relation
	for (h /= 3; h > 0; h /= 3)
		for (i = 0; i < h; i++)
			for(j = i + h; j < size; j += h) {
				temp = array[j];
				lens = j;
				while (lens > lens - 1 && array[lens - h] > temp)
					lens[array] = (lens - h)[array], lens -= h;
				array[lens] = temp;
			}
}

/***
	sort_quick0:
	퀵 정렬 알고리즘
***/
void sort_quick0(int array[], int size)
{
	int i, j, pivot;

	//
	//	매우 빠름
	//
	if (size <= 1)
		return;
	pivot = array[size - 1];
	i = -1;
	j = size - 1;
	while(1) {
		while (array[++i] < pivot)
			;
		while (array[--j] > pivot)
			;
		if (i >= j)
			break;
		swap(&(array[i]), &(array[j]));
	}
	swap(&(array[i]), &(array[size - 1]));
	sort_quick0(array, i);
	sort_quick0(array + i + 1, size - i - 1);
}

/***
	sort_quick1:
	퀵 정렬 알고리즘 (non-recusive)
***/
void sort_quick1(int array[], int size)
{
	int ptrstk[100];
	int stkptr, i, j, pivot, left, right;
	
	//
	//	다소 느림
	//

	stkptr = -1;
	
	left = 0;
	right = size - 1;

	ptrstk[++stkptr] = right;
	ptrstk[++stkptr] = left;

	while(stkptr >= 0) {
		left = ptrstk[stkptr--];
		right = ptrstk[stkptr--];
		if (right <= left)
			continue;
		pivot = array[right];
		i = left - 1;
		j = right;
		while(1) {
			while (array[++i] < pivot)
				;
			while (array[--j] > pivot)
				;
			if (i >= j)
				break;
			swap(&(array[i]), &(array[j]));
		}
		swap(&(array[i]), &(array[right]));
		ptrstk[++stkptr] = right;
		ptrstk[++stkptr] = i + 1;
		ptrstk[++stkptr] = i - 1;
		ptrstk[++stkptr] = left;
	}
}

/***
	sort_quick2:
	퀵 정렬 알고리즘 (random)
***/
void sort_quick2(int array[], int size)
{
	/**
		이 코드엔 문제가 있습니다.
	**/
	int ptrstk[100];
	int stkptr, i, j, pivot, left, right, random;

	srand(time(NULL));

	stkptr = -1;
	
	left = 0;
	right = size - 1;

	ptrstk[++stkptr] = right;
	ptrstk[++stkptr] = left;

	while(stkptr >= 0) {
		left = ptrstk[stkptr--];
		right = ptrstk[stkptr--];
		if (right <= left)
			continue;
		random = rand() % (right - left + 1);//(int)((right-left+1) * rand() / (RAND_MAX + 1)) + left;
		pivot = array[random];
		swap(&(array[random]), &(array[right]));
		i = left - 1;
		j = right;
		while(1) {
			while (array[++i] < pivot)
				;
			while (array[--j] > pivot)
				;
			if (i >= j)
				break;
			swap(&(array[i]), &(array[j]));
		}
		swap(&(array[i]), &(array[right]));
		ptrstk[++stkptr] = right;
		ptrstk[++stkptr] = i + 1;
		ptrstk[++stkptr] = i - 1;
		ptrstk[++stkptr] = left;
	}
}

/***
	sort_quick3:
	퀵 정렬 알고리즘 (partion)
***/
void sort_quick3(int array[], int size)
{
	/**
		이 코드엔 문제가 있습니다.
	**/
	int ptrstk[100];
	int stkptr, i, j, pivot, left, right, random;

	srand(time(NULL));

	stkptr = -1;
	
	left = 0;
	right = size - 1;

	ptrstk[++stkptr] = right;
	ptrstk[++stkptr] = left;

	while(stkptr >= 0) {
		left = ptrstk[stkptr--];
		right = ptrstk[stkptr--];
		if (right - left <= 150)
			sort_insertion(array + left, right - left + 1);
		else {
			random = rand() % (right - left + 1);//(int)((right-left+1) * rand() / (RAND_MAX + 1)) + left;
			
			pivot = array[random];
			swap(&(array[random]), &(array[right]));
			i = left - 1;
			j = right;
			while(1) {
				while (array[++i] < pivot)
					;
				while (array[--j] > pivot)
					;
				if (i >= j)
					break;
				swap(&(array[i]), &(array[j]));
			}
			swap(&(array[i]), &(array[right]));
			ptrstk[++stkptr] = right;
			ptrstk[++stkptr] = i + 1;
			ptrstk[++stkptr] = i - 1;
			ptrstk[++stkptr] = left;
		}
	}
}

/***
	sort_quick4:
	퀵 정렬 알고리즘 (mid average value)
***/
void sort_quick4(int array[], int size)
{
	/**
		이 코드엔 문제가 있습니다.
	**/
	int ptrstk[100];
	int stkptr, i, j, pivot, left, right, mid;

	stkptr = -1;
	
	left = 0;
	right = size - 1;

	ptrstk[++stkptr] = right;
	ptrstk[++stkptr] = left;

	while(stkptr >= 0) {
		left = ptrstk[stkptr--];
		right = ptrstk[stkptr--];
		if (right - left <= 150)
			sort_insertion(array + left, right - left + 1);
		else {
			mid = (right + 1) >> 1; // divide by 2
			if (array[left] > array[mid])
				swap(&(array[left]), &(array[mid]));
			if (array[left] > array[right])
				swap(&(array[left]), &(array[right]));
			if (array[mid] > array[right])
				swap(&(array[mid]), &(array[right]));
			pivot = array[mid];
			swap(&(array[mid]), &(array[right - 1]));
			i = left;
			j = right - 1;
			while(1) {
				while (array[++i] < pivot)
					;
				while (array[--j] > pivot)
					;
				if (i >= j)
					break;
				swap(&(array[i]), &(array[j]));
			}
			swap(&(array[i]), &(array[right]));
			ptrstk[++stkptr] = right;
			ptrstk[++stkptr] = i + 1;
			ptrstk[++stkptr] = i - 1;
			ptrstk[++stkptr] = left;
		}
	}
}


/***
	sort_radix:
	기수 정렬 알고리즘 http://rosettacode.org/wiki/Sorting_algorithms/Radix_sort
***/
typedef unsigned uint;
#define swap(a, b) { tmp = a; a = b; b = tmp; }
#define each(i, x) for (i = 0; i < x; i++)
 
/* sort unsigned ints */
static void rad_sort_u(uint *from, uint *to, uint bit)
{
	if (!bit || to < from + 1) return;
 
	uint *ll = from, *rr = to - 1, tmp;
	while (1) {
		/* find left most with bit, and right most without bit, swap */
		while (ll < rr && !(*ll & bit)) ll++;
		while (ll < rr &&  (*rr & bit)) rr--;
		if (ll >= rr) break;
		swap(*ll, *rr);
	}
 
	if (!(bit & *ll) && ll < to) ll++;
	bit >>= 1;
 
	rad_sort_u(from, ll, bit);
	rad_sort_u(ll, to, bit);
}
 
/* sort signed ints: flip highest bit, sort as unsigned, flip back */
void radix_sort(int *a, const size_t len)
{
	size_t i;
	uint *x = (uint*) a;
 
	each(i, len) x[i] ^= INT_MIN;
	rad_sort_u(x, x + len, INT_MIN);
	each(i, len) x[i] ^= INT_MIN;
}



/***
	sort_bucket:
	버킷 정렬 알고리즘
***/
void sort_bucket(int array[], int size, int *count)
{
	/**
		이 코드엔 문제가 있습니다.
	**/
	int i, j = 0;
	for (i = 0; i < size; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 0; i < size; i++)
	{
		for (; count[i] > 0; count[i]--)
		{
			array[j++] = i;
		}
	}
}


/***
	sort_heap:
	힙 정렬 알고리즘
***/
static void _internal_heap_down(int array[], int c_node, int i)
{
	int k, t;
	t = array[i];
	while(i <= c_node >> 1) {
		k = i << 1;
		if (k < c_node && array[k] < array[k+1])
			k++;
		if (t >= array[k])
			break;
		array[i] = array[k];
		i = k;
	}
	array[i] = t;
}

static void _interanl_heap_up(int array[], int i)
{
	int t;
	t = array[i];
	0[array] = INT_MAX;
	while(array[i >> 1] <= t) {
		array[i] = array[i >> 1];
		i >>= 1;
	}
	array[i] = t;
}

static void _internal_heap_insert(int array[], int *c_node, int i)
{
	array[++*c_node] = i;
	_interanl_heap_up(array, *c_node);
}

static int _internal_heap_extract(int array[], int *c_node)
{
	int k = array[1];
	array[1] = array[(*c_node)--];
	_internal_heap_down(array, *c_node, 1);
	return k;
}

void sort_heap(int array[], int size)
{
	int i, c_node;

	//
	//	모든 상태에서 매우 빠른 속도를 보이고, 
	//	특정 부분에선 가장 최고의 처리속도를 보여준다.
	//
	c_node = 0;
	for (i = 1; i <= size; i++)
		_internal_heap_insert(array, &c_node, array[i]);
	for (i = c_node; i >= 1; i--)
		array[i] = _internal_heap_extract(array, &c_node);
}


/***
	sort_merge:
	병합 정렬 알고리즘
***/
void sort_merge(int array[], int size, int *count)
{
	int f, s, scope, i ,j, k;
	
	//
	//	다소 느림
	//
	for(scope = 1; scope < size; scope *= 2) {
		f = -2 * scope;
		s = f + scope;
		while ( s + scope * 2 < size) {
			f = s + scope;
			s = f + scope;
			i = f;
			j = s;
			k = f;
			while (i < f + scope || (j < s + scope && j < size)) {
				if (array[i] <= array[j]) {
					if (i < f + scope)
						count[k++] = array[i++];
					else
						count[k++] = array[j++];
				} else {
					if (j < s + scope && j < size)
						count[k++] = array[j++];
					else
						count[k++] = array[i++];
				}
			}
		}
		for (i = 0; i < size; i++)
			array[i] = count[i];
	}
}

#define W 16
#define M 4
#define MV (1 << M)

unsigned bits(unsigned x, int k, int j)
{
	return (x >> k) & ~(~0 << j);
}

void stratight_radix_Sort(char a[], int n)
{
	int i, j;
	int *b, *count;
	b = (int *)malloc(sizeof(int)*n);
	count = (int *)malloc(sizeof(int)*MV);
	for(i = 0; i < W/M; i++) {
		for (j = 0; j < MV; j++)
			count[j] = 0;
		for (j = 0; j < n; j++)
			count[bits(a[j], i*M, M)]++;
		for (j = 1; j < MV; j++)
			count[j] = count[j] + count[j - 1];
		for (j = n - 1; j >= 0; j--)
			b[--count[bits(a[j], i*M, M)]] = a[j];
		for (j = 0; j < n; j++)
			a[j] = b[j];
	}
	free(b);
	free(count);
}

