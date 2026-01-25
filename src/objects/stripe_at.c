#include "head.h"

t_tuple	stripe_at(t_pattern p, t_tuple pos)
{
	int		is_negative;
	int		div;

	div = 1.0f/2.0f;
	is_negative = 0;
	if (pos.x < 0)
		is_negative = 1;
	while (pos.x > 2 || pos.x < -2)
		pos.x *= div;
	if ((pos.x < 1 && !is_negative) || pos.x < -1)
		return (p.a);
	return(p.b);
}

t_tuple	stripe_at_obj(t_pattern p, t_object obj, t_tuple pos)
{
	t_tuple	obj_point;
	t_tuple	pattern_point;

	obj_point = multiply_matrix_tuple(inverse(obj.transform), pos);
	pattern_point = multiply_matrix_tuple(inverse(p.transform), obj_point);
	return(stripe_at(p, pattern_point));
}
