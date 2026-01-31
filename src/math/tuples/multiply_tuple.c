#include "head.h"

t_tuple	multiply_tuple(t_tuple t, float times)
{
	if (t.error_code)
		return (t);
	return (
		tuple(
			t.x * times,
			t.y * times,
			t.z * times,
			t.w * times
		)
	);
}
