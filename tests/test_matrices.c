#include "head.h"

int	main(void) {
	float		numbers[16] = {1, 2, 3, 4, 5.5, 6.5, 7.5, 8.5, 9, 10, 11, 12, 13.5, 14.5, 15.5, 16.5};
	t_matrix	m = matrix(numbers, 4);

	for (unsigned int i = 0; i < m.size; i++) {
		for (unsigned int j = 0; j < m.size; j++) {
			printf(" %.2f ", m.matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n=-=-=-= TRANSPOSE =-=-=-=\n");

	m = transpose(m);
	for (unsigned int i = 0; i < m.size; i++) {
		for (unsigned int j = 0; j < m.size; j++) {
			printf(" %.2f ", m.matrix[i][j]);
		}
		printf("\n");
	}
}