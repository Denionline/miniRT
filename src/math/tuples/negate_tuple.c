#include "head.h"

t_tuple	negate_tuple(t_tuple t)
{
	if (t.error_code)
		return (t);
	return (
		tuple(
			-t.x,
			-t.y,
			-t.z,
			-t.w
		)
	);
}
