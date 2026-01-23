#include "head.h"

t_computations	prepare_computations(t_intersection inter, t_ray r)
{
	t_computations	comps;

	comps.t = inter.t;
	comps.object = inter.object;

	comps.point = position(r, comps.t);
	comps.eyev = negate_tuple(r.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	if (dot(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = TRUE;
		comps.normalv = negate_tuple(comps.normalv);
	}
	else
		comps.inside = FALSE;
	return (comps);
}
