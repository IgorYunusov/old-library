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

// �� ����� �����մϴ�.
PMatrix matrix_make(size_t row, size_t column);
// �� ���� ����� �����մϴ�.
PMatrix matrix_make_unit(size_t unit_size);
// 2*2 ��Ŀ� ���� ȸ����ȯ�� �����մϴ�. (sin(x))
PMatrix matrix_make_rotate2_real(double real);
// 2*2 ��Ŀ� ���� ȸ����ȯ�� �����մϴ�. (sin(��))
PMatrix matrix_make_rotate2_radian(double rad);
// 4*4 ��Ŀ� ���� x�� ȸ����ȯ�� �����մϴ�. (sin(x))
PMatrix matrix_make_rotate4x_real(double real);
// 4*4 ��Ŀ� ���� y�� ȸ����ȯ�� �����մϴ�. (sin(x))
PMatrix matrix_make_rotate4y_real(double real);
// 4*4 ��Ŀ� ���� z�� ȸ����ȯ�� �����մϴ�. (sin(x))
PMatrix matrix_make_rotate4z_real(double real);
// 4*4 ��Ŀ� ���� x�� ȸ����ȯ�� �����մϴ�. (sin(��))
PMatrix matrix_make_rotate4x_radian(double rad);
// 4*4 ��Ŀ� ���� y�� ȸ����ȯ�� �����մϴ�. (sin(��))
PMatrix matrix_make_rotate4y_radian(double rad);
// 4*4 ��Ŀ� ���� z�� ȸ����ȯ�� �����մϴ�. (sin(��))
PMatrix matrix_make_rotate4z_radian(double rad);
// ��Ŀ� ��� ������ ������ ä��ϴ�.
PMatrix matrix_fill(PMatrix pm, double value);
// ���õ� �࿡ ��� ���п� ���� ä��ϴ�.
PMatrix matrix_fill_row(PMatrix pm, size_t row, double value);
// ���õ� ���� ��� ���п� ���� ä��ϴ�.
PMatrix matrix_fill_column(PMatrix pm, size_t column, double value);
// �Է� ��Ŀ� ���� ���纻�� �����մϴ�.
PMatrix matrix_copy(PMatrix pm);
// �� ����� ���� ���մϴ�.
PMatrix matrix_each_plus(PMatrix pm_left, PMatrix pm_right);
// �� ��Ŀ� ���� ���꿬���� �����մϴ�.
PMatrix matrix_each_minus(PMatrix pm_left, PMatrix pm_right);
// ����� �� ���п� ����� ���մϴ�.
PMatrix matrix_constant_plus(PMatrix pm, double value);
// ����� �� ���п� ����� ���ϴ�.
PMatrix matrix_constant_minus(PMatrix pm, double value);
// ����� �� ���п� ����� ���մϴ�.
PMatrix matrix_constant_multiple(PMatrix pm, double value);
// ����� �� ���п� ����� �����ϴ�.
PMatrix matrix_constant_divide(PMatrix pm, double value);
// �� ����� ���� ���մϴ�.
PMatrix matrix_multiple(PMatrix pm_left, PMatrix pm_right);
// ��Ľ��� ���� ���մϴ�.
double matrix_determinant(PMatrix target);
// �Է� ����� ������� ���մϴ�.
PMatrix matrix_inverse(PMatrix target);
// �Է� ����� ��ġ ����� ���մϴ�.
PMatrix matrix_transpose(PMatrix target);
// ����� ��� ������ ����մϴ�.
void matrix_show(PMatrix pm);

#ifdef __cplusplus
}
#endif

#define MATRIX_ERROR		((PMatrix)(-1))
#define MATRIX_CALCULATE_ERROR ((PMatrix)(-2))

#endif