#ifndef PARSE_H
# define PARSE_H

#include "scene.h"

enum N_PARAMS {
	NPARAM_TUPLE = 3,
	NPARAM_AMBLIGHT = 2,
	NPARAM_CAMERA = 3,
	NPARAM_LIGHT = 3,
	NPARAM_SPHERE = 3,
	NPARAM_PLANE = 3,
	NPARAM_CYLINDER = 5,
};

void	parse_scene(t_scene **scene, char *file);
void	parse_amblight(t_scene *scene, t_amblight **amblight, char *line);
void	parse_camera(t_scene *scene, t_camera **camera, char *line);
void	parse_light(t_scene *scene, t_light *l, char *line);
void	parse_object(t_scene *s, t_world *w, char *line, enum object_type type);

t_tuple	string_to_tuple(t_scene *scene, char *string, enum e_TUPLE_TYPES w);
void	check_params(t_scene *scene, char *str, enum N_PARAMS nparams);

#endif