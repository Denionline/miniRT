#include "head.h"

int	main(void)
{
	t_tuple		p;
	t_matrix 	A;
	t_matrix 	B;	
	t_matrix 	C;

	p = point(1	, 0, 1);
	A = rotation_x(PI / 2);
	B = scaling(5, 5, 5);
	C = translation(10, 5, 7);
	printf("orginal tuple:\n");
	print_tuple(p);
	printf("transformations:\n \
		And A ← rotation_x(π / 2)\n \
		And B ← scaling(5, 5, 5)\n \
		And C ← translation(10, 5, 7)\n");
	printf("A * p:\n");
	t_tuple p2 = multiply_matrix_tuple(A, p);
	print_tuple(p2);
	printf("B * A * p:\n");
	t_tuple p3 = multiply_matrix_tuple(B, p2);
	print_tuple(p3);
	printf("C * B * A * p:\n");
	t_tuple p4 = multiply_matrix_tuple(C, p3);
	print_tuple(p4);


	printf("Reverse Order");
	printf(" T = C * B * A:\n");
	t_matrix T = multiply_matrix(C , multiply_matrix(B, A));
	p2 = multiply_matrix_tuple(T, p);
	print_tuple(p2);
	return (0);
}