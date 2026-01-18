#include "head.h"

t_ray	transform_ray(t_ray r, t_matrix m)
{
	r.origin = multiply_matrix_tuple(m, r.origin);
	r.direction = multiply_matrix_tuple(m, r.direction);
	return (r);
}
