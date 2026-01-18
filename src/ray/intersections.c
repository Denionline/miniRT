#include "head.h"

t_intersections	intersections(t_intersection values[], unsigned int count)
{
	t_intersection	*new_array;
	unsigned int	i;

	new_array = calloc(count, sizeof(t_intersection));
	if (!new_array)
		exit(404);
	i = -1;
	while (++i < count)
		new_array[i] = values[i];
	return (
		(t_intersections) {
			.array = new_array,
			.count = count,
		}
	);
}
