#include "head.h"

int	main(void) {
	t_object	*s;
	t_tuple		n;
	t_tuple		in;
	t_tuple		normal;

	s = &(t_object){
		.type = SPHERE,
		.transform = identity_matrix(),
	};

	printf("\nComputing the Normal on a Sphere\n");
	n = normal_at(s, point(1, 0, 0));
	print_tuple(n);
	n = normal_at(s, point(0, 1, 0));
	print_tuple(n);
	n = normal_at(s, point(0, 0, 1));
	print_tuple(n);
	n = normal_at(s, point(0.57, 0.57, 0.57));
	print_tuple(n);
	
	printf("\nTransforming Normals\n");
	print_matrix(s->transform);
	s->transform = multiply_matrix(s->transform, translation(0, 1, 0));
	print_matrix(s->transform);
	n = normal_at(s, point(0, 1.70711, -0.70711));
	print_tuple(n);
	
	s->transform = identity_matrix();
	print_matrix(s->transform);
	s->transform = multiply_matrix(scaling(1, 0.5, 1), rotate_z(PI / 5));
	print_matrix(s->transform);
	n = normal_at(s, point(0, sqrtf(2) / 2, -(sqrtf(2) / 2)));
	print_tuple(n);

	printf("\nReflect\n");
	in = vector(1, -1, 0);
	normal = vector(0, 1, 0);
	n = reflect(in, normal);
	print_tuple(n);

	in = vector(0, -1, 0);
	normal = vector(sqrtf(2) / 2, sqrtf(2) / 2, 0);
	n = reflect(in, normal);
	print_tuple(n);
}