#include "head.h"

t_tuple	tuple(float x, float y, float z, float w)
{
	return ((t_tuple) {{x}, {y}, {z}, w});
}

t_tuple	vector(float x, float y, float z)
{
	return ((t_tuple) {{x}, {y}, {z}, VECTOR});
}

t_tuple	point(float x, float y, float z)
{
	return ((t_tuple) {{x}, {y}, {z}, POINT});
}

t_tuple	color(float r, float g, float b)
{
	return ((t_tuple) {{r}, {g}, {b}, COLOR});
}
