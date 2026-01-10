#include "head.h"

int main(void)
{
	t_canvas	canvas;
	init_canvas(&canvas);
	pixel_put(&canvas, 150, 200, 11250145);
	mlx_loop(canvas.mlx_ptr);
	ft_destroy_canvas(&canvas);
	return (0);
}
