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

static void	fill_values(t_object *new_plane, char *line)
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
			new_plane->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			new_plane->normal = normalize(
				string_to_tuple(line, VECTOR)
			);
		else if (paramc == 2 && ++paramc)
			new_plane->material = material(
				multiply_tuple(
					string_to_tuple(line, COLOR),
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
	int			error_code;

	check_params(scene, line, NPARAM_PLANE, 0);
	new_plane = saffe_calloc(scene, line, 1, sizeof(t_object));
	new_plane->type = PLANE;
	fill_values(new_plane, line);
	error_code = error_check(new_plane);
	if (error_code)
		end(scene, error_code, line, TRUE);
	p = new_plane->position;
	new_plane->transform = geral_rotation(new_plane->normal);
	new_plane->transform = multiply_matrix(
		translation(p.x, p.y, p.z),
		new_plane->transform
	);
	return (new_plane);
}
