#include "head.h"

static void	fill_values(t_scene *scene, t_object *new_sphere, char *line)
{
	size_t	paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_SPHERE)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && *line == 's')
			line += 2;
		else if (paramc == 0 && ++paramc)
			new_sphere->position = string_to_tuple(scene, line, POINT);
		else if (paramc == 1 && ++paramc)
			new_sphere->diameter = ft_atof(line);
		else if (paramc == 2 && ++paramc)
			new_sphere->material = material(
				multiply_tuple(
					string_to_tuple(scene, line, COLOR),
					1.0f / 255.0f
				)
			);
		while (*line && !ft_isspace(*(line++)))
			;
	}
}

t_object	*parse_sphere(t_scene *scene, char *line)
{
	t_object	*new_sphere;
	float		radius;

	check_params(scene, line, NPARAM_SPHERE);
	new_sphere = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_sphere->type = SPHERE;
	fill_values(scene, new_sphere, line);
	radius = new_sphere->diameter * 0.5f;
	new_sphere->transform = scaling(radius, radius, radius);
	new_sphere->transform = multiply_matrix(
			translation(
				new_sphere->position.x, 
				new_sphere->position.y,
				new_sphere->position.z 
			),
			new_sphere->transform
		);
	return (new_sphere);
}
