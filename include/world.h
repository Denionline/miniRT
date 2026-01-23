#ifndef WORLD_H
# define WORLD_H

#include "head.h"

typedef struct s_computations
{
	t_object	*object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	int			inside;
	float		t;
}	t_computations;


typedef struct s_world
{
	t_light			light;
	t_object		**objects;
	unsigned int	n_objs;
}	t_world;

t_world			world(void);
t_world			default_world(void);

t_intersections	intersect_world(t_world w, t_ray r);
t_computations	prepare_computations(t_intersection inter, t_ray r);
t_tuple			shade_hit(t_world w, t_computations comps);
t_tuple			color_at(t_world w, t_ray r);

#endif