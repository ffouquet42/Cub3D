/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:45:31 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/11 19:21:16 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

static inline	void	ft_putstr(char *str, int fd)
{
	if (fd < 0)
		return ;
	while (*str)
		write(fd, str++, 1);
}

static inline	void	parsing_msg_error_2(t_error *error)
{
	if (error->error_g & ERROR_RGB)
		ft_putstr(E_RGB, 2);
	if (error->error_g & ERROR_INIT_MLX)
		ft_putstr(E_INIT_MLX, 2);
	if (error->error_g & ERROR_INIT_IMG)
		ft_putstr(E_INIT_IMG, 2);
	if (error->error_g & ERROR_MLX_WIN)
		ft_putstr(E_MLX_WIN, 2);
	if (error->error_g & ERROR_POS)
		ft_putstr(E_GET_P_POS, 2);
}

static inline	void	general_error(t_error *error)
{
	if (error->error_g & ERROR_FILE)
		ft_putstr(E_PARS_FILE, 2);
	if (error->error_g & ERROR_MALLOC)
		ft_putstr(E_MALLOC_FAIL, 2);
}

static inline	void	arg_error(t_error *error)
{
	// ft_putstr("Argument or file error(s):\n", 2);
	if (error->error_g & ERROR_ARG)
		ft_putstr(E_PARS_ARGS, 2);
	if (error->error_g & ERROR_CUB)
		ft_putstr(E_PARS_CUB, 2);
}

inline	void	msg_error(t_error *error)
{
	ft_putstr("ERROR\n", 2);
	
	arg_error(error);
	general_error(error);
	if (error->error_g & ERROR_EMPTY_S)
		ft_putstr(E_EMPTY_SCENE, 2);
	if (error->error_g & ERROR_SCENE)
		ft_putstr(E_GET_SCENE, 2);
	if (error->error_g & ERROR_MAP)
		ft_putstr(E_GET_MAP, 2);
	if (error->error_g & ERROR_RM_MAP)
		ft_putstr(E_RM_MAP, 2);
	if (error->error_g & ERROR_SORT_S)
		ft_putstr(E_SORT_SCE, 2);
	if (error->error_g & ERROR_CHAR)
		ft_putstr(E_MAP_CHAR, 2);
	if (error->error_g & ERROR_START)
		ft_putstr(E_ONE_START, 2);
	if (error->error_g & ERROR_WALL)
		ft_putstr(E_CLO_WALL, 2);
	if (error->error_g & ERROR_XPM)
		ft_putstr(E_NO_XPM, 2);
	parsing_msg_error_2(error);
}
