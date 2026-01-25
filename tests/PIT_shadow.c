#include "head.h"

int	main(void)
{
	t_world 	w;
	t_camera	c;
	t_tuple		from;
	t_tuple		to;
	t_tuple 	up;
	t_object	*floor;
	t_object	*l_wall;
	t_object	*r_wall;
	t_object	*middle;
	t_object	*right;
	t_object	*left;

	w = world();

	floor = sphere();
	floor->transform = scaling(10, 0.01, 10);
	floor->material.color = color_float(1, 0.9, 0.9);
	floor->material.specular = 0;

	l_wall = sphere();
	l_wall->transform = multiply_matrix(
		translation(0, 0, 5),
		multiply_matrix(
			rotate_y(-PI/4),
			multiply_matrix(
				rotate_x(PI/2),
				scaling(10, 0.01, 10)
			)
		)
	);
	l_wall->material = floor->material;
	r_wall = sphere();
	r_wall->transform = multiply_matrix(
		translation(0, 0, 5),
		multiply_matrix(
			rotate_y(PI/4),
			multiply_matrix(
				rotate_x(PI/2), 
				scaling(10, 0.01, 10)
			)
		)
	);
	r_wall->material = floor->material;
	
	middle = sphere();
	middle->transform = (translation(-0.5, 1, 0.5));
	middle->material = material();
	middle->material.color = color_float(0.1, 1, 0.5);
	middle->material.difuse = 0.7;
	middle->material.specular = 0.3;

	right = sphere();
	right->transform = multiply_matrix(
		translation(1.5, 0.5, -0.5),
		scaling(0.5, 0.5, 0.5)
	);
	right->material = material();
	right->material.color = color_float(0.5, 1, 0.1);
	right->material.difuse = 0.7;
	right->material.specular = 0.3;

	left = sphere();
	left->transform = multiply_matrix(
		translation(-1.5, 0.33, -0.75),
		scaling(0.33, 0.33, 0.33)
	);
	left->material = material();
	left->material.color = color_float(1, 0.8, 0.1);
	left->material.difuse = 0.7;
	left->material.specular = 0.3;

	append_object_on_world(&w, floor);
	append_object_on_world(&w, l_wall);
	append_object_on_world(&w, r_wall);
	append_object_on_world(&w, middle);
	append_object_on_world(&w, right);
	append_object_on_world(&w, left);

	w.light = point_light(
		point(-10, 10, -10),
		color_float(1, 1, 1)
	);
	c = camera(500, 500, PI / 3);
	from = point(0, 1.5, -5);
	to = point(0, 1, 0);
	up = vector(0, 1, 0);
	c.transform  = (view_transform(from, to, up));
	t_canvas canvas = render(c, w);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
