#include "head.h"

int	main()
{
	t_tuple	origin;
	t_tuple	direction;

	origin = point (1, 2, 3);
	direction = vector(4, 5, 6);

	t_ray r = ray(origin, direction);
	printf("ray.origin:\n");
	print_tuple(r.origin);
	printf("ray.direction:\n");
	print_tuple(r.direction);

	printf("\nCalculating Position\n");

	origin = point (2, 3, 4);
	direction = vector(1, 0, 0);

	r = ray(origin, direction);
	printf("ray.origin:\n");
	print_tuple(r.origin);
	printf("ray.direction:\n");
	print_tuple(r.direction);
	printf("after 0 s, new position:\n");
	print_tuple(position(r, 0));
	printf("after 1 s, new position:\n");
	print_tuple(position(r, 1));
	printf("after -1 s, new position:\n");
	print_tuple(position(r, -1));
	printf("after 2.5 s, new position:\n");
	print_tuple(position(r, 2.5));

	return (0);
}
