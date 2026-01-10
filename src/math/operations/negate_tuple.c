#include "head.h"

t_tuple	negate_tuple(t_tuple t)
{
	return (
		(t_tuple) {
			{-t.x},
			{-t.y},
			{-t.z},
			-t.w,
		}
	);
}
