#include "head.h"

static t_object	*parse_cylinder(char *line)
{
	t_object	*new_cylinder;
	size_t		paramc;
	
	new_cylinder = saffe_calloc(1, sizeof(t_object));
	new_cylinder->type = CYLINDER;
	new_cylinder->transform = identity_matrix();
	paramc = 0;
	while (line && *line && paramc < 5)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			new_cylinder->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			new_cylinder->normal = normalize(string_to_tuple(line, VECTOR));
		else if (paramc == 2 && ++paramc)
			new_cylinder->diameter = ft_atof(line);
		else if (paramc == 3 && ++paramc)
			new_cylinder->height = ft_atof(line);
		else if (paramc == 4 && ++paramc)
			new_cylinder->material = material(string_to_tuple(line, COLOR));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (new_cylinder);
}

static t_object	*parse_plane(char *line)
{
	t_object	*new_plane;
	size_t		paramc;

	new_plane = saffe_calloc(1, sizeof(t_object));
	new_plane->type = PLANE;
	new_plane->transform = identity_matrix();
	paramc = 0;
	while (line && *line && paramc < 3)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			new_plane->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			new_plane->normal = normalize(string_to_tuple(line, VECTOR));
		else if (paramc == 2 && ++paramc)
			new_plane->material = material(string_to_tuple(line, COLOR));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (new_plane);
}

static t_object	*parse_sphere(char *line)
{
	t_object	*new_sphere;
	size_t		paramc;

	new_sphere = saffe_calloc(1, sizeof(t_object));
	new_sphere->type = SPHERE;
	new_sphere->transform = identity_matrix();
	paramc = 0;
	while (line && *line && paramc < 3)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			new_sphere->position = string_to_tuple(line, POINT);
		else if (paramc == 1 && ++paramc)
			new_sphere->diameter = ft_atof(line);
		else if (paramc == 2 && ++paramc)
			new_sphere->material = material(multiply_tuple(string_to_tuple(line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (new_sphere);
}

void	parse_object(t_world *w, char *line, enum object_type type)
{
	t_object	*new_object;

	line += 2;
	if (type == SPHERE)
		new_object = parse_sphere(line);
	else if (type == PLANE)
		new_object = parse_plane(line);
	else if (type == CYLINDER)
		new_object = parse_cylinder(line);
	append_object_on_world(w, new_object);
}	
