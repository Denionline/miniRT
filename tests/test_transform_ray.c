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

	t_object	s;
	t_sphere	sphere;

	printf("Transform Sphere\n");
	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	s = set_transform(s, scaling(2, 2, 2));
	t_intersections xs = intersect(&s, ray(point(0, 0, -5), vector(0, 0, 1)));
	printf("xs.count = %d\n", xs.count);
	printf("xs[0].t = %f\n", xs.array[0].t);
	printf("xs[1].t = %f\n", xs.array[1].t);
	free(xs.array);

	printf("Transform Sphere\n");
	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	s = set_transform(s, translation(5, 0, 0));
	xs = intersect(&s, ray(point(0, 0, -5), vector(0, 0, 1)));
	printf("xs.count = %d\n", xs.count);
	free(xs.array);
	return (0);
}