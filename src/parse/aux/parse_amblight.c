#include "head.h"

void	parse_amblight(t_amblight *amblight, char *line)
{
	size_t	i;

	if (amblight->ratio)
		exit(42); // Already exists
	i = 1;
	while (line && line[i])
	{
		while (ft_isspace(line[i]))
			i++;
		if (!amblight->ratio)
			amblight->ratio = ft_atof(line + i);
		else if (is_tuple_empty(amblight->color))
			amblight->color = string_to_tuple(line + i, COLOR);
		while (line[i] && !ft_isspace(line[i++]));
	}
}