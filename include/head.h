#ifndef HEAD_H
# define HEAD_H

#include "minilibx-linux/mlx.h"
#include "libft/include/libft.h"

#include <stdio.h>
#include <math.h>
#include <stdint.h>

#include "math_head.h"
#include "matrix.h"
#include "map.h"
#include "canvas.h"
#include "ray.h"
#include "obj.h"

typedef struct s_head
{
	t_map	*map;
}	t_head;

//Test auxiliars
void	print_matrix(t_matrix m);
void	print_tuple(t_tuple t);

#endif
