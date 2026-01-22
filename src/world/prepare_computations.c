#include "head.h"

t_computations	prepare_computations(t_intersection inter, t_ray r)
{
	t_computations	comps;

	comps.t = inter.t;
	comps.object = inter.object;

	comps.point = position(r, comps.t);
	comps.eyev = negate_tuple(r.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	return (comps);
}
