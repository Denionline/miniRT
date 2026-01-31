#include "head.h"

static int	error_check(t_object *plane)
{
	if (plane->position.error_code)
		return (plane->position.error_code);
	if (plane->normal.error_code)
		return (plane->normal.error_code);
	if (plane->material.color.error_code)
		return (plane->material.color.error_code);
	return (0);
}

static t_pattern	check_pattern(char *line)
{
	if (line[0] == 'c' && line[1] == 'k')
		return (checkboard_pattern(color_float(1, 1, 1), color_float(0, 0, 0), PLANE));
	return ((t_pattern){});
}

static int	check_cond(size_t *paramc, t_object *new_plane, char *line)
{
	if ((*paramc) == 0 && *line == 'p')
		line += 2;
	else if ((*paramc) == 0 && ++(*paramc))
		new_plane->position = string_to_tuple(line, POINT);
	else if ((*paramc) == 1 && ++(*paramc))
		new_plane->normal = normalize(
			string_to_tuple(line, VECTOR)
		);
	else if ((*paramc) == 2 && ++(*paramc))
		new_plane->material = material(
			multiply_tuple(
				string_to_tuple(line, COLOR),
				1.0f / 255.0f
			)
		);
	else if ((*paramc) == 3 && ++(*paramc))
	{
		if(*line != '\n')
		{
			new_plane->material.pattern = check_pattern(line);
			if (!new_plane->material.pattern.has_pattern)
				return (0);
		}
	}
	return (1);
}

static int	fill_values(t_object *new_plane, char *line)
{
	size_t		paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_PLANE)
	{
		while (ft_isspace(*line))
			line++;
		if (!check_cond(&paramc, new_plane, line))
			return (0);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (1);
}

t_object	*parse_plane(t_scene *scene, char *line)
{
	t_object	*new_plane;
	t_tuple		p;
	int			error_code;

	check_params(scene, line, NPARAM_PLANE, 0);
	new_plane = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_plane->type = PLANE;
	if (!fill_values(new_plane, line))
		end(scene, ERR_INVALID_CHAR, line, TRUE);
	error_code = error_check(new_plane);
	if (error_code)
		end(scene, error_code, line, TRUE);
	p = new_plane->position;
	new_plane->transform = geral_rotation(new_plane->normal);
	new_plane->transform = multiply_matrix(
		translation(p.x, p.y, p.z),
		new_plane->transform
	);
	new_plane->transform = inverse(new_plane->transform);
	new_plane->material.pattern.transform = new_plane->transform;
	return (new_plane);
}
