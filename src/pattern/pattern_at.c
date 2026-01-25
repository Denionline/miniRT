#include "head.h"

t_tuple	pattern_at(t_pattern g, t_tuple p)
{
	t_tuple	distance;
	float	fraction;

	distance = subtract_tuples(g.b, g.a);
	fraction = p.x - floor(p.x);
	return (sum_tuples(g.a, multiply_tuple(distance, fraction)));
}
