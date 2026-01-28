#include "head.h"

t_tuple	local_normal_at(t_object *obj, t_tuple p)
{
	float	y;

	if (obj->type == PLANE)
		return (vector(0, 1, 0));
	if (obj->type == CYLINDER)
		return (vector(p.x, 0, p.z));
	if (obj->type == CONE)
	{
		y = sqrtf(powf(p.x, 2) + powf(p.z, 2));
		if (p.y > 0)
			y *= -1.0f;
		return (vector(p.x, y, p.z));
	}
	return (p);
}
