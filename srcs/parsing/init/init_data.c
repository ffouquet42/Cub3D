/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fllanet <fllanet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/01/31 12:41:58 by fllanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3D.h"

void	init_data_2(t_data *data)
{
	data->e_scene->no = 0;
	data->e_scene->so = 0;
	data->e_scene->ea = 0;
	data->e_scene->we = 0;
	data->e_scene->f = 0;
	data->e_scene->c = 0;
	// data->game->key_w = 0;
	// data->game->key_a = 0;
	// data->game->key_s = 0;
	// data->game->key_d = 0;
	// data->game->key_left = 0;
	// data->game->key_right = 0;
	// data->game->texture = 0;
	// data->game->cur_time = 0;
	// data->game->old_time = 0;
	// data->mini->display = 0;
	// data->mouse_x = 0;
	// data->rotation_speed = ROTSPEED;
	// data->textures[NO_TEXT].mlx_img = NULL;
	// data->textures[SO_TEXT].mlx_img = NULL;
	// data->textures[EA_TEXT].mlx_img = NULL;
	// data->textures[WE_TEXT].mlx_img = NULL;
	// data->mouse_active = 0;
	// data->run = 0;
	// data->movespeed = MOVESPEED;
}

int	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->window_x = 1920;
	data->window_y = 1080;
	data->game = malloc(sizeof(t_game));
	if (!data->game)
		return (1);
	data->raycast = malloc(sizeof(t_raycast));
	if (!data->raycast)
		return (1);
	data->e_scene = malloc(sizeof(t_e_scene));
	if (!data->e_scene)
		return (1);
	init_data_2(data);
	init_mlx(data);
	return (0);
}