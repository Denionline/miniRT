#include "head.h"

// int	main(void) {
// 	t_world			w;
// 	t_object		*s1;
// 	t_object		*s2;
// 	t_ray			r;
// 	t_intersection	i;
// 	t_computations	comps;
// 	t_tuple			c;
// 	w = world();
// 	w.light = point_light(point(0, 0, -10), color_float(1, 1, 1));
// 	s1 = sphere();
// 	append_object_on_world(&w, s1);
// 	s2 = sphere();
// 	s2->transform = translation(0, 0, 10);
// 	append_object_on_world(&w, s2);
// 	r = ray(point(0, 0, 5), vector(0, 0, 1));
// 	i = intersection(4, s2);
// 	comps = prepare_computations(i, r);
// 	c = shade_hit(w, comps);
// 	print_tuple_simple("Hited by shade", c);
// }

int	main(void) {
	t_ray 			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_object		*shape = sphere();
	shape->transform = translation(0, 0, 1);
	t_intersection	i = intersection(5, shape);
	t_computations	comps = prepare_computations(i, r);
	printf("comps.over_point.z < -NARUTO/2 => %s\n", comps.over_point.z < -NARUTO/2 ? "TRUE" : "FALSE");
	printf("comps.point.z > comps.over_point.z => %s\n", comps.point.z > comps.over_point.z? "TRUE" : "FALSE");
}
