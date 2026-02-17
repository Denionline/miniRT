/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:41:14 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 19:19:27 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# define ESC_KEY 65307

typedef struct s_canvas	t_canvas;

typedef struct s_hook_ctx
{
	t_canvas	*canvas;
	t_scene		*scene;
}	t_hook_ctx;

typedef struct s_canvas
{
	void	*mlx_ptr;
	void	*img_ptr;
	void	*win_ptr;
	void	*address;
	int		bpp;
	int		sl;
	int		endian;
	int		hsize;
	int		vsize;
}	t_canvas;

int			init_canvas(t_canvas *canvas, int hsize, int vsize);
int			ft_destroy_canvas(t_canvas *canvas);
void		pixel_put(t_canvas *canvas, int x, int y, t_tuple color);
void		ft_init_hooks(t_canvas *canvas, t_scene *scene);
t_canvas	render(t_camera c, t_world w);
t_tuple		pixel_at(t_canvas *canvas, int x, int y);

#endif
