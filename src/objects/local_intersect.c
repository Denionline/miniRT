#include "head.h"

t_intersections	local_intersect(t_object *plane, t_ray r)
{
	t_intersection	inter;
	t_intersection	inter2;
	t_tuple			t;
	float			delta;

	if (plane->type == PLANE)
	{
		if (fabs(r.direction.y) < NARUTO)
			return (intersections(NULL, 0));
		
		inter.t = -r.origin.y / r.direction.y;
		inter.object = plane;
		return (intersections((t_intersection[1]){inter}, 1));
	}
	t.x = powf(r.direction.x, 2) + powf(r.direction.z, 2);
	if (fabs(t.x) < 0.00001)
		return (intersections(NULL, 0));
	t.y = 2.0f * r.origin.x * r.direction.x + 2 * r.origin.z * r.direction.z;
	t.z = powf(r.origin.x, 2) + powf(r.origin.z, 2) - 1.0f;
	delta = powf(t.y, 2) - 4.0f * t.x * t.z ;
	if (delta < 0)
		return (intersections(NULL, 0));
	inter.t = (-t.y - sqrtf(delta)) / (2.0f * t.x);
	inter.object = plane;
	inter2.t = (-t.y + sqrtf(delta)) / (2.0f * t.x);
	inter2.object = plane;
	return (intersections((t_intersection[2]){inter, inter2}, 2));

}