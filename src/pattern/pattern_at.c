#include "head.h"

static t_tuple	gradient_color(t_pattern pat, t_tuple p);
static t_tuple	checkboard_color(t_pattern pat, t_tuple p);

t_tuple	pattern_at(t_pattern pat, t_tuple p)
{
	p = converter_map(p, pat.tpye_obj);
	if (pat.type_p == RING)
	{
		if (fabs(fmod(floorf(sqrtf(powf(p.x, 2.0f) + powf(p.y, 2))), 2)) < 0.001f) 
			return (pat.a);
		return (pat.b);
	}
	if (pat.type_p == STRIP)
	{
		if (fabs(fmod(floor(p.x), 2.0f)) < NARUTO) 
			return (pat.a);
		return (pat.b);
	}
	if (pat.type_p == GRADIENT)
		return (gradient_color(pat, p));
	if (pat.type_p == CHECKBOARD)
		return (checkboard_color(pat, p));
	return (color_float(0, 0, 0));
}

static t_tuple	gradient_color(t_pattern pat, t_tuple p)
{
	t_tuple	distance;
	float	fraction;

	distance = subtract_tuples(pat.b, pat.a);
	fraction = (p.x + 1.0f) / 2.0f;
	if (fraction < 0) 
		fraction = 0;
	if (fraction > 1) 
		fraction = 1;
	return (sum_tuples(pat.a, multiply_tuple(distance, fraction)));
}

static t_tuple	checkboard_color(t_pattern pat, t_tuple p)
{
	int check;

	check = (int)floorf(p.x) + (int)floorf(p.y);
	if (check % 2 == 0) 
		return (pat.a);
	return (pat.b);
}

t_tuple	pattern_at_obj(t_pattern p, t_object obj, t_tuple pos)
{
	t_tuple	obj_point;

	obj_point = multiply_matrix_tuple((obj.transform), pos);
	return(pattern_at(p, obj_point));
}
