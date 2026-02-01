/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:43:19 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:43:29 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "world.h"

typedef struct s_amblight
{
	float	ratio;
	t_tuple	color;
}	t_amblight;

typedef struct s_scene
{
	t_world		*world;
	t_amblight	*amblight;
	t_camera	*camera;
}	t_scene;

#endif