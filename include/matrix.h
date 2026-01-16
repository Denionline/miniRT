#ifndef MATRIX_H
# define MATRIX_H

#include "head.h"

typedef struct s_matrix
{
	float			matrix[4][4];
	unsigned int	size;
}	t_matrix;

t_matrix	matrix(float *numbers, unsigned int size);
t_matrix	multiply_matrix(t_matrix m1, t_matrix m2);
t_matrix	identity_matrix(void);
t_tuple		multiply_matrix_tuple(t_matrix matrix, t_tuple t);
t_matrix	translation(float x, float y, float z);

#endif
