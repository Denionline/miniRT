#include "head.h"

t_matrix	identity_matrix(void)
{
	return (matrix(
		(float[]){
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		}
		, 4));
}