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

static void	fill_values(t_object *new_cylinder, char *line)
{
	size_t		paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_CYLINDER)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && *line == 'c')
			line += 2;
		else if (paramc == 0 && ++paramc)
			new_cylinder->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			new_cylinder->normal = normalize(
				string_to_tuple(line, VECTOR));
		else if (paramc == 2 && ++paramc)
			new_cylinder->diameter = ft_atof(line);
		else if (paramc == 3 && ++paramc)
			new_cylinder->height = ft_atof(line);
		else if (paramc == 4 && ++paramc)
			new_cylinder->material = material(multiply_tuple(
				string_to_tuple(line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
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
	fill_values(new_cylinder, line);
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
