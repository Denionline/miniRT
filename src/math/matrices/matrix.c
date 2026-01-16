#include "head.h"

t_matrix	matrix(float *numbers, unsigned int size)
{
	t_matrix		m;
	unsigned int	i;
	unsigned int	j;

	if (size > 4)
		size = 4;
	else if (size < 2)
		size = 2;
	m.size = size;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			m.matrix[i][j] = numbers[i * size + j];
	}
	return (m);
}
