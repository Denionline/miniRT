#include "head.h"

t_tuple	normalize(t_tuple t)
{
	const float	mag = magnitude(t);

	if (t.error_code)
		return (t);
	return (
		tuple(
			t.x / mag,
			t.y / mag,
			t.z / mag,
			t.w / mag
		)
	);
}
