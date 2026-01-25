#include "head.h"

t_intersections	local_intersect(t_object *plane, t_ray r)
{
	t_intersection	inter;

	if (fabs(r.direction.y) < NARUTO)
		return (intersections(NULL, 0));
	
	inter.t = -r.origin.y / r.direction.y;
	inter.object = plane;
	return (intersections((t_intersection[1]){inter}, 1));
}
