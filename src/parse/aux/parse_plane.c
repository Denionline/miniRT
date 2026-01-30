#include "head.h"

static void	fill_values(t_scene *scene, t_object *new_plane, char *line)
{
	size_t		paramc;

	paramc = 0;
	while (line && *line && paramc < NPARAM_PLANE)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && *line == 'p')
			line += 2;
		else if (paramc == 0 && ++paramc)
			new_plane->position = string_to_tuple(scene, line, POINT);
		else if (paramc == 1 && ++paramc)
			new_plane->normal = normalize(
				string_to_tuple(scene, line, VECTOR)
			);
		else if (paramc == 2 && ++paramc)
			new_plane->material = material(
				multiply_tuple(
					string_to_tuple(scene, line, COLOR),
					1.0f / 255.0f
				)
			);
		while (*line && !ft_isspace(*(line++)))
			;
	}
}

t_object	*parse_plane(t_scene *scene, char *line)
{
	t_object	*new_plane;
	t_tuple		p;

	check_params(scene, line, NPARAM_PLANE);
	new_plane = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_plane->type = PLANE;
	fill_values(scene, new_plane, line);
	p = new_plane->position;
	new_plane->transform = geral_rotation(new_plane->normal);
	new_plane->transform = multiply_matrix(
		translation(p.x, p.y, p.z),
		new_plane->transform
	);
	return (new_plane);
}
