/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:30:15 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 14:30:16 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

float	minor_3d(t_matrix matrix_3d, unsigned int row, unsigned int col)
{
	return (determinant(submatrix(matrix_3d, row, col)));
}
