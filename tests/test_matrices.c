#include "head.h"

int	main(void) {
	t_matrix	m1 = matrix(
		(float[16]){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2}
		, 4);
	t_matrix	m2 = matrix(
		(float[16]){-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8}
		, 4);

	t_matrix	m = multiply_matrix(m1, m2);
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