#include "head.h"

static unsigned int	construct_color(t_tuple color, int endian);

void	pixel_put(t_canvas *canvas, int x, int y, t_tuple color)
{
	char *dst;

	dst = canvas->address + (y * canvas->sl + x * (canvas->bpp / 8));
	*(unsigned int*)dst = construct_color(color, canvas->endian);
}

static unsigned int	construct_color(t_tuple color, int endian)
{
	if (!endian)
		return ((int) color.r << 16 | (int) color.g << 8 | (int) color.b);
	return ((int) color.b << 16 | (int) color.g << 8 | (int) color.r);
}
