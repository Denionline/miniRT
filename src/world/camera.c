#include "head.h"


t_camera	camera(float fov)
{
	t_camera	cam;
	float		aspect;

	cam = (t_camera) 
	{
		.fov = fov,
		.transform = identity_matrix()
	};
	aspect = WIDTH / HEIGHT;
	cam.pixel_size = tanf(fov / 2) * 2 / WIDTH;
	if (aspect < 1)
		cam.pixel_size *= aspect;
	return (cam);
}
