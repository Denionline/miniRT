#include "head.h"

static t_matrix	geral_rotation(t_tuple	vec_norm);

static t_object	*parse_cylinder(t_scene *scene, char *line)
{
	t_object	*new_cylinder;
	size_t		paramc;
	
	check_params(scene, line, NPARAM_CYLINDER);
	new_cylinder = saffe_calloc(scene, 1, sizeof(t_object));
	new_cylinder->type = CYLINDER;
	paramc = 0;
	while (line && *line && paramc < NPARAM_CYLINDER)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			new_cylinder->position = string_to_tuple(scene, line, POINT);
		else if (paramc == 1 && ++paramc)
			new_cylinder->normal = normalize(string_to_tuple(scene, line, VECTOR));
		else if (paramc == 2 && ++paramc)
			new_cylinder->diameter = ft_atof(line);
		else if (paramc == 3 && ++paramc)
			new_cylinder->height = ft_atof(line);
		else if (paramc == 4 && ++paramc)
			new_cylinder->material = material(multiply_tuple(string_to_tuple(scene, line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (new_cylinder);
}

static t_object	*parse_plane(t_scene *scene, char *line)
{
	t_object	*new_plane;
	size_t		paramc;
	t_tuple		p;

	check_params(scene, line, NPARAM_PLANE);
	new_plane = saffe_calloc(scene, 1, sizeof(t_object));
	new_plane->type = PLANE;
	paramc = 0;
	while (line && *line && paramc < NPARAM_PLANE)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			new_plane->position = string_to_tuple(scene, line, POINT);
		else if (paramc == 1 && ++paramc)
			new_plane->normal = normalize(string_to_tuple(scene, line, VECTOR));
		else if (paramc == 2 && ++paramc)
			new_plane->material = material(multiply_tuple(string_to_tuple(scene, line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	p = new_plane->position;
	new_plane->transform = geral_rotation(new_plane->normal);
	new_plane->transform = multiply_matrix(translation(p.x, p.y, p.z), new_plane->transform);
	return (new_plane);
}

static t_object	*parse_sphere(t_scene *scene, char *line)
{
	t_object	*new_sphere;
	size_t		paramc;

	check_params(scene, line, NPARAM_SPHERE);
	new_sphere = saffe_calloc(scene, 1, sizeof(t_object));
	new_sphere->type = SPHERE;
	paramc = 0;
	while (line && *line && paramc < NPARAM_SPHERE)
	{
		while (ft_isspace(*line))
			line++;
		if (paramc == 0 && ++paramc)
			new_sphere->position = string_to_tuple(scene, line, POINT);
		else if (paramc == 1 && ++paramc)
			new_sphere->diameter = ft_atof(line);
		else if (paramc == 2 && ++paramc)
			new_sphere->material = material(multiply_tuple(string_to_tuple(scene, line, COLOR), 1.0f / 255.0f));
		while (*line && !ft_isspace(*(line++)))
			;
	}
	return (new_sphere);
}

void	parse_object(t_scene *s, t_world *w, char *line, enum object_type type)
{
	t_object	*new_object;

	line += 2;
	if (type == SPHERE)
		new_object = parse_sphere(s, line);
	else if (type == PLANE)
		new_object = parse_plane(s, line);
	else if (type == CYLINDER)
		new_object = parse_cylinder(s, line);
	new_object->transform = identity_matrix();
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
	vec_axis = normalize(cross(vec_d, vec_norm));
	angle = acos(dot(vec_d, vec_norm));
	return (rodrigues_rotation(vec_axis, angle));
}
