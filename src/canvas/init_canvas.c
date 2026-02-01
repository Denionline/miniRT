/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_canvas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:32:28 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:32:29 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	init_canvas(t_canvas *canvas, int hsize, int vsize)
{
	canvas->hsize = hsize;
	canvas->vsize = vsize;
	canvas->mlx_ptr = mlx_init();
	if (canvas->mlx_ptr == (void *)0)
		return (0);
	canvas->win_ptr = mlx_new_window(canvas->mlx_ptr, hsize, vsize, "LA ELE");
	canvas->img_ptr = mlx_new_image(canvas->mlx_ptr, hsize, vsize);
	canvas->address = mlx_get_data_addr(canvas->img_ptr, &canvas->bpp, &canvas->sl, &canvas->endian);
	return (1);
}
