#include "head.h"

int	main(void) {
	t_matrix	m;
	t_canvas	canvas;
	t_tuple		p;
	t_tuple		new_color;

	new_color = color(0, 0, 255);
	p = point(0, 0, 0);
	init_canvas(&canvas);
	m = identity_matrix();
	m = multiply_matrix(m, translation(10, 5, 7));
	m = multiply_matrix(m, scaling(5, 5, 5));
	for (int i = 0; i < 12; i++)
	{
		m = multiply_matrix(m, rotation_x(PI / 2));
		p = multiply_matrix_tuple(m, p);
		print_tuple(p);
		pixel_put(&canvas, p.x, p.y, new_color);
	}
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
