#include "head.h"

t_object	sphere(t_tuple pos, t_sphere s)
{
	t_object	obj;

	obj = (t_object) {};
	obj.position = pos;
	obj.options = &s;
	return (obj);
}
