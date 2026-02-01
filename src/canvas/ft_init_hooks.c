/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:32:30 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 18:23:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

typedef struct s_hook_ctx
{
	t_canvas	*canvas;
	t_scene		*scene;
} 	t_hook_ctx;

static int	destroy_and_end(t_hook_ctx *ctx)
{
	if (!ctx)
		exit(0);
	ft_destroy_canvas(ctx->canvas);
	end(ctx->scene, 0, NULL, FALSE);
	return (0);
}

static int	handle_keypress(int keycode, t_hook_ctx *ctx)
{
	if (keycode == ESC_KEY)
		return (destroy_and_end(ctx));
	return (0);
}

void	ft_init_hooks(t_canvas *canvas, t_scene *scene)
{
	t_hook_ctx	*ctx;

	ctx = malloc(sizeof(*ctx));
	if (!ctx)
		end(scene, ERR_MALLOC, NULL, FALSE);
	ctx->canvas = canvas;
	ctx->scene = scene;
	mlx_hook(canvas->win_ptr,
		2, 1L << 0, (int (*)(void))(void *)handle_keypress, ctx);
	mlx_hook(canvas->win_ptr,
		17, 0, (int (*)(void))(void *)destroy_and_end, ctx);
}
