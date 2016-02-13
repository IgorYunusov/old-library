/*************************************************************************
  
   RollRat Software Solve Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: matrix.h
                         Abstract: Common Matrix
                         Creation: 2015-03-14
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#ifndef _MATRIX_21b72c0b7adc5c7b4a50ffcb90d92dd6_
#define _MATRIX_21b72c0b7adc5c7b4a50ffcb90d92dd6_

#define radian 0.01745329251994329576923690768489 // 57.295779513082320876798154814105

#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include <math.h>

typedef struct _MATRIX_fdd0437fc4bca5478ad8dc933839fbc7_ {
	// [row][column]
	double **matrix;
	size_t row, column;
}	Matrix, *PMatrix;

#ifdef __cplusplus
extern "C" {
#endif

// 새 행렬을 생성합니다.
PMatrix matrix_make(size_t row, size_t column);
// 새 단위 행렬을 생성합니다.
PMatrix matrix_make_unit(size_t unit_size);
// 2*2 행렬에 대한 회전변환을 수행합니다. (sin(x))
PMatrix matrix_make_rotate2_real(double real);
// 2*2 행렬에 대한 회전변환을 수행합니다. (sin(θ))
PMatrix matrix_make_rotate2_radian(double rad);
// 4*4 행렬에 대한 x축 회전변환을 수행합니다. (sin(x))
PMatrix matrix_make_rotate4x_real(double real);
// 4*4 행렬에 대한 y축 회전변환을 수행합니다. (sin(x))
PMatrix matrix_make_rotate4y_real(double real);
// 4*4 행렬에 대한 z축 회전변환을 수행합니다. (sin(x))
PMatrix matrix_make_rotate4z_real(double real);
// 4*4 행렬에 대한 x축 회전변환을 수행합니다. (sin(θ))
PMatrix matrix_make_rotate4x_radian(double rad);
// 4*4 행렬에 대한 y축 회전변환을 수행합니다. (sin(θ))
PMatrix matrix_make_rotate4y_radian(double rad);
// 4*4 행렬에 대한 z축 회전변환을 수행합니다. (sin(θ))
PMatrix matrix_make_rotate4z_radian(double rad);
// 행렬에 모든 성분을 값으로 채웁니다.
PMatrix matrix_fill(PMatrix pm, double value);
// 선택된 행에 모든 성분에 값을 채웁니다.
PMatrix matrix_fill_row(PMatrix pm, size_t row, double value);
// 선택된 열에 모든 성분에 값을 채웁니다.
PMatrix matrix_fill_column(PMatrix pm, size_t column, double value);
// 입력 행렬에 대한 복사본을 생성합니다.
PMatrix matrix_copy(PMatrix pm);
// 두 행렬을 서로 더합니다.
PMatrix matrix_each_plus(PMatrix pm_left, PMatrix pm_right);
// 두 행렬에 대한 감산연산을 수행합니다.
PMatrix matrix_each_minus(PMatrix pm_left, PMatrix pm_right);
// 행렬의 각 성분에 상수를 더합니다.
PMatrix matrix_constant_plus(PMatrix pm, double value);
// 행렬의 각 성분에 상수를 뺍니다.
PMatrix matrix_constant_minus(PMatrix pm, double value);
// 행렬의 각 성분에 상수를 곱합니다.
PMatrix matrix_constant_multiple(PMatrix pm, double value);
// 행렬의 각 성분에 상수를 나눕니다.
PMatrix matrix_constant_divide(PMatrix pm, double value);
// 두 행렬을 서로 곱합니다.
PMatrix matrix_multiple(PMatrix pm_left, PMatrix pm_right);
// 행렬식의 값을 구합니다.
double matrix_determinant(PMatrix target);
// 입력 행렬의 역행렬을 구합니다.
PMatrix matrix_inverse(PMatrix target);
// 입력 행렬의 전치 행렬을 구합니다.
PMatrix matrix_transpose(PMatrix target);
// 행렬의 모든 성분을 출력합니다.
void matrix_show(PMatrix pm);

#ifdef __cplusplus
}
#endif

#define MATRIX_ERROR		((PMatrix)(-1))
#define MATRIX_CALCULATE_ERROR ((PMatrix)(-2))

#endif