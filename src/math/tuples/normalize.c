#include "head.h"

t_tuple	normalize(t_tuple t)
{
	const float	mag = 1.0f / magnitude(t);

	return (
		tuple(
			t.x * mag,
			t.y * mag,
			t.z * mag,
			t.w * mag
		)
	);
}
