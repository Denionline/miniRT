/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenes <dximenes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 14:31:26 by dximenes          #+#    #+#             */
/*   Updated: 2026/02/19 10:11:02 by dximenes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	print_error(enum e_ERROR_CODE e_ERROR_CODE)
{
	printf("Error\n");
	if (e_ERROR_CODE == ERR_MALLOC)
		printf("Malloc error\n");
	else if (e_ERROR_CODE == ERR_NOT_ENOUGH_ARGS)
		printf("Invalid numbers of args, try: ./miniRT scenes/default.rt\n");
	else if (e_ERROR_CODE == ERR_OPEN_FILE)
		printf("Error to open the scene\n");
	else if (e_ERROR_CODE == ERR_INVALID_TUPLE)
		printf("Invalid point or vector\n");
	else if (e_ERROR_CODE == ERR_UNKNOWN_IDENTIFIER)
		printf("Unknown identifier on line\n");
	else if (e_ERROR_CODE == ERR_OUT_OF_RANGE)
		printf("Some parameter on scene is out of range\n");
	else if (e_ERROR_CODE == ERR_INVALID_CHAR)
		printf("There is some invalid character on scene\n");
	else if (e_ERROR_CODE == ERR_DUPLICATE)
		printf("There is some unique rule duplicated\n");
	else if (e_ERROR_CODE == ERR_MISSING)
		printf("There is some mandatory rule missing\n");
	else if (e_ERROR_CODE == ERR_INVALID_FILE)
		printf("Invalid extension of file\n");
	else
		printf("Unexpected Error\n");
}
