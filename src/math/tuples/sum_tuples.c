#include "head.h"

t_tuple	sum_tuples(t_tuple t1, t_tuple t2)
{
	if (t1.error_code || t2.error_code)
		return ((t_tuple){.error_code = ERR_INVALID_TUPLE});
	return (
		tuple(
			t1.x + t2.x,
			t1.y + t2.y,
			t1.z + t2.z,
			t1.w + t2.w
		)
	);
}
