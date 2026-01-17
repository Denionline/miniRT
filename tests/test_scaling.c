#include "head.h"

void	print_vector(t_tuple p)
{
	printf("%3.f,%3.f,%3.f\n", p.x, p.y, p.z);
}

int	main(void)
{
	t_matrix	m;
	t_tuple		p;

	printf("\n With Point\n");
	m = scaling(2, 3, 4);
	p = point(-4, 6, 8);
	printf("Scaling: 2 3 4\n");
	printf("Point:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));

	printf("\n With Vector\n");
	m = scaling(2, 3, 4);
	p = vector(-4, 6, 8);
	printf("Scaling: 2 3 4\n");
	printf("Vector:");
	print_vector(p);
	printf("resut: ");
	print_vector(multiply_matrix_tuple(m, p));

	printf("\n Shrinking Because Inverse\n");
	m = scaling(2, 3, 4);
	t_matrix inv = inverse(m);
	p = vector(-4, 6, 8);
	printf("Scaling: 2 3 4\n");
	printf("Vector:");
	print_vector(p);
	printf("result Inverse(m) * vector: ");
	print_vector(multiply_matrix_tuple(inv, p));
}