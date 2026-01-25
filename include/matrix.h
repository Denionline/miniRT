#ifndef MATRIX_H
# define MATRIX_H

#include "math_head.h"

typedef struct s_matrix
{
	float			matrix[4][4];
	unsigned int	size;
}	t_matrix;

t_matrix	matrix(float *numbers, unsigned int size);
t_matrix	transpose(t_matrix old_matrix);
t_matrix	multiply_matrix(t_matrix m1, t_matrix m2);
t_matrix	identity_matrix(void);
t_tuple		multiply_matrix_tuple(t_matrix matrix, t_tuple t);
t_matrix	translation(float x, float y, float z);
t_matrix	transpose(t_matrix old_matrix);
t_matrix	submatrix(t_matrix matrix_org, unsigned int row, unsigned int col);
t_matrix	inverse(t_matrix m);
t_matrix	scaling(float x, float y, float z);
t_matrix	shearing(t_tuple p1, t_tuple p2);
float		minor_3d(t_matrix matrix_3d, unsigned int row, unsigned int col);
float		cofactor(t_matrix matrix_3d, unsigned int row, unsigned int col);
float		determinant(t_matrix m);

//Transformations
t_matrix	rotate_x(double radians);
t_matrix	rotate_y(double radians);
t_matrix	rotate_z(double radians);

#endif
