#include "head.h"

int	main(void)
{
	t_canvas	canvas;
	t_tuple		new_color;
	t_object	s;
	t_sphere	sphere;
	t_ray		r;
	t_tuple		position;
	float		world_x;
	float		world_y;
	float		wall_z = 10;
	t_intersections	xs;

	s.position = point(0, 0, 0);
	s.type = SPHERE;
	sphere.diameter = 2.0f;
	s.options = &sphere;
	r = ray(point(0, 0, -5), vector(0, 0, 1));
	new_color = color(255, 0, 0);
	init_canvas(&canvas);
	float	ps = wall_z / WIDTH;
	for (int i = 0; i < WIDTH; i += 1)
	{
		world_y =  wall_z / 2 - ps * i;
		for (int j = 0; j < HEIGHT; j += 1)
		{
			world_x = -wall_z / 2 + ps * j;
			printf("%f\n", world_x);
			printf("%f\n", world_y);
			position = point(world_y, world_x, wall_z);
			r = ray(point(0, 0, -5), normalize(subtract_tuples(position, r.origin)));
			xs = intersect(&s, r);
			if (xs.count > 0)
			{
				printf("ACERTOU    %d\n", i);
				printf("ACERTOU    %d\n", j);
				pixel_put(&canvas, i, j, new_color);
			}
		}
	}
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
