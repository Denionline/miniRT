#include "head.h"

int	main()
{
	t_object	obj;
	t_light		l;
	t_material	m;

	l = point_light(point(0, 0, 0), color(255, 255, 255));
	printf("light in pos:\n");
	print_tuple(l.position);
	printf("light with intensity:\n");
	print_color(l.intensity);

	m = (t_material) 
	{
		.color = color(255, 0, 0),
		.ambient = 0.1,
		.difuse = 0.9,
		.specular = 1.9,
		.shininess = 200.0
	};
	obj = (t_object) {
		.diameter = 2.0f,
		.position = point(0, 0, 0),
		.type = SPHERE,
		.material = m
	};

	t_tuple	eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	t_tuple	normalv = vector(0, 0, -1);
	l = point_light(point(0, 0, -10), color(1, 1, 1));
	
}