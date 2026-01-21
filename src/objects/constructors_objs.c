#include "head.h"

t_material	material(void)
{
	return ((t_material) {
		.color	= color_float(1, 1, 1),
		.ambient = 0.1f,
		.difuse = 0.9f,
		.specular = 0.9f,
		.shininess = 200.0f
	});
}

t_object	sphere(void)
{
	return ((t_object) {
		.transform = identity_matrix(),
		.diameter	= 2.0f,
		.position =  point(0, 0, 0),
		.type = SPHERE
	});
}
