/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surface.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:43:23 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:43:26 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SURFACE_H
# define SURFACE_H

# include "head.h"

t_tuple	normal_at(t_object *object, t_tuple p);
t_tuple	reflect(t_tuple in, t_tuple normal);

#endif