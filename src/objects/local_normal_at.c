#include "head.h"

t_tuple	local_normal_at(t_object *plane, t_tuple p)
{
	if (plane->type == PLANE)
		return (vector(0, 1, 0));
	if (plane->type == CYLINDER)
		return (vector(p.x, 0, p.z));
	return (p);
}
