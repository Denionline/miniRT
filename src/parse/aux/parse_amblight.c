#include "head.h"

static int	error_check(t_amblight *amblight)
{
	if (amblight->color.error_code)
		return (amblight->color.error_code);
	return (0);
}

static void	fill_values(t_amblight *amblight, char *line)
{
	size_t	paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_AMBLIGHT)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && *line == 'A')
			line += 1;
		else if (paramc == 0 && ++paramc)
			amblight->ratio = ft_atof(line);
		else if (paramc == 1 && ++paramc)
			amblight->color = multiply_tuple(
				string_to_tuple(line, COLOR),
				1.0f / 255.0f
			);
		while (*line && !ft_isspace(*(line++)))
			;
	}
}

void	parse_amblight(t_scene *scene, t_amblight **amblight, char *line)
{
	int	error_code;

	check_params(scene, line, NPARAM_AMBLIGHT, (*amblight) != NULL);
	*amblight = saffe_calloc(scene, line, 1, sizeof(t_amblight));
	fill_values(*amblight, line);
	if ((*amblight)->ratio < 0.00f || (*amblight)->ratio > 1.00f)
		end(scene, ERR_OUT_OF_RANGE, line, TRUE);
	error_code = error_check(*amblight);
	if (error_code)
		end(scene, error_code, line, TRUE);
}
