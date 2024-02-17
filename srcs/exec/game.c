/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:49:56 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/17 19:50:57 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	game_management(t_data *data)
{
	if (init_game(data))
		return (1); // msg error 
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_mouse_move(data->mlx, data->win, WINWIDTH / 2, WINHEIGHT / 2);
	return (0);
}