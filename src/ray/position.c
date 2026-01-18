#include "head.h"

// Return the position of the ray after t units of time
t_tuple	position(t_ray r, float	t)
{
	return (sum_tuples(r.origin, multiply_tuple(r.direction, t)));
}
