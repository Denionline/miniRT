#include "head.h"

void	parse_light(t_light *l, char *line)
{
	size_t	paramc;

	paramc = 0;
	while (line && *line && paramc < 3)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			l->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			l->brightness = ft_atof(line);
		else if (paramc == 2 && ++paramc)
			l->color = string_to_tuple(line, COLOR);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	l->intensity = multiply_tuple(l->color, l->brightness);
}