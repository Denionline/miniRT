#include "head.h"

static int	error_check(t_camera *camera)
{
	if (camera->position.error_code)
		return (camera->position.error_code);
	if (camera->direction.error_code)
		return (camera->direction.error_code);
	return (0);
}

static void	fill_values(t_camera *c, char *line)
{
	size_t	paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_CAMERA)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && *line == 'C')
			line += 1;
		else if (paramc == 0 && ++paramc)
			c->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			c->direction = string_to_tuple(line, VECTOR);
		else if (paramc == 2 && ++paramc)
			c->fov = ft_atof(line);
		while (*line && !ft_isspace(*(line++)))
			;
	}
}

void	parse_camera(t_scene *scene, t_camera **c, char *line)
{
	t_tuple	direction;
	t_tuple	position;
	float	fov;
	int		error_code;

	check_params(scene, line, NPARAM_CAMERA, (*c) != NULL);
	*c = saffe_calloc(scene, line, 1, sizeof(t_camera));
	fill_values(*c, line);
	error_code = error_check(*c);
	if (error_code)
		end(scene, error_code, line, TRUE);
	fov = (*c)->fov;
	if (fov < 0 || 180 < fov)
		end(scene, ERR_OUT_OF_RANGE, line, TRUE);
	position = (*c)->position;
	direction = (*c)->direction;
	**c = camera(500, 300, fov * PI / 180.0f);
	(*c)->transform = inverse(
		view_transform(
			position,
			sum_tuples(position, direction),
			vector(0, 1, 0)
		)
	);
	
}
