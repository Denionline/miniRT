#ifndef MAP_H
# define MAP_H

#include "head.h"

typedef struct s_amblight
{
	float	ratio;
	t_tuple	color;
}	t_amblight;

typedef struct s_scene
{
	t_world		world;
	t_amblight	amblight;
	t_camera	camera;
}	t_scene;

void	parse_scene(t_scene *scene, char *file);
void	parse_amblight(t_amblight *amblight, char *line);
void	parse_camera(t_camera *camera, char *line);
void	parse_light(t_world *w, char *line);
void	parse_object(t_world *w, char *line, enum object_type type);

t_tuple	string_to_tuple(char *string, enum e_TUPLE_TYPES w);

#endif