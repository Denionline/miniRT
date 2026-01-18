#include "head.h"

int	main(void) {
	t_canvas	canvas; init_canvas(&canvas);
	t_tuple		new_color = color(255, 255, 255);

	const t_tuple base = point(0, 1, 0);

	const t_matrix scale = scaling(200, 200, 1);
	const t_matrix translate = translation(WIDTH / 2, HEIGHT / 2, 0);

	const t_matrix total_base = multiply_matrix(translate, scale);
	
	for (int i = 0; i < 12; i++)
	{
		t_matrix rotation = rotation_z(i * PI / 6);

		t_tuple rotated = multiply_matrix_tuple(rotation, base);
		t_tuple final_point = multiply_matrix_tuple(total_base, rotated);

		pixel_put(&canvas, final_point.x, final_point.y, new_color);
	}

	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
