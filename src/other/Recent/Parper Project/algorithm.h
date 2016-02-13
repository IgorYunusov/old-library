/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   algorithm.h

Project:

   Paper Project

------
   AUTHOR: HyunJun Jeong  2015-04-25

***************************************************************************/

#ifndef _ALGORITHM_33f7d454c2ca4152bcaf445452a3d572_
#define _ALGORITHM_33f7d454c2ca4152bcaf445452a3d572_

void sort_selection(int array[], int size);
void sort_insertion(int array[], int size);
void sort_bubble(int array[], int size);
void sort_shell(int array[], int size);
void sort_quick0(int array[], int size);
void sort_quick1(int array[], int size);
void sort_quick2(int array[], int size);
void sort_quick3(int array[], int size);
void sort_quick4(int array[], int size);
void radix_sort(int *a, const size_t len);
void sort_bucket(int array[], int size, int *count);
void sort_heap(int array[], int size);
void sort_merge(int array[], int size, int *count);

#endif