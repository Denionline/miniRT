#include "head.h"

t_matrix	matrix(float *numbers, unsigned int size)
{
	t_matrix		m;
	unsigned int	i;
	unsigned int	j;

	m.size = size;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			m.matrix[i][j] = numbers[i * size + j];
			j++;
		}
		i++;
	}
	return (m);
}
