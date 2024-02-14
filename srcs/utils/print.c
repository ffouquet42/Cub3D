/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:45:31 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/14 08:25:56 by mfeldman         ###   ########.fr       */
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

void	parsing_msg_error(t_error *error) //Rename for more spaces 
{
	if (error->error_g & ERROR_ARG)
		ft_putstr(E_PARS_ARGS, 2);
	if (error->error_g & ERROR_FILE)
		ft_putstr(E_PARS_FILE, 2);
	if (error->error_g & ERROR_CUB)
		ft_putstr(E_PARS_CUB, 2);
	if (error->error_g & ERROR_EMPTY)
		ft_putstr(E_EMPTY_MAP, 2);
	if (error->error_g & ERROR_SCENE)
		ft_putstr(E_GET_SCENE, 2);
	if (error->error_g & ERROR_MAP)
		ft_putstr(E_GET_MAP, 2);
	if (error->error_g & ERROR_RM_MAP)
		ft_putstr(E_RM_MAP, 2);
	if (error->error_g & ERROR_SORT_S)
		ft_putstr(E_SORT_SCE, 2);
	if (error->error_g & ERROR_CHAR)
		ft_putstr(E_MAP_CHAR, 1);
	if (error->error_g & ERROR_START)
		ft_putstr(E_ONE_START, 1);
	if (error->error_g & ERROR_WALL)
		ft_putstr(E_CLO_WALL, 1);

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
