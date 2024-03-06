/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:57:27 by fllanet           #+#    #+#             */
/*   Updated: 2024/03/06 03:04:10 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_first_orientation_two(t_data *data, char c)
{
	if (c == 'N')
	{
		data->game->player_or_y = 1;
		data->game->plane_x = -0.66;
	}
	if (c == 'W')
	{
		data->game->player_or_x = -1;
		data->game->plane_y = -0.66;
	}
}

void	set_first_orientation(t_data *data, char c)
{
	if (c == 'S')
	{
		data->game->player_or_y = -1;
		data->game->plane_x = 0.66;
	}
	if (c == 'E')
	{
		data->game->player_or_x = 1; 
		data->game->plane_y = 0.66;
	}
	set_first_orientation_two(data, c);
}

