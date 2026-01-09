#include "head.h"

int	init_canvas(t_canvas *canvas)
{
	canvas->init_screen = mlx_init();
	if (canvas->init_img == (void *)0)
		return (0);
	canvas->win = mlx_new_window(canvas->init_screen, WIDTH, HEIGHT, "LA ELE");
	canvas->init_img = mlx_new_image(canvas->init_screen, WIDTH, HEIGHT);
	canvas->address = mlx_get_data_addr(canvas->init_img, &canvas->bpp, &canvas->sl, &canvas->endian);
	return (1);
}
