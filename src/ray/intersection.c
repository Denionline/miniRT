#include "head.h"

t_intersection	intersection(float value_of, t_object *object)
{
	return (
		(t_intersection) {
			.t = value_of,
			.object = object,
		}
	);
}
