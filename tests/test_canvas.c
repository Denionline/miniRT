#include "head.h"

int main(void)
{
	t_canvas	canvas;
	t_tuple		new_color;

	new_color = color(255, 0, 0);
	init_canvas(&canvas);
	pixel_put(&canvas, 150, 200, new_color);
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
