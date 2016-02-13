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


// �⺻ �Լ� ���� ���� : int array[], int size

/***
	swap:
	�� �������� ���� ���� �ٲߴϴ�.
***/
void swap(char *left, char *right)
{
	char *tmp = (char *)*left;
	*left = *right;
	*right = tmp;
}

/***
	sort_selection:
	���� ���� �˰���
***/
void sort_selection(int array[], int size)
{
	int i, j;
	int min;

	//
	//	��� ���迡�� ��ü������ ���� ó���ӵ��� ���̴�
	//	�˰����̴�. ȿ������ �ſ� ��������.
	//
	for(i = 0; i < size - 1; i++) {

		//
		//	�ּҰ��� �ʱ⼳�� �������̴�.
		//	�� ���� ��ҹ迭�� ���� �տ� ���̰� �ȴ�.
		//
		min = i;

		//
		//	�迭�� ��ȸ�ϸ� min���� ���� �迭�� ������ �˻��Ѵ�. 
		//	���� �׷��� �迭 ��Ұ� �ִٸ� min�� �װ����� ������.
		//
		for (j = i + 1; j < size; j++) {

			//
			//	�ּڰ� �߰� ����
			//
			if (array[j] < array[min])
				min = j;
		}
		swap(&(array[min]), &(array[i]));
	}

	/*
		�ʹ� ������ õ ���̻��� ũ�⸦ ���� �迭���� ����� �������� �ƴ���
	*/
}

/***
	sort_insertion:
	���� ���� �˰���
***/
void sort_insertion(int array[], int size)
{
	int i, j, t;

	//
	//	����迭���� ���� ���� �ӵ��� ���̴�
	//	�˰����̴�.
	//
	for (i = 1; i < size; i++) {
		t = array[i];
		j = i;

		//
		//	�ӽð��� ���Ե� ��ġ�� ���� ó������ �����±���
		//	ã�Ƽ� j�� �ִ´�.
		//
		while(array[j-1] > t && j > 0) {

			//
			//	�迭 ��Ҹ� �� ĭ�� �ڷ� �ű�
			//
			array[j] = array[j - 1];
			j--;
		}
		array[j] = t;
	}
}

/***
	sort_bubble:
	��ǰ ���� �˰���
***/
void sort_bubble(int array[], int size)
{
	int i, j, thres;
	
	//
	//	����迭���� �������� �������� ���� �ӵ��� 
	//	���̴� �˰������� �迭�� �迭�Ǿ����� 
	//	Ȯ���ϴ� �뵵�� ������
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
	�� ���� �˰���
***/
void sort_shell(int array[], int size)
{
	int i, j, h, temp, lens;

	//
	//	��� ���ǿ��� �߰������� ó�� 
	//	�ӵ��� ������ �˰����̴�.
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
	�� ���� �˰���
***/
void sort_quick0(int array[], int size)
{
	int i, j, pivot;

	//
	//	�ſ� ����
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
	�� ���� �˰��� (non-recusive)
***/
void sort_quick1(int array[], int size)
{
	int ptrstk[100];
	int stkptr, i, j, pivot, left, right;
	
	//
	//	�ټ� ����
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
	�� ���� �˰��� (random)
***/
void sort_quick2(int array[], int size)
{
	/**
		�� �ڵ忣 ������ �ֽ��ϴ�.
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
	�� ���� �˰��� (partion)
***/
void sort_quick3(int array[], int size)
{
	/**
		�� �ڵ忣 ������ �ֽ��ϴ�.
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
	�� ���� �˰��� (mid average value)
***/
void sort_quick4(int array[], int size)
{
	/**
		�� �ڵ忣 ������ �ֽ��ϴ�.
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
	��� ���� �˰��� http://rosettacode.org/wiki/Sorting_algorithms/Radix_sort
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
	��Ŷ ���� �˰���
***/
void sort_bucket(int array[], int size, int *count)
{
	/**
		�� �ڵ忣 ������ �ֽ��ϴ�.
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
	�� ���� �˰���
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
	//	��� ���¿��� �ſ� ���� �ӵ��� ���̰�, 
	//	Ư�� �κп��� ���� �ְ��� ó���ӵ��� �����ش�.
	//
	c_node = 0;
	for (i = 1; i <= size; i++)
		_internal_heap_insert(array, &c_node, array[i]);
	for (i = c_node; i >= 1; i--)
		array[i] = _internal_heap_extract(array, &c_node);
}


/***
	sort_merge:
	���� ���� �˰���
***/
void sort_merge(int array[], int size, int *count)
{
	int f, s, scope, i ,j, k;
	
	//
	//	�ټ� ����
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

