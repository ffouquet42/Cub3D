/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 21:17:33 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/04 02:20:57 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static	void	move_up(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y + data->game->player_or_y * data->speed);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y += data->game->player_or_y * data->speed;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x + data->game->player_or_x * data->speed);
	if (data->map[y][x] != '1')
		data->game->player_pos_x += data->game->player_or_x * data->speed;
}

static	void	move_left(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y - data->game->plane_y * 0.65
			* MOVESPEED);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y -= data->game->plane_y * 0.65 * MOVESPEED;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x - data->game->plane_x * 0.65
			* MOVESPEED);
	if (data->map[y][x] != '1')
		data->game->player_pos_x -= data->game->plane_x * 0.65 * MOVESPEED;
}

static	void	move_down(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y - data->game->player_or_y * 0.5
			* MOVESPEED);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y -= data->game->player_or_y * 0.5 * MOVESPEED;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x - data->game->player_or_x * 0.5
			* MOVESPEED);
	if (data->map[y][x] != '1')
		data->game->player_pos_x -= data->game->player_or_x * 0.5 * MOVESPEED;
}

static	void	move_right(t_data *data)
{
	int		y;
	int		x;

	y = (int)(data->game->player_pos_y + data->game->plane_y * 0.65
			* MOVESPEED);
	x = (int)data->game->player_pos_x;
	if (data->map[y][x] != '1')
		data->game->player_pos_y += data->game->plane_y * 0.65 * MOVESPEED;
	y = (int)data->game->player_pos_y;
	x = (int)(data->game->player_pos_x + data->game->plane_x * 0.65
			* MOVESPEED);
	if (data->map[y][x] != '1')
		data->game->player_pos_x += data->game->plane_x * 0.65 * MOVESPEED;
}

void	move(t_data *data)
{
	if (data->run)
		data->speed = 2 * MOVESPEED;
	else
		data->speed = MOVESPEED;
	if (data->key->key_w)
		move_up(data);
	else if (data->key->key_a)
		move_left(data);
	else if (data->key->key_s)
		move_down(data);
	else if (data->key->key_d)
		move_right(data);
	if (data->key->key_right)
		rotate_right(data);
	else if (data->key->key_left)
		rotate_left(data);
}
