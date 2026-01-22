#ifndef WORLD_H
# define WORLD_H

#include "head.h"

typedef struct s_camera
{
	float		fov;
	float		pixel_size;
	float		half_w;
	float		half_h;
	t_matrix	transform;
}	t_camera;


typedef struct s_world
{
	t_light			light;
	t_object		**objects;
	unsigned int	n_objs;
}	t_world;

t_world			world(void);
t_world			default_world(void);

t_intersections	intersect_world(t_world w, t_ray r);

t_matrix	view_transform(t_tuple init_location, t_tuple look_pos, t_tuple up_vector);
t_camera	camera(float fov);
t_ray		ray_for_pixel(t_camera cam, float px, float py);

#endif
