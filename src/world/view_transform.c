#include "head.h"

t_matrix	view_transform(t_tuple init_location, t_tuple look_pos, t_tuple up_vector)
{
	t_tuple		going;
	t_tuple		left;
	t_tuple		up_scene;
	t_matrix	m;

	going = normalize(subtract_tuples(look_pos, init_location));
	left = cross(going, normalize(up_vector));
	up_scene = cross(left, going);
	m = matrix((float []){
			left.x, left.y, left.z, 0,
			up_scene.x, up_scene.y, up_scene.z, 0,
			-going.x, -going.y, -going.z, 0,
			0, 0, 0, 1
		}
		, 4);
	
	return (multiply_matrix(m, \
		translation(-init_location.x, -init_location.y, -init_location.z)));
}
