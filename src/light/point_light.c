#include "head.h"

t_light	point_light(t_tuple pos, t_tuple color)
{
	return ((t_light) {
		.position = pos,
		.intensity = color
	});
}
