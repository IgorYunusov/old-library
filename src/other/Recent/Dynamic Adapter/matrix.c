/*************************************************************************
  
   RollRat Software Solve Method Collection

   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
===++                                                                ++===
                             File: matrix.c
                         Abstract: Common Matrix
                         Creation: 2015-03-14
===--                                                                --===
   [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]

   Copyright (C) 2015. rollrat. All Rights Reserved.

***************************************************************************/

#define __STDC_IEC_559__ 
#define _USE_MATH_DEFINES

#include "matrix.h"

#define DETERMINANT_ERROR	(10e-10)

PMatrix matrix_make(size_t row, size_t column)
{
	Matrix *pm = (Matrix *)malloc(sizeof(Matrix));
	size_t i;

	pm->matrix = (double **)malloc(sizeof(double *) * row);

	for (i = 0; i < row; i++)
		i[pm->matrix] = (double *)malloc(sizeof(double) * column);

	pm->column = column, pm->row = row;
	return pm;
}

PMatrix matrix_make_unit(size_t unit_size)
{
	PMatrix pm = matrix_make(unit_size, unit_size);
	size_t r, c;

	for (r = 0; r < unit_size; r++)
		for (c = 0; c < unit_size; c++)
			r[pm->matrix][c] = r == c ? 1 : 0;

	return pm;
}

PMatrix matrix_make_rotate2_real(double real)
{
	PMatrix pm = matrix_make(2, 2);

	pm->matrix[0][0] = pm->matrix[1][1] = cos(real);
	pm->matrix[1][0] = sin(real);
	pm->matrix[0][1] = -pm->matrix[1][0];

	return pm;
}

PMatrix matrix_make_rotate2_radian(double rad)
{
	return matrix_make_rotate2_real(rad * radian);
}

PMatrix matrix_make_rotate4x_real(double real)
{
	PMatrix pm = matrix_make(4, 4);

	pm->matrix[1][1] = pm->matrix[2][2] = cos(real);
	pm->matrix[2][1] = sin(real);
	pm->matrix[1][2] = -pm->matrix[2][1];

	pm->matrix[0][0] = pm->matrix[3][3] = 1.0f;

	                   pm->matrix[0][1] = pm->matrix[0][2] = pm->matrix[0][3] =
	pm->matrix[1][0] =                                       pm->matrix[1][3] =
	pm->matrix[2][0] =                                       pm->matrix[2][3] =
	pm->matrix[3][0] = pm->matrix[3][1] = pm->matrix[3][2] 
	= 0.0f;

	return pm;
}

PMatrix matrix_make_rotate4y_real(double real)
{
	PMatrix pm = matrix_make(4, 4);

	pm->matrix[0][0] = pm->matrix[2][2] = cos(real);
	pm->matrix[0][2] = sin(real);
	pm->matrix[2][0] = -pm->matrix[0][2];

	pm->matrix[1][1] = pm->matrix[3][3] = 1.0f;

	                   pm->matrix[0][1] =                    pm->matrix[0][3] =
	pm->matrix[1][0] =                    pm->matrix[1][2] = pm->matrix[1][3] =
	                   pm->matrix[2][1] =                    pm->matrix[2][3] =
	pm->matrix[3][0] = pm->matrix[3][1] = pm->matrix[3][2] 
	= 0.0f;

	return pm;
}

PMatrix matrix_make_rotate4z_real(double real)
{
	PMatrix pm = matrix_make(4, 4);
	
	pm->matrix[0][0] = pm->matrix[1][1] = cos(real);
	pm->matrix[1][0] = sin(real);
	pm->matrix[0][1] = -pm->matrix[1][0];

	pm->matrix[2][2] = pm->matrix[3][3] = 1.0f;

	                                      pm->matrix[0][2] = pm->matrix[0][3] =
	                                      pm->matrix[1][2] = pm->matrix[1][3] =
	pm->matrix[2][0] = pm->matrix[2][1] =                    pm->matrix[2][3] =
	pm->matrix[3][0] = pm->matrix[3][1] = pm->matrix[3][2] 
	= 0.0f;

	return pm;
}

PMatrix matrix_make_rotate4x_radian(double rad)
{
	return matrix_make_rotate4x_real(rad * radian);
}

PMatrix matrix_make_rotate4y_radian(double rad)
{
	return matrix_make_rotate4y_real(rad * radian);
}

