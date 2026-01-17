#include "head.h"

t_ray	ray(t_tuple origin, t_tuple direction)
{
	return ((t_ray) {.origin = origin, .direction = direction});
}
