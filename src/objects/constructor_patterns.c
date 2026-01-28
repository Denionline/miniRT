# include "head.h"

t_pattern	ring_pattern(t_tuple color1, t_tuple color2)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type = RING;
	return (p);
}

t_pattern	stripe_pattern(t_tuple color1, t_tuple color2)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type = STRIP;
	return (p);
}

t_pattern	gradient_pattern(t_tuple color1, t_tuple color2)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type = GRADIENT;
	return (p);
}

t_pattern	checkboard_pattern(t_tuple color1, t_tuple color2)
{
	t_pattern	p;

	p.a = color1;
	p.b = color2;
	p.transform = identity_matrix();
	p.has_pattern = 1;
	p.type = CHECKBOARD;
	return (p);
}
