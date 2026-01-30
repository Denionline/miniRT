#include "head.h"

void	parse_camera(t_camera **c, char *line)
{
	t_tuple	direction;
	t_tuple	position;
	float	fov;
	size_t	paramc;

	*c = saffe_calloc(1, sizeof(t_camera));
	fov = 0.0f;
	direction = (t_tuple){};
	position = (t_tuple){};
	paramc = 0;
	while (line && *line && paramc < 3)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			direction = string_to_tuple(line, VECTOR);
		else if (paramc == 2 && ++paramc)
			fov = ft_atof(line);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	**c = camera(500, 300, fov * PI / 180.0f );
	(*c)->transform = inverse(view_transform(position, sum_tuples(position, direction), vector(0, 1, 0)));
}
