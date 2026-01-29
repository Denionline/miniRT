#include "head.h"

t_ray	ray_for_pixel(t_camera cam, float px, float py)
{
	t_tuple	offset;
	t_tuple	world_cord;
	t_tuple	pixel;
	t_ray	r;

	offset = point((px + 0.5) * cam.pixel_size, (py + 0.5) * cam.pixel_size, 0);
	world_cord = point(cam.half_w - offset.x, cam.half_h - offset.y, 0);
	pixel = multiply_matrix_tuple((cam.transform), point(world_cord.x, world_cord.y, -1));
	r.origin = multiply_matrix_tuple((cam.transform), point(0, 0, 0));
	r.direction = normalize(subtract_tuples(pixel, r.origin));
	return (r);
}
