#include "head.h"

void	parse_object(t_scene *s, t_world *w, char *line, enum object_type type)
{
	t_object	*new_object;

	new_object = NULL;
	if (type == SPHERE)
		new_object = parse_sphere(s, line);
	else if (type == PLANE)
		new_object = parse_plane(s, line);
	else if (type == CYLINDER)
		new_object = parse_cylinder(s, line);
	else if (type == CONE)
		new_object = parse_cone(s, line);
	append_object_on_world(w, new_object);
}	

