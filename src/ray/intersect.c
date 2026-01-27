#include "head.h"

static t_intersections	intersect_values(t_intersections inter, t_tuple vec, float delta, t_object *ob)
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
	inter.array = calloc(2, sizeof(t_intersection));
	if (!inter.array)
		exit(404);
	inter.array[0] = intersection((-vec.y + sqr_root) * division, ob);
	inter.array[1] = intersection((-vec.y - sqr_root) * division, ob);
	return (inter);
}

t_intersections	intersect(t_object *object, t_ray r)
{
	t_intersections	inter;
	t_tuple			vec;
	float			delta;

	r = transform_ray(r, inverse(object->transform));
	inter = (t_intersections) {};

	if (object->type != SPHERE)
		return (local_intersect(object, r));
	vec = vector(dot(r.direction, r.direction), \
	2 * dot(r.origin, r.direction), dot(r.origin, r.origin) - \
	(object->diameter * 0.5) * \
	(object->diameter * 0.5));
	delta = vec.y * vec.y - 4.0f * vec.x * vec.z;
	inter = intersect_values(inter, vec, delta, object);
	return (inter);
}