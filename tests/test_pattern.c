#include "head.h"

// int main(void)
// {
// 	t_pattern	p;

// 	p = stripe_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
// 	printf("point(0, 0, 0)\n");
// 	print_color(stripe_at(p, point(0, 0, 0)));
// 	printf("point(0, 1, 0)\n");
// 	print_color(stripe_at(p, point(0, 1, 0)));
// 	printf("point(0, 2, 0)\n");
// 	print_color(stripe_at(p, point(0, 2, 0)));
// 	printf("point(0, 0, 0)\n");
// 	print_color(stripe_at(p, point(0, 0, 0)));
// 	printf("point(0, 0, 1)\n");
// 	print_color(stripe_at(p, point(0, 0, 1)));
// 	printf("point(0, 0, 2)\n");
// 	print_color(stripe_at(p, point(0, 0, 2)));
// 	printf("point(0, 0, 0)\n");
// 	print_color(stripe_at(p, point(0, 0, 0)));
// 	printf("point(0.9, 0, 0)\n");
// 	print_color(stripe_at(p, point(0.9, 0, 0)));
// 	printf("point(1, 0, 0)\n");
// 	print_color(stripe_at(p, point(1, 0, 0)));
// 	printf("point(-0.1, 0, 0)\n");
// 	print_color(stripe_at(p, point(-0.1, 0, 0)));
// 	printf("point(-1, 0, 0)\n");
// 	print_color(stripe_at(p, point(-1, 0, 0)));
// 	printf("point(-1.1, 0, 0)\n");
// 	print_color(stripe_at(p, point(-1.1, 0, 0)));
// }

// int main(void)
// {
// 	t_pattern	p;
// 	t_object	*obj;

// 	obj = sphere();
// 	p = stripe_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
// 	obj->transform = scaling(2, 2, 2);
// 	printf("point(1.5, 0, 0) with obj scaling(2,2,2)\n");
// 	print_color(stripe_at_obj(p, *obj, point(1.5, 0, 0)));

// 	obj = sphere();
// 	printf("point(1.5, 0, 0) with scaling (2, 2, 2) in pattern\n");
// 	p.transform = scaling(2, 2, 2);
// 	print_color(stripe_at_obj(p, *obj, point(1.5, 0, 0)));

// 	obj->transform = scaling(2, 2, 2);
// 	p.transform = translation(0.5, 0, 0);
// 	printf("point(2.5, 0, 0) with obj scaling and translation\n");
// 	p.transform = translation(0.5, 0, 0);
// 	print_color(stripe_at_obj(p, *obj, point(2.5, 0, 0)));
// }

int main(void)
{
	t_pattern	p;

	p = ring_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
	print_tuple(pattern_at(p, point(0, 0, 0)));

	p = ring_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
	print_tuple(pattern_at(p, point(1, 0, 0)));

	p = ring_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
	print_tuple(pattern_at(p, point(0, 0, 1)));

	p = ring_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
	print_tuple(pattern_at(p, point(0.708, 0, 0.708)));
}
