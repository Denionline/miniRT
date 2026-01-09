#include "head.h"

void	pixel_put(t_canvas *canvas, int x, int y, int color)
{
	char *dst;

	dst = canvas->address + (y * canvas->sl + x * (canvas->bpp / 8));
	*(unsigned int*)dst = color;
}
