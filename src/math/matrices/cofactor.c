/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:30:08 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:30:09 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

float	cofactor(t_matrix matrix_3d, unsigned int row, unsigned int col)
{
	if ((row + col) % 2 != 0)
		return (-1.0f * minor_3d(matrix_3d, row, col));
	return (minor_3d(matrix_3d, row, col));
}
