#include "head.h"

int	main()
{
	t_object	obj;
	t_light		l;
	t_material	m;

	l = point_light(point(0, 0, -10), color(255, 255, 255));
	printf("light in pos:\n");
	print_tuple(l.position);
	printf("light with intensity:\n");
	print_color(l.intensity);

	m = material();
	obj = sphere();
	obj.material = m;

	t_tuple	eyev = vector(0, 0, -1);
	t_tuple	normalv = vector(0, 0, -1);
	l = point_light(point(0, 0, -10), color_float(1, 1, 1));
	t_phong_vec vec = (t_phong_vec) {.eyev = eyev, .normalv = normalv};
	t_tuple	result = lighting(m, l, point(0, 0, 0), vec);
	print_color(result);
	print_tuple(result);

	eyev = vector(0, sqrt(2)/2, -sqrt(2)/2);
	normalv = vector(0, 0, -1);
	l = point_light(point(0, 0, -10), color_float(1, 1, 1));
	vec = (t_phong_vec) {.eyev = eyev, .normalv = normalv};
	result = lighting(m, l, point(0, 0, 0), vec);
	print_color(result);
	print_tuple(result);

	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	l = point_light(point(0, 10, -10), color_float(1, 1, 1));
	vec = (t_phong_vec) {.eyev = eyev, .normalv = normalv};
	result = lighting(m, l, point(0, 0, 0), vec);
	print_color(result);
	print_tuple(result);

	eyev = vector(0, -sqrt(2)/2, -sqrt(2)/2);
	normalv = vector(0, 0, -1);
	l = point_light(point(0, 10, -10), color_float(1, 1, 1));
	vec = (t_phong_vec) {.eyev = eyev, .normalv = normalv};
	result = lighting(m, l, point(0, 0, 0), vec);
	print_color(result);
	print_tuple(result);

	eyev = vector(0, 0, -1);
	normalv = vector(0, 0, -1);
	l = point_light(point(0, 0, 10), color_float(1, 1, 1));
	vec = (t_phong_vec) {.eyev = eyev, .normalv = normalv};
	result = lighting(m, l, point(0, 0, 0), vec);
	print_color(result);
	print_tuple(result);

}