#include "head.h"

static size_t	is_all_negatives(t_intersections inters)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (i < inters.count)
		count += inters.array[i++].t < 0;
	return (count == inters.count);
}

static t_intersection get_smallest_time(t_intersection *values, size_t size)
{
	t_intersection	*best;
	size_t			i;

	best = NULL;
	i = 0;
	while (i < size)
	{
		if (values[i].t >= 0 && (best == NULL || values[i].t < best->t))
			best = &values[i];
		i++;
	}
	if (best)
		return (*best);
	return (intersection(0, NULL));
}

t_intersection	hit(t_intersections inters)
{
	if (is_all_negatives(inters))
		return (intersection(0, NULL));
	return (get_smallest_time(inters.array, inters.count));
}
