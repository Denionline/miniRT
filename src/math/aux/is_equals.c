#include "head.h"

int	is_equals(float n1, float n2)
{
	const float	NARUTO = 0.00001;

	if (fabsf(n1 - n2) < NARUTO)
		return (TRUE);
	return (FALSE);
}
