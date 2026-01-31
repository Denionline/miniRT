#include "head.h"

int	main(void)
{
	t_world		*w;
	t_camera	c;
	t_tuple		from;
	t_tuple		to;
	t_tuple		up;

	t_object	*floor;
	t_object	*middle;
	t_object	*right;
	t_object	*left;

	w = world();
	w->light = point_light(point(-10, 10, -10), color_float(1, 1, 1), 1);

	floor = plane();
	floor->material = material(color_float(1, 0.9, 0.9));
	floor->material.pattern = checkboard_pattern(color_float(137.0f / 255.0f, 81.0f / 255.0f, 41.0f / 255.0f), color_float(1, 1, 1), floor->type);
	append_object_on_world(w, floor);

	middle = sphere();
	middle->transform = translation(-0.5, 1, 0.5);
	middle->material = material(color_float(0.1, 1, 0.5));
	middle->material.difuse = 0.7;
	middle->material.specular = 0.3;
	append_object_on_world(w, middle);

	right = sphere();
	right->transform = multiply_matrix(translation(1.5, 0.5, -0.5), scaling(0.5, 0.5, 0.5));
	right->material = material(color_float(0.5, 1, 0.1));
	right->material.difuse = 0.7;
	right->material.specular = 0.3;
	append_object_on_world(w, right);

	left = sphere();
	left->transform = multiply_matrix(translation(-1.5, 0.33, -0.75), scaling(0.33, 0.33, 0.33));
	left->material = material(color_float(1, 0.8, 0.1));
	left->material.difuse = 0.7;
	left->material.specular = 0.3;
	append_object_on_world(w, left);

	c = camera(500, 500, PI / 3);
	from = point(0, 1.5, -5);
	to = sum_tuples(from, vector(0, 0, 1));
	up = vector(0, 1, 0);
	c.transform = inverse(view_transform(from, to, up));
	t_canvas canvas = render(c, *w);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
