#include "head.h"

static void	print_tuple(t_tuple t) {
	if (t.w == VECTOR)
		printf("%6s", "Vector");
	else if (t.w == POINT)
		printf("%6s", "Point");
	else
		printf("%6s", "Tuple");
	printf(" | x: %6.2f | y: %6.2f | z: %6.2f | w: %6.2f\n", t.x, t.y, t.z, t.w);
}

static void	print_matrix(t_matrix m) {
	printf("Matrix\n");
	for (unsigned int i = 0; i < m.size; i++) {
		for (unsigned int j = 0; j < m.size; j++) {
			printf(" %.5f ", m.matrix[i][j]);
		}
		printf("\n");
	}
}


int	main(void) {
	t_tuple		p;
	t_matrix	m1;
	t_matrix	m2;

	p = point(0, 1, 0);
	m1 = rotation_x(PI / 4);
	m2 = rotation_x(PI / 2);
	print_tuple(p);
	print_matrix(m1);
	print_matrix(m2);
	print_tuple(multiply_matrix_tuple(m1, p));
	print_tuple(multiply_matrix_tuple(m2, p));
}