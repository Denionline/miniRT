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

t_tuple	color(uint8_t r, uint8_t g, uint8_t b)
{
	return ((t_tuple) {.r = r, .g = g, .b = b});
}
