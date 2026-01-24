#include "head.h"

float	magnitude(t_tuple t)
{
	return (sqrt((t.x * t.x) + (t.y * t.y) + (t.z * t.z)));
}
