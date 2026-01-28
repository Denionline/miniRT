#include "head.h"

t_material	material(t_tuple color)
{
	return ((t_material) {
		.color	= color,
		.ambient = 0.1f,
		.difuse = 0.9f,
		.specular = 0.9f,
		.shininess = 200.0f
	});
}

t_object	*sphere(void)
{
	t_object	*new_object;

	new_object = ft_calloc(1, sizeof(t_object));
	if (!new_object)
		exit(42);
	new_object->transform = identity_matrix();
	new_object->diameter = 2.0f;
	new_object->position =  point(0, 0, 0);
	new_object->material = material(color_float(1, 1, 1));
	new_object->type = SPHERE;
	return (new_object);
}

t_object	*plane(void)
{
	t_object	*new_object;

	new_object = ft_calloc(1, sizeof(t_object));
	if (!new_object)
		exit(42);
	new_object->transform = identity_matrix();
	new_object->position = point(0, 0, 0);
	new_object->material = material(color_float(1, 1, 1));
	new_object->type = PLANE;
	return (new_object);
}

t_object	*cylinder(void)
{
	t_object	*new_object;

	new_object = ft_calloc(1, sizeof(t_object));
	if (!new_object)
		exit(42);
	new_object->transform = identity_matrix();
	new_object->position = point(0, 0, 0);
	new_object->diameter = 2.0f;
	new_object->height = 1.0f;
	new_object->material = material(color_float(1, 1, 1));
	new_object->type = CYLINDER;
	return (new_object);
}
