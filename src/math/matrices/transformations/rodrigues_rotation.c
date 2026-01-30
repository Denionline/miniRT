#include "head.h"

t_matrix	rodrigues_rotation(t_tuple vec_axis, float angle)
{
	t_matrix	m;
	float		c;
	float		s;
	float		const1;

	c = cos(angle);
	s = sin(angle);
	const1 = 1.0f - c;
	m = identity_matrix();
	m.matrix[0][0] = c + const1 * vec_axis.x * vec_axis.x;
	m.matrix[0][1] = const1 * vec_axis.x * vec_axis.y - vec_axis.z * s;
	m.matrix[0][2] = const1 * vec_axis.x * vec_axis.z + vec_axis.y * s;
	m.matrix[1][0] = const1 * vec_axis.y * vec_axis.x + vec_axis.z * s;
	m.matrix[1][1] = const1 * vec_axis.y * vec_axis.y + c;
	m.matrix[1][2] = const1 * vec_axis.y * vec_axis.z - vec_axis.x * s;
	m.matrix[2][0] = const1 * vec_axis.z * vec_axis.x - vec_axis.y * s;
	m.matrix[2][1] = const1 * vec_axis.z * vec_axis.y + vec_axis.x * s;
	m.matrix[2][2] = const1 * vec_axis.z * vec_axis.z + c;
	return (m);
}
