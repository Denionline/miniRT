#ifndef PARSE_H
# define PARSE_H

#include "scene.h"

enum N_PARAMS {
	NPARAM_TUPLE = 3,
	NPARAM_AMBLIGHT = 3,
	NPARAM_CAMERA = 4,
	NPARAM_LIGHT = 4,
	NPARAM_SPHERE = 4,
	NPARAM_PLANE = 4,
	NPARAM_CYLINDER = 6,
};

void		parse_scene(t_scene **scene, char *file);
void		parse_amblight(t_scene *scene, t_amblight **amblight, char *line);
void		parse_camera(t_scene *scene, t_camera **camera, char *line);
void		parse_light(t_scene *scene, t_light *l, char *line);
void		parse_object(t_scene *s, t_world *w, char *line, enum object_type type);

t_object	*parse_sphere(t_scene *scene, char *line);
t_object	*parse_plane(t_scene *scene, char *line);
t_object	*parse_cylinder(t_scene *scene, char *line);

t_tuple		string_to_tuple(char *string, enum e_TUPLE_TYPES w);
void		check_params(t_scene *scene, char *str, int nparams, int exists);
t_matrix	geral_rotation(t_tuple	vec_norm);

#endif