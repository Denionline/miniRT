/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:30 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:33:31 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

t_camera	camera(float hsize, float vsize, float fov)
{
	t_camera	cam;
	float		aspect;
	float		half_v;

	half_v = tanf(fov * 0.5f);
	cam = (t_camera) 
	{
		.hsize = hsize,
		.vsize = vsize,
		.fov = fov,
		.transform = identity_matrix()
	};
	aspect = cam.hsize / cam.vsize;
	if (aspect >= 1)
	{
		cam.half_w = half_v;
		cam.half_h = half_v / aspect; 
	}
	else
	{
		cam.half_w = half_v * aspect;
		cam.half_h = half_v; 
	}
	cam.pixel_size = cam.half_w * 2.0f / cam.hsize;
	return (cam);
}
