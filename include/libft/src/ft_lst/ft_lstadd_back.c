/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:52:49 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/18 21:29:36 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next != NULL)
		node = node->next;
	new->prev = node;
	node->next = new;
}
