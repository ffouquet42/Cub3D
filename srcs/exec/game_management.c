/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfeldman <mfeldman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:49:56 by mfeldman          #+#    #+#             */
/*   Updated: 2024/03/07 20:47:57 by mfeldman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../includes/cub3D.h"

// int	game_loop(t_data *data)
// {
// 	move(data);
// 	raycast(data);
// 	return (EXIT_SUCCESS);
// }

// int	key_release(int keycode, t_data *data)
// {
// 	if (keycode == KEY_W)
// 		data->key->key_w = false;
// 	else if (keycode == KEY_S)
// 		data->key->key_s = false;
// 	else if (keycode == KEY_A)
// 		data->key->key_a = false;
// 	else if (keycode == KEY_D)
// 		data->key->key_d = false;
// 	if (keycode == KEY_RIGHT)
// 		data->key->key_right = false;
// 	else if (keycode == KEY_LEFT)
// 		data->key->key_left = false;
// 	if (keycode == KEY_SHIFT)
// 		data->run = false;
// 	return (EXIT_SUCCESS);
// }

// int	key_press(int keycode, t_data *data)
// {
// 	if (keycode == KEY_ESC)
// 		free_all(data);
// 	else if (keycode == KEY_W)
// 		data->key->key_w = true;
// 	else if (keycode == KEY_S)
// 		data->key->key_s = true;
// 	else if (keycode == KEY_A)
// 		data->key->key_a = true;
// 	else if (keycode == KEY_D)
// 		data->key->key_d = true;
// 	if (keycode == KEY_RIGHT)
// 		data->key->key_right = true;
// 	else if (keycode == KEY_LEFT)
// 		data->key->key_left = true;
// 	if (keycode == KEY_SHIFT)
// 		data->run = true;
// 	return (EXIT_SUCCESS);
// }

// bool	game_management(t_data *data)
// {
// 	data->mlx = mlx_init();
// 	if (!data->mlx)
// 		return (data->error->error_g |= ERROR_INIT_MLX, EXIT_FAILURE);
// 	if (init_data(data))
// 		return (EXIT_FAILURE);
// 	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
// 	if (!data->win)
// 		return (data->error->error_g |= ERROR_MLX_WIN, EXIT_FAILURE);
// 	// mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
// 	// mlx_hook(data->win, KeyRelease, KeyReleaseMask, key_release, data);
// 	// mlx_loop_hook(data->mlx, game_loop, data);
// 	// mlx_hook(data->win, 17, 0, (void *)free_all, data);
// 	// mlx_loop(data->mlx);
// 	// free_all(data);
// 	return (EXIT_SUCCESS);
// }
