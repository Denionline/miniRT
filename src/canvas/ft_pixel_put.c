/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:32:29 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:41:22 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

static unsigned int	construct_color(t_tuple color, int endian)
{
	if (!endian)
		return (color.r << 16 | color.g << 8 | color.b);
	return (color.b << 16 | color.g << 8 | color.r);
}

void	pixel_put(t_canvas *canvas, int x, int y, t_tuple color)
{
	char	*dst;

	if (x >= canvas->hsize || y >= canvas->vsize
		|| x < 0 || y < 0)
		return ;
	dst = canvas->address;
	dst += (canvas->vsize - y) * canvas->sl;
	dst += x * (canvas->bpp / 8);
	*(unsigned int *)dst = construct_color(color, canvas->endian);
}
