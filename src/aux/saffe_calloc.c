/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saffe_calloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:32:38 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:32:39 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	*saffe_calloc(t_scene *scene, char *s,size_t n, size_t size)
{
	void	*new_alloc;

	new_alloc = ft_calloc(n, size);
	if (!new_alloc)
		end(scene, ERR_MALLOC, s, s != NULL);
	return (new_alloc);
}
