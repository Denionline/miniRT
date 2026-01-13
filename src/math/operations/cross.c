#include "head.h"

t_tuple	cross(t_tuple t1, t_tuple t2)
{
	return (
		vector(
			(t1.y * t2.z) - (t1.z * t2.y),
			(t1.z * t2.x) - (t1.x * t2.z),
			(t1.x * t2.y) - (t1.y * t2.x)
		)
	);
}
