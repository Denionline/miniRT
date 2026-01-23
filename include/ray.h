#ifndef RAY_H
# define RAY_H

#include "head.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_intersection
{
	float		t;
	t_object	*object;
} t_intersection;

typedef struct s_intersections
{
	t_intersection	*array;
	unsigned int	count;
} t_intersections;


t_ray			ray(t_tuple origin, t_tuple direction);
t_ray			transform_ray(t_ray r, t_matrix m);
t_tuple			position(t_ray r, float	t);
t_ray			ray(t_tuple origin, t_tuple direction);
t_tuple			position(t_ray r, float	t);
t_intersections	intersect(t_object *object, t_ray r);
t_intersection	intersection(float value_of, t_object *object);
t_intersections	intersections(t_intersection values[], unsigned int count);
t_intersection	*sort_intersections(t_intersection val[], size_t len);
t_intersection	hit(t_intersections inters);

#endif
