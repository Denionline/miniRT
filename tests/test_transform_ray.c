#include "head.h"

void	print_ray(t_ray r)
{
	printf("ray with:");
}

int	main()
{
	t_ray		r;
	t_matrix	m;
	
	r = ray(point(1, 2, 3), vector(0, 1, 0));
	m = translation(3, 4, 5);
	t_ray r2 = transform_ray(r, m);

	printf("r:");
	return (0);
}