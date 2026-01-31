#include "head.h"

static int	error_check(t_light *l)
{
	if (l->position.error_code)
		return (l->position.error_code);
	if (l->color.error_code)
		return (l->color.error_code);
	return (0);
}
static void	fill_values(t_light *l, char *line)
{
	size_t	paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_LIGHT)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && *line == 'L')
			line += 1;
		else if (paramc == 0 && ++paramc)
			l->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			l->brightness = ft_atof(line);
		else if (paramc == 2 && ++paramc)
			l->color = multiply_tuple(
				string_to_tuple(line, COLOR),
				1.0f / 255.0f
			);
		while (*line && !ft_isspace(*(line++)))
			;
	}
}

void	parse_light(t_scene *scene, t_light *l, char *line)
{
	int	error_code;

	check_params(scene, line, NPARAM_LIGHT, l->exists);
	fill_values(l, line);
	if (l->brightness < 0.00f || l->brightness > 1.00f)
		end(scene, ERR_OUT_OF_RANGE, line, TRUE);
	error_code = error_check(l);
	if (error_code)
		end(scene, error_code, line, TRUE);
	l->intensity = multiply_tuple(l->color, l->brightness);
	l->exists = TRUE;
}
