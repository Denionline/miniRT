#ifndef HEAD_H
# define HEAD_H

#include "minilibx-linux/mlx.h"
#include "libft/include/libft.h"
#include "get_next_line/include/get_next_line.h"

#include <stdio.h>
#include <math.h>
#include <stdint.h>

/* ANSI colors */
#define C_RESET   "\033[0m"
#define C_TITLE   "\033[1;36m"
#define C_LABEL   "\033[1;33m"
#define C_VALUE   "\033[0;37m"
#define C_VEC     "\033[0;32m"
#define C_MAT     "\033[0;35m"
#define C_WARN    "\033[0;31m"

#include "math_head.h"
#include "matrix.h"
#include "light.h"
#include "ray.h"
#include "obj.h"
#include "scene.h"
#include "world.h"
#include "canvas.h"
#include "surface.h"
#include "parse.h"
#include "end.h"

void	*saffe_calloc(t_scene *scene, char *s,size_t n, size_t size);

int	is_tuple_empty(t_tuple t);
int	is_matrix_empty(t_matrix m);
int	is_line_empty(char *line);

//Test auxiliars
void	print_matrix(t_matrix m);
void	print_tuple(t_tuple t);
void	print_color(t_tuple t);
void	print_object(t_object o);
void	print_material(t_material m);
void	print_computations(t_computations c);
void	print_tuple_simple(const char *name, t_tuple t);
void	print_matrix_simple(t_matrix m);
void	print_light(t_light l);
void	print_world(t_world *w);
void	print_scene(t_scene *s);

#endif
