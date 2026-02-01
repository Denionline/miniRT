/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:33:42 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 17:54:46 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	main(int argc, char *argv[])
{
	t_canvas canvas;
	t_scene	*scene;

	if (argc != 2)
		execl("./.select_scene", ".select_scene", (char *)NULL);
	parse_scene(&scene, argv[1]);
	canvas = render(*scene->camera, *scene->world);
	ft_init_hooks(&canvas, scene);
	mlx_loop(canvas.mlx_ptr);
	end(scene, 0, NULL, FALSE);
}
