#include "head.h"

static unsigned int	construct_color(t_tuple color, int endian);

void	pixel_put(t_canvas *canvas, int x, int y, t_tuple color)
{
	char *dst;

	if (x >= WIDTH || y >= HEIGHT
		|| x < 0 || y < 0)
		return ;
	dst = canvas->address + ((HEIGHT - y) * canvas->sl + x * (canvas->bpp / 8));
	*(unsigned int*)dst = construct_color(color, canvas->endian);
}

static unsigned int	construct_color(t_tuple color, int endian)
{
	if (!endian)
		return ( color.r << 16 | color.g << 8 |  color.b);
	return ( color.b << 16 |  color.g << 8 |  color.r);
}
