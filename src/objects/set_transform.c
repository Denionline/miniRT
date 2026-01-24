#include "head.h"

t_object	*set_transform(t_object *obj, t_matrix transform)
{
	obj->transform = inverse(transform);
	obj->transform.size = transform.size;
	return (obj);
}
