/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:36:18 by dximenes          #+#    #+#             */
/*   Updated: 2025/09/24 11:47:56 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_amount_occurrences(char *string, char search)
{
	int	occurrences;
	int	i;

	if (!string || !search)
		return (0);
	occurrences = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] == search)
			occurrences++;
		i++;
	}
	return (occurrences);
}

char	*ft_strremove(char *string, char search)
{
	const int	amout_occurrences = get_amount_occurrences(string, search);
	char		*new_string;
	int			j;
	int			i;

	if (!string)
		return (NULL);
	if (!search || amout_occurrences == 0)
		return (string);
	new_string = ft_calloc(ft_strlen(string) - amout_occurrences + 1, 1);
	if (!new_string)
		return (NULL);
	j = 0;
	i = 0;
	while (string[i])
	{
		if (string[i] != search)
			new_string[j++] = string[i];
		i++;
	}
	new_string[j] = '\0';
	free(string);
	return (new_string);
}
