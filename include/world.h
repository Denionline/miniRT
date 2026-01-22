#ifndef WORLD_H
# define WORLD_H

#include "head.h"

typedef struct s_world
{
	t_light			light;
	t_object		**objects;
	unsigned int	n_objs;
}	t_world;

t_world			world(void);
t_world			default_world(void);

t_intersections	intersect_world(t_world w, t_ray r);

#endif