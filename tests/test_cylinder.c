#include "head.h"

int	main(void)
{
	t_world		w;
	t_camera	c;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	t_object	*floor;


	w = world();

	w.light = point_light(point(-10, 10, -25), color_float(1, 1, 1));

	floor = cylinder();
	floor->height = 2.0f;
	floor->material = material();
	floor->material.color = color_float(222.0f/255.0f, 184.0f/255.0f, 135/255.0f);
	floor->material.specular = 0;
	append_object_on_world(&w, floor);

	c = camera(500, 500, PI / 3);
	from = point(0, 1.5, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	c.transform = (view_transform(from, to, up));
	t_canvas canvas = render(c, w);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
