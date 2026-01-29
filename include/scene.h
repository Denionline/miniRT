#ifndef MAP_H
# define MAP_H

#include "world.h"

typedef struct s_amblight
{
	float	ratio;
	t_tuple	color;
	int		exists;
}	t_amblight;

typedef struct s_scene
{
	t_world		*world;
	t_amblight	*amblight;
	t_camera	*camera;
}	t_scene;

#endif