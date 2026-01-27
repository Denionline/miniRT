#include "head.h"

static int	check_height(t_object *cyl, t_ray r, float t)
{
	float	y;
	float	half_h;

	half_h = cyl->height / 2.0;
	y = r.origin.y + t * r.direction.y;
	if (y > -half_h && y < half_h)
		return(1);
	return (0);
}

// q[0]=a, q[1]=b, q[2]=c, q[3]=disc
static t_intersections	intersect_cyl(t_object *cyl, t_ray r, t_intersection *xs)
{
	float	q[4];
	float	t[2];
	int		count;

	count = 0;
	q[0] = powf(r.direction.x, 2) + powf(r.direction.z, 2);
	if (fabs(q[0]) < 0.00001)
		return (intersections(NULL, 0));
	q[1] = 2.0f * (r.origin.x * r.direction.x + r.origin.z * r.direction.z);
	q[2] = powf(r.origin.x, 2) + powf(r.origin.z, 2) - 1.0f;
	q[3] = (q[1] * q[1]) - (4.0f * q[0] * q[2]);
	if (q[3] < 0)
		return (intersections(NULL, 0));
	t[0] = (-q[1] - sqrtf(q[3])) / (2.0f * q[0]);
	t[1] = (-q[1] + sqrtf(q[3])) / (2.0f * q[0]);
	if (check_height(cyl, r, t[0]))
		xs[count++] = (t_intersection){t[0], cyl};
	if (check_height(cyl, r, t[1]))
		xs[count++] = (t_intersection){t[1], cyl};
	return (intersections(xs, count));
}

t_intersections	local_intersect(t_object *plane, t_ray r)
{
	t_intersection	inter[3];

	if (plane->type == PLANE)
	{
		if (fabs(r.direction.y) < NARUTO)
			return (intersections(NULL, 0));
		
		inter[0].t = -r.origin.y / r.direction.y;
		inter[0].object = plane;
		return (intersections(inter, 1));
	}
	return(intersect_cyl(plane, r, inter));
}
