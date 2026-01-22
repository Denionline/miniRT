#include "head.h"

t_camera	camera(float fov)
{
	t_camera	cam;
	float		aspect;
	float		half_v;

	half_v = tanf(fov / 2);
	cam = (t_camera) 
	{
		.fov = fov,
		.transform = identity_matrix()
	};
	aspect = WIDTH / HEIGHT;
	if (aspect < 1)
	{
		cam.half_w = half_v;
		cam.half_w = half_v / aspect; 
	}
	else
	{
		cam.half_w = half_v * aspect;
		cam.half_w = half_v; 
	}
	cam.pixel_size = cam.half_w * 2 / HEIGHT;
	return (cam);
}
