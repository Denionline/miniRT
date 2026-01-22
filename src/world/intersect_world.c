#include "head.h"

t_intersections	append_intersections(t_intersections inters, t_intersections temp )
{
	t_intersections	new_inters;
	size_t			i;
	size_t			j;

	new_inters.count = inters.count + temp.count;
	new_inters.array = ft_calloc(
		new_inters.count,
		sizeof(t_intersection)
	);
	if (!new_inters.array)
		exit(42);
	i = 0;
	while (i < inters.count)
	{
		new_inters.array[i] = inters.array[i];
		i++;
	}
	j = 0;
	while (j < temp.count)
		new_inters.array[i++] = temp.array[j++];
	free(inters.array);
	return (new_inters);
}


t_intersections	intersect_world(t_world w, t_ray r)
{
	t_intersections	inters;
	t_intersections	temp;
	size_t			i;

	inters.array = NULL;
	inters.count = 0;
	i = 0;
	while (i < w.n_objs)
	{
		temp = intersect(w.objects[i], r);
		if (temp.count > 0)
			inters = append_intersections(inters, temp);
		free(temp.array);
		i++;
	}
	inters.array = sort_intersections(inters.array, inters.count);
	return (inters);
}
