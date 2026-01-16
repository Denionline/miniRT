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
	for (unsigned int i = 0; i < m.size; i++) {
		for (unsigned int j = 0; j < m.size; j++) {
			printf(" %.2f ", m.matrix[i][j]);
		}
		printf("\n");
	}
}

int	main(void) {
	t_matrix	m1;
	t_matrix	m2;
	t_matrix	m;
	t_tuple		p;
	t_tuple		r;

	m1 = matrix(
		(float[16]){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2}
		, 4);
	m2 = matrix(
		(float[16]){-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8}
		, 4);

	m = multiply_matrix(m1, m2);
	printf("\n=-=-=-= TRANSPOSE =-=-=-=\n");

	m1 = matrix(
		(float[16]){1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2}
		, 4);
	m2 = matrix(
		(float[16]){-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8}
		, 4);

	m = multiply_matrix(m1, m2);
	print_matrix(m);

	printf("\n=-=-=-= TRANSPOSE =-=-=-=\n");
	
	m = transpose(m);
	for (unsigned int i = 0; i < m.size; i++) {
		for (unsigned int j = 0; j < m.size; j++) {
			printf(" %.2f ", m.matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	m = translation(5, -3, 2);
	p = point(-3, 4, 5);

	print_matrix(m);
	print_tuple(p);
	r = multiply_matrix_tuple(m, p);
	print_tuple(r);
	print_matrix(m);

	printf("\n=-=-=-= Determinat 2d =-=-=-=\n");
	t_matrix	m3 = matrix(
		(float[]){1, 5, -3, 2}
		, 2);
	print_matrix(m3);
	printf ("Determinant: %.3f\n", determ_2d(m3));

	printf("\n=-=-=-= Submatrix =-=-=-=\n");
	t_matrix	m4 = matrix(
		(float[]){1, 5, 0, -3, 2, 7, 0, 6, -3}
		, 3);
	printf("matrix:\n");
	print_matrix(m4);
	printf("submatrix:\n");
	print_matrix(submatrix(m4, 0, 2));

	printf("\n=-=-=-= Submatrix 2 =-=-=-=\n");
	t_matrix	m5 = matrix(
		(float[]){-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1}
		, 4);
	printf("matrix:\n");
	print_matrix(m5);
	printf("submatrix:\n");
	print_matrix(submatrix(m5, 2, 1));

	printf("\n=-=-=-= Minor - Cofactor =-=-=-=\n");
	t_matrix	m6 = matrix(
		(float[]){3, 5, 0, 2, -1, -7, 6, -1, 5}
		, 3);
	printf("matrix:\n");
	print_matrix(m6);
	printf("Minor: %.3f\n", minor_3d(m6, 1, 0));
	printf("Minor: %.3f\n", cofactor(m6, 1, 0));

}
