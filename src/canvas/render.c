#include "head.h"

t_canvas	render(t_camera c, t_world w)
{
	t_canvas	canvas;
	t_ray		r;
	int			i;
	int			j;
	
	init_canvas(&canvas, c.hsize, c.vsize);
	j = 0;
	while (j < c.vsize)
	{
		i = 0;
		while (i < c.hsize)
		{
			r = ray_for_pixel(c, i, canvas.vsize - 1 - j);
			pixel_put(&canvas, i, j, color(color_at(w, r)));
			i++;
		}
		mlx_put_image_to_window(canvas.mlx_ptr, canvas.win_ptr, canvas.img_ptr, 0, 0);
		j++;
	}
	return (canvas);
}
