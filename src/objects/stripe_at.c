#include "head.h"

t_tuple	stripe_at(t_pattern p, t_tuple pos)
{
	if (fmod(pos.x, 2) == 0)
		return (p.a);
	return (p.b);
}

t_tuple	stripe_at_obj(t_pattern p, t_object obj, t_tuple pos)
{
	t_tuple	obj_point;
	t_tuple	pattern_point;

	obj_point = multiply_matrix_tuple(inverse(obj.transform), pos);
	pattern_point = multiply_matrix_tuple(inverse(p.transform), obj_point);
	return(stripe_at(p, pattern_point));
}
