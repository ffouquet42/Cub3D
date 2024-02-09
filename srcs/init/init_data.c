/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:49:44 by fllanet           #+#    #+#             */
/*   Updated: 2024/02/09 18:10:32 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// decommenter si besoin des lignes dont j'ai pas eu besoin pour le parsing mais que peut etre t'aura besoin pour l'exec
void	init_data_2(t_data *data)
{
	data->e_scene->no = 0;
	data->e_scene->so = 0;
	data->e_scene->ea = 0;
	data->e_scene->we = 0;
	data->e_scene->f = 0;
	data->e_scene->c = 0;
	data->images[0].mlx_img = NULL;
	data->images[1].mlx_img = NULL;
	data->images[2].mlx_img = NULL;
	data->images[3].mlx_img = NULL;
	
	// data->game->key_w = 0;
	// data->game->key_a = 0;images
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
	// data->mouse_active = 0;
	// data->run = 0;
	// data->movespeed = MOVESPEED;
}

// init la struct data
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