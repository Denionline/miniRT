#include "head.h"

int	main(void) {
	t_world			w = default_world();
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_intersections	xs = intersect_world(w, r);

	printf("xs.count = %d\n", xs.count);
	printf("xs[0].t = %.2f\n", xs.array[0].t);
	printf("xs[1].t = %.2f\n", xs.array[1].t);
	printf("xs[2].t = %.2f\n", xs.array[2].t);
	printf("xs[3].t = %.2f\n", xs.array[3].t);
}
