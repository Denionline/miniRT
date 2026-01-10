#include "head.h"

int main(void)
{
	t_canvas	canvas;
	t_tuple		new_color;

	new_color = color(255, 0, 0);
	init_canvas(&canvas);

	for (int i = 0; i < WIDTH; i += 10)
	{
		for (int j = 0; j < HEIGHT; j += 10)
		{
			pixel_put(&canvas, i, j, new_color);
			new_color = add_color(new_color, color(i / 5, j / 5, i / 5));
		}
	}
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
