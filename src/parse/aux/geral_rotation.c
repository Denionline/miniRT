#include "head.h"

t_matrix	geral_rotation(t_tuple	vec_norm)
{
	t_tuple	vec_d;
	t_tuple	vec_axis;
	float	angle;

	vec_d = vector(0, 1, 0);
	vec_norm = normalize(vec_norm);
	if (is_equals(vec_norm.x, vec_d.x))
	{
		if (is_equals(vec_norm.y, vec_d.y) && is_equals(vec_norm.z, vec_d.z))
			return (identity_matrix());
	}
	if (is_equals(vec_norm.x, -vec_d.x))
	{
		if (is_equals(vec_norm.y, -vec_d.y) && is_equals(vec_norm.z, -vec_d.z))
			return (rotate_x(PI));
	}
	vec_axis = normalize(cross(vec_d, vec_norm));
	angle = acos(dot(vec_d, vec_norm));
	return (rodrigues_rotation(vec_axis, angle));
}
