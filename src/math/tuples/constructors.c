#include "head.h"

t_tuple	tuple(float x, float y, float z, float w)
{
	return ((t_tuple) {.x = x, .y = y, .z = z, .w = w});
}

t_tuple	vector(float x, float y, float z)
{
	return ((t_tuple) {.x = x, .y = y, .z = z, .w = VECTOR});
}

t_tuple	point(float x, float y, float z)
{
	return ((t_tuple) {.x = x, .y = y, .z = z, .w = POINT});
}

t_tuple	color(float r, float g, float b)
{
	if (r > 1)
		r = 1;
	if (r < 0)
		r = 0;
	if (g > 1)
		g = 1;
	if (g < 0)
		g = 0;
	if (b > 1)
		b = 1;
	if (b < 0)
		b = 0;
	return ((t_tuple) {.r = r * 255, .g = g * 255, .b = b * 255});
}

t_tuple	color_float(float x, float y, float z)
{
	return ((t_tuple) {.x = x, .y = y, .z = z, .w = COLOR});
}

