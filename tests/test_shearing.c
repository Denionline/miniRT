#include "head.h"

void	print_vector(t_tuple p)
{
	printf("%3.f,%3.f,%3.f\n", p.x, p.y, p.z);
}

int	main(void)
{
	t_matrix	m;
	t_tuple		p;


	m = shearing(point(1, 0, 0), point(0, 0, 0));
	p = point(2, 3, 4);
	printf("shearing(1, 0, 0, 0, 0, 0)\n");
	printf("Point:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));

	m = shearing(point(0, 1, 0), point(0, 0, 0));
	p = point(2, 3, 4);
	printf("shearing(0, 1, 0, 0, 0, 0)\n");
	printf("Point:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));

	m = shearing(point(0, 0, 1), point(0, 0, 0));
	p = point(2, 3, 4);
	printf("shearing(0, 0, 1, 0, 0, 0)\n");
	printf("Point:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));

	m = shearing(point(0, 0, 0), point(1, 0, 0));
	p = point(2, 3, 4);
	printf("shearing(0, 0, 0, 1, 0, 0)\n");
	printf("Point:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));

	m = shearing(point(0, 0, 0), point(0, 1, 0));
	p = point(2, 3, 4);
	printf("shearing(0, 0, 0, 0, 1, 0)\n");
	printf("Point:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));

	m = shearing(point(0, 0, 0), point(0, 0, 1));
	p = point(2, 3, 4);
	printf("shearing(0, 0, 0, 0, 0, 1)\n");
	printf("Point:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));
}