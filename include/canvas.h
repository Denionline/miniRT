#ifndef CANVAS_H
# define CANVAS_H

# define WIDTH 800
# define HEIGHT 560

typedef struct s_canvas
{
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	void	*address;
	int		bpp;
	int		sl;
	int		endian;
}	t_canvas;

int		init_canvas(t_canvas *canvas);
void	pixel_put(t_canvas *canvas, int x, int y, int color);
void	ft_destroy_canvas(t_canvas *canvas);

#endif