/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:49:56 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/17 21:06:49 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

bool	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->game->key_w = 0;
	if (keycode == KEY_S)
		data->game->key_s = 0;
	if (keycode == KEY_A)
		data->game->key_a = 0;
	if (keycode == KEY_D)
		data->game->key_d = 0;
	if (keycode == KEY_RIGHT)
		data->game->key_right = 0;
	if (keycode == KEY_LEFT)
		data->game->key_left = 0;
	if (keycode == KEY_SHIFT)
		data->run = 0;
	return (1);
}

bool	key_press(int keycode, t_data *data)
{
	// one line 
	if (keycode == KEY_ESC)
		exit(1); //exit free a faire 
	if (keycode == KEY_W)
		data->game->key_w = 1;
	if (keycode == KEY_S)
		data->game->key_s = 1;
	if (keycode == KEY_A)
		data->game->key_a = 1;
	if (keycode == KEY_D)
		data->game->key_d = 1;
	if (keycode == KEY_RIGHT)
		data->game->key_right = 1;
	if (keycode == KEY_LEFT)
		data->game->key_left = 1;
	if (keycode == KEY_SHIFT)
		data->run = 1;
	return (0);
}

bool	game_management(t_data *data)
{
	if (init_game(data))
		return (1); // msg error 
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	mlx_hook(data->win, KeyPress, KeyPressMask, &key_press, &data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &key_release, &data);
	mlx_hook(data->win, 17, 1l << 17, &end_of_prog, &data);
	mlx_loop_hook(data->mlx, game_loop, &data);
	mlx_loop(data->mlx);
	mlx_do_key_autorepeaton(data->mlx);
	return (0);
}