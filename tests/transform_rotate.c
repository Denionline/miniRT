#include "head.h"

int	main(void) {
	t_tuple		p;
	t_matrix	m1;
	t_matrix	m2;

	printf("-----Rotate X-----\n");
	p = point(0, 1, 0);
	m1 = rotation_x(PI / 4);
	m2 = rotation_x(PI / 2);
	print_tuple(p);
	print_matrix(m1);
	print_matrix(m2);
	print_tuple(multiply_matrix_tuple(m1, p));
	print_tuple(multiply_matrix_tuple(m2, p));
	printf("-----Inverse Rotate X-----\n");
	p = point(0, 1, 0);
	m1 = rotation_x(PI / 4);
	m2 = inverse(m1);
	print_tuple(p);
	print_matrix(m1);
	print_matrix(m2);
	print_tuple(multiply_matrix_tuple(m2, p));
}