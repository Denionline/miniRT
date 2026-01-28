#include "head.h"

t_tuple	pattern_at(t_pattern pat, t_tuple p)
{
	t_tuple	distance;
	float	fraction;

	if (pat.type == RING)
	{
		if (fabs(fmod(floorf(sqrtf(powf(p.x, 2.0f) + powf(p.y, 2))), 2)) < 0.001f) 
			return (pat.a);
		return (pat.b);
	}
	if (pat.type == STRIP)
	{
		if (fabs(fmod(floor(p.x), 2.0f)) < 0.0001f) 
			return (pat.a);
		return (pat.b);
	}
	if (pat.type == GRADIENT)
	{
		distance = subtract_tuples(pat.b, pat.a);
		fraction = (p.x + 1.0f) / 2.0f;
		if (fraction < 0) 
			fraction = 0;
		if (fraction > 1) 
			fraction = 1;
		return (sum_tuples(pat.a, multiply_tuple(distance, fraction)));
	}
	return (color_float(0, 0, 0));
}

t_tuple	pattern_at_obj(t_pattern p, t_object obj, t_tuple pos)
{
	t_tuple	obj_point;
	t_tuple	pattern_point;

	obj_point = multiply_matrix_tuple(inverse(obj.transform), pos);
	pattern_point = multiply_matrix_tuple(inverse(p.transform), obj_point);
	return(pattern_at(p, pattern_point));
}
