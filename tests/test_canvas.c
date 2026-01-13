#include "head.h"
#include <stdio.h>

int main(void)
{
	t_canvas	canvas;
	t_tuple		new_color;

	new_color = color(0, 0, 255);
	new_color = mult_color(color(0, 0, 255), new_color);

	init_canvas(&canvas);
	for (int i = 0; i < WIDTH; i += 1)
	{
		for (int j = 0; j < HEIGHT; j += 1)
			pixel_put(&canvas, i, j, sum_color(new_color, color(0, 0, j)));
	}
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
