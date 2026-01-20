#include "head.h"

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	return subtract_tuples(
		in,
		multiply_tuple(
			normal,
			2 * dot(in, normal)
		)
	);
}

