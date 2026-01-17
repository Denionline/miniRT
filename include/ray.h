#ifndef RAY_H
# define RAY_H

#include "head.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

t_ray	ray(t_tuple origin, t_tuple direction);

#endif
