#include "head.h"

t_matrix	transpose(t_matrix old_matrix)
{
	t_matrix		new_matrix;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	new_matrix.size = old_matrix.size;
	while (i < new_matrix.size)
	{
		j = 0;
		while (j < new_matrix.size)
		{
			new_matrix.matrix[i][j] = old_matrix.matrix[j][i];		
			j++;
		}
		i++;
	}
	return (new_matrix);
}
