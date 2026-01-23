#include "head.h"

static t_tuple	construct_color(unsigned int *address, int endian);

t_tuple	pixel_at(t_canvas *canvas, int x, int y)
{
	char *dst;

	if (x >= canvas->hsize || y >= canvas->vsize
		|| x < 0 || y < 0)
		return (color_float(0, 0, 0));
	dst = canvas->address + ((canvas->vsize - y) * canvas->sl + x * (canvas->bpp / 8));
	return (construct_color((unsigned int *) dst, canvas->endian));
}

static t_tuple	construct_color(unsigned int *address, int endian)
{
	float			div;
	unsigned int	addr;

	addr = *address;
	div = 1.0f / 255.0f;
	if (!endian)
		return (color_float(((addr) & 0xFF) * div, ((addr >> 8) & 0xFF) * div, ((addr >> 16) & 0xFF) * div));
	return (color_float(((addr >> 16) & 0xFF) * div, ((addr >> 8) & 0xFF) * div, (addr & 0xFF) * div));
}
