#include "head.h"

static int	error_check(t_object *cylinder)
{
	if (cylinder->position.error_code)
		return (cylinder->position.error_code);
	if (cylinder->normal.error_code)
		return (cylinder->normal.error_code);
	if (cylinder->material.color.error_code)
		return (cylinder->material.color.error_code);
	return (0);
}

static t_pattern	check_pattern(char *line)
{
	if (line[0] == 'c' && line[1] == 'k')
		return (checkboard_pattern(color_float(1, 1, 1), color_float(0, 0, 0), CONE));
	return ((t_pattern){});
}

static int	check_cond(size_t *paramc, t_object *new_cone, char *line)
{
	if ((*paramc) == 0 && *line == 'c')
		line += 2;
	else if ((*paramc) == 0 && ++(*paramc))
		new_cone->position = string_to_tuple(line, POINT);
	else if ((*paramc) == 1 && ++(*paramc))
		new_cone->normal = normalize(
			string_to_tuple(line, VECTOR));
	else if ((*paramc) == 2 && ++(*paramc))
		new_cone->diameter = ft_atof(line);
	else if ((*paramc) == 3 && ++(*paramc))
		new_cone->height = ft_atof(line);
	else if ((*paramc) == 4 && ++(*paramc))
		new_cone->material = material(multiply_tuple(
			string_to_tuple(line, COLOR), 1.0f / 255.0f));
	else if ((*paramc) == 5 && ++(*paramc))
	{
		if(*line != '\n')
		{
			new_cone->material.pattern = check_pattern(line);
			if (!new_cone->material.pattern.has_pattern)
				return (0);
		}
	}
	return (1);
}

static int	fill_values(t_object *new_cone, char *line)
{
	size_t		paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_CYLINDER)
	{
		while (ft_isspace(*line))
			line++;
		if (!check_cond(&paramc, new_cone, line))
			return (0);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (1);
}

t_object	*parse_cone(t_scene *scene, char *line)
{
	t_object	*new_cone;
	t_tuple		p;
	float		radius;
	int			error_code;
	
	check_params(scene, line, NPARAM_CONE, 0);
	new_cone = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_cone->type = CONE;
	if (!fill_values(new_cone, line))
		end(scene, ERR_INVALID_CHAR, line, TRUE);
	error_code = error_check(new_cone);
	if (error_code)
		end(scene, error_code, line, TRUE);
	p = new_cone->position;
	radius = new_cone->diameter * 0.5f;
	new_cone->transform = geral_rotation(new_cone->normal);
	new_cone->transform = multiply_matrix(
		scaling(radius, new_cone->height, radius),
		new_cone->transform
	);
	new_cone->transform = multiply_matrix(
		translation(p.x, p.y, p.z),
		new_cone->transform
	);
	new_cone->transform = inverse(new_cone->transform);
	return (new_cone);
}
