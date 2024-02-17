/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:17:33 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/17 22:34:31 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move_up(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y + data->game->player_or_y * data->movespeed);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y += data->game->player_or_y * data->movespeed;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x + data->game->player_or_x * data->movespeed);
	if (data->map[y][x] != '1')
		data->game->player_pos_x += data->game->player_or_x * data->movespeed;
}

void	move_left(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y - data->game->plane_y * 0.65 * MOVESPEED);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y -= data->game->plane_y * 0.65 * MOVESPEED;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x - data->game->plane_x * 0.65 * MOVESPEED);
	if (data->map[y][x] != '1')
		data->game->player_pos_x -= data->game->plane_x * 0.65 * MOVESPEED;
}

void	move_down(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y - data->game->player_or_y * 0.5 * MOVESPEED);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y -= data->game->player_or_y * 0.5 * MOVESPEED;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x - data->game->player_or_x * 0.5 * MOVESPEED);
	if (data->map[y][x] != '1')
		data->game->player_pos_x -= data->game->player_or_x * 0.5 * MOVESPEED;
}

void	move_right(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y + data->game->plane_y * 0.65 * MOVESPEED);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y += data->game->plane_y * 0.65 * MOVESPEED;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x + data->game->plane_x * 0.65 * MOVESPEED);
	if (data->map[y][x] != '1')
		data->game->player_pos_x += data->game->plane_x * 0.65 * MOVESPEED;
}
