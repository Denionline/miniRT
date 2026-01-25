#include "head.h"

t_pattern	stripe_pattern(t_tuple color1, t_tuple color2)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.has_pattern = 1;
	return (p);
}

