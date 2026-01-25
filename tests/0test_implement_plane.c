#include "head.h"

void	print_ray(t_ray *r)
{
	if (!r)
	{
		printf("Ray: (null)\n");
		return ;
	}
	printf("Ray\n");
	printf(" ├─ origin\n");
	printf(" │   └─ x: %8.4f | y: %8.4f | z: %8.4f | w: %4.1f\n",
		r->origin.x, r->origin.y, r->origin.z, r->origin.w);
	printf(" └─ direction\n");
	printf("     └─ x: %8.4f | y: %8.4f | z: %8.4f | w: %4.1f\n",
		r->direction.x, r->direction.y, r->direction.z, r->direction.w);
}


void	print_intersection(t_intersection *i)
{
	if (!i)
	{
		printf("Intersection: (null)\n");
		return ;
	}
	printf("Intersection\n");
	printf(" ├─ t       : %8.4f\n", i->t);
	printf(" └─ object  : %p\n", (void *)i->object);
}

void	print_intersections(t_intersections *xs)
{
	unsigned int	i;

	if (!xs)
	{
		printf("Intersections: (null)\n");
		return ;
	}
	printf("Intersections\n");
	printf(" ├─ count : %u\n", xs->count);
	printf(" └─ list\n");

	if (!xs->array || xs->count == 0)
	{
		printf("    (empty)\n");
		return ;
	}

	i = 0;
	while (i < xs->count)
	{
		printf("    [%u]\n", i);
		printf("     ├─ t      : %8.4f\n", xs->array[i].t);
		printf("     └─ object : %p\n", (void *)xs->array[i].object);
		i++;
	}
}


int	main(void) {
	t_object		*p;
	t_ray			r;
	t_intersections	xs;
	
	p = plane();
	r = ray(point(0, 10, 0), vector(0, 0, 1));
	xs = local_intersect(p, r);
	printf("\nThe Plane : %p\n", (void *)p);
	print_ray(&r);
	if (xs.array) {
		print_intersections(&xs);
	} else {
		printf("EMPTY\n\n");
	}
	
	p = plane();
	r = ray(point(0, 0, 0), vector(0, 0, 1));
	xs = local_intersect(p, r);
	printf("\nThe Plane : %p\n", (void *)p);
	print_ray(&r);
	if (xs.array) {
		print_intersections(&xs);
	} else {
		printf("EMPTY\n\n");
	}

	p = plane();
	r = ray(point(0, 1, 0), vector(0, -1, 0));
	xs = local_intersect(p, r);
	printf("\nThe Plane : %p\n", (void *)p);
	print_ray(&r);
	if (xs.array) {
		print_intersections(&xs);
	} else {
		printf("EMPTY\n\n");
	}

	p = plane();
	r = ray(point(0, -1, 0), vector(0, 1, 0));
	xs = local_intersect(p, r);
	printf("\nThe Plane : %p\n", (void *)p);
	print_ray(&r);
	if (xs.array) {
		print_intersections(&xs);
	} else {
		printf("EMPTY\n\n");
	}
}
