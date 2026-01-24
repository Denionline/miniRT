#include "head.h"

int	is_shadowed(t_world w, t_tuple p)
{
	t_tuple	vector_d;
	t_ray	r;
	float	distance;
	t_intersection	rit;
 
	vector_d = subtract_tuples(w.light.position, p);
	distance = magnitude(vector_d);
	r = ray(p, normalize(vector_d));
	rit = hit(intersect_world(w, r));
	if (rit.object && rit.t < distance)
		return (TRUE);
	return (FALSE);
}
