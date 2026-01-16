#include "head.h"

static void	alloc_values(t_matrix matrix_org, t_matrix *sub_m, unsigned int row, unsigned int col)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	i_s;
	unsigned int	j_s;

	i = 0;
	i_s = 0;
	while (i < matrix_org.size)
	{
		j = 0;
		j_s = j;
		while (j < matrix_org.size && i != row)
		{
			if (j != col)
			{
				sub_m->matrix[i_s][j_s] = matrix_org.matrix[i][j];
				j_s++;
			}
			j++;
		}
		if (i != row)
			i_s++;
		i++;
	}
}

t_matrix	submatrix(t_matrix matrix_org, unsigned int row, unsigned int col)
{
	t_matrix		sub_m;

	if (row > matrix_org.size || col > matrix_org.size)
		return (matrix_org);
	sub_m = (t_matrix) {};
	sub_m.size = matrix_org.size - 1;
	alloc_values(matrix_org, &sub_m, row, col);
	return (sub_m);
}
