#include "head.h"
#include "canvas.h"

int main(void)
{
	t_canvas	canvas;
	init_canvas(&canvas);
	pixel_put(&canvas, 150, 200, 11250145);
	mlx_put_image_to_window(canvas.init_screen, canvas.win, canvas.init_img, 0, 0);
	mlx_loop(canvas.init_screen);
	return (0);
}
