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
	return (0);
}
