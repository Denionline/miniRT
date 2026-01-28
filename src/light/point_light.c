#include "head.h"

t_light	point_light(t_tuple pos, t_tuple color, float brightness)
{
	return ((t_light) {
		.position = pos,
		.intensity = multiply_tuple(color, brightness)
	});
}
