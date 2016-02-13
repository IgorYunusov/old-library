/*************************************************************************
  
   RollRat Software Dynamic Adapter

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: connectome.h
                         Abstract: Related with neuro network
                         Creation: 2015-04-05
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _DA_a0aed4414444238b9f47eb60e0e73fa7_
#define _DA_a0aed4414444238b9f47eb60e0e73fa7_

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <math.h>
#include "matrix.h"

/*======================================================

	Structure: Eigen

	이 구조체는 고유벡터와 고유값 각각 하나 씩 가진 구조체
	입니다. 또한 이 구조체는 Connectome의 매개체로 작용하며
	그 이상의 의미는 부여되지 않았습니다.

======================================================*/
typedef struct _DA_ee640aa26bf58f3e13adf70b69a3a93d_ {
	PMatrix vector;
	double value;
}	Eigen, *PEigen;



#ifdef __cplusplus
extern "C" {
#endif


	
#ifdef __cplusplus
}
#endif

#endif