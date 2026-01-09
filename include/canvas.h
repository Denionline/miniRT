#ifndef CANVAS_H
# define CANVAS_H

# define WIDTH 800
# define HEIGHT 560

typedef struct s_canvas
{
	void	*init_screen;
	void	*init_img;
	void	*win;
	void	*address;
	int		bpp;
	int		sl;
	int		endian;
}	t_canvas;

int		init_canvas(t_canvas *canvas);
void	pixel_put(t_canvas *canvas, int x, int y, int color);

#endif