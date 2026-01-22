#ifndef WORLD_H
# define WORLD_H

#include "head.h"

typedef struct s_camera
{
	float		fov;
	float		pixel_size;
	t_matrix	transform;
}	t_camera;

t_matrix	view_transform(t_tuple init_location, t_tuple look_pos, t_tuple up_vector);
t_camera	camera(float fov);
#endif
