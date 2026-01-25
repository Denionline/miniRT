#include "head.h"

t_intersections	intersections(t_intersection values[], unsigned int count)
{
	t_intersection	*new_array;
	unsigned int	i;

	if (!values || !count)
		return ((t_intersections){NULL, 0});
	new_array = calloc(count, sizeof(t_intersection));
	if (!new_array)
		exit(42);
	i = 0;
	while (i < count)
	{
		new_array[i] = values[i];
		i++;
	}
	return (
		(t_intersections) {
			.array = sort_intersections(new_array, count),
			.count = count,
		}
	);
}
