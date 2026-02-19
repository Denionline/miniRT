/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:56:18 by dximenes          #+#    #+#             */
/*   Updated: 2025/10/19 11:57:03 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	nlong;
	int			size;

	size = 0;
	nlong = n;
	if (nlong < 0)
	{
		ft_putchar_fd('-', fd);
		nlong *= -1;
	}
	if (nlong >= 10)
		ft_putnbr_fd((int)(nlong / 10), fd);
	size += ft_putchar_fd((char)(nlong % 10 + '0'), fd);
	return (size);
}
