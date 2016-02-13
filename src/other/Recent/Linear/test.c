#include "matrix.h"

int maina()
{
	PMatrix tx = matrix_make_unit(2);

	tx->matrix[0][0] = 1.0;
	tx->matrix[0][1] = 1.0;
	tx->matrix[1][0] = 1.0;
	tx->matrix[1][1] = 2.0;

	matrix_show(matrix_inverse(tx));

	return 0;
}