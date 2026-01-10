#include "head.h"

void	ft_destroy_canvas(t_canvas *canvas)
{
	if (!canvas || !canvas->mlx_ptr)
		return ;
	if (canvas->img_ptr)
		mlx_destroy_image(canvas->mlx_ptr, canvas->img_ptr);
	if (canvas->win_ptr)
		mlx_destroy_window(canvas->mlx_ptr, canvas->win_ptr);
	mlx_destroy_display(canvas->mlx_ptr);
	free(canvas->mlx_ptr);
	canvas->mlx_ptr = NULL;
	canvas->img_ptr = NULL;
	canvas->win_ptr = NULL;
}
