#include "head.h"

t_matrix	translation(float x, float y, float z)
{
	return (
		matrix((float []){
			1, 0, 0, x,
			0, 1, 0, y,
			0, 0, 1, z,
			0, 0, 0, 1
		}, 4)
	);
}