PMatrix matrix_make_rotate4z_radian(double rad)
{
	return matrix_make_rotate4z_real(rad * radian);
}

PMatrix matrix_fill(PMatrix pm, double value)
{
	if (value == 0.0f)
		memset(pm->matrix, 0, pm->row * pm->column * sizeof(double));
	else {
		size_t r, c;
		for (r = 0; r < pm->row; r++)
			for (c = 0; c < pm->column; c++)
				pm->matrix[r][c] = value;
	}
	return (pm);
}

PMatrix matrix_fill_row(PMatrix pm, size_t row, double value)
{
	size_t c;

	if (row > pm->row)
		return MATRIX_ERROR;

	for (c = 0; c < pm->column; c++)
		pm->matrix[row][c] = value;

	return pm;
}

PMatrix matrix_fill_column(PMatrix pm, size_t column, double value)
{
	size_t r;

	if (column > pm->column)
		return MATRIX_ERROR;

	for (r = 0; r < pm->column; r++)
		pm->matrix[r][column] = value;

	return pm;
}

PMatrix matrix_copy(PMatrix pm)
{
	PMatrix tpm = matrix_make(pm->row, pm->column);

	memcpy_s(tpm->matrix, pm->row * pm->column * sizeof(double), 
		pm->matrix, pm->row * pm->column * sizeof(double));

	return tpm;
}

static int matrix_check_row_column(PMatrix left, PMatrix right)
{
	if (left->column != right->column)
		return 0;
	if (left->row != right->row)
		return 0;

	return 1;
}

PMatrix matrix_each_plus(PMatrix pm_left, PMatrix pm_right)
{
	PMatrix pm;
	size_t r, c;

	if (!matrix_check_row_column(pm_left, pm_right))
		return MATRIX_ERROR;

	pm = matrix_make(pm_left->row, pm_right->column);

	for (r = 0; r < pm_left->row; r++)
		for (c = 0; c < pm_left->column; c++)
			pm->matrix[r][c] = pm_left->matrix[r][c] + pm_right->matrix[r][c];

	return pm;
}

PMatrix matrix_each_minus(PMatrix pm_left, PMatrix pm_right)
{
	PMatrix pm;
	size_t r, c;

	if (!matrix_check_row_column(pm_left, pm_right))
		return MATRIX_ERROR;

	pm = matrix_make(pm_left->row, pm_right->column);

	for (r = 0; r < pm_left->row; r++)
		for (c = 0; c < pm_left->column; c++)
			pm->matrix[r][c] = pm_left->matrix[r][c] - pm_right->matrix[r][c];

	return pm;
}

PMatrix matrix_constant_plus(PMatrix pm, double value)
{
	PMatrix pmt;
	size_t r, c;

	pmt = matrix_make(pm->row, pm->column);

	for (r = 0; r < pm->row; r++)
		for (c = 0; c < pm->column; c++)
			pmt->matrix[r][c] = pm->matrix[r][c] + value;

	return pmt;
}

PMatrix matrix_constant_minus(PMatrix pm, double value)
{
	PMatrix pmt;
	size_t r, c;

	pmt = matrix_make(pm->row, pm->column);

	for (r = 0; r < pm->row; r++)
		for (c = 0; c < pm->column; c++)
			pmt->matrix[r][c] = pm->matrix[r][c] - value;

	return pmt;
}

PMatrix matrix_constant_multiple(PMatrix pm, double value)
{
	PMatrix pmt;
	size_t r, c;

	pmt = matrix_make(pm->row, pm->column);

	for (r = 0; r < pm->row; r++)
		for (c = 0; c < pm->column; c++)
			pmt->matrix[r][c] = pm->matrix[r][c] * value;

	return pmt;
}

PMatrix matrix_constant_divide(PMatrix pm, double value)
{
	PMatrix pmt;
	size_t r, c;

	pmt = matrix_make(pm->row, pm->column);

	for (r = 0; r < pm->row; r++)
		for (c = 0; c < pm->column; c++)
			pmt->matrix[r][c] = pm->matrix[r][c] / value;

	return pmt;
}

static int matrix_check_row_column_multiple(PMatrix left, PMatrix right)
{
	if (left->column != right->row)
		return 0;

	return 1;
}

