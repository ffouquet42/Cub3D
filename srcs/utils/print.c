/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:45:31 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/12 13:03:23 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	ft_putstr(char *str, int fd)
{
	if (fd < 0)
		return ;
	while (*str)
		write(fd, str++, 1);
}

void	parsing_msg_error(t_error *error)
{
	ft_putstr("Error\n", 1);
	if (error->error_g & ERROR_ARG)
		ft_putstr(E_PARS_ARGS, 1);
	if (error->error_g & ERROR_FILE)
		ft_putstr(E_PARS_FILE, 1);
	if (error->error_g & ERROR_CUB)
		ft_putstr(E_PARS_CUB, 1);
	if (error->error_g & ERROR_EMPTY)
		ft_putstr(E_EMPTY_MAP, 1);
	if (error->error_g & ERROR_RECT)
		ft_putstr("- Incorrect rectangle\n", 1);
	if (error->error_g & ERROR_WALL)
		ft_putstr("- Incorrect walls\n", 1);
	if (error->error_g & ERROR_POS)
		ft_putstr("- Incorrect start\n", 1);
	if (error->error_g & ERROR_EXIT)
		ft_putstr("- Incorrect exit\n", 1);
	if (error->error_g & ERROR_COL)
		ft_putstr("- Incorrect collectibles\n", 1);
	if (error->error_g & ERROR_CHAR)
		ft_putstr("- Incorrect characters\n", 1);
	if (error->error_g & ERROR_NO_VALID_PATH)
		ft_putstr("- Incorrect path\n", 1);
	if (error->error_g & ERROR_MALLOC)
		ft_putstr(E_MALLOC_FAIL, 1);
}
