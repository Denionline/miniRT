#include "head.h"

// p - define proportion in the axis
// follow the schematic : X_Y:  X in proportion to Y
// p1 = x_y, x_z, y_x
// p2 = y_z, z_x, z_y

t_matrix	shearing(t_tuple p1, t_tuple p2)
{
	t_matrix skew;

	skew = identity_matrix();
	skew.matrix[0][1] = p1.x;
	skew.matrix[0][2] = p1.y;
	skew.matrix[1][0] = p1.z;
	skew.matrix[1][2] = p2.x;
	skew.matrix[2][0] = p2.y;
	skew.matrix[2][1] = p2.z;
	return (skew);
}
