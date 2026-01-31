#ifndef WORLD_H
# define WORLD_H

#include "head.h"

typedef struct s_camera
{
	float		hsize;
	float		vsize;
	float		fov;
	float		pixel_size;
	float		half_w;
	float		half_h;
	t_matrix	transform;
	t_tuple		position;
	t_tuple		direction;
}	t_camera;

typedef struct s_computations
{
	t_object	*object;
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	int			inside;
	float		t;
	t_tuple		over_point;
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

t_matrix		view_transform(t_tuple init_location, t_tuple look_pos, t_tuple up_vector);
t_camera		camera(float hsize, float vsize, float fov);
t_ray			ray_for_pixel(t_camera cam, float px, float py);

int				is_shadowed(t_world w, t_tuple p);

//aux
void	append_object_on_world(t_world *w, t_object *new_object);

#endif
