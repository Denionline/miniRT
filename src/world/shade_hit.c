#include "head.h"

t_tuple	shade_hit(t_world w, t_computations comps)
{
	t_phong_vec	pv;

	pv.eyev = comps.eyev;
	pv.normalv = comps.normalv;
	return (lighting(comps.object->material, w.light, comps.point, pv));
}
