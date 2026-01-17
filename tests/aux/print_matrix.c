#include "head.h"

void	print_matrix(t_matrix m)
{
	unsigned int	i;
	unsigned int	j;

	printf("Matrix (%u x %u)\n", m.size, m.size);
	printf("┌");
	for (i = 0; i < m.size; i++)
		printf("──────────");
	printf("┐\n");

	for (i = 0; i < m.size; i++)
	{
		printf("│");
		for (j = 0; j < m.size; j++)
			printf(" %8.5f ", m.matrix[i][j]);
		printf("│\n");
	}

	printf("└");
	for (i = 0; i < m.size; i++)
		printf("──────────");
	printf("┘\n");
}