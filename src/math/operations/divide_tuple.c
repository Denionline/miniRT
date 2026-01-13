#include "head.h"

t_tuple	divide_tuple(t_tuple t, float times)
{
	return (
		tuple(
			t.x / times,
			t.y / times,
			t.z / times,
			t.w / times
		)
	);
}
