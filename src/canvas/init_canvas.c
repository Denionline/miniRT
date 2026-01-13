#include "head.h"

int	init_canvas(t_canvas *canvas)
{
	canvas->mlx_ptr = mlx_init();
	if (canvas->mlx_ptr == (void *)0)
		return (0);
	canvas->win_ptr = mlx_new_window(canvas->mlx_ptr, WIDTH, HEIGHT, "LA ELE");
	canvas->img_ptr = mlx_new_image(canvas->mlx_ptr, WIDTH, HEIGHT);
	canvas->address = mlx_get_data_addr(canvas->img_ptr, &canvas->bpp, &canvas->sl, &canvas->endian);
	return (1);
}
