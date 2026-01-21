#ifndef SURFACE_H
# define SURFACE_H

#include "head.h"

t_tuple	normal_at(t_object *object, t_tuple p);
t_tuple	reflect(t_tuple in, t_tuple normal);

#endif