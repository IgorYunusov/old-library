/*************************************************************************
  
   Copyright (C) 2015. rollrat. All Rights Reserved.

------
FILE NAME:
   
   sort.h - [Private]

Project:

   RollRat Eval
   
Abstract:

   Sorting Algorithm

------
   AUTHOR: HyunJun Jeong  2015-01-29

***************************************************************************/

#ifndef _EVAL_SORT_
#define _EVAL_SORT_

#include "type.h"

BOOL EvalCompareString(const char *s1, const char *s2, size_t size);

void EvalQuickSort(void *ptr, size_t n_array, size_t size, int(*compare)(const void *, const void *));
void EvalInsertSort(void *ptr, size_t n_array, size_t size, int(*compare)(const void *, const void *));
int EvalInternalCompareString(const void *s1, const void *s2);

#endif