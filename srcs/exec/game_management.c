/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:49:56 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/21 20:29:56 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move(t_data *data)
{
	if (data->game->key_w)
		move_up(data);
	else if (data->game->key_a)
		move_left(data);
	else if (data->game->key_s)
		move_down(data);
	else if (data->game->key_d)
		move_right(data);
	if (data->game->key_right)
		rotate_right(data);
	else if (data->game->key_left)
		rotate_left(data);
}

int	game_loop(t_data *data)
{
	if (data->run)
		data->speed = 2 * MOVESPEED;
	else
		data->speed = MOVESPEED;
	move(data);
	raycast(data);
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->game->key_w = false;
	else if (keycode == KEY_S)
		data->game->key_s = false;
	else if (keycode == KEY_A)
		data->game->key_a = false;
	else if (keycode == KEY_D)
		data->game->key_d = false;
	if (keycode == KEY_RIGHT)
		data->game->key_right = false;
	else if (keycode == KEY_LEFT)
		data->game->key_left = false;
	if (keycode == KEY_SHIFT)
		data->run = false;
	return (0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		free_all(data);
	else if (keycode == KEY_W)
		data->game->key_w = true;
	else if (keycode == KEY_S)
		data->game->key_s = true;
	else if (keycode == KEY_A)
		data->game->key_a = true;
	else if (keycode == KEY_D)
		data->game->key_d = true;
	if (keycode == KEY_RIGHT)
		data->game->key_right = true;
	else if (keycode == KEY_LEFT)
		data->game->key_left = true;
	if (keycode == KEY_SHIFT)
		data->run = true;
	return (0);
}

bool	game_management(t_data *data)
{
	if (init_game(data))
		return (1);
	printf("%s%i", "key_a:", data->game->key_a);
	// mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	// mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
	// mlx_loop_hook(data->mlx, game_loop, data);
	// mlx_hook(data->win, 17, 0, (void *)free_all, data);
	// mlx_loop(data->mlx);
	// free_all(data);
	return (0);
}
