#include "head.h"

int	main(void)
{
	t_canvas	canvas;
	t_tuple		new_color;
	t_object	*s;
	t_ray		r;
	t_tuple		position;
	float		world_x;
	float		world_y;
	float		wall_z = 10;
	t_intersections	xs;
	
	s = sphere();
	s = set_transform(s, scaling(1, 1, 1));
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
			position = point(world_y, world_x, wall_z);
			r = ray(point(0, 0, -5), normalize(subtract_tuples(position, r.origin)));
			xs = intersect(s, r);
			if (xs.count > 0)
				pixel_put(&canvas, i, j, new_color);
			free(xs.array);
		}
		mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	}
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
