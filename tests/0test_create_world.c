#include "head.h"

// int	main(void) {
// 	t_world			w = default_world();
// 	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_intersections	xs = intersect_world(w, r);
// 	printf("xs.count = %d\n", xs.count);
// 	printf("xs[0].t = %.2f\n", xs.array[0].t);
// 	printf("xs[1].t = %.2f\n", xs.array[1].t);
// 	printf("xs[2].t = %.2f\n", xs.array[2].t);
// 	printf("xs[3].t = %.2f\n", xs.array[3].t);
// }

// int	main(void) {
// 	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_object		*shape = sphere();
// 	t_intersection	i = intersection(4, shape);
// 	t_computations	comps = prepare_computations(i, r);

// int	main(void) {
// 	t_ray r = ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_object *shape = sphere();
// 	t_intersection i = intersection(4, shape);
// 	t_computations comps = prepare_computations(i, r);
// 	print_computations(comps);
// }

// int	main(void) {
// 	t_ray r = ray(point(0, 0, 0), vector(0, 0, 1));
// 	t_object *shape = sphere();
// 	t_intersection i = intersection(1, shape);
// 	t_computations comps = prepare_computations(i, r);
// 	print_computations(comps);
// }

// int	main(void) {
// 	t_world			w = default_world();
// 	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
// 	t_object		*shape = w.objects[0];
// 	t_intersection	i = intersection(4, shape);
// 	t_computations	comps = prepare_computations(i, r);
// 	t_tuple			c = shade_hit(w, comps);
// 	print_tuple_simple("Color", c);
// }

// int	main(void) {
// 	t_world			w = default_world();
// 	w.light = point_light(point(0, 0.25, 0), color_float(1, 1, 1));
// 	t_ray			r = ray(point(0, 0, 0), vector(0, 0, 1));
// 	t_object		*shape = w.objects[1];
// 	t_intersection	i = intersection(0.5, shape);
// 	t_computations	comps = prepare_computations(i, r);
// 	t_tuple			c = shade_hit(w, comps);
// 	print_world(w);
// 	print_tuple_simple("\nShaded color", c);
// }

int	main(void) {
	t_world		w = default_world();
	t_object	*outer = w.objects[0];
	outer->material.ambient = 1;
	t_object	*inner = w.objects[1];
	inner->material.ambient = 1;
	t_ray		r = ray(point(0, 0, 0.75), vector(0, 0, -1));
	t_tuple		c = color_at(w, r);
	print_object(*inner);
	print_tuple_simple("Color inner is", c);
}
