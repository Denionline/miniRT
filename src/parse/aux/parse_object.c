#include "head.h"

static void	parse_sphere(t_object *sphere, char *line)
{
	size_t	i;

	i = 2;
	while (line && line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (is_tuple_empty(sphere->position))
			sphere->position = string_to_tuple(line + i, POINT);
		else if (!sphere->diameter)
			sphere->diameter = ft_atof(line + i);
		else if (is_tuple_empty(sphere->material.color))






		while (line[i] && !ft_isspace(line[i++]));
	}
}

void	parse_object(t_world *w, char *line, enum object_type type)
{
	t_object	*new_object;

	new_object = ft_calloc(1, sizeof(t_object));
	if (!new_object)
		exit(42); //Malloc error
	*new_object = (t_object){};
	// if (type == SPHERE)
}	
