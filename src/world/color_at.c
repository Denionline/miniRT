#include "head.h"

t_tuple	color_at(t_world w, t_ray r)
{
	t_intersections	inters;
	t_intersection	h;
	t_computations	comps;

	inters = intersect_world(w, r);
	h = hit(inters);
	//free_here
	if (!h.object)
		return (color_float(0, 0, 0));
	comps = prepare_computations(h, r);
	return (shade_hit(w, comps));
}
