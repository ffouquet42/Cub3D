/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:49:56 by mfeldman          #+#    #+#             */
/*   Updated: 2024/02/18 16:59:30 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move(t_data *data)
{
	int y;
	
	if (data->game->key_w)
		move_up(data);
	if (data->game->key_a)
		move_left(data);
	if (data->game->key_s)
		move_down(data);
	if (data->game->key_d)
		move_right(data);
	if (data->game->key_right)
		rotate_right(data);
	if (data->game->key_left)
		rotate_left(data);
	if (data->mouse == 1)
	{
		mlx_mouse_get_pos(data->mlx, data->win, &data->mouse_x, &y);
		if (data->mouse_x > WIN_WIDTH / 2)
			rotate_right(data);
		else if (data->mouse_x < WIN_WIDTH / 2)
			rotate_left(data);
		mlx_mouse_move(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	}
}

int game_loop(t_data *data) // uint 
{

	if (data->run == 1)
		data->speed = 2 * MOVESPEED;
	else
		data->speed = MOVESPEED;
	move(data);
	raycast(data);
	return (0);
}

int 	key_release(int keycode, t_data *data) // voir uint 
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
	if (keycode == KEY_M && data->mouse == 0)
		data->mouse = 1;
	else if (keycode == KEY_M && data->mouse == 1)
		data->mouse = 0;
	if (keycode == KEY_SHIFT)
		data->run = 0;
	return (0);
}

int key_press(int keycode, t_data *data) // voir uint 
{
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
	mlx_hook(data->win, 17, 1l << 17, (void *)free_all, &data); // a faire 
	mlx_loop_hook(data->mlx, game_loop, &data);
	mlx_loop(data->mlx);
	mlx_do_key_autorepeaton(data->mlx);
	return (0);
}