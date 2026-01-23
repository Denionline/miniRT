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

t_tuple	color(t_tuple color_f)
{
	if (color_f.x > 1)
		color_f.x = 1;
	if (color_f.x < 0)
		color_f.x = 0;
	if (color_f.y > 1)
		color_f.y = 1;
	if (color_f.y < 0)
		color_f.y = 0;
	if (color_f.z > 1)
		color_f.z = 1;
	if (color_f.z < 0)
		color_f.z = 0;
	return ((t_tuple) {.r = color_f.x * 255, .g = color_f.y * 255, .b = color_f.z * 255});
}

t_tuple	color_float(float x, float y, float z)
{
	return ((t_tuple) {.x = x, .y = y, .z = z, .w = COLOR});
}

