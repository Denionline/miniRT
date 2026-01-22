#include "head.h"

int	main(void) {
	t_tuple		from;
	t_tuple		to;
	t_tuple 	up;
	t_matrix	t;

	from = point(0, 0, 0);
	to = point(0, 0, -1);
	up = vector(0, 1, 0);
	t = view_transform(from, to, up);
	printf("from:\n");
	print_tuple(from);
	printf("to:\n");
	print_tuple(to);
	printf("up:\n");
	print_tuple(up);
	print_matrix(t);

	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	to = point(0, 0, 1);
	t = view_transform(from, to, up);
	printf("from:\n");
	print_tuple(from);
	printf("to:\n");
	print_tuple(to);
	printf("up:\n");
	print_tuple(up);
	print_matrix(t);

	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	from = point(0, 0, 8);
	to = point(0, 0, 0);
	t = view_transform(from, to, up);
	printf("from:\n");
	print_tuple(from);
	printf("to:\n");
	print_tuple(to);
	printf("up:\n");
	print_tuple(up);
	print_matrix(t);
	print_matrix(translation(0, 0, -8));

	printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

	from = point(1, 3, 2);
	to = point(4, -2, 8);
	up = vector(1, 1, 0);
	t = view_transform(from, to, up);
	printf("from:\n");
	print_tuple(from);
	printf("to:\n");
	print_tuple(to);
	printf("up:\n");
	print_tuple(up);
	print_matrix(t);

}
