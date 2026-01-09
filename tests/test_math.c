#include "head.h"
#include <stdio.h>

int	main(void) {
	t_tuple	p = point(4.3, -4.2, 3.1);
	t_tuple	v = vector(4.3, -4.2, 3.1);

	printf("Point\nx: %.2f\ny: %.2f\nz: %.2f\nw: %.2f\n", p.x, p.y, p.z, p.w);
	printf("\nVector\nx: %.2f\ny: %.2f\nz: %.2f\nw: %.2f\n", v.x, v.y, v.z, v.w);

	printf("\n%.2f == %.2f -> %s\n", p.x, v.x, is_equals(p.x, v.x) ? "EQUAL" : "NOT EQUAL");
}
