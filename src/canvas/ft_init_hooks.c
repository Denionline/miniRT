#include "head.h"

static int handle_keypress(int keycode, t_canvas *canvas);

void	ft_init_hooks(t_canvas *canvas)
{
	mlx_hook(canvas->win_ptr, 2, 1L<<0, (int (*)(void)) (void *)handle_keypress, canvas);
	mlx_hook(canvas->win_ptr, 17, 0, (int (*)(void)) (void *)ft_destroy_canvas, canvas);
}

static int handle_keypress(int keycode, t_canvas *canvas)
{
    if (keycode == ESC_KEY)
        ft_destroy_canvas(canvas);
    return (0);
}
