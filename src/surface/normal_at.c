#include "head.h"

t_tuple	normal_at(t_object *object, t_tuple p)
{
	t_tuple object_point;
	t_tuple new_object;
	t_matrix inv;

	if (!object)
		return (tuple(0, 0, 0, 0));
	inv = inverse(object->transform);
	object_point = multiply_matrix_tuple(inv, p);
	new_object = multiply_matrix_tuple(transpose(inv), object_point);
	new_object = normalize(new_object);
	new_object.w = 0;
	return (new_object);
}
