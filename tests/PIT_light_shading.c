#include "head.h"

int	main(void)
{
	t_canvas		canvas;
	t_tuple			new_color;
	t_object		*s;
	t_ray			r;
	t_tuple			pos;
	float			world_x;
	float			world_y;
	float			wall_z = 10;
	t_light			l;
	t_intersections	xs;
	t_intersection	rit;
	t_tuple			normal;
	
	
	s = cylinder();
	s->material.color = color_float(1, 0.2, 1);
	// s->material.pattern = gradient_pattern(color_float(3.0f / 255.0f, 0.0f, 30.0f / 255.0f), color_float(236.0f / 255.0f, 56.0f / 255.0f, 188.0f / 255.0f));
	//s->material.pattern = stripe_pattern(color_float(1, 0, 0), color_float(1, 1, 1));
	s->material.pattern = checkboard_pattern(color_float(137.0f / 255.0f, 81.0f / 255.0f, 41.0f / 255.0f), color_float(1, 1, 1), s->type);
	l = point_light(point(-10, 10, -10), color_float(1, 1, 1), 1);
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	new_color = color_float(1, 0, 0);
	init_canvas(&canvas, 900, 900);
	float	ps = wall_z / 900;
	for (int i = 0; i < 900; i += 1)
	{
		world_y =  wall_z / 2 - ps * i;
		for (int j = 0; j < 900; j += 1)
		{
			world_x = -wall_z / 2 + ps * j;
			pos = point(world_y, world_x, wall_z);
			r = ray(point(0, 0, -5), normalize(subtract_tuples(pos, r.origin)));
			xs = intersect(s, r);
			rit = hit(xs);
			if (!rit.object)
				continue;
			pos = position(r, rit.t);
			normal = normal_at(rit.object, pos);
			new_color = lighting(rit.object->material, l, pos, (t_phong_vec){.eyev = negate_tuple(r.direction), .normalv = normal}, *s);
			if (xs.count > 0)
				pixel_put(&canvas, i, j, color(new_color));
			free(xs.array);
		}
		mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	}
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
