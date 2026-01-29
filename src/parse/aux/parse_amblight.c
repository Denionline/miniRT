#include "head.h"

void	parse_amblight(t_amblight **amblight, char *line)
{
	size_t	paramc;

	check_params(line, NPARAM_AMBLIGHT);
	*amblight = saffe_calloc(1, sizeof(t_amblight));
	paramc = 0;
	while (line && *line && paramc < NPARAM_AMBLIGHT)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			(*amblight)->ratio = ft_atof(line);
		else if (paramc == 1 && ++paramc)
			(*amblight)->color = multiply_tuple(string_to_tuple(line, COLOR), 1.0f / 255.0f);
		while (*line && !ft_isspace(*(line++)))
			;
	}
}
