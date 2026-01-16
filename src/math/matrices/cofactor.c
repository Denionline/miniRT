# include "head.h"

float	cofactor(t_matrix matrix_3d, unsigned int row, unsigned int col)
{
	if ((row + col) % 2 != 0)
		return (-1.0f * minor_3d(matrix_3d, row, col));
	return (minor_3d(matrix_3d, row, col));
}
