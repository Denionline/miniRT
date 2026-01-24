#include "head.h"

int	main(void)
{
	t_material	m;
	t_tuple	eyev;
	t_tuple	normalv;
	t_tuple r;
	t_light	l;

	m = material();
	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	l = point_light(point(0, 0, -10), color_float(1, 1, 1));
	r = lighting(m, l, point(0, 0, 0), (t_phong_vec) {eyev, normalv, TRUE});
	print_color(r);
	print_tuple(r);
	printf("=-=-=-=-=-=-=-=-=-=-=\n");

	t_world w = default_world();
	printf("is_shadowed in (0, 10, 0): %d\n", is_shadowed(w, point(0, 10, 0)));
	printf("is_shadowed in (10, -10, 10): %d\n", is_shadowed(w, point(10, -10, 10)));
	printf("is_shadowed in (-20, 20, -20): %d\n", is_shadowed(w, point(-20, 20, -20)));
	printf("is_shadowed in (-2, 2, -2): %d\n", is_shadowed(w, point(-2, 2, -2)));	
}