PMatrix matrix_multiple(PMatrix pm_left, PMatrix pm_right)
{
	PMatrix pm;
	size_t r, c, k;

	if (!matrix_check_row_column_multiple(pm_left, pm_right))
		return MATRIX_ERROR;

	pm = matrix_make(pm_left->row, pm_right->column);

	for(r = 0; r < pm_left->row; r++)
		for(c = 0; c < pm_right->column; c++)
		{
			double sum = 0.0f;
			for (k = 0; k < pm_right->row; k++)
				sum += pm_left->matrix[r][k] * pm_right->matrix[k][c];
			pm->matrix[r][c] = sum;
		}

	return pm;
}

static int matrix_check_determinant(PMatrix target)
{
	if (target->column != target->row)
		return 0;

	return 1;
}

double matrix_determinant(PMatrix target)
{
	double det = 1.0f, a, b;
	size_t r, c, k, w, z;
	PMatrix tpm;

	if (!matrix_check_determinant(target))
		return (double)(-1);

	tpm = matrix_copy(target);

	for(r = 0; r < target->row; r++) {
		if ( -DETERMINANT_ERROR < tpm->matrix[r][r] 
			&& tpm->matrix[r][r] < -DETERMINANT_ERROR ) {
			for(k = 0; k < target->row; k++) {
				if (-DETERMINANT_ERROR < tpm->matrix[k][r]
					&& tpm->matrix[k][r] < DETERMINANT_ERROR)
					continue;
				for (c = 0; c < target->column; c++)
					tpm->matrix[r][c] += tpm->matrix[k][c];
				break;
			}
		}
	}

	for(r = 0; r < target->row; r++) {
		w = tpm->matrix[r][r];
		for(k = r + 1; k < target->row; k++) {
			if (tpm->matrix[k][r] == 0)
				continue;
			z = tpm->matrix[k][r];
			for (c = 0; c < target->column; c++)
				tpm->matrix[k][c] -= tpm->matrix[r][c] / w * z;
		}
	}

	for (r = 0; r < target->row; r++)
		det *= tpm->matrix[r][r];
	return det;
}

PMatrix matrix_inverse(PMatrix target)
{
	PMatrix pm, tpm;
	size_t r, c, k, cross;

	if (!matrix_check_determinant(target))
		return MATRIX_ERROR;
	
	tpm = matrix_copy(target);
	pm = matrix_make_unit(target->row);

	for(r = 0; r < target->row; r++) {
		if ( -DETERMINANT_ERROR < tpm->matrix[r][r] 
			&& tpm->matrix[r][r] < -DETERMINANT_ERROR ) {
			for(k = 0; k < target->row; k++) {
				if (-DETERMINANT_ERROR < tpm->matrix[k][r]
					&& tpm->matrix[k][r] < DETERMINANT_ERROR)
					continue;
				for (c = 0; c < target->column; c++) {
					tpm->matrix[r][c] += tpm->matrix[k][c];
					pm->matrix[r][c] += pm->matrix[k][c];
				}
				break;
			}
			if ( -DETERMINANT_ERROR < tpm->matrix[r][r]
				&& tpm->matrix[r][r] < -DETERMINANT_ERROR )
				return MATRIX_CALCULATE_ERROR;
		}
	}

	for(r = 0; r < target->row; r++) {
		cross = tpm->matrix[r][r];
		for(c = 0; c < target->column; c++) {
			tpm->matrix[r][c] /= cross;
			tpm->matrix[r][c] /= cross;
		}

		for(k = 0; k < target->row; k++) {
			if (k == r)
				continue;
			if (tpm->matrix[k][r] == 0.0f)
				continue;
			cross = tpm->matrix[k][r];
			for(c = 0; c < tpm->column; c++) {
				tpm->matrix[k][c] -= tpm->matrix[r][c] * cross;
				pm->matrix[k][c] -= pm->matrix[r][c] * cross;
			}
		}
	}

	return pm;
}

PMatrix matrix_transpose(PMatrix target)
{
	PMatrix pm;
	size_t r, c;

	pm = matrix_make(target->column, target->row);
	
	for (r = 0; r < target->row; r++)
		for (c = 0; c < target->column; c++)
			pm->matrix[c][r] = target->matrix[r][c];

	return pm;
}

void matrix_show(PMatrix pm)
{
	size_t r, c;
	for (r = 0; r < pm->row; r++) {
		for (c = 0; c < pm->column; c++)
			printf("%0.19f ", pm->matrix[r][c]);
		putchar('\n');
	}
}