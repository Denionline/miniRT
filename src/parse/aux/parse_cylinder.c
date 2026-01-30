#include "head.h"

static void	fill_values(t_scene *scene, t_object *new_cylinder, char *line)
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
			new_cylinder->position = string_to_tuple(scene, line, POINT);
		else if (paramc == 1 && ++paramc)
			new_cylinder->normal = normalize(
				string_to_tuple(scene, line, VECTOR));
		else if (paramc == 2 && ++paramc)
			new_cylinder->diameter = ft_atof(line);
		else if (paramc == 3 && ++paramc)
			new_cylinder->height = ft_atof(line);
		else if (paramc == 4 && ++paramc)
			new_cylinder->material = material(multiply_tuple(
				string_to_tuple(scene, line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
}

t_object	*parse_cylinder(t_scene *scene, char *line)
{
	t_object	*new_cylinder;
	t_tuple		p;
	float		radius;
	
	check_params(scene, line, NPARAM_CYLINDER);
	new_cylinder = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_cylinder->type = CYLINDER;
	fill_values(scene, new_cylinder, line);
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
	return (new_cylinder);
}
