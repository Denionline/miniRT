#include "head.h"

t_tuple	spherical_map(t_tuple p)
{
	float	theta;
	float	radius;
	float	polar_angle;
	t_tuple	new_p;

	p.w = 1;
	theta = atan2f(p.x, p.z);
	radius = magnitude(p);
	polar_angle = acosf(p.y / radius);
	new_p = (t_tuple) {
		.x = 1 - (theta * 0.5f / PI),
		.y = 1 - (polar_angle / PI)
	};
	return (new_p);
}

t_tuple	cylindrical_map(t_tuple p)
{
	float	theta;
	t_tuple	new_p;

	p.w = 1;
	theta = atan2f(p.x, p.z);
	new_p = (t_tuple) {
		.x = 1 - ((theta / (2 * PI)) + 0.5f),
		.y = p.y - floorf(p.y)
	};
	return (new_p);
}

t_tuple planar_map(t_tuple p)
{
    return (vector(p.x, p.z, 0));
}

t_tuple	converter_map(t_tuple p, enum object_type t)
{
	if (t == PLANE)
		return (planar_map(p));
	if (t == CYLINDER)
		return (cylindrical_map(p));
	return (spherical_map(p));
}