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
		return (checkboard_pattern(color_float(1, 1, 1), color_float(0, 0, 0), CYLINDER));
	return ((t_pattern){});
}

static int	check_cond(size_t *paramc, t_object *new_cylinder, char *line)
{
	if ((*paramc) == 0 && *line == 'c')
		line += 2;
	else if ((*paramc) == 0 && ++(*paramc))
		new_cylinder->position = string_to_tuple(line, POINT);
	else if ((*paramc) == 1 && ++(*paramc))
		new_cylinder->normal = normalize(
			string_to_tuple(line, VECTOR));
	else if ((*paramc) == 2 && ++(*paramc))
		new_cylinder->diameter = ft_atof(line);
	else if ((*paramc) == 3 && ++(*paramc))
		new_cylinder->height = ft_atof(line);
	else if ((*paramc) == 4 && ++(*paramc))
		new_cylinder->material = material(multiply_tuple(
			string_to_tuple(line, COLOR), 1.0f / 255.0f));
	else if ((*paramc) == 5 && ++(*paramc))
	{
		if(*line != '\n')
		{
			new_cylinder->material.pattern = check_pattern(line);
			if (!new_cylinder->material.pattern.has_pattern)
				return (0);
		}
	}
	return (1);
}

static int	fill_values(t_object *new_cylinder, char *line)
{
	size_t		paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_CYLINDER)
	{
		while (ft_isspace(*line))
			line++;
		if (!check_cond(&paramc, new_cylinder, line))
			return (0);
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (1);
}

t_object	*parse_cylinder(t_scene *scene, char *line)
{
	t_object	*new_cylinder;
	t_tuple		p;
	float		radius;
	int			error_code;
	
	check_params(scene, line, NPARAM_CYLINDER, 0);
	new_cylinder = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_cylinder->type = CYLINDER;
	if (!fill_values(new_cylinder, line))
		end(scene, ERR_INVALID_CHAR, line, TRUE);
	error_code = error_check(new_cylinder);
	if (error_code)
		end(scene, error_code, line, TRUE);
	p = new_cylinder->position;
	radius = new_cylinder->diameter * 0.5f;
	new_cylinder->transform = geral_rotation(new_cylinder->normal);
	new_cylinder->transform = multiply_matrix(
		scaling(radius, new_cylinder->height, radius),
		new_cylinder->transform
	);
	new_cylinder->transform = multiply_matrix(
		translation(p.x, p.y, p.z),
		new_cylinder->transform
	);
	new_cylinder->transform = inverse(new_cylinder->transform);
	return (new_cylinder);
}
