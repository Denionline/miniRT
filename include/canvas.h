#ifndef CANVAS_H
# define CANVAS_H

# define WIDTH 900
# define HEIGHT 900
# define ESC_KEY 65307

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
int		ft_destroy_canvas(t_canvas *canvas);
void	pixel_put(t_canvas *canvas, int x, int y, t_tuple color);
void	ft_init_hooks(t_canvas *canvas);
t_tuple	sum_color(t_tuple color1, t_tuple color2);
t_tuple	sub_color(t_tuple color1, t_tuple color2);
t_tuple	mult_color(t_tuple color1, t_tuple color2);
t_tuple	mult_color_float(t_tuple t, float times);

#endif
