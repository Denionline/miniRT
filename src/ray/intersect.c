#include "head.h"

static t_intersect	intersect_values(t_intersect inter, t_tuple vec, float delta)
{
	float	sqr_root;
	float	division;

	division = 0.5f / vec.x;
	if (delta < 0)
		return (inter);
	inter.count = 1;
	sqr_root = 0;
	if (delta > 0)
	{
		inter.count = 2;
		sqr_root = sqrtf(delta);
	}
	inter.pos[0] = (-vec.y + sqr_root) * division;
	inter.pos[1] = (-vec.y - sqr_root) * division;
	return (inter);
}

t_intersect	intersect(t_object sphere, t_ray r)
{
	t_intersect	inter;
	t_tuple		vec;
	float		delta;

	inter = (t_intersect) {};
	vec = vector(dot(r.direction, r.direction), \
	2 * dot(r.origin, r.direction), dot(r.origin, r.origin) - \
	(((t_sphere *) sphere.options)->diameter * 0.5) * \
	(((t_sphere *) sphere.options)->diameter * 0.5));
	delta = vec.y * vec.y - 4.0f * vec.x * vec.z;
	inter = intersect_values(inter, vec, delta);
	return (inter);
}
