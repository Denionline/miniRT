#include "head.h"

int	main()
{
	t_ray		r;
	t_object	s;
	t_sphere	sphere;

	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	r = ray(point(0, 0, -5), vector(0, 0, 1));

	t_intersect t = intersect(s, r);
	printf("\nfor 0, 0, -5 ray:\n");
	printf("Number of colision: %d\n", t.count);
	printf("Pos: %f and %f\n", t.pos[0], t.pos[1]);

	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	r = ray(point(0, 1, -5), vector(0, 0, 1));

	t = intersect(s, r);
	printf("\nfor 0, 1, -5 ray:\n");
	printf("Number of colision: %d\n", t.count);
	printf("Pos: %f and %f\n", t.pos[0], t.pos[1]);

	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	r = ray(point(0, 2, -5), vector(0, 0, 1));

	t = intersect(s, r);
	printf("\nfor 0, 2, -5 ray:\n");
	printf("Number of colision: %d\n", t.count);
	printf("Pos: %f and %f\n", t.pos[0], t.pos[1]);


	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	r = ray(point(0, 0, 0), vector(0, 0, 1));

	t = intersect(s, r);
	printf("\nfor 0, 0, 0 ray:\n");
	printf("Number of colision: %d\n", t.count);
	printf("Pos: %f and %f\n", t.pos[0], t.pos[1]);

	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	r = ray(point(0, 0, 5), vector(0, 0, 1));

	t = intersect(s, r);
	printf("\nfor 0, 0, 0 ray:\n");
	printf("Number of colision: %d\n", t.count);
	printf("Pos: %f and %f\n", t.pos[0], t.pos[1]);
	return (0);
}