#include "head.h"

t_world	*world(void)
{
	t_world	*new_world;

	new_world = saffe_calloc(1, sizeof(t_world));
	return (new_world);
}

t_world	default_world(void)
{
	t_world		new_world;
	t_object	*s1;
	t_object	*s2;
	
	s1 = sphere();
	s1->material.color = color_float(0.8, 1.0, 0.6);
	s1->material.difuse = 0.7f;
	s1->material.specular = 0.2f;
	s2 = sphere();
	s2->transform = scaling(0.5f, 0.5f, 0.5f);
	new_world.light = point_light(point(-10, 10, -10), color_float(1, 1, 1), 1);
	new_world.objects = ft_calloc(2, sizeof(t_object *));
	if (!new_world.objects)
		exit(42);
	new_world.objects[0] = s1;
	set_transform(s2, scaling(0.5f, 0.5f, 0.5f));
	new_world.objects[1] = s2;
	new_world.n_objs = 2;
	return (new_world);
}
