#include "head.h"

void	print_ray(t_ray r)
{
	printf("ray with direction:\n");
	print_tuple(r.direction);
	printf("ray with origin:\n");
	print_tuple(r.origin);
}

int	main()
{
	t_ray		r;
	t_matrix	m;
	
	r = ray(point(1, 2, 3), vector(0, 1, 0));
	m = translation(3, 4, 5);
	printf("\nOriginal ray:\n");
	print_ray(r);
	t_ray r2 = transform_ray(r, m);
	printf("\nTransformed ray With translation 3,4,5:\n");
	print_ray(r2);
	printf("r:");

	r = ray(point(1, 2, 3), vector(0, 1, 0));
	m = scaling(2, 3, 4);
	printf("\nOriginal ray:\n");
	print_ray(r);
	r2 = transform_ray(r, m);
	printf("\nTransformed ray With scaling 2,3,4:\n");
	print_ray(r2);
	printf("r:");

	printf("Transform Sphere\n");
	t_object s = sphere(point(0, 0, 0), (t_sphere) {});
	printf("%f", ((t_sphere *) (s.options))->diameter);
	return (0);
}