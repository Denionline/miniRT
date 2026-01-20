#include "head.h"

static void	print_hit(t_intersection rit) {
	if (rit.object == NULL)
		printf("\nNULL\n");
	else
		printf("\nhit.t = %.2f\n", rit.t);
}

int	main(void) {
	t_intersection	i1;
	t_intersection	i2;
	t_intersection	i3;
	t_intersection	i4;
	t_intersections	xs;
	t_object		s;
	t_ray			r;
	t_sphere		sphere;
	t_intersection	rit;

	s.position = point(8, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;

	printf("Intersection\n");
	i1 = intersection(1, &s);
	i2 = intersection(2, &s);
	xs = intersections((t_intersection[2]){i1, i2}, 2);
	printf("xs[0].t = %.2f\n", xs.array[0].t);
	printf("xs[1].t = %.2f\n", xs.array[1].t);
	
	
	printf("\nIntersect and Intersections\n");
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	xs = intersect(&s, r);
	printf("xs.count = %d\n", xs.count);
	printf("xs[0].object = %.2f\n", xs.array[0].object->position.x);
	printf("xs[1].object = %.2f\n", xs.array[1].object->position.x);
	
	printf("\nHit\n");
	i1 = intersection(1, &s);
	i2 = intersection(2, &s);
	xs = intersections((t_intersection[2]){i2, i1}, 2);
	rit = hit(xs);
	print_hit(rit);
	i1 = intersection(-1, &s);
	i2 = intersection(1, &s);
	xs = intersections((t_intersection[2]){i2, i1}, 2);
	rit = hit(xs);
	print_hit(rit);
	i1 = intersection(-2, &s);
	i2 = intersection(-1, &s);
	xs = intersections((t_intersection[2]){i2, i1}, 2);
	rit = hit(xs);
	print_hit(rit);
	i1 = intersection(5, &s);
	i2 = intersection(7, &s);
	i3 = intersection(-3, &s);
	i4 = intersection(2, &s);
	xs = intersections((t_intersection[4]){i1, i2, i3, i4}, 4);
	rit = hit(xs);
	print_hit(rit);
}
