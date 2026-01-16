#include "head.h"

float	minor_3d(t_matrix matrix_3d, unsigned int row, unsigned int col)
{
	return (determ_2d(submatrix(matrix_3d, row, col)));
}
