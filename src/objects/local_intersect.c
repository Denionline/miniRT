#include "head.h"

static t_intersections	intersect_cone(t_object *cone, t_ray r, t_intersection *xs);
static t_intersections	intersect_cyl(t_object *cyl, t_ray r, t_intersection *xs);
static int				check_height(t_ray r, float t);

t_intersections	local_intersect(t_object *obj, t_ray r)
{
	t_intersection	inter[3];

	if (obj->type == PLANE)
	{
		if (fabs(r.direction.y) < NARUTO)
			return (intersections(NULL, 0));
		
		inter[0].t = -r.origin.y / r.direction.y;
		inter[0].object = obj;
		return (intersections(inter, 1));
	}
	if (obj->type == CYLINDER)
		return(intersect_cyl(obj, r, inter));
	return(intersect_cone(obj, r, inter));
}

// q[0]=a, q[1]=b, q[2]=c, q[3]=delta -> Bhaskara
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
	if (check_height(r, t[0]))
		xs[count++] = (t_intersection){t[0], cyl};
	if (check_height(r, t[1]))
		xs[count++] = (t_intersection){t[1], cyl};
	return (intersections(xs, count));
}

// q[0]=a, q[1]=b, q[2]=c, q[3]=delta -> Bhaskara
static t_intersections	intersect_cone(t_object *cone, t_ray r, t_intersection *xs)
{
	float	q[4];
	float	t[2];
	int		count;

	count = 0;
	q[0] = powf(r.direction.x, 2) - powf(r.direction.y, 2) + \
	powf(r.direction.z, 2);
	q[1] = 2.0f * (r.origin.x * r.direction.x - r.origin.y * r.direction.y + \
	r.origin.z * r.direction.z);
	if (fabs(q[0]) < 0.00001 && fabs(q[1]) < 0.00001)
		return (intersections(NULL, 0));
	q[2] = powf(r.origin.x, 2) - powf(r.origin.y, 2) + powf(r.origin.z, 2);
	q[3] = (q[1] * q[1]) - (4.0f * q[0] * q[2]);
	if (q[3] < 0)
		return (intersections(NULL, 0));
	t[0] = (-q[1] - sqrtf(q[3])) / (2.0f * q[0]);
	if (fabs(q[0]) < 0.00001)
		t[0] = -q[2] / (2.0f * q[1]);
	t[1] = (-q[1] + sqrtf(q[3])) / (2.0f * q[0]);
	if (check_height(r, t[0]))
		xs[count++] = (t_intersection){t[0], cone};
	if (check_height(r, t[1]))
		xs[count++] = (t_intersection){t[1], cone};
	return (intersections(xs, count));
}

static int  check_height(t_ray r, float t)
{
    float   y;

    y = r.origin.y + t * r.direction.y;
    if (y > -0.5f && y < 0.5f)
        return (1);
    return (0);
}
