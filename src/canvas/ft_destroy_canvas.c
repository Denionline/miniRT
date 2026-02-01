/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_canvas.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:32:31 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:23:31 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_destroy_canvas(t_canvas *canvas)
{
	if (!canvas || !canvas->mlx_ptr)
		return (0);
	if (canvas->img_ptr)
		mlx_destroy_image(canvas->mlx_ptr, canvas->img_ptr);
	if (canvas->win_ptr)
		mlx_destroy_window(canvas->mlx_ptr, canvas->win_ptr);
	mlx_destroy_display(canvas->mlx_ptr);
	free(canvas->mlx_ptr);
	canvas->mlx_ptr = NULL;
	canvas->img_ptr = NULL;
	canvas->win_ptr = NULL;
	return (0);
}
