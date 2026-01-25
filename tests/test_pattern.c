#include "head.h"

int main(void)
{
	t_pattern	p;

	p = stripe_pattern(color_float(1, 1, 1), color_float(0, 0, 0));
	printf("point(0, 0, 0)\n");
	print_color(stripe_at(p, point(0, 0, 0)));
	printf("point(0, 1, 0)\n");
	print_color(stripe_at(p, point(0, 1, 0)));
	printf("point(0, 2, 0)\n");
	print_color(stripe_at(p, point(0, 2, 0)));
	printf("point(0, 0, 0)\n");
	print_color(stripe_at(p, point(0, 0, 0)));
	printf("point(0, 0, 1)\n");
	print_color(stripe_at(p, point(0, 0, 1)));
	printf("point(0, 0, 2)\n");
	print_color(stripe_at(p, point(0, 0, 2)));
	printf("point(0, 0, 0)\n");
	print_color(stripe_at(p, point(0, 0, 0)));
	printf("point(0.9, 0, 0)\n");
	print_color(stripe_at(p, point(0.9, 0, 0)));
	printf("point(1, 0, 0)\n");
	print_color(stripe_at(p, point(1, 0, 0)));
	printf("point(-0.1, 0, 0)\n");
	print_color(stripe_at(p, point(-0.1, 0, 0)));
	printf("point(-1, 0, 0)\n");
	print_color(stripe_at(p, point(-1, 0, 0)));
	printf("point(-1.1, 0, 0)\n");
	print_color(stripe_at(p, point(-1.1, 0, 0)));
}
