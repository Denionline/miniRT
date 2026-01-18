#ifndef RAY_H
# define RAY_H

#include "head.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_intersect
{
	unsigned int	count;
	float			pos[2];

}	t_intersect;


t_ray		ray(t_tuple origin, t_tuple direction);
t_tuple		position(t_ray r, float	t);
t_intersect	intersect(t_object spere, t_ray r);

#endif
