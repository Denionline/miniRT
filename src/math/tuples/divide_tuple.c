#include "head.h"

t_tuple	divide_tuple(t_tuple t, float times)
{
	if (t.error_code)
		return (t);
	if (times < NARUTO)
		return tuple(0, 0, 0, 0);
	return (
		tuple(
			t.x / times,
			t.y / times,
			t.z / times,
			t.w / times
		)
	);
}
