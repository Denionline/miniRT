#include "head.h"

t_object	*set_transform(t_object *obj, t_matrix transform)
{
	t_object	*new_obj;

	new_obj = obj;
	new_obj->transform = inverse(transform);
	new_obj->transform.size = 1;
	return (new_obj);
}
