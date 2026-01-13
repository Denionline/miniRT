#include "head.h"


t_tuple	sum_color(t_tuple color1, t_tuple color2)
{
	t_tuple	new_color;

	new_color = (color(color1.r + color2.r, color1.g + color2.g, \
	color1.b + color2.b));
	return (new_color);
}

t_tuple	sub_color(t_tuple color1, t_tuple color2)
{
	t_tuple	new_color;
	
	new_color = (color(color1.r - color2.r, color1.g - color2.g, \
	color1.b - color2.b));
	return (new_color);
}

t_tuple	mult_color(t_tuple color1, t_tuple color2)
{
	t_tuple	new_color;
	
	new_color = (color(color1.r * color2.r, color1.g * color2.g, \
	color1.b * color2.b));
	return (new_color);
}
