#include "head.h"

t_tuple	shade_hit(t_world w, t_computations comps)
{
	t_phong_vec	pv;

	pv.eyev = comps.eyev;
	pv.normalv = comps.normalv;
	pv.in_shadow = is_shadowed(w, comps.over_point);
	return (lighting(comps.object->material, w.light, comps.over_point, pv, *comps.object));
}
