#include "head.h"

void	parse_light(t_light *l, char *line)
{
	size_t	i;

	if (!is_tuple_empty(l->position))
		exit(42); // Already exists
	i = 1;
	while (line && line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (is_tuple_empty(l->position))
			l->position = string_to_tuple(line + i, POINT);
		else if (!l->brightness)
			l->brightness = ft_atof(line + i);
		else if (is_tuple_empty(l->color))
			l->color = string_to_tuple(line + i, COLOR);
		while (line[i] && !ft_isspace(line[i++]));
	}
}