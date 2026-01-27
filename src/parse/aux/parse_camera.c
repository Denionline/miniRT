#include "head.h"

void	parse_camera(t_camera *c, char *line)
{
	t_tuple	direction;
	t_tuple	position;
	float	fov;
	size_t	i;

	if (c->fov)
		exit(42); // Already exists
	i = 1;
	while (line && line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (is_tuple_empty(position))
			position = string_to_tuple(line + i, POINT);
		else if (is_tuple_empty(direction))
			direction = string_to_tuple(line + i, VECTOR);
		else if (!fov)
			fov = ft_atof(line + i);
		while (line[i] && !ft_isspace(line[i++]));
	}
	*c = camera(500, 500, fov);
	c->position = position;
	c->direction = direction;
}
