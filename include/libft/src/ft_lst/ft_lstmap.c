/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 14:18:46 by dximenes          #+#    #+#             */
/*   Updated: 2025/05/18 22:03:42 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_clearmemo(void *temp, t_list *newlst, void (*del)(void *))
{
	del(temp);
	if (newlst)
		ft_lstclear(&newlst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*temp;

	if (!lst)
		return (NULL);
	temp = f(lst->content);
	newlst = ft_lstnew(temp, 0);
	if (!newlst)
		return (ft_clearmemo(temp, newlst, del));
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp = f(lst->content);
		node = ft_lstnew(temp, 0);
		if (!node)
			return (ft_clearmemo(temp, newlst, del));
		ft_lstadd_back(&newlst, node);
	}
	return (newlst);
}
