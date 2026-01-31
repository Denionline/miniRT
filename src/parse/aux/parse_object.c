#include "head.h"

static t_matrix	geral_rotation(t_tuple	vec_norm);

static t_object	*parse_cylinder(char *line)
{
	t_object	*new_cylinder;
	size_t		paramc;
	t_tuple		p;
	float		radius;

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
			new_cylinder->material = material(multiply_tuple(string_to_tuple(line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	p = new_cylinder->position;
	radius = new_cylinder->diameter * 0.5f;
	new_cylinder->transform = geral_rotation(new_cylinder->normal);
	new_cylinder->transform = multiply_matrix(scaling(radius, new_cylinder->height, radius), new_cylinder->transform);
	new_cylinder->transform = multiply_matrix(translation(p.x, p.y, p.z), new_cylinder->transform);
	new_cylinder->transform = inverse(new_cylinder->transform);
	return (new_cylinder);
}

static t_object	*parse_plane(char *line)
{
	t_object	*new_plane;
	size_t		paramc;
	t_tuple		p;

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
			new_plane->material = material(multiply_tuple(string_to_tuple(line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	p = new_plane->position;
	new_plane->transform = geral_rotation(new_plane->normal);
	new_plane->transform = multiply_matrix(translation(p.x, p.y, p.z), new_plane->transform);
	new_plane->transform = inverse(new_plane->transform);
	return (new_plane);
}

static t_object	*parse_sphere(char *line)
{
	t_object	*new_sphere;
	size_t		paramc;
	float		radius;

	new_sphere = saffe_calloc(1, sizeof(t_object));
	new_sphere->type = SPHERE;
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
	radius = new_sphere->diameter * 0.5f;
	new_sphere->transform = scaling(radius, radius, radius);
	new_sphere->transform = multiply_matrix(translation(new_sphere->position.x, new_sphere->position.y, new_sphere->position.z)\
	, new_sphere->transform);
	new_sphere->transform = inverse(new_sphere->transform);
	return (new_sphere);
}

void	parse_object(t_world *w, char *line, enum object_type type)
{
	t_object	*new_object;

	line += 2;
	new_object = NULL;
	if (type == SPHERE)
		new_object = parse_sphere(line);
	else if (type == PLANE)
		new_object = parse_plane(line);
	else if (type == CYLINDER)
		new_object = parse_cylinder(line);
	append_object_on_world(w, new_object);
}	

static t_matrix	geral_rotation(t_tuple	vec_norm)
{
	t_tuple	vec_d;
	t_tuple	vec_axis;
	float	angle;

	vec_d = vector(0, 1, 0);
	vec_norm = normalize(vec_norm);
	if (is_equals(vec_norm.x, vec_d.x) && is_equals(vec_norm.y, vec_d.y) \
&& is_equals(vec_norm.z, vec_d.z))
		return (identity_matrix());
	if (is_equals(vec_norm.x, -vec_d.x) && is_equals(vec_norm.y, -vec_d.y) \
&& is_equals(vec_norm.z, -vec_d.z))
		return (rotate_x(PI));
	vec_axis = normalize(cross(vec_d, vec_norm));
	angle = acos(dot(vec_d, vec_norm));
	return (rodrigues_rotation(vec_axis, angle));
}
