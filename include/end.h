/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:41:41 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/01 15:01:38 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef END_H
# define END_H

enum e_ERROR_CODE
{
	ERR_MALLOC = 42,
	ERR_OPEN_FILE,
	ERR_NOT_ENOUGH_ARGS,
	ERR_INVALID_TUPLE,
	ERR_OUT_OF_RANGE,
	ERR_INVALID_CHAR,
	ERR_UNKNOWN_IDENTIFIER,
	ERR_DUPLICATE,
	ERR_MISSING,
};

void	end(t_scene *scene, int status_code, char *description, int to_free);
void	print_error(enum e_ERROR_CODE error_code);

#endif