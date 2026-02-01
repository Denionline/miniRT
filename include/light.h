/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:42:12 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 19:19:59 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "obj.h"
# include "math_head.h"

typedef struct s_light
{
	t_tuple	position;
	t_tuple	intensity;
	t_tuple	color;
	float	brightness;
	int		exists;
}	t_light;

typedef struct s_phong_vec
{
	t_tuple		eyev;
	t_tuple		normalv;
	int			in_shadow;
	t_object	*object;
}	t_phong_vec;

typedef struct s_phong_colors
{
	t_tuple	effective;
	t_tuple	ambient;
	t_tuple	difuse;
	t_tuple	specular;
}	t_phong_colors;

t_light	point_light(t_tuple pos, t_tuple color, float brightness);
t_tuple	lighting(t_material m, t_light l, t_tuple t, t_phong_vec p);

#endif