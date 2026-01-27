#include "head.h"

int	main(void) {
	t_pattern g = gradient_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
	t_tuple	c;

	c = pattern_at(g, point(0, 0, 0));
	print_tuple(c);
	c = pattern_at(g, point(0.25, 0, 0));
	print_tuple(c);
	c = pattern_at(g, point(0.5, 0, 0));
	print_tuple(c);
	c = pattern_at(g, point(0.75, 0, 0));
	print_tuple(c);
}
