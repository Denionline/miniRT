#include "head.h"
#include <stdio.h>

int main(void)
{
	t_canvas	canvas;
	init_canvas(&canvas);
	pixel_put(&canvas, 150, 200, 11250145);
	mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
	ft_init_hooks(&canvas);
	mlx_loop(canvas.mlx_ptr);
}